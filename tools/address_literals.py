"""Turn original-VA literals in function source into relocatable references.

This is only for the replacement build's scratch copies. Baseline src/functions
files remain the byte-matching sources. Section ranges are pinned from the
original PE; ordinary builds use these recorded constants, not the EXE.
"""

import re


TOKEN = re.compile(
    r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\''
    r'|(?<![\w])0[xX]([0-9a-fA-F]+)([uUlL]*)(?![\w])'
)
SECTIONS = (
    (0x401000, 0x44F5F0, "GEX_FN"),
    (0x450000, 0x450447, "GEX_RDATA"),
    (0x451000, 0x4A44E0, "GEX_DATA"),
)


def literal_targets(source: str) -> dict[int, str]:
    found = {}
    for match in TOKEN.finditer(source):
        if match.group(1) is None:
            continue
        address = int(match.group(1), 16)
        for start, end, prefix in SECTIONS:
            if start <= address < end:
                found[address] = prefix
                break
    return found


def relocate(source: str, language: str) -> tuple[str, dict[int, str]]:
    targets = literal_targets(source)
    if not targets:
        return source, targets

    def replacement(match: re.Match) -> str:
        if match.group(1) is None:
            return match.group()
        address = int(match.group(1), 16)
        prefix = targets.get(address)
        if prefix is None:
            return match.group()
        return f"((unsigned long)&{prefix}_{address:08x})"

    body = TOKEN.sub(replacement, source)
    linkage = 'extern "C" ' if language == "cpp" else "extern "
    declarations = []
    for address, prefix in sorted(targets.items()):
        name = f"{prefix}_{address:08x}"
        if prefix == "GEX_FN":
            declarations.append(f"{linkage}void {name}(void);")
        else:
            declarations.append(f"{linkage}unsigned char {name};")
    return "// Replacement-build relocations for original VA literals.\n" + \
           "\n".join(declarations) + "\n" + body, targets
