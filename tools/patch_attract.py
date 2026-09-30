#!/usr/bin/env python3
"""Make a copy of either Gex PE that starts a selected attract recording.

Only the title idle comparison and its initial three-entry recording cursor are
changed. The original executable is always read as input, never written.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

import pefile


ROOT = Path(__file__).resolve().parent.parent
ORIGINAL_SHA256 = "e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86"
ORIGINAL_PATH = Path.home() / ".wine/drive_c/GOG Games/Gex/GEX.exe"
DEMO_LEVELS = (0, 9, 36)
DEMO_IDL_PARTS = (4, 5, 6)

# The absolute operands vary between the original and source-only link. Match
# the instruction structure, then check that repeated operands agree.
TITLE_IDLE = re.compile(
    rb"\xa1(?P<timer>.{4})\x40\xa3(?P=timer)"
    rb"\x3d\x84\x03\x00\x00\x0f\x8e.{4}"
    rb"\xa1(?P<cursor>.{4})\x40\xa3(?P=cursor)\x83\xf8\x03",
    re.DOTALL,
)


def patch(data: bytes, demo: int) -> tuple[bytes, dict]:
    pe = pefile.PE(data=data, fast_load=True)
    if pe.FILE_HEADER.Machine != 0x14c or pe.OPTIONAL_HEADER.Magic != 0x10b:
        raise ValueError("expected a 32-bit x86 PE")
    sections = {sec.Name.rstrip(b"\0"): sec for sec in pe.sections}
    text = sections[b".text"]
    image = data[text.PointerToRawData:text.PointerToRawData + text.SizeOfRawData]
    matches = list(TITLE_IDLE.finditer(image))
    if len(matches) != 1:
        raise ValueError(f"expected one title idle instruction sequence, found {len(matches)}")
    match = matches[0]
    timer_va = struct.unpack("<I", match.group("timer"))[0]
    cursor_va = struct.unpack("<I", match.group("cursor"))[0]
    image_base = pe.OPTIONAL_HEADER.ImageBase
    if timer_va < image_base or cursor_va < image_base:
        raise ValueError("title operands are not image addresses")
    cursor_offset = pe.get_offset_from_rva(cursor_va - image_base)
    if data[cursor_offset:cursor_offset + 4] != b"\x03\x00\x00\x00":
        raise ValueError("expected untouched initial recording cursor 3")
    cmp_offset = text.PointerToRawData + match.start() + 11
    if data[cmp_offset:cmp_offset + 5] != b"\x3d\x84\x03\x00\x00":
        raise ValueError("title idle compare was not at the expected position")
    patched = bytearray(data)
    patched[cmp_offset + 1:cmp_offset + 5] = b"\0" * 4
    patched[cursor_offset:cursor_offset + 4] = struct.pack("<I", (demo + 2) % 3)
    changes = [i for i, (a, b) in enumerate(zip(data, patched)) if a != b]
    expected = set(range(cmp_offset + 1, cmp_offset + 5)) | set(range(cursor_offset, cursor_offset + 4))
    if not changes or not set(changes).issubset(expected):
        raise ValueError("patch changed bytes outside its two intended fields")
    return bytes(patched), {
        "format": "gex-attract-patch-v1", "demo": demo,
        "level": DEMO_LEVELS[demo], "idlPart": DEMO_IDL_PARTS[demo],
        "titleCompareVA": hex(image_base + text.VirtualAddress + match.start() + 11),
        "titleCompareFileOffset": cmp_offset,
        "cursorVA": hex(cursor_va), "cursorFileOffset": cursor_offset,
        "changedFileOffsets": changes,
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, default=ORIGINAL_PATH)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--demo", type=int, choices=range(3), required=True,
                        help="0: level 0, 1: level 9, 2: level 36")
    args = parser.parse_args()
    source = args.input.resolve(strict=True)
    target = args.output.absolute()
    if source == target or target.resolve() == source:
        parser.error("output must be a separate copy")
    work = (ROOT / ".work").resolve()
    if not target.parent.resolve().is_relative_to(work):
        parser.error("output must stay under this project's .work directory")
    original = source.read_bytes()
    source_hash = hashlib.sha256(original).hexdigest()
    if source == ORIGINAL_PATH.resolve() and source_hash != ORIGINAL_SHA256:
        parser.error("installed original hash differs from the pinned GEX.exe")
    result, manifest = patch(original, args.demo)
    manifest.update({"inputSHA256": source_hash,
                     "outputSHA256": hashlib.sha256(result).hexdigest(),
                     "originalPinned": source_hash == ORIGINAL_SHA256})
    target.parent.mkdir(parents=True, exist_ok=True)
    temp = target.with_name(target.name + ".tmp")
    temp.write_bytes(result)
    temp.chmod(0o755)
    temp.replace(target)
    receipt = target.with_suffix(target.suffix + ".json")
    receipt_temp = receipt.with_name(receipt.name + ".tmp")
    receipt_temp.write_text(json.dumps(manifest, indent=2) + "\n")
    receipt_temp.replace(receipt)
    print(f"Attract {args.demo}: level {manifest['level']}, IDL part {manifest['idlPart']}")
    print(f"Patched copy: {target}")
    print(f"Changed {len(manifest['changedFileOffsets'])} bytes; receipt: {target}.json")


if __name__ == "__main__":
    main()
