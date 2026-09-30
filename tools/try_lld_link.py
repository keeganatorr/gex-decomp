#!/usr/bin/env python3
"""Attempt a resource-bearing source-only PE link with LLD and modern imports.

VC4 LINK handles the source COFF but fails internally while padding a .rsrc
COFF section. LLD links that resource object correctly. The source functions
are still compiled with the pinned VC4 CL contract; only the final linker and
Win32 import archives differ. This diagnostic main is not Gex's entry point.
"""

import argparse
import json
from pathlib import Path
import re
import shutil
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
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--game", action="store_true",
                        help="link through WinMainCRTStartup instead of diagnostic main")
    args = parser.parse_args()
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
    if args.game:
        # LLD selects multiple VC4 CRT startup members from libc.lib when its
        # WinMain entry is requested. Keep the Windows startup member and all
        # ordinary CRT members in an ignored, build-local archive copy.
        game_crt = WORK / "libc-game.lib"
        shutil.copyfile(libraries[0], game_crt)
        removed = ["crt0.obj", "dllcrt0.obj", "wcrt0.obj", "wwincrt0.obj"]
        members = [f"build\\intel\\st_obj\\{name}" for name in removed]
        subprocess.run(["llvm-ar", "d", str(game_crt), *members], check=True)
        listing = subprocess.run(["llvm-ar", "t", str(game_crt)],
                                 capture_output=True, text=True, check=True).stdout
        if "build\\intel\\st_obj\\wincrt0.obj" not in listing or any(
                member in listing for member in members):
            raise SystemExit("VC4 game CRT startup archive selection failed")
        libraries[0] = game_crt
    entry = "game_entry.obj" if args.game else "main.obj"
    inputs = [WORK / name for name in objects] + [
        WORK / name for name in (entry, "data.obj", "rsrc.obj")]
    missing = [path for path in inputs + libraries if not path.is_file()]
    if missing:
        raise SystemExit(f"missing LLD link input: {missing[0]} ({len(missing)} total)")
    output = WORK / ("gex-source.exe" if args.game else "full-link-lld.exe")
    symbol_map = WORK / "gex-source.map" if args.game else None
    output.unlink(missing_ok=True)
    response = WORK / ("link-game-lld.rsp" if args.game else "link-lld.rsp")
    response.write_text("\n".join([
        "/nologo", "/subsystem:windows" if args.game else "/subsystem:console",
        "/entry:WinMainCRTStartup" if args.game else "/entry:mainCRTStartup",
        "/safeseh:no", "/nodefaultlib",
        "/errorlimit:0", "/out:" + quoted(output),
        *(["/map:" + quoted(symbol_map)] if symbol_map else []),
        *(quoted(path) for path in inputs + libraries),
    ]) + "\n")
    run = subprocess.run(["lld-link", "@" + str(response)], cwd=WORK,
                         capture_output=True, text=True, timeout=120)
    log = run.stdout + run.stderr
    log_path = WORK / ("game-link-lld.log" if args.game else "full-link-lld.log")
    log_path.write_text(log)
    undefined = sorted(set(UNDEFINED.findall(log)))
    duplicate = sorted(set(DUPLICATE.findall(log)))
    report = {"format": "gex-source-lld-link-probe-v1", "sourceObjects": len(objects),
              "linkerExitCode": run.returncode, "unresolvedCount": len(undefined),
              "unresolvedSymbols": undefined, "duplicateDefinitions": duplicate,
              "resourceObject": ".work/replacement-data/image_resources.obj",
              "entryKind": "game" if args.game else "diagnostic",
              "executable": str(output.relative_to(ROOT)) if output.is_file() else None,
              "note": "VC4 source COFF with LLD and modern Win32 import archives."}
    report_path = WORK / ("game-lld-report.json" if args.game else "lld-report.json")
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    print(f"LLD resource-bearing link: {len(undefined)} unresolved, "
          f"{len(duplicate)} duplicates; exit {run.returncode}")
    print(f"log: {log_path}")


if __name__ == "__main__":
    main()
