#!/usr/bin/env python3
"""Attempt a whole-source PE link and retain the unresolved-symbol report.

This is a diagnostic link with the temporary link-smoke main, not a playable
replacement. It reads source-built rebound COFF and toolchain libraries only.
The old VC4 linker needs short object names to fit its response-file limit.
"""

from collections import Counter
import json
import os
from pathlib import Path
import re
import shutil
import subprocess


ROOT = Path(__file__).resolve().parent.parent
INPUT = ROOT / ".work/replacement-rebound"
WORK = ROOT / ".work/replacement-short"
UNRESOLVED = re.compile(r'LNK2001: unresolved external symbol (?:"[^"]+"\(([^)]+)\)|(\S+))')
DUPLICATE = re.compile(r"LNK2005: (\S+)")
TOTAL = re.compile(r"LNK1120: (\d+) unresolved externals")


def win(path: Path) -> str:
    return "Z:" + str(path.resolve()).replace("/", "\\")


def main() -> None:
    project = json.loads((ROOT / "project.json").read_text())
    tc = project["toolchain"]
    compiler = Path(tc["compiler"])
    linker = compiler.with_name("link.exe")
    crt = compiler.parent.parent / "lib"
    sdk = compiler.parents[5] / "public/sdk/lib/chicago/i386"
    comctl_def = ROOT / "src/replacement/comctl32.def"
    comctl_lib = WORK / "comctl32.lib"
    sources = sorted((ROOT / "src/functions").glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                                      "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].cpp"))
    objects = [INPUT / f"{source.stem}.obj" for source in sources]
    harness = ROOT / ".work/replacement-link-smoke/link_smoke.obj"
    image_data = ROOT / ".work/replacement-data/image_data.rebound.obj"
    image_resources = ROOT / ".work/replacement-data/image_resources.obj"
    libraries = [crt / "libc.lib", sdk / "kernel32.lib", sdk / "user32.lib",
                 sdk / "gdi32.lib", sdk / "advapi32.lib", crt / "winmm.lib",
                 crt / "shell32.lib", crt / "comdlg32.lib", crt / "oldnames.lib"]
    # The original PE forwards these two thunks through its IAT. The VC4-era
    # SDK set above lacks these archives; use the same import libraries as the
    # resource-bearing LLD link for the source-only replacement assessment.
    import_lib_query = subprocess.run(
        ["i686-w64-mingw32-gcc", "-print-file-name=libddraw.a"],
        capture_output=True, text=True, check=True)
    import_lib_dir = Path(import_lib_query.stdout.strip()).resolve().parent
    libraries += [import_lib_dir / "libddraw.a", import_lib_dir / "libdsound.a"]
    missing = [path for path in [linker, harness, image_data, image_resources,
                                  comctl_def, *objects, *libraries]
               if not path.is_file()]
    if missing:
        raise SystemExit(f"missing build input: {missing[0]} ({len(missing)} total)")
    WORK.mkdir(parents=True, exist_ok=True)
    subprocess.run(["i686-w64-mingw32-dlltool", "-d", str(comctl_def),
                    "-l", str(comctl_lib), "-k"], check=True)
    libraries.append(comctl_lib)
    object_map = {}
    for index, (source, obj) in enumerate(zip(sources, objects)):
        short = f"{index:x}.obj"
        shutil.copyfile(obj, WORK / short)
        object_map[short] = source.stem
    shutil.copyfile(harness, WORK / "main.obj")
    shutil.copyfile(image_data, WORK / "data.obj")
    shutil.copyfile(image_resources, WORK / "rsrc.obj")
    (WORK / "object-addresses.json").write_text(json.dumps(object_map, indent=2) + "\n")
    response = WORK / "link.rsp"
    response.write_text("/NOLOGO\n/SUBSYSTEM:CONSOLE\n/OUT:full-link-probe.exe\n" +
                        "\n".join(object_map) + "\nmain.obj\n" +
                        "data.obj\nrsrc.obj\n" +
                        "\n".join(win(path) for path in libraries) + "\n")
    if response.stat().st_size >= 16000:
        raise SystemExit("VC4 response file is too long; shorten object names")
    env = dict(os.environ, WINEPREFIX=tc["winePrefix"], WINEDEBUG="-all")
    try:
        run = subprocess.run([tc["wine"], str(linker), "@" + win(response)],
                             cwd=WORK, env=env, capture_output=True, text=True,
                             timeout=120)
        output, exit_code = run.stdout + run.stderr, run.returncode
    except subprocess.TimeoutExpired as exc:
        output = ((exc.stdout or b"").decode(errors="replace") +
                  (exc.stderr or b"").decode(errors="replace") + "\nTIMEOUT\n")
        exit_code = -1
    (WORK / "full-link.log").write_text(output)
    unresolved = Counter(decorated or plain for decorated, plain in UNRESOLVED.findall(output))
    duplicate = Counter(DUPLICATE.findall(output))
    total_match = TOTAL.search(output)
    report = {
        "format": "gex-source-link-probe-v1",
        "sourceObjects": len(objects), "linkerExitCode": exit_code,
        "dataObject": str(image_data.relative_to(ROOT)),
        "resourceObject": str(image_resources.relative_to(ROOT)),
        "reportedUnresolvedTotal": int(total_match.group(1)) if total_match else None,
        "uniqueLnk2001Symbols": len(unresolved), "lnk2001Occurrences": sum(unresolved.values()),
        "unresolvedSymbols": dict(unresolved.most_common()),
        "duplicateDefinitions": dict(duplicate.most_common()),
        "responseBytes": response.stat().st_size,
        "note": "Diagnostic link with link-smoke main; no original EXE/DB/proof artifacts read.",
    }
    (WORK / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"{len(objects)} source-built objects attempted with VC4 LINK")
    print(f"{report['reportedUnresolvedTotal']} linker-reported unresolved externals; "
          f"{len(duplicate)} duplicate definitions")
    print(f"log: {WORK / 'full-link.log'}")
    if not total_match and exit_code:
        print("link stopped before the unresolved-symbol summary; inspect the log")


if __name__ == "__main__":
    main()
