#!/usr/bin/env python3
"""Byte-compare every captured Gex frame and locate the first visual split."""

import argparse
from array import array
import hashlib
import json
from pathlib import Path
import re
import sys

from PIL import Image


ROOT = Path(__file__).resolve().parent.parent
WIDTH, HEIGHT = 320, 224


def words(raw: bytes) -> array:
    values = array("H")
    values.frombytes(raw)
    if sys.byteorder != "little":
        values.byteswap()
    return values


def rgb555(values: array) -> Image.Image:
    pixels = [((value & 31) * 255 // 31,
               ((value >> 5) & 31) * 255 // 31,
               ((value >> 10) & 31) * 255 // 31) for value in values]
    picture = Image.new("RGB", (WIDTH, HEIGHT))
    picture.putdata(pixels)
    return picture


def difference(a: array, b: array) -> tuple[int, list[int], dict]:
    changed = [i for i, (left, right) in enumerate(zip(a, b)) if left != right]
    if not changed:
        return 0, changed, {}
    xs = [index % WIDTH for index in changed]
    ys = [index // WIDTH for index in changed]
    tiles = {}
    for x, y in zip(xs, ys):
        key = f"{x // 16 * 16},{y // 16 * 16}"
        tiles[key] = tiles.get(key, 0) + 1
    return len(changed), changed, {
        "x0": min(xs), "y0": min(ys), "x1": max(xs), "y1": max(ys),
        "top16x16Tiles": [
            {"x": int(key.split(",")[0]), "y": int(key.split(",")[1]),
             "changedPixels": count}
            for key, count in sorted(tiles.items(), key=lambda item: -item[1])[:12]
        ],
    }


def focus(first: dict) -> dict:
    fields = first.get("stateDifferences", {})
    box = first.get("bounds", {})
    if any(name in fields for name in ("padHeldHex", "padJustHex")):
        candidates = ["0040f740 / 0040f520 recording playback",
                      "0041fc40 controller update", "0040f5e0 button edge tracking"]
        reason = "Recorded input diverges at or before this frame."
    elif first.get("changedScreenPixels") and not first.get("changedPixels"):
        candidates = ["00406c30 final presentation", "004066d0 GDI palette and surfaces"]
        reason = "Native render words match; displayed RGB pixels diverge during presentation."
    elif "player" in fields:
        candidates = ["00416320 player processing",
                      "00434b10 collision callback",
                      "00434260 path motion"]
        reason = "Player state diverges at or before this rendered frame."
    elif fields:
        candidates = ["00410280 camera logic", "00410c60 camera follow",
                      "0040a010 main level frame"]
        reason = "Camera state diverges at or before this rendered frame."
    elif box and box["y0"] < 32:
        candidates = ["0040a010 HUD/overlay draw call",
                      "0043faa0 text renderer", "00444590 object draw"]
        reason = "Native pixels differ near the HUD or overlay."
    else:
        candidates = ["0043fb40 tile drawing", "00444590 object drawing",
                      "0043db70 cel dispatch", "00406c30 final presentation"]
        reason = "Sampled state matches; inspect drawing commands and renderer inputs."
    return {"reason": reason, "candidateFunctions": candidates,
            "caveat": "Screen region and sampled state narrow investigation; they do not prove code ownership."}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--oracle", type=Path, required=True)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--strict", action="store_true",
                        help="exit nonzero if any pixel, screen, or sampled state differs")
    args = parser.parse_args()
    out = args.out.absolute()
    if not out.is_relative_to(ROOT / ".work"):
        parser.error("output must stay under this project's .work directory")
    oracle = json.loads((args.oracle / "manifest.json").read_text())
    source = json.loads((args.source / "manifest.json").read_text())
    for item in (oracle, source):
        if item["format"] != "gex-native-frames-v1" or item["width"] != WIDTH or item["height"] != HEIGHT:
            parser.error("unsupported capture manifest")
        if item["conflictingDuplicateTimers"]:
            parser.error("a capture had different pixels for the same timer; inspect its manifest")
    if oracle["demo"] != source["demo"] or oracle["level"] != source["level"]:
        parser.error("captured different attract recordings")
    if oracle.get("screenBox") != source.get("screenBox"):
        parser.error("captures used different screen crop boxes")
    screen_enabled = oracle.get("screenBox") is not None
    out.mkdir(parents=True, exist_ok=True)
    results = []
    first = None
    first_pixel = None
    first_state = None
    first_screen = None
    count = min(len(oracle["frames"]), len(source["frames"]))
    for index in range(count):
        left = oracle["frames"][index]
        right = source["frames"][index]
        a_raw = (args.oracle / left["file"]).read_bytes()
        b_raw = (args.source / right["file"]).read_bytes()
        if len(a_raw) != WIDTH * HEIGHT * 2 or len(b_raw) != len(a_raw):
            parser.error(f"bad frame length at index {index}")
        if (hashlib.sha256(a_raw).hexdigest() != left["sha256"] or
                hashlib.sha256(b_raw).hexdigest() != right["sha256"]):
            parser.error(f"frame hash differs from capture manifest at index {index}")
        a, b = words(a_raw), words(b_raw)
        changed, positions, box = difference(a, b)
        state = {}
        for name in ("padHeldHex", "padJustHex", "player", "cameraX", "cameraY"):
            if name not in left or name not in right:
                continue
            if left.get(name) != right.get(name):
                state[name] = {"oracle": left.get(name), "source": right.get(name)}
        row = {"index": index, "oracleTimer": left["timer"],
               "sourceTimer": right["timer"], "exact": changed == 0,
               "changedPixels": changed}
        if screen_enabled:
            if "screenFile" not in left or "screenFile" not in right:
                parser.error(f"missing screen capture at frame {index}")
            a_screen = (args.oracle / left["screenFile"]).read_bytes()
            b_screen = (args.source / right["screenFile"]).read_bytes()
            if len(a_screen) != WIDTH * HEIGHT * 3 or len(b_screen) != len(a_screen):
                parser.error(f"bad screen frame length at index {index}")
            if (hashlib.sha256(a_screen).hexdigest() != left["screenSHA256"] or
                    hashlib.sha256(b_screen).hexdigest() != right["screenSHA256"]):
                parser.error(f"screen hash differs from capture manifest at index {index}")
            screen_positions = [pixel for pixel in range(WIDTH * HEIGHT)
                                if a_screen[pixel * 3:pixel * 3 + 3]
                                != b_screen[pixel * 3:pixel * 3 + 3]]
            row["changedScreenPixels"] = len(screen_positions)
            row["screenExact"] = not screen_positions
            if screen_positions:
                xs = [pixel % WIDTH for pixel in screen_positions]
                ys = [pixel // WIDTH for pixel in screen_positions]
                row["screenBounds"] = {"x0": min(xs), "y0": min(ys),
                                       "x1": max(xs), "y1": max(ys)}
                if first_screen is None:
                    first_screen = row
                    Image.frombytes("RGB", (WIDTH, HEIGHT), a_screen).save(out / "first-screen-oracle.png")
                    Image.frombytes("RGB", (WIDTH, HEIGHT), b_screen).save(out / "first-screen-source.png")
                    screen_mask = Image.new("RGB", (WIDTH, HEIGHT))
                    screen_set = set(screen_positions)
                    screen_mask.putdata([(255, 0, 255) if pixel in screen_set else (0, 0, 0)
                                         for pixel in range(WIDTH * HEIGHT)])
                    screen_mask.save(out / "first-screen-difference.png")
        if box:
            row["bounds"] = box
        if state:
            row["stateDifferences"] = state
        results.append(row)
        if first is None and (changed or state or row.get("changedScreenPixels")):
            first = row
        if first_state is None and state:
            first_state = row
        if first_pixel is None and changed:
            first_pixel = row
            rgb555(a).save(out / "first-oracle.png")
            rgb555(b).save(out / "first-source.png")
            mask = Image.new("RGB", (WIDTH, HEIGHT), (0, 0, 0))
            changed_positions = set(positions)
            data = [(255, 0, 255) if pixel in changed_positions else (0, 0, 0)
                    for pixel in range(WIDTH * HEIGHT)]
            mask.putdata(data)
            mask.save(out / "first-difference.png")
    report = {"format": "gex-frame-comparison-v1", "demo": oracle["demo"],
              "comparedFrames": count, "oracleFrames": len(oracle["frames"]),
              "sourceFrames": len(source["frames"]),
              "allFramesPixelExact": all(row["exact"] for row in results)
                                      and count == len(oracle["frames"]) == len(source["frames"]),
              "allFramesScreenExact": (all(row["screenExact"] for row in results)
                                        and count == len(oracle["frames"]) == len(source["frames"]))
                                       if screen_enabled else None,
              "firstMismatch": first, "firstPixelMismatch": first_pixel,
              "firstScreenMismatch": first_screen,
              "firstStateMismatch": first_state,
              "focus": focus(first) if first else None,
              "frames": results}
    (out / "comparison.json").write_text(json.dumps(report, indent=2) + "\n")
    triage = [f"# Attract demo {oracle['demo']} frame comparison", "",
              f"Compared {count} frame pairs.",
              f"Original capture SHA256: `{oracle.get('executableSHA256') or 'not recorded'}`.",
              f"Source capture SHA256: `{source.get('executableSHA256') or 'not recorded'}`.", ""]
    if first:
        triage += [f"First divergence: frame {first['index']} "
                   f"(original timer {first['oracleTimer']}, "
                   f"source timer {first['sourceTimer']}).",
                   f"Previous compared frame: {first['index'] - 1 if first['index'] else 'none'}.",
                   f"Native changed pixels: {first['changedPixels']}.",
                   f"Displayed RGB changed pixels: {first.get('changedScreenPixels', 'not captured')}.",
                   f"Native bounds: `{first.get('bounds')}`.",
                   f"Screen bounds: `{first.get('screenBounds')}`.",
                   f"Sampled state differences: `{first.get('stateDifferences', {})}`.", "",
                   "Candidate source files for inspection:", ""]
        for candidate in report["focus"]["candidateFunctions"]:
            for address in re.findall(r"\b[0-9a-f]{8}\b", candidate):
                triage.append(f"- `src/functions/{address}.cpp` — {candidate}")
        triage += ["", report["focus"]["caveat"],
                   "Inspect the pinned original instructions read only; "
                   "compare the candidate source and frame state before editing."]
    else:
        triage.append("All compared native and captured screen frames match byte for byte.")
    (out / "triage.md").write_text("\n".join(triage) + "\n")
    if first:
        print(f"First divergence: frame {first['index']}; "
              f"first pixel mismatch: {first_pixel['index'] if first_pixel else 'none'}; "
              f"first screen mismatch: {first_screen['index'] if first_screen else 'none'}; "
              f"first sampled state mismatch: {first_state['index'] if first_state else 'none'}")
    else:
        print(f"All {count} compared frames are byte-identical")
    if len(oracle["frames"]) != len(source["frames"]):
        print("Capture lengths differ; comparison is incomplete")
    print(f"Report: {out / 'comparison.json'}")
    if args.strict and (first or len(oracle["frames"]) != len(source["frames"])):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
