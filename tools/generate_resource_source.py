#!/usr/bin/env python3
"""One-time conversion of the pinned PE resource tree to textual COFF source.

The ordinary replacement build assembles the generated .s file. Resource data
entry RVAs are emitted with .rva, which creates IMAGE_REL_I386_DIR32NB fixups
so their payloads remain valid when the new linker moves the .rsrc section.
"""

import argparse
import hashlib
import json
from pathlib import Path
import struct

from generate_image_data_source import emit_bytes, read_pe


ROOT = Path(__file__).resolve().parent.parent


def resource_entries(content: bytes, section_rva: int) -> dict[int, int]:
    leaves = {}
    seen = set()

    def directory(offset: int, depth: int) -> None:
        if depth > 16 or offset in seen:
            raise ValueError(f"resource directory cycle/depth at {offset:x}")
        seen.add(offset)
        if offset + 16 > len(content):
            raise ValueError(f"resource directory outside section at {offset:x}")
        named, ids = struct.unpack_from("<HH", content, offset + 12)
        end = offset + 16 + (named + ids) * 8
        if end > len(content):
            raise ValueError(f"resource directory entries outside section at {offset:x}")
        for at in range(offset + 16, end, 8):
            destination = struct.unpack_from("<I", content, at + 4)[0]
            child = destination & 0x7fffffff
            if destination & 0x80000000:
                directory(child, depth + 1)
                continue
            if child + 16 > len(content):
                raise ValueError(f"resource data entry outside section at {child:x}")
            rva, size = struct.unpack_from("<II", content, child)
            payload = rva - section_rva
            if payload < 0 or payload + size > len(content):
                raise ValueError(f"resource payload outside section at {child:x}")
            if child in leaves and leaves[child] != payload:
                raise ValueError(f"conflicting resource data entry at {child:x}")
            leaves[child] = payload

    directory(0, 0)
    return leaves


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path,
                        default=ROOT / ".work/replacement-data/image_resources.s")
    args = parser.parse_args()
    project = json.loads((ROOT / "project.json").read_text())
    binary = (ROOT / ".work/original.exe").read_bytes()
    digest = hashlib.sha256(binary).hexdigest()
    if digest != project["sha256"]:
        raise SystemExit("pinned original SHA256 mismatch")
    base, sections = read_pe(binary)
    section = sections[".rsrc"]
    content = section["raw"]
    section_rva = section["start"] - base
    entries = resource_entries(content, section_rva)
    labels = set(entries.values())
    points = sorted(set(entries) | labels)
    lines = [
        "# Textual resource source extracted once from the pinned Gex PE.",
        f"# Source PE SHA256: {digest}",
        f"# .rsrc {section['start']:08x} + {len(content)} raw bytes; {len(entries)} data-entry RVAs.",
        '.section .rsrc,"dr"', '.balign 16',
    ]
    cursor = 0
    for point in points:
        if point < cursor:
            raise ValueError(f"resource label inside RVA field at {point:x}")
        emit_bytes(lines, content[cursor:point])
        if point in labels:
            lines.append(f"GEX_RSRC_PAYLOAD_{point:08x}:")
        if point in entries:
            lines.append(f".rva GEX_RSRC_PAYLOAD_{entries[point]:08x}")
            cursor = point + 4
        else:
            cursor = point
    emit_bytes(lines, content[cursor:])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines) + "\n")
    print(f"resource source: {args.output} ({args.output.stat().st_size} bytes)")
    print(f"raw bytes {len(content)}; resource data entries {len(entries)}")


if __name__ == "__main__":
    main()
