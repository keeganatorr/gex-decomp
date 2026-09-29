#!/usr/bin/env python3
"""Normalize source-built COFF references by known function/data addresses.

Uses explicit project symbol bindings, or an unambiguous embedded entry address,
to redirect undefined function symbols to source-built functions and collapse
same-address data aliases. No machine code, original executable bytes or
backend proof artifacts are used.
The transformed objects remain ignored under .work/replacement-rebound/.
"""

from collections import defaultdict
import json
from pathlib import Path
import re
import shutil
import subprocess
from function_names import coff_export


ROOT = Path(__file__).resolve().parent.parent
INPUT = ROOT / ".work/replacement-objects"
OUTPUT = ROOT / ".work/replacement-rebound"
ADDRESS = re.compile(r"(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])")
# The pinned PE has six-byte import thunks at these addresses. Their IAT slots
# and stdcall spellings are documented in docs/iat-binding-review.md. The
# replacement link uses the import library's forwarding symbol directly.
IMPORT_THUNKS = {
    "00409870": "_DirectSoundCreate@12",
    "00409876": "_DirectDrawCreate@12",
}
IMAGE_BASE_NAMES = {"_DAT_00400000", "_IMAGE_DOS_HEADER_00400000"}
# These source declarations include an extra leading underscore. Resolve them
# to the matching CRT exports; the breakpoint uses the Win32 DebugBreak API.
LIBRARY_ALIASES = {
    "__printf": "_printf",
    "___fcloseall": "__fcloseall",
    "___setmbcp": "__setmbcp",
    "___debugbreak": "_DebugBreak@0",
    "_doexit": "__doexit",
    "___doexit": "__doexit",
}


def symbols(objects: list[Path]) -> tuple[dict[str, list[tuple[str, str]]], set[str]]:
    run = subprocess.run(["llvm-nm", "-g", "--format=posix", *(str(obj) for obj in objects)],
                         capture_output=True, text=True, check=True)
    by_object = defaultdict(list)
    definitions = set()
    current = None
    for line in run.stdout.splitlines():
        if line.endswith(":"):
            current = Path(line[:-1]).stem
        elif line and current:
            fields = line.split()
            if len(fields) >= 2:
                by_object[current].append((fields[0], fields[1]))
                if fields[1] != "U":
                    definitions.add(fields[0])
    return by_object, definitions


def main() -> None:
    project = json.loads((ROOT / "project.json").read_text())
    bindings = {name: address.lower() for name, address in project["symbolBindings"].items()}
    aliases = json.loads((ROOT / "src/replacement/symbol_aliases.json").read_text())["aliases"]
    bindings.update({name: item["address"].lower() for name, item in aliases.items()})
    import_exports = {}
    for name, address in project["symbolBindings"].items():
        if name.startswith("__imp_"):
            import_exports.setdefault(address.lower(), name)
    source_files = sorted((ROOT / "src/functions").glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                                        "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].cpp"))
    addresses = {source.stem for source in source_files}
    objects = [INPUT / f"{source.stem}.obj" for source in source_files]
    if any(not obj.is_file() for obj in objects):
        raise SystemExit("run tools/compile_source_set.py successfully first")
    by_object, definitions = symbols(objects)
    exports = {}
    for address in addresses:
        exports[address] = coff_export(address, by_object[address])
    data_exports = {}
    for name in sorted(definitions):
        destination = bindings.get(name)
        if destination is None:
            embedded = {value.lower() for value in ADDRESS.findall(name)}
            if len(embedded) == 1:
                destination = next(iter(embedded))
        if destination is not None and int(destination, 16) >= 0x450000:
            data_exports.setdefault(destination, name)
    OUTPUT.mkdir(parents=True, exist_ok=True)
    changed_objects = 0
    changed_function_symbols = 0
    changed_data_symbols = 0
    skipped = {}
    for source in source_files:
        address = source.stem
        changes = {}
        for name, kind in by_object[address]:
            if kind != "U" or name in definitions:
                continue
            destination = bindings.get(name)
            if destination is None:
                embedded = {value.lower() for value in ADDRESS.findall(name)}
                if len(embedded) == 1:
                    destination = next(iter(embedded))
            if destination in exports:
                target = exports[destination]
                changed_function_symbols += name != target
            elif destination in IMPORT_THUNKS:
                target = IMPORT_THUNKS[destination]
                changed_function_symbols += name != target
            elif name in IMAGE_BASE_NAMES:
                # LLD defines this symbol at the replacement PE's actual load
                # base, including when the loader relocates the image.
                target = "___ImageBase"
                changed_data_symbols += name != target
            elif name in LIBRARY_ALIASES:
                target = LIBRARY_ALIASES[name]
                changed_function_symbols += name != target
            elif destination in import_exports:
                target = import_exports[destination]
                changed_data_symbols += name != target
            elif destination is not None and int(destination, 16) >= 0x450000 and not name.startswith("__imp_"):
                target = data_exports.get(destination, "_GEX_DATA_" + destination)
                changed_data_symbols += name != target
            else:
                continue
            if name != target:
                changes[name] = target
        target_obj = OUTPUT / f"{address}.obj"
        if changes:
            mapping = OUTPUT / f"{address}.symbols"
            mapping.write_text("".join(f"{old} {new}\n" for old, new in sorted(changes.items())))
            run = subprocess.run(["llvm-objcopy", "--redefine-syms=" + str(mapping),
                                  str(INPUT / f"{address}.obj"), str(target_obj)],
                                 capture_output=True, text=True)
            if run.returncode:
                skipped[address] = run.stderr.strip()
                target_obj.unlink(missing_ok=True)
                continue
            changed_objects += 1
        else:
            shutil.copyfile(INPUT / f"{address}.obj", target_obj)
    report = {"format": "gex-source-rebind-v1", "objects": len(objects),
              "changedObjects": changed_objects,
              "changedFunctionSymbols": changed_function_symbols,
              "changedDataSymbols": changed_data_symbols,
              "failedObjects": skipped,
              "note": "COFF symbol names only; original EXE and proof artifacts unused."}
    (OUTPUT / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"{changed_function_symbols} function and {changed_data_symbols} data references "
          f"normalized in {changed_objects} objects")
    print(f"{len(skipped)} objects could not be rewritten")
    if skipped:
        for address, error in list(skipped.items())[:10]:
            print(f"  {address}: {error}")
        raise SystemExit(2)


if __name__ == "__main__":
    main()
