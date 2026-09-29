#!/usr/bin/env python3
"""Assemble checked-in image data and bind its function pointers to source COFF.

This ordinary build step does not read GEX.exe or the backend database. The
textual image_data.s was generated once with generate_image_data_source.py.
"""

import json
from pathlib import Path
import re
import subprocess
from address_literals import literal_targets
from function_names import coff_export


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
    source_text = SOURCE.read_text()
    defined = set(re.findall(r"^\.globl (_GEX_(?:RDATA|DATA)_[0-9a-f]{8})$",
                             source_text, re.MULTILINE))
    referenced = {}
    for path in sorted((ROOT / "src/functions").glob("[0-9a-f]" * 8 + ".cpp")):
        referenced.update(literal_targets(path.read_text()))
    additions = []
    for address, kind in sorted(referenced.items()):
        if kind not in ("GEX_RDATA", "GEX_DATA"):
            continue
        symbol = f"_GEX_{kind.removeprefix('GEX_')}_{address:08x}"
        if symbol in defined:
            continue
        base = 0x450000 if kind == "GEX_RDATA" else 0x451000
        additions += [f".globl {symbol}",
                      f".set {symbol}, _{kind}_{base:08x} + {address - base}"]
    expanded = WORK / "image_data.expanded.s"
    expanded.write_text(source_text + "\n".join(additions) + "\n")
    subprocess.run(["i686-w64-mingw32-as", "-o", str(raw), str(expanded)], check=True)
    objects = sorted(OBJECTS.glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                   "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].obj"))
    run = subprocess.run(["llvm-nm", "-g", "--format=posix", *(str(obj) for obj in objects)],
                         capture_output=True, text=True, check=True)
    by_object = {}
    current = None
    for line in run.stdout.splitlines():
        if line.endswith(":"):
            current = Path(line[:-1]).stem
        elif line and current:
            fields = line.split()
            if len(fields) >= 2:
                by_object.setdefault(current, []).append((fields[0], fields[1]))
    exports = {address: coff_export(address, symbols)
               for address, symbols in by_object.items()}
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
              "sourceAddressAliases": len(additions) // 2,
              "note": "Assembled from checked-in text source; no original EXE read."}
    (WORK / "image_data.report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"image data assembled: {len(changes)} function symbols rebound; "
          f"{len(missing_code)} code addresses still lack source")
    print(f"object: {rebound}")


if __name__ == "__main__":
    main()
