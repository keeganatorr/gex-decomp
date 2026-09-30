#!/usr/bin/env python3
"""One-time extraction of initialized PE data into textual COFF assembly.

This development tool reads the pinned original to recover initial data and
PE base relocations. Ordinary replacement builds assemble its checked-in text
output and never read the original. Generated source is a faithful data bridge,
not recovered historical declarations or types.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from address_literals import literal_targets


ROOT = Path(__file__).resolve().parent.parent
ORIGINAL = ROOT / ".work/original.exe"
CENSUS = ROOT / ".work/replacement-rebound/link-census.json"
CANONICAL = re.compile(r"_GEX_DATA_([0-9a-f]{8})$")


def read_pe(data: bytes) -> tuple[int, dict]:
    header = struct.unpack_from("<I", data, 0x3C)[0]
    if data[header:header + 4] != b"PE\0\0":
        raise ValueError("not a PE image")
    count = struct.unpack_from("<H", data, header + 6)[0]
    optional_size = struct.unpack_from("<H", data, header + 20)[0]
    optional = header + 24
    base = struct.unpack_from("<I", data, optional + 28)[0]
    sections = {}
    for index in range(count):
        at = optional + optional_size + index * 40
        name = data[at:at + 8].rstrip(b"\0").decode("ascii")
        virtual_size, rva, raw_size, raw_at = struct.unpack_from("<IIII", data, at + 8)
        sections[name] = {
            "start": base + rva, "end": base + rva + virtual_size,
            "rawSize": raw_size, "raw": data[raw_at:raw_at + raw_size],
        }
    return base, sections


def relocations(data: bytes, base: int, sections: dict) -> dict[int, int]:
    content = sections[".reloc"]["raw"]
    at = 0
    result = {}
    while at + 8 <= len(content):
        page, size = struct.unpack_from("<II", content, at)
        if page == 0 or size < 8 or at + size > len(content):
            break
        for index in range((size - 8) // 2):
            item = struct.unpack_from("<H", content, at + 8 + index * 2)[0]
            kind = item >> 12
            if kind == 0:
                continue
            address = base + page + (item & 0xFFF)
            if not any(s["start"] <= address < s["start"] + s["rawSize"]
                       for s in (sections[".data"], sections[".rdata"])):
                continue
            if kind != 3:
                raise ValueError(f"unsupported initialized-data relocation {kind} at {address:08x}")
            section = next(s for s in (sections[".data"], sections[".rdata"])
                           if s["start"] <= address < s["start"] + s["rawSize"])
            offset = address - section["start"]
            if offset + 4 > len(section["raw"]):
                raise ValueError(f"relocation past raw data at {address:08x}")
            result[address] = struct.unpack_from("<I", section["raw"], offset)[0]
        at += size
    return result


def emit_bytes(lines: list[str], content: bytes) -> None:
    if not content:
        return
    if not any(content):
        lines.append(f".zero {len(content)}")
        return
    for at in range(0, len(content), 16):
        chunk = content[at:at + 16]
        lines.append(".byte " + ",".join(f"0x{byte:02x}" for byte in chunk))


def emit_raw_section(lines: list[str], section: dict, labels: set[int],
                     relocs: dict[int, str], prefix: str) -> None:
    start = section["start"]
    content = section["raw"]
    cursor = 0
    points = sorted({address - start for address in labels | relocs.keys()})
    for point in points:
        if point < cursor:
            raise ValueError(f"label lies inside relocation at {start + point:08x}")
        if point < 0 or point >= len(content):
            raise ValueError(f"label outside file-backed section at {start + point:08x}")
        emit_bytes(lines, content[cursor:point])
        address = start + point
        if address in labels:
            name = f"_{prefix}_{address:08x}"
            lines.extend((f".globl {name}", f"{name}:"))
        if address in relocs:
            lines.append(f".long {relocs[address]}")
            cursor = point + 4
        else:
            cursor = point
    emit_bytes(lines, content[cursor:])


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path,
                        default=ROOT / ".work/replacement-data/image_data.s")
    args = parser.parse_args()
    if not CENSUS.is_file():
        raise SystemExit("run the source-built COFF census first")
    project = json.loads((ROOT / "project.json").read_text())
    binary = ORIGINAL.read_bytes()
    digest = hashlib.sha256(binary).hexdigest()
    if digest != project["sha256"]:
        raise SystemExit("pinned original SHA256 mismatch")
    base, sections = read_pe(binary)
    data = sections[".data"]
    rdata = sections[".rdata"]
    bss_start = data["start"] + data["rawSize"]
    reloc = relocations(binary, base, sections)
    needed = set()
    report = json.loads(CENSUS.read_text())
    for symbol in report["dataRangeReferencesWithoutDefinition"]:
        match = CANONICAL.fullmatch(symbol)
        if match:
            needed.add(int(match.group(1), 16))
    aliases = json.loads((ROOT / "src/replacement/symbol_aliases.json").read_text())["aliases"]
    needed.update(int(item["address"], 16) for item in aliases.values())
    for source in (ROOT / "src/functions").glob("*.cpp"):
        needed.update(literal_targets(source.read_text()))
    data_labels = {address for address in needed if data["start"] <= address < data["end"]}
    rdata_labels = set()
    destinations = {}
    for address, value in reloc.items():
        if sections[".text"]["start"] <= value < sections[".text"]["end"]:
            destination = f"_GEX_FN_{value:08x}"
        elif data["start"] <= value < data["end"]:
            data_labels.add(value)
            destination = f"_GEX_DATA_{value:08x}"
        elif rdata["start"] <= value < rdata["end"]:
            rdata_labels.add(value)
            destination = f"_GEX_RDATA_{value:08x}"
        else:
            raise ValueError(f"relocation {address:08x} points outside reconstructed sections: {value:08x}")
        destinations[address] = destination
    lines = [
        "# Generated data source for the pinned Gex PE; no executable is read at build time.",
        f"# Source PE SHA256: {digest}",
        f"# .rdata {rdata['start']:08x} + {rdata['rawSize']} raw bytes",
        f"# .data {data['start']:08x} + {data['rawSize']} raw bytes, zero tail to {data['end']:08x}",
        f"# {len(destinations)} pointer relocations expressed as symbolic references.",
        ".section .rdata,\"dr\"", ".balign 16",
    ]
    emit_raw_section(lines, rdata, rdata_labels,
                     {a: target for a, target in destinations.items()
                      if rdata["start"] <= a < rdata["start"] + rdata["rawSize"]},
                     "GEX_RDATA")
    lines += [".section .data,\"dw\"", ".balign 16"]
    emit_raw_section(lines, data,
                     {a for a in data_labels if a < bss_start},
                     {a: target for a, target in destinations.items()
                      if data["start"] <= a < bss_start}, "GEX_DATA")
    # Arrays cross the PE raw/zero-filled boundary; preserve their addresses
    # in one section so other objects cannot be inserted between the halves.
    lines += [
        '# Keep the original data span contiguous: the block-request array crosses',
        '# the original file-backed/zero-filled boundary at 00462800.',
        '.section .data,"dw"', '.balign 16',
    ]
    cursor = bss_start
    for address in sorted(a for a in data_labels if a >= bss_start):
        if address > cursor:
            lines.append(f".space {address - cursor}")
        name = f"_GEX_DATA_{address:08x}"
        lines.extend((f".globl {name}", f"{name}:"))
        cursor = address
    lines.append(f".space {data['end'] - cursor}")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines) + "\n")
    print(f"source: {args.output} ({args.output.stat().st_size} bytes)")
    print(f"relocations {len(destinations)}, data labels {len(data_labels)}, rdata labels {len(rdata_labels)}")


if __name__ == "__main__":
    main()
