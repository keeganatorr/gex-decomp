#!/usr/bin/env python3
"""Census global definitions and unresolved references in source-built COFF.

Requires tools/compile_source_set.py to have completed. Reads only the new
objects and project.json; no original EXE, backend DB or proof artifacts.
"""

from collections import defaultdict
import argparse
import json
from pathlib import Path
import re
import subprocess


ROOT = Path(__file__).resolve().parent.parent
DEFAULT_WORK = ROOT / ".work/replacement-objects"
ADDRESS = re.compile(r"(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--objects-dir", type=Path, default=DEFAULT_WORK)
    args = parser.parse_args()
    work = args.objects_dir.resolve()
    source_files = sorted((ROOT / "src/functions").glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                                        "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].cpp"))
    objects = [work / f"{source.stem}.obj" for source in source_files]
    missing = [str(obj) for obj in objects if not obj.is_file()]
    if missing:
        raise SystemExit(f"compile the source set first; {len(missing)} objects missing")
    run = subprocess.run(["llvm-nm", "-g", "--format=posix", *(str(obj) for obj in objects)],
                         capture_output=True, text=True, check=True)
    defined = defaultdict(list)
    undefined = defaultdict(list)
    object_name = None
    for line in run.stdout.splitlines():
        if not line:
            continue
        if line.endswith(":"):
            object_name = Path(line[:-1]).stem
            continue
        fields = line.split()
        if len(fields) < 2 or object_name is None:
            continue
        symbol, kind = fields[:2]
        (undefined if kind == "U" else defined)[symbol].append(object_name)
    unresolved = {symbol: owners for symbol, owners in undefined.items()
                  if symbol not in defined}
    duplicates = {symbol: owners for symbol, owners in defined.items()
                  if len(set(owners)) > 1}
    source_addresses = {source.stem for source in source_files}
    missing_export = defaultdict(dict)
    code_without_source = {}
    data_symbols = {}
    other = {}
    for symbol, owners in unresolved.items():
        matches = {match.lower() for match in ADDRESS.findall(symbol)}
        available = matches & source_addresses
        if len(available) == 1:
            address = next(iter(available))
            missing_export[address][symbol] = owners
        elif len(matches) == 1:
            address = int(next(iter(matches)), 16)
            if 0x400000 <= address < 0x450000:
                code_without_source[symbol] = owners
            elif address >= 0x450000:
                data_symbols[symbol] = owners
            else:
                other[symbol] = owners
        else:
            other[symbol] = owners
    report = {
        "format": "gex-coff-link-census-v1",
        "objects": len(objects),
        "definedGlobalSymbols": len(defined),
        "undefinedGlobalSymbols": len(undefined),
        "unresolvedWithinObjects": len(unresolved),
        "duplicateDefinitions": duplicates,
        "referencesToAvailableSourceWithDifferentExport": missing_export,
        "codeRangeReferencesWithoutSource": code_without_source,
        "dataRangeReferencesWithoutDefinition": data_symbols,
        "otherUnresolved": other,
        "limits": [
            "Library archives are not included; CRT and Win32 import references remain unresolved here.",
            "Address classification is lexical and does not prove a function boundary.",
            "The COFF object set has not yet been linked as a game image.",
        ],
    }
    target = work / "link-census.json"
    target.write_text(json.dumps(report, indent=2) + "\n")
    print(f"{len(objects)} source-built objects; {len(defined)} global definitions")
    print(f"{len(unresolved)} unresolved symbols within the object set")
    print(f"{len(duplicates)} duplicate definitions")
    print(f"{len(missing_export)} source addresses need export aliases")
    print(f"{len(code_without_source)} code-range symbols have no source object")
    print(f"{len(data_symbols)} data-range symbols have no definition in this object set")
    print(f"{len(other)} other unresolved symbols (includes CRT/imports)")
    print("most called source addresses with missing exports:")
    for address, names in sorted(missing_export.items(),
                                 key=lambda item: -sum(map(len, item[1].values())))[:12]:
        print(f"  {address}: {sum(map(len, names.values()))} uses, {len(names)} symbols")
    print(f"report: {target}")


if __name__ == "__main__":
    main()
