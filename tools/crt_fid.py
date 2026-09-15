#!/usr/bin/env python3
"""Offline CRT Function ID candidate generation; writes only beneath .work/fid.

No backend/MCP access. See docs/crt-fid.md for the report contract and limitations.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import signal
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
TARGET_SHA256 = "e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86"
APPROVED_ARCHIVES = {
    "e5f0d0e6dd2e01dbb0005e9dd4764507b852ede9a824798f0970bc570966a7e3": "libc.lib",
    "d7bdb49c0a3bc77dee026b9aa9a994c5a78963c8aefc6512dbb298b4d41c4907": "libcmt.lib",
}
SCRIPT_NAMES = ("CrtFidSupport.java", "CrtFidPrepare.java", "CrtFidBuild.java", "CrtFidQuery.java")


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def identity(path: Path) -> dict:
    return {"path": str(path), "sha256": digest(path.read_bytes()), "size": path.stat().st_size}


def write_json(path: Path, value) -> None:
    # All callers use fresh run-owned paths; never replace an existing report.
    with path.open("x", encoding="utf-8") as f:
        json.dump(value, f, indent=2, sort_keys=True, allow_nan=False)
        f.write("\n")


def archive_members(data: bytes) -> list[dict]:
    """Parse ordinary COFF/ar archives, not thin archives. Never use member paths.

    Supports Microsoft /offset + NUL long names and GNU /offset + /newline.
    Duplicate names are kept with header offsets. BSD extended names fail closed.
    """
    if not data.startswith(b"!<arch>\n"):
        raise ValueError("not an ordinary ar archive")
    raw, longnames, pos = [], None, 8
    while pos < len(data):
        if pos + 60 > len(data) or data[pos + 58:pos + 60] != b"`\n":
            raise ValueError("truncated/invalid archive header")
        name = data[pos:pos + 16].rstrip(b" ")
        field = data[pos + 48:pos + 58].strip()
        if not field.isdigit():
            raise ValueError("invalid member size")
        size = int(field)
        end = pos + 60 + size
        if end > len(data):
            raise ValueError("truncated archive member")
        body = data[pos + 60:end]
        if name == b"//":
            if longnames is not None:
                raise ValueError("duplicate long-name table")
            longnames = body
        elif name not in (b"/", b"/SYM64/"):
            raw.append((pos, name, body))
        if size & 1 and (end >= len(data) or data[end:end + 1] != b"\n"):
            raise ValueError("missing archive alignment padding")
        pos = end + (size & 1)
    result = []
    for offset, name, body in raw:
        if name.startswith(b"#1/"):
            raise ValueError("BSD extended names are not supported")
        if name.startswith(b"/") and name[1:].isdigit():
            index = int(name[1:])
            if longnames is None or index >= len(longnames):
                raise ValueError("invalid long-name offset")
            if index and longnames[index - 1:index] not in (b"\0", b"\n"):
                raise ValueError("long-name offset does not start a name")
            tail = longnames[index:]
            ends = [i for i in (tail.find(b"\0"), tail.find(b"/\n")) if i >= 0]
            if not ends:
                raise ValueError("unterminated long name")
            name = tail[:min(ends)]
        elif name.endswith(b"/"):
            name = name[:-1]
        if not name or b"\0" in name:
            raise ValueError("invalid member name")
        result.append({"headerOffset": offset, "originalName": name.decode("ascii"),
                       "sha256": digest(body), "size": len(body), "data": body})
    return result


def coff_symbols(data: bytes) -> list[str]:
    """Raw, decorated defined external function symbols in ordinary i386 COFF."""
    if len(data) < 20:
        raise ValueError("short COFF header")
    machine, sections, _, ptr, count, optional, _ = struct.unpack_from("<HHIIIHH", data)
    if machine != 0x14c or optional or not sections:
        raise ValueError("only ordinary i386 COFF objects are supported")
    end = ptr + count * 18
    if 20 + sections * 40 > len(data) or ptr < 20 + sections * 40 or end + 4 > len(data):
        raise ValueError("invalid COFF tables")
    strings_size = struct.unpack_from("<I", data, end)[0]
    if strings_size < 4 or end + strings_size > len(data):
        raise ValueError("invalid COFF string table")
    names, i = set(), 0
    while i < count:
        off = ptr + i * 18
        name, value, section, typ, storage, aux = struct.unpack_from("<8sIhHBB", data, off)
        if i + aux >= count:
            raise ValueError("invalid auxiliary symbol count")
        if name[:4] == b"\0" * 4:
            n = struct.unpack_from("<I", name, 4)[0]
            if n < 4 or n >= strings_size:
                raise ValueError("invalid symbol string offset")
            tail = data[end + n:end + strings_size]
            if b"\0" not in tail:
                raise ValueError("unterminated symbol name")
            name = tail.split(b"\0", 1)[0]
        else:
            name = name.split(b"\0", 1)[0]
        if storage == 2 and 0 < section <= sections and typ & 0x30 == 0x20:
            flags = struct.unpack_from("<I", data, 20 + (section - 1) * 40 + 36)[0]
            if flags & 0x20000020:
                names.add(name.decode("ascii"))
        i += 1 + aux
    return sorted(names)


def validate_extents(value) -> list[dict]:
    if not isinstance(value, list):
        raise ValueError("extents must be a JSON list")
    result, seen, verified = [], set(), []
    for item in value:
        if not isinstance(item, dict) or set(item) != {"entry", "size", "extentVerified"}:
            raise ValueError("extent requires exactly entry, size, extentVerified")
        entry, size, flag = item["entry"], item["size"], item["extentVerified"]
        if not isinstance(entry, str) or not re.fullmatch(r"(?:0x)?[0-9a-fA-F]{8}", entry):
            raise ValueError("entry must be an eight-digit hexadecimal address")
        address = int(entry, 16)
        if type(size) is not int or size <= 0 or address + size > 2**32:
            raise ValueError("invalid extent size/range")
        if type(flag) is not bool or address in seen:
            raise ValueError("invalid extentVerified or duplicate entry")
        seen.add(address)
        result.append({"entry": f"{address:08x}", "size": size, "extentVerified": flag})
        if flag:
            verified.append((address, address + size))
    verified.sort()
    if any(a[1] > b[0] for a, b in zip(verified, verified[1:])):
        raise ValueError("overlapping verified extents")
    return sorted(result, key=lambda r: r["entry"])


def fresh_run(run_id: str, root: Path = ROOT) -> Path:
    if not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_-]{0,79}", run_id):
        raise ValueError("invalid run ID")
    base = root / ".work" / "fid"
    # Refuse redirects outside the checkout, including an existing run symlink.
    for path in (root / ".work", base, base / run_id):
        if path.is_symlink():
            raise ValueError(f"symlink output refused: {path}")
    base.mkdir(parents=True, exist_ok=True)
    run = base / run_id
    run.mkdir()  # No resume/overwrite: failed runs remain evidence.
    return run


def run_headless(run: Path, ghidra: Path, java: Path, args: list[str], label: str,
                 timeout: int) -> None:
    # Do not inherit shell startup hooks, JVM injection, provider keys or GUI settings.
    env = {"LANG": "C.UTF-8", "LC_ALL": "C.UTF-8", "TZ": "UTC"}
    env.update(HOME=str(run / "home"), XDG_CONFIG_HOME=str(run / "home/config"),
               XDG_CACHE_HOME=str(run / "home/cache"), XDG_DATA_HOME=str(run / "home/data"),
               TMPDIR=str(run / "tmp"), JAVA_HOME=str(java),
               PATH=str(java / "bin") + ":/usr/bin:/bin")
    # _JAVA_OPTIONS also isolates LaunchSupport, which runs before the headless JVM.
    props = {"user.home": run / "home", "application.settingsdir": run / "settings",
             "application.cachedir": run / "cache", "application.tempdir": run / "tmp",
             "java.io.tmpdir": run / "tmp", "crt.fid.run": run}
    if any(re.search(r"\s", str(p)) for p in props.values()):
        raise ValueError("JVM isolation paths must not contain whitespace")
    env["_JAVA_OPTIONS"] = " ".join(f"-D{k}={v}" for k, v in props.items())
    # Ghidra 12 rejects dot-prefixed project path components (.work). Linux procfs
    # provides a lexical alias into this subprocess's run-owned working directory.
    cmd = [str(ghidra / "support/analyzeHeadless"), "/proc/self/cwd/projects", *args,
           "-scriptPath", str(run / "scripts"), "-max-cpu", "2",
           "-log", str(run / f"{label}.ghidra.log"),
           "-scriptlog", str(run / f"{label}.script.log")]
    write_json(run / f"{label}.command.json", {"argv": cmd, "jvmProperties": props_as_strings(props)})
    with (run / f"{label}.log").open("xb") as log:
        proc = subprocess.Popen(cmd, cwd=run, env=env, stdout=log, stderr=subprocess.STDOUT,
                                start_new_session=True)
        try:
            code = proc.wait(timeout=timeout)
        except BaseException:
            os.killpg(proc.pid, signal.SIGKILL)
            proc.wait()
            raise
    if code:
        raise RuntimeError(f"headless failed ({code}); see {run / (label + '.log')}")


def props_as_strings(props):
    return {k: str(v) for k, v in props.items()}


def tool_identity(ghidra: Path, java: Path) -> dict:
    # Include analysis data/patterns/native executables as well as jars and processor specs.
    paths = sorted(p for p in (ghidra / "Ghidra").rglob("*") if p.is_file())
    paths += [ghidra / "support" / n for n in ("analyzeHeadless", "launch.sh", "launch.properties", "LaunchSupport.jar")]
    files = [identity(p) for p in paths]
    return {"ghidraFiles": files, "ghidraManifestSha256": digest(json.dumps(files, sort_keys=True).encode()),
            "javaFiles": [identity(java / n) for n in ("bin/java", "release", "lib/modules")],
            "pythonVersion": sys.version, "pythonExecutable": identity(Path(sys.executable).resolve()),
            "driver": identity(Path(__file__).resolve())}


def execute(args) -> Path:
    archives, objects, selectors_found = [], {}, set()
    for path in args.archive:
        path = path.resolve()
        data = path.read_bytes()
        sha = digest(data)
        if sha not in APPROVED_ARCHIVES:
            raise ValueError(f"archive hash is not approved: {path} ({sha})")
        if any(a["sha256"] == sha for a in archives):
            raise ValueError("duplicate archive")
        selected = []
        for member in archive_members(data):
            # Selector is an exact original name or exact basename, never a glob/path to extract.
            original = member["originalName"]
            basename = original.replace("\\", "/").rsplit("/", 1)[-1]
            hits = set(args.member) & {original, basename}
            if not args.all_members and not hits:
                continue
            selectors_found.update(hits)
            body = member.pop("data")
            # c1032 archives also carry machine-neutral symbol aliases and empty
            # debug/thread placeholders. Record these, never import them as code.
            if len(body) >= 20 and (struct.unpack_from('<H', body)[0] == 0 or body[:4] == b'\x4c\x01\x00\x00'):
                member['canonicalSymbols'] = []
                member['diagnostic'] = 'machine-neutral alias or sectionless placeholder; not an i386 function object'
            else:
                member["canonicalSymbols"] = coff_symbols(body)
            if not member["canonicalSymbols"]:
                member.setdefault("diagnostic", "no defined external COFF function symbols")
            else:
                member["objectFile"] = f"objects/{member['sha256']}.obj"
                objects[member["sha256"]] = (body, member["canonicalSymbols"])
            selected.append(member)
        archives.append({"path": str(path), "sha256": sha, "size": len(data),
                         "approvedName": APPROVED_ARCHIVES[sha], "members": selected})
    if set(args.member) - selectors_found:
        raise ValueError(f"member selectors not found: {sorted(set(args.member) - selectors_found)}")
    if not objects or len(objects) > args.max_members:
        raise ValueError(f"selected {len(objects)} unique objects; limit is {args.max_members}")
    target = args.target.resolve()
    target_data = target.read_bytes()
    if digest(target_data) != TARGET_SHA256:
        raise ValueError("target SHA256 mismatch")
    extents_data = args.extents.read_bytes() if args.extents else b"[]"
    extents = validate_extents(json.loads(extents_data))
    tools = tool_identity(args.ghidra.resolve(), args.java_home.resolve())
    run = fresh_run(args.run_id)
    try:
        for folder in ("objects", "scripts", "projects", "home", "settings", "cache", "tmp", "canonical"):
            (run / folder).mkdir()
        scripts = []
        for name in SCRIPT_NAMES:
            source = ROOT / "tools/ghidra" / name
            data = source.read_bytes()
            (run / "scripts" / name).write_bytes(data)
            scripts.append({"name": name, "sha256": digest(data)})
        for sha, (data, _) in sorted(objects.items()):
            (run / "objects" / f"{sha}.obj").write_bytes(data)
        (run / "target.exe").write_bytes(target_data)
        (run / "extents-input.json").write_bytes(extents_data)
        write_json(run / "extents.json", extents)
        manifest = {"schemaVersion": 1, "archives": archives,
                    "objects": {sha: {"canonicalSymbols": names} for sha, (_, names) in sorted(objects.items())}}
        write_json(run / "manifest.json", manifest)
        write_json(run / "invocation.json", {"tools": tools, "scripts": scripts,
            "targetSha256": TARGET_SHA256, "scoreThreshold": args.score_threshold,
            "timeoutSeconds": args.timeout, "maxMembers": args.max_members,
            "memberSelectors": args.member, "allMembers": args.all_members})
        def headless(argv, label):
            run_headless(run, args.ghidra.resolve(), args.java_home.resolve(), argv, label, args.timeout)
        headless(["crt-library", "-import", str(run / "objects"), "-recursive",
                  "-noanalysis", "-postScript", "CrtFidPrepare.java", "library"], "import-all")
        for sha in sorted(objects):
            if not (run / "canonical" / f"{sha}.json").is_file():
                raise RuntimeError("canonical-symbol stage did not complete; inspect logs")
        headless(["crt-library/objects", "-process", f"{sorted(objects)[0]}.obj", "-noanalysis",
                  "-postScript", "CrtFidBuild.java"], "build")
        if not (run / "generation.json").is_file():
            raise RuntimeError("FID generation did not complete; inspect logs")
        db_before = identity(run / "crt.fidb")
        headless(["crt-target", "-import", str(run / "target.exe"),
                  "-noanalysis", "-postScript", "CrtFidPrepare.java", "target"], "target-import")
        if not (run / "target-prepared.json").is_file():
            raise RuntimeError("target preparation did not complete; inspect logs")
        headless(["crt-target", "-process", "target.exe", "-readOnly", "-noanalysis",
                  "-postScript", "CrtFidQuery.java", str(args.score_threshold)], "query")
        query = json.loads((run / "query.json").read_text())
        if identity(run / "crt.fidb") != db_before:
            raise RuntimeError("read-only query changed FID database")
        if query["targetSha256"] != TARGET_SHA256 or query["activeDatabases"] != [str(run / "crt.fidb")]:
            raise RuntimeError("query identity/isolation mismatch")
        provenance = {}
        for archive in archives:
            for member in archive["members"]:
                provenance.setdefault(member["sha256"], []).append({
                    "archiveSha256": archive["sha256"], "memberSha256": member["sha256"],
                    "originalName": member["originalName"], "headerOffset": member["headerOffset"]})
        for result in query["results"]:
            for match in result["matches"]:
                sha = Path(match["domainPath"]).stem
                if sha not in provenance or match["name"] not in objects[sha][1]:
                    raise RuntimeError("match lacks canonical object provenance")
                match["provenance"] = [p for p in provenance[sha] if p["archiveSha256"] == match["libraryVersion"]]
                if not match["provenance"]:
                    raise RuntimeError("match library provenance mismatch")
        if tool_identity(args.ghidra.resolve(), args.java_home.resolve()) != tools:
            raise RuntimeError("tool installation/driver changed during run")
        generation = json.loads((run / "generation.json").read_text())
        semantic = {"generation": {k: v for k, v in generation.items() if k != "databaseSha256"},
                    "query": {k: v for k, v in query.items() if k not in ("databaseSha256", "activeDatabases")},
                    "extents": extents}
        report = {"schemaVersion": 1, "kind": "crt-fid-candidates", "status": "completed",
                  "proof": False, "runId": args.run_id, "tools": tools, "scripts": scripts,
                  "semanticSha256": digest(json.dumps(semantic, sort_keys=True, separators=(",", ":")).encode()),
                  "archives": archives, "target": {"sourcePath": str(target), **identity(run / "target.exe")},
                  "database": db_before, "extents": {"input": identity(run / "extents-input.json"), "normalized": extents},
                  "generation": generation, "query": query,
                  "artifacts": [identity(p) for p in sorted(run.glob("*.json"))] +
                               [identity(p) for p in sorted(run.glob("*.log"))] +
                               [identity(p) for p in sorted((run / "canonical").glob("*.json"))]}
        write_json(run / "report.json", report)
        return run / "report.json"
    except BaseException as exc:
        write_json(run / "failure.json", {"status": "failed", "error": str(exc), "proof": False})
        raise


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--archive", action="append", required=True, type=Path)
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("--member", action="append", default=[])
    group.add_argument("--all-members", action="store_true")
    parser.add_argument("--max-members", type=int, default=16)
    parser.add_argument("--target", type=Path, default=ROOT / ".work/original.exe")
    parser.add_argument("--extents", type=Path)
    parser.add_argument("--ghidra", type=Path, default=Path("/opt/ghidra"))
    parser.add_argument("--java-home", type=Path, default=Path("/usr/lib/jvm/java-21-openjdk"))
    parser.add_argument("--run-id", required=True)
    parser.add_argument("--timeout", type=int, default=300, help="seconds per headless process")
    parser.add_argument("--score-threshold", type=float, default=0.0)
    args = parser.parse_args()
    if not (0 <= args.score_threshold <= 100000) or args.max_members <= 0 or args.timeout <= 0:
        parser.error("invalid bound/score threshold")
    try:
        print(execute(args))
    except (ValueError, OSError, RuntimeError, subprocess.TimeoutExpired) as exc:
        parser.exit(1, f"crt-fid: {exc}\n")


if __name__ == "__main__":
    main()
