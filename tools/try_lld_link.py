#!/usr/bin/env python3
"""Attempt a resource-bearing source-only PE link with LLD and modern imports.

VC4 LINK handles the source COFF but fails internally while padding a .rsrc
COFF section. LLD links that resource object correctly. The source functions
are still compiled with the pinned VC4 CL contract; only the final linker and
Win32 import archives differ. This diagnostic main is not Gex's entry point.
"""

import json
from pathlib import Path
import re
import subprocess


ROOT = Path(__file__).resolve().parent.parent
WORK = ROOT / ".work/replacement-short"
PROJECT = json.loads((ROOT / "project.json").read_text())
LIBRARY_NAMES = ("kernel32", "user32", "gdi32", "advapi32", "winmm",
                 "shell32", "comdlg32", "comctl32", "ddraw", "dsound")
UNDEFINED = re.compile(r"^lld-link: error: undefined symbol: (.+)$", re.M)
DUPLICATE = re.compile(r"^lld-link: error: duplicate symbol: (.+)$", re.M)


def quoted(path: Path) -> str:
    return '"' + str(path.resolve()).replace('"', '\\"') + '"'


def main() -> None:
    manifest = WORK / "object-addresses.json"
    if not manifest.is_file():
        raise SystemExit("run tools/try_full_link.py first to stage short object names")
    objects = list(json.loads(manifest.read_text()))
    compiler = Path(PROJECT["toolchain"]["compiler"])
    crt = compiler.parent.parent / "lib"
    query = subprocess.run(["i686-w64-mingw32-gcc", "-print-file-name=libkernel32.a"],
                           capture_output=True, text=True, check=True)
    mingw = Path(query.stdout.strip()).resolve().parent
    libraries = [crt / "libc.lib", crt / "oldnames.lib"] + [
        mingw / f"lib{name}.a" for name in LIBRARY_NAMES]
    inputs = [WORK / name for name in objects] + [
        WORK / name for name in ("main.obj", "data.obj", "rsrc.obj")]
    missing = [path for path in inputs + libraries if not path.is_file()]
    if missing:
        raise SystemExit(f"missing LLD link input: {missing[0]} ({len(missing)} total)")
    output = WORK / "full-link-lld.exe"
    output.unlink(missing_ok=True)
    response = WORK / "link-lld.rsp"
    response.write_text("\n".join([
        "/nologo", "/subsystem:console", "/safeseh:no", "/nodefaultlib",
        "/errorlimit:0", "/out:" + quoted(output),
        *(quoted(path) for path in inputs + libraries),
    ]) + "\n")
    run = subprocess.run(["lld-link", "@" + str(response)], cwd=WORK,
                         capture_output=True, text=True, timeout=120)
    log = run.stdout + run.stderr
    (WORK / "full-link-lld.log").write_text(log)
    undefined = sorted(set(UNDEFINED.findall(log)))
    duplicate = sorted(set(DUPLICATE.findall(log)))
    report = {"format": "gex-source-lld-link-probe-v1", "sourceObjects": len(objects),
              "linkerExitCode": run.returncode, "unresolvedCount": len(undefined),
              "unresolvedSymbols": undefined, "duplicateDefinitions": duplicate,
              "resourceObject": ".work/replacement-data/image_resources.obj",
              "executable": str(output.relative_to(ROOT)) if output.is_file() else None,
              "note": "Diagnostic main; VC4 source COFF with LLD and modern Win32 import archives."}
    (WORK / "lld-report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"LLD resource-bearing link: {len(undefined)} unresolved, "
          f"{len(duplicate)} duplicates; exit {run.returncode}")
    print(f"log: {WORK / 'full-link-lld.log'}")


if __name__ == "__main__":
    main()
