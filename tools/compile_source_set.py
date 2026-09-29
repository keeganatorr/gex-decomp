#!/usr/bin/env python3
"""Compile each reconstructed Gex function to a Ghidra-named COFF object.

This source-only build inventory does not open the original EXE, database or
retained verifier artifacts. It changes no proof or backend state. Objects and
the report stay ignored under .work/replacement-objects/.
"""

import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
from address_literals import relocate
from function_names import NAMES


ROOT = Path(__file__).resolve().parent.parent
PROJECT = json.loads((ROOT / "project.json").read_text())
TC = PROJECT["toolchain"]
WORK = ROOT / ".work/replacement-objects"
IMAGE_OWNED_GLOBALS = {
    "0040fe00": ("int CAMERA_XPos_004a2a38;", "int CAMERA_YPos_004a2a1c;",
                 "int DAT_004A2964;"),
    "0044a9a2": ("unsigned int DAT_00461404;",),
}


def use_image_storage(source: str, address: str) -> str:
    """Let the source-built data section own globals originally defined in a TU."""
    for definition in IMAGE_OWNED_GLOBALS.get(address, ()):
        count = source.count(definition)
        if count != 1:
            raise ValueError(f"{address}: expected one definition of {definition}, found {count}")
        source = source.replace(definition, "extern " + definition)
    return source


def win(path: Path) -> str:
    return "Z:" + str(path.resolve()).replace("/", "\\")


def compile_one(source: Path, env: dict[str, str], cached: dict,
                refresh: bool) -> dict:
    address = source.stem
    override = PROJECT.get("functionOverrides", {}).get(address, {})
    language = override.get("language", "cpp")
    flags = override.get("flags", TC["flags"])
    export = NAMES[address]
    obj = WORK / f"{address}.obj"
    transformed, literals = relocate(use_image_storage(source.read_text(), address), language)
    scratch_source = WORK / "source" / f"{address}.cpp"
    source_hash = hashlib.sha256(source.read_bytes()).hexdigest()
    contract = {"language": language, "flags": flags, "export": export,
                "compilerHash": TC["componentHashes"]["cl.exe"],
                "literalRelocation": "v1", "imageStorage": "v1"}
    basis = hashlib.sha256((source_hash + hashlib.sha256(transformed.encode()).hexdigest() +
                            json.dumps(contract, sort_keys=True)).encode()).hexdigest()
    previous = cached.get(address, {})
    if not refresh and previous.get("basis") == basis and previous.get("result") == "compiled" and obj.is_file():
        if hashlib.sha256(obj.read_bytes()).hexdigest() == previous.get("objectSha256"):
            return previous
    obj.unlink(missing_ok=True)
    scratch_source.parent.mkdir(parents=True, exist_ok=True)
    scratch_source.write_text(transformed)
    command = [TC["wine"], TC["compiler"], "/nologo", "/c", *flags,
               "/Fo" + win(obj),
               ("/Tc" if language == "c" else "/Tp") + win(scratch_source)]
    try:
        run = subprocess.run(command, cwd=WORK, env=env, text=True,
                             stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                             timeout=90)
        output = run.stdout
        passed = run.returncode == 0 and obj.is_file()
        result_kind = "compiled" if passed else "failed"
    except subprocess.TimeoutExpired as exc:
        output = str(exc)
        passed = False
        result_kind = "timeout"
    result = {"source": str(source.relative_to(ROOT)), "sourceSha256": source_hash,
              "basis": basis, "contract": contract,
              "relocatedLiterals": [f"{address:08x}" for address in sorted(literals)],
              "result": result_kind,
              "objectSha256": hashlib.sha256(obj.read_bytes()).hexdigest() if passed else None,
              "compilerOutput": output[-4000:]}
    if not passed:
        obj.unlink(missing_ok=True)
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, help="compile only the first N sources")
    parser.add_argument("--refresh", action="store_true", help="ignore the object cache")
    args = parser.parse_args()
    sources = sorted((ROOT / "src/functions").glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                                      "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].cpp"))
    if args.limit is not None:
        if args.limit < 1:
            parser.error("--limit must be positive")
        sources = sources[:args.limit]
    WORK.mkdir(parents=True, exist_ok=True)
    report_path = WORK / "report.json"
    old = json.loads(report_path.read_text()) if report_path.is_file() else {}
    cached = old.get("functions", {})
    env = dict(os.environ, WINEPREFIX=TC["winePrefix"], WINEDEBUG="-all",
               WINEDLLOVERRIDES="winemenubuilder.exe=d",
               INCLUDE="", LIB="", CL="", _CL_="")
    subprocess.run(["wineserver", "-p900"], env=env, stdin=subprocess.DEVNULL,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    subprocess.run([TC["wine"], "cmd", "/c", "exit"], env=env,
                   stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL,
                   stderr=subprocess.DEVNULL, timeout=60, check=True)
    results = dict(cached)
    for index, source in enumerate(sources, 1):
        results[source.stem] = compile_one(source, env, cached, args.refresh)
        if index % 50 == 0 or index == len(sources):
            failures = sum(results[item.stem]["result"] != "compiled" for item in sources[:index])
            print(f"{index}/{len(sources)} compiled or cached; {failures} failed", flush=True)
    report = {"format": "gex-source-compile-v1", "sourceCount": len(sources),
              "functions": results,
              "note": "Source-only COFF compilation; no original EXE, DB or proof artifacts read."}
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    failed = [a for a in (source.stem for source in sources)
              if results[a]["result"] != "compiled"]
    print(f"report: {report_path}")
    print(f"selected {len(sources)}; compiled {len(sources)-len(failed)}; failed {len(failed)}")
    if failed:
        print("first failures: " + ", ".join(failed[:20]))
        raise SystemExit(2)


if __name__ == "__main__":
    main()
