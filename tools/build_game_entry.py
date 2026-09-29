#!/usr/bin/env python3
"""Compile the source-only WinMain CRT adapter with the pinned VC4 compiler."""

import json
import os
from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parent.parent
TC = json.loads((ROOT / "project.json").read_text())["toolchain"]
SOURCE = ROOT / "src/replacement/game_entry.cpp"
OUTPUT = ROOT / ".work/replacement-short/game_entry.obj"


def win(path: Path) -> str:
    return "Z:" + str(path.resolve()).replace("/", "\\")


def main() -> None:
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, WINEPREFIX=TC["winePrefix"], WINEDEBUG="-all",
               INCLUDE="", LIB="", CL="", _CL_="")
    subprocess.run([TC["wine"], TC["compiler"], "/nologo", "/c",
                    *TC["flags"], "/Fo" + win(OUTPUT), "/Tp" + win(SOURCE)],
                   cwd=OUTPUT.parent, env=env, check=True, timeout=90)
    print(f"game entry adapter: {OUTPUT}")


if __name__ == "__main__":
    main()
