#!/usr/bin/env python3
"""Read-only source/link inventory; never opens GEX.exe or the backend DB.

This is a lexical survey of the current isolated translation units. It is not
a linker result: an address in an identifier is only a candidate relationship.
"""

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
from function_names import NAMES


ROOT = Path(__file__).resolve().parent.parent
IDENTIFIER = re.compile(r"\b[A-Za-z_]\w*\b")
COMMENT_OR_STRING = re.compile(
    r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\''
)


def code_only(source: str) -> str:
    return COMMENT_OR_STRING.sub(lambda match: " " * len(match.group()), source)


def inventory() -> dict:
    project = json.loads((ROOT / "project.json").read_text())
    bindings = project["symbolBindings"]
    # project.json stores COFF spellings (_cdecl_name, _stdcall_name@N),
    # while declarations in the source use their undecorated identifiers.
    source_names = defaultdict(set)
    for coff_name in bindings:
        if coff_name.startswith("_?"):
            continue  # C++ decorated names cannot be mapped lexically.
        source_names[coff_name.lstrip("_").split("@", 1)[0]].add(coff_name)
    sources = {path.stem: path for path in
               (ROOT / "src/functions").glob("[0-9a-f][0-9a-f][0-9a-f][0-9a-f]"
                                                   "[0-9a-f][0-9a-f][0-9a-f][0-9a-f].cpp")}
    referenced = Counter()
    no_target = []
    source_function_refs = defaultdict(set)
    for address, path in sorted(sources.items()):
        tokens = Counter(IDENTIFIER.findall(code_only(path.read_text())))
        identifiers = set(tokens)
        if NAMES[address] not in identifiers:
            no_target.append(address)
        for identifier in identifiers & source_names.keys():
            # A lone occurrence is normally an unused extern declaration.
            # This still remains a heuristic, not a COFF undefined-symbol list.
            if tokens[identifier] < 2:
                continue
            for symbol in source_names[identifier]:
                referenced[symbol] += 1
                if bindings[symbol].lower() in sources:
                    source_function_refs[bindings[symbol].lower()].add(identifier)
    code_range_without_source = Counter()
    data_range = Counter()
    for symbol, count in referenced.items():
        address = int(bindings[symbol], 16)
        if 0x400000 <= address < 0x450000 and f"{address:08x}" not in sources:
            code_range_without_source[symbol] = count
        elif address >= 0x450000:
            data_range[symbol] = count
    return {
        "sourceFiles": len(sources),
        "sourcesWithoutMappedName": no_target,
        "boundSymbolsReferenced": len(referenced),
        "boundSymbolsPointingToSource": sum(
            count for symbol, count in referenced.items()
            if bindings[symbol].lower() in sources),
        "candidateCodeRangeReferencesWithoutSource":
            dict(code_range_without_source.most_common()),
        "referencedDataRangeSymbols": dict(data_range.most_common()),
        "referencedAliasesBySource": {
            address: sorted(names) for address, names in sorted(source_function_refs.items())
        },
        "limits": [
            "Only identifiers with explicit project symbol bindings are classified.",
            "Code-range addresses are lexical candidates, not proven function boundaries.",
            "This survey does not compile or link the sources.",
        ],
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", action="store_true", help="print full JSON inventory")
    args = parser.parse_args()
    result = inventory()
    if args.json:
        print(json.dumps(result, indent=2))
        return
    print(f"{result['sourceFiles']} isolated function sources")
    print(f"{len(result['sourcesWithoutMappedName'])} without mapped function name")
    print(f"{result['boundSymbolsReferenced']} distinct bound symbols referenced")
    print(f"{result['boundSymbolsPointingToSource']} bound symbol uses point to a source file")
    print(f"{len(result['candidateCodeRangeReferencesWithoutSource'])} distinct bound code-range references lack a source file")
    print(f"{len(result['referencedDataRangeSymbols'])} distinct bound data-range symbols used lexically")
    print("Most referenced code-range symbols without a source file:")
    for name, count in list(result["candidateCodeRangeReferencesWithoutSource"].items())[:15]:
        print(f"  {count:4} {name}")
    print("Lexical inventory only; use a full link to establish actual missing symbols.")


if __name__ == "__main__":
    main()
