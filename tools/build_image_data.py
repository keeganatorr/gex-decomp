#!/usr/bin/env python3
"""Assemble checked-in image data and bind its function pointers to source COFF.

This ordinary build step does not read GEX.exe or the backend database. The
textual image_data.s was generated once with generate_image_data_source.py.
"""

import json
from pathlib import Path
import re
import subprocess


ROOT = Path(__file__).resolve().parent.parent
SOURCE = ROOT / "src/replacement/image_data.s"
OBJECTS = ROOT / ".work/replacement-objects"
WORK = ROOT / ".work/replacement-data"
TARGET = re.compile(r"_GEX_FN_([0-9a-f]{8})$")


def main() -> None:
    if not SOURCE.is_file():
        raise SystemExit(f"missing textual data source: {SOURCE}")
    WORK.mkdir(parents=True, exist_ok=True)
    raw = WORK / "image_data.obj"
    rebound = WORK / "image_data.rebound.obj"
    subprocess.run(["i686-w64-mingw32-as", "-o", str(raw), str(SOURCE)], check=True)
    objects = sorted(OBJECTS.glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                   "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].obj"))
    run = subprocess.run(["llvm-nm", "-g", "--format=posix", *(str(obj) for obj in objects)],
                         capture_output=True, text=True, check=True)
    exports = {}
    current = None
    for line in run.stdout.splitlines():
        if line.endswith(":"):
            current = Path(line[:-1]).stem
        elif line and current:
            fields = line.split()
            if len(fields) >= 2 and fields[1].upper() == "T" and f"GEX_FN_{current}" in fields[0]:
                if current in exports:
                    raise SystemExit(f"multiple target exports for {current}")
                exports[current] = fields[0]
    run = subprocess.run(["llvm-nm", "-u", "--format=posix", str(raw)],
                         capture_output=True, text=True, check=True)
    changes = {}
    missing_code = set()
    for line in run.stdout.splitlines():
        fields = line.split()
        if len(fields) < 2 or fields[1] != "U":
            continue
        match = TARGET.fullmatch(fields[0])
        if not match:
            continue
        address = match.group(1)
        if address in exports:
            changes[fields[0]] = exports[address]
        else:
            missing_code.add(address)
    mapping = WORK / "image_data.symbols"
    mapping.write_text("".join(f"{old} {new}\n" for old, new in sorted(changes.items())))
    subprocess.run(["llvm-objcopy", "--redefine-syms=" + str(mapping),
                    str(raw), str(rebound)], check=True)
    report = {"format": "gex-image-data-build-v1", "source": str(SOURCE.relative_to(ROOT)),
              "functionSymbolsRebound": len(changes), "missingFunctionAddresses": sorted(missing_code),
              "note": "Assembled from checked-in text source; no original EXE read."}
    (WORK / "image_data.report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"image data assembled: {len(changes)} function symbols rebound; "
          f"{len(missing_code)} code addresses still lack source")
    print(f"object: {rebound}")


if __name__ == "__main__":
    main()
