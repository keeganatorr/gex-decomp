#!/usr/bin/env python3
"""Compile the source-only WinMain CRT adapter with the pinned VC4 compiler."""

import json
import os
from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parent.parent
TC = json.loads((ROOT / "project.json").read_text())["toolchain"]
SOURCES = {
    "game_entry": ROOT / "src/replacement/game_entry.cpp",
    "menu_options": ROOT / "src/replacement/menu_options.cpp",
    "widescreen_runtime": ROOT / "src/replacement/widescreen_runtime.cpp",
    "manual_zoom": ROOT / "src/replacement/manual_zoom.cpp",
    "sprite_viewer": ROOT / "src/replacement/sprite_viewer.cpp",
    "save_states": ROOT / "src/replacement/save_states.cpp",
    "state_audio": ROOT / "src/replacement/state_audio.cpp",
}
OUTPUT_DIR = ROOT / ".work/replacement-short"


def win(path: Path) -> str:
    return "Z:" + str(path.resolve()).replace("/", "\\")


def main() -> None:
    from build_save_state_schema import build
    build()
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, WINEPREFIX=TC["winePrefix"], WINEDEBUG="-all",
               INCLUDE="", LIB="", CL="", _CL_="")
    for name, source in SOURCES.items():
        output = OUTPUT_DIR / f"{name}.obj"
        subprocess.run([TC["wine"], TC["compiler"], "/nologo", "/c",
                        *TC["flags"], "/Fo" + win(output), "/Tp" + win(source)],
                       cwd=OUTPUT_DIR, env=env, check=True, timeout=90)
        print(f"game entry adapter: {output}")


if __name__ == "__main__":
    main()
