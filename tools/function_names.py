"""C identifiers assigned to function addresses by name-ghidra-functions."""

import csv
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent


def read_names() -> dict[str, str]:
    with (ROOT / "src/replacement/function_names.tsv").open(newline="") as source:
        return {row["address"]: row["emitted_name"]
                for row in csv.DictReader(source, delimiter="\t")}


NAMES = read_names()


def coff_export(address: str, symbols: list[tuple[str, str]]) -> str:
    name = NAMES[address]
    candidates = [symbol for symbol, kind in symbols if kind.upper() == "T" and (
        symbol == "_" + name or symbol.startswith("_" + name + "@") or
        symbol.startswith("?" + name + "@@"))]
    if len(candidates) != 1:
        raise ValueError(f"{address}: expected one COFF export for {name}, got {candidates}")
    return candidates[0]
