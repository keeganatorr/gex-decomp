"""Loaded by GDB inside Wine; capture the native 320x224 Gex render buffer."""

import gdb
import hashlib
import json
import os
from pathlib import Path
import struct


config = json.loads(Path(os.environ["GEX_CAPTURE_CONFIG"]).read_text())
out = Path(config["out"])
out.mkdir(parents=True, exist_ok=True)
addresses = config["addresses"]
records = []
last_timer = None
previous_sample_timer = None
last_hash = None
duplicates = 0
conflicting_duplicates = []
presentations = 0
first_timer = None
next_sample_timer = None
complete = False
end_reason = None


def read(address, size):
    return bytes(gdb.selected_inferior().read_memory(address, size))


def word(name):
    return struct.unpack("<I", read(addresses[name], 4))[0]


def signed(value):
    return value - 0x100000000 if value & 0x80000000 else value


def save():
    manifest = {"format": "gex-native-frames-v4" if config["fullDemo"] else "gex-native-frames-v3",
                "demo": config["demo"],
                "executableSHA256": config.get("executableSHA256"),
                "addressMapSHA256": config.get("addressMapSHA256"),
                "level": config["level"], "width": 320, "height": 224,
                "pixelFormat": "little-endian native 5:5:5 words, red in low bits",
                "frameBytes": 320 * 224 * 2,
                "postFlushPoint": "entry to 00406c00 before DIB clear, after GFX_Flush display conversion",
                "capturePreFlush": config["capturePreFlush"],
                "capturePoint": ("entry to 00406c00 after display conversion, before DIB clear"
                                 if config["fullDemo"] else
                                 "entry to GFX_Flush_00406c30 before display conversion"),
                "captureClock": "UpdateTimer returns 1 every call in both processes",
                "clockOriginalBytes": clock_original.hex(),
                "fullDemo": config["fullDemo"],
                "sampleIntervalTicks": config["sampleIntervalTicks"],
                "firstTimer": first_timer,
                "lastTimer": last_timer,
                "totalPresentations": presentations,
                "complete": complete,
                "endReason": end_reason,
                "screenBox": config.get("screenBox"),
                "duplicatePresentations": duplicates,
                "conflictingDuplicateTimers": conflicting_duplicates,
                "frames": records}
    tmp = out / "manifest.json.tmp"
    tmp.write_text(json.dumps(manifest, indent=2) + "\n")
    tmp.replace(out / "manifest.json")


class Capture(gdb.Breakpoint):
    def stop(self):
        global last_timer, previous_sample_timer, last_hash, duplicates, presentations
        global first_timer, next_sample_timer, complete, end_reason
        try:
            showing = word("demoShowing")
            level = word("level")
            if showing != 1 or level != config["level"]:
                if config["fullDemo"] and presentations:
                    complete = True
                    end_reason = ("demo flag cleared" if showing != 1
                                  else f"level changed to {level}")
                    save()
                    print(f"GEX_CAPTURE_END {end_reason}; presentations={presentations} samples={len(records)}", flush=True)
                    return True
                return False
            pointer = word("framebuffer")
            if not pointer:
                return False
            timer = word("timer")
            presentations += 1
            if timer == last_timer:
                duplicates += 1
            last_timer = timer
            if first_timer is None:
                first_timer = timer
                next_sample_timer = timer
            if config["fullDemo"] and presentations > config["maxPresentations"]:
                end_reason = "presentation limit reached before demo ended"
                save()
                print(f"GEX_CAPTURE_LIMIT {end_reason}", flush=True)
                return True
            if config["fullDemo"] and timer < next_sample_timer:
                return False
            if config["fullDemo"]:
                while next_sample_timer <= timer:
                    next_sample_timer += config["sampleIntervalTicks"]
            number = len(records)
            record = {"index": number, "timer": timer,
                      "rngState": word("rng"),
                      "gameState": word("gameState"),
                      "cameraX": signed(word("cameraX")),
                      "cameraY": signed(word("cameraY")),
                      "padHeldHex": read(addresses["input"], 15).hex(),
                      "padJustHex": read(addresses["input"] + 15, 15).hex()}
            player = word("player")
            if player:
                record["player"] = {
                    "x": signed(struct.unpack("<I", read(player + 0x78, 4))[0]),
                    "y": signed(struct.unpack("<I", read(player + 0x7c, 4))[0]),
                    "frameGroup": struct.unpack("<I", read(player + 0x50, 4))[0],
                    "frameIndex": struct.unpack("<I", read(player + 0x54, 4))[0],
                }
            if config["capturePreFlush"]:
                # Each visible line has 320 16-bit pixels in a 0x800-byte stride.
                backing = read(pointer + 0x4000, 223 * 0x800 + 640)
                pixels = b"".join(backing[row * 0x800:row * 0x800 + 640]
                                  for row in range(224))
                digest = hashlib.sha256(pixels).hexdigest()
                if timer == previous_sample_timer and digest != last_hash:
                    conflicting_duplicates.append({"index": number,
                                                   "timer": timer,
                                                   "sha256": digest})
                previous_sample_timer, last_hash = timer, digest
                name = f"frame-{number:06d}.rgb555"
                (out / name).write_bytes(pixels)
                record["file"] = name
                record["sha256"] = digest
            else:
                backing = read(pointer + 0x4000, 223 * 0x800 + 640)
                pixels = b"".join(backing[row * 0x800:row * 0x800 + 640]
                                  for row in range(224))
                name = f"post-flush-{number:06d}.raw"
                (out / name).write_bytes(pixels)
                record["postFlushFile"] = name
                record["postFlushSHA256"] = hashlib.sha256(pixels).hexdigest()
                record["postFlushMode"] = word("displayMode")
                record["postFlushTimer"] = timer
            records.append(record)
            save()
            if number == 0 or (number + 1) % 25 == 0:
                print(f"GEX_CAPTURE frame={number} timer={timer}", flush=True)
            return not config["fullDemo"] and len(records) >= config["frames"]
        except Exception as error:
            (out / "capture-error.txt").write_text(repr(error) + "\n")
            print(f"GEX_CAPTURE_ERROR {error!r}", flush=True)
            return True


clock_original = read(addresses["updateTimer"], 6)
if clock_original[0] != 0x56:
    raise RuntimeError("unexpected UpdateTimer entry; refusing fixed-step capture")
gdb.selected_inferior().write_memory(addresses["updateTimer"], b"\xb8\x01\x00\x00\x00\xc3")
print(f"GEX_CAPTURE fixed-step clock at {addresses['updateTimer']:#x}", flush=True)
Capture("*" + hex(addresses["clearAfterFlush"] if config["fullDemo"] else addresses["flush"]))
