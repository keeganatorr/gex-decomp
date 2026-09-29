#!/usr/bin/env python3
"""Assemble checked-in textual Windows resources without the original EXE."""

from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parent.parent
SOURCE = ROOT / "src/replacement/image_resources.s"
OBJECT = ROOT / ".work/replacement-data/image_resources.obj"


def main() -> None:
    if not SOURCE.is_file():
        raise SystemExit(f"missing textual resource source: {SOURCE}")
    OBJECT.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(["i686-w64-mingw32-as", "-o", str(OBJECT), str(SOURCE)], check=True)
    print(f"resource object assembled: {OBJECT}")


if __name__ == "__main__":
    main()
