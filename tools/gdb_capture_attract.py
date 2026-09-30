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
last_hash = None
duplicates = 0
conflicting_duplicates = []


def read(address, size):
    return bytes(gdb.selected_inferior().read_memory(address, size))


def word(name):
    return struct.unpack("<I", read(addresses[name], 4))[0]


def signed(value):
    return value - 0x100000000 if value & 0x80000000 else value


def save():
    manifest = {"format": "gex-native-frames-v1", "demo": config["demo"],
                "executableSHA256": config.get("executableSHA256"),
                "addressMapSHA256": config.get("addressMapSHA256"),
                "level": config["level"], "width": 320, "height": 224,
                "pixelFormat": "little-endian native 5:5:5 words, red in low bits",
                "frameBytes": 320 * 224 * 2,
                "capturePoint": "entry to GFX_Flush_00406c30, before display conversion",
                "captureClock": "UpdateTimer returns 1 every call in both processes",
                "clockOriginalBytes": clock_original.hex(),
                "screenBox": config.get("screenBox"),
                "duplicatePresentations": duplicates,
                "conflictingDuplicateTimers": conflicting_duplicates,
                "frames": records}
    tmp = out / "manifest.json.tmp"
    tmp.write_text(json.dumps(manifest, indent=2) + "\n")
    tmp.replace(out / "manifest.json")


class ScreenAfterFlush(gdb.Breakpoint):
    def __init__(self, record, return_address):
        super().__init__("*" + hex(return_address), internal=True, temporary=True)
        self.record = record

    def stop(self):
        try:
            from PIL import ImageGrab
            x, y, width, height = config["screenBox"]
            picture = ImageGrab.grab(bbox=(x, y, x + width, y + height)).convert("RGB")
            pixels = picture.tobytes()
            name = f"screen-{self.record['index']:06d}.rgb24"
            (out / name).write_bytes(pixels)
            self.record["screenFile"] = name
            self.record["screenSHA256"] = hashlib.sha256(pixels).hexdigest()
            save()
            return len(records) >= config["frames"]
        except Exception as error:
            (out / "capture-error.txt").write_text(repr(error) + "\n")
            print(f"GEX_SCREEN_CAPTURE_ERROR {error!r}", flush=True)
            return True


class Capture(gdb.Breakpoint):
    def stop(self):
        global last_timer, last_hash, duplicates
        try:
            if word("demoShowing") != 1 or word("level") != config["level"]:
                return False
            pointer = word("framebuffer")
            if not pointer:
                return False
            timer = word("timer")
            # Each visible line has 320 16-bit pixels in a 0x800-byte stride.
            backing = read(pointer + 0x4000, 223 * 0x800 + 640)
            pixels = b"".join(backing[row * 0x800:row * 0x800 + 640]
                              for row in range(224))
            digest = hashlib.sha256(pixels).hexdigest()
            if timer == last_timer:
                duplicates += 1
                if digest != last_hash:
                    conflicting_duplicates.append({"timer": timer, "sha256": digest})
                    save()
                return False
            last_timer, last_hash = timer, digest
            number = len(records)
            name = f"frame-{number:06d}.rgb555"
            (out / name).write_bytes(pixels)
            record = {"index": number, "timer": timer, "sha256": digest,
                      "file": name,
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
            records.append(record)
            save()
            if number == 0 or (number + 1) % 25 == 0:
                print(f"GEX_CAPTURE frame={number} timer={timer} hash={digest[:12]}", flush=True)
            if config.get("screenBox"):
                stack = int(gdb.parse_and_eval("$esp")) & 0xffffffff
                return_address = struct.unpack("<I", read(stack, 4))[0]
                ScreenAfterFlush(record, return_address)
                return False
            return len(records) >= config["frames"]
        except Exception as error:
            (out / "capture-error.txt").write_text(repr(error) + "\n")
            print(f"GEX_CAPTURE_ERROR {error!r}", flush=True)
            return True


clock_original = read(addresses["updateTimer"], 6)
if clock_original[0] != 0x56:
    raise RuntimeError("unexpected UpdateTimer entry; refusing fixed-step capture")
gdb.selected_inferior().write_memory(addresses["updateTimer"], b"\xb8\x01\x00\x00\x00\xc3")
print(f"GEX_CAPTURE fixed-step clock at {addresses['updateTimer']:#x}", flush=True)
Capture("*" + hex(addresses["flush"]))
