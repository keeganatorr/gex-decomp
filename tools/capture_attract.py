#!/usr/bin/env python3
"""Run a selected attract build under Wine/GDB and capture native frames.

Run under xvfb-run or an existing graphical desktop. The executable must be a
patched copy made with patch_attract.py, placed beside the separately supplied
game assets. Output stays under .work/.
"""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import signal
import subprocess


ROOT = Path(__file__).resolve().parent.parent
SOURCE_NAMES = {
    "flush": "_GFX_Flush_00406c30",
    "framebuffer": "_GEX_DATA_00487f70",
    "demoShowing": "_GEX_DATA_004a2a0c",
    "level": "_GEX_DATA_004a2964",
    "timer": "_GEX_DATA_004a2ac8",
    "cameraX": "_GEX_DATA_004a2a38",
    "cameraY": "_GEX_DATA_004a2a1c",
    "player": "_GEX_DATA_004a27fc",
    "input": "_GEX_DATA_004a0280",
    "rng": "_GEX_DATA_00461180",
    "gameState": "_GEX_DATA_00455c3c",
    "displayMode": "_GEX_DATA_00454fc8",
    "clearAfterFlush": "_FUN_00406c00_IfFreeGameNotEquals1_Unk_WHAT_DOES_THIS_DO_CONTAINS_PPVBITS",
    "updateTimer": "_UpdateTimer_00405120",
}
ORIGINAL_ADDRESSES = {
    "flush": 0x00406c30, "framebuffer": 0x00487f70,
    "demoShowing": 0x004a2a0c, "level": 0x004a2964,
    "timer": 0x004a2ac8, "cameraX": 0x004a2a38,
    "cameraY": 0x004a2a1c, "player": 0x004a27fc,
    "input": 0x004a0280,
    "rng": 0x00461180, "gameState": 0x00455c3c,
    "displayMode": 0x00454fc8,
    "clearAfterFlush": 0x00406c00,
    "updateTimer": 0x00405120,
}


def source_addresses(path: Path) -> dict[str, int]:
    lines = path.read_text(errors="replace").splitlines()
    result = {}
    for key, symbol in SOURCE_NAMES.items():
        matches = [line for line in lines if re.search(r"\s" + re.escape(symbol) + r"\s", line)]
        if len(matches) != 1:
            raise ValueError(f"expected one {symbol} in {path}, found {len(matches)}")
        fields = matches[0].split()
        result[key] = int(fields[2], 16)
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--kind", choices=("oracle", "source"), required=True)
    parser.add_argument("--demo", type=int, choices=range(3), required=True)
    selection = parser.add_mutually_exclusive_group()
    selection.add_argument("--frames", type=int, default=100)
    selection.add_argument("--until-demo-end", action="store_true",
                           help="capture the whole selected demo, sampling once per 30 game ticks")
    parser.add_argument("--sample-ticks", type=int, default=30)
    parser.add_argument("--max-presentations", type=int, default=30000)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--map", type=Path,
                        default=ROOT / ".work/replacement-short/gex-source.map")
    parser.add_argument("--timeout", type=int, default=180)
    args = parser.parse_args()
    if (args.frames is not None and args.frames < 1) or min(args.timeout, args.sample_ticks, args.max_presentations) < 1:
        parser.error("frames, timeout, sample ticks, and presentation limit must be positive")
    exe = args.exe.resolve(strict=True)
    out = args.out.absolute()
    if not out.is_relative_to(ROOT / ".work"):
        parser.error("output must stay under this project's .work directory")
    receipt = json.loads(Path(str(exe) + ".json").read_text())
    if receipt["format"] != "gex-attract-patch-v1" or receipt["demo"] != args.demo:
        parser.error("executable has no matching attract patch receipt")
    if hashlib.sha256(exe.read_bytes()).hexdigest() != receipt["outputSHA256"]:
        parser.error("executable hash differs from attract patch receipt")
    if args.kind == "oracle" and not receipt["originalPinned"]:
        parser.error("oracle patch was not made from the pinned original")
    if args.kind == "source":
        current_source = ROOT / ".work/replacement-short/gex-source.exe"
        if (not current_source.exists() or
                hashlib.sha256(current_source.read_bytes()).hexdigest() != receipt["inputSHA256"]):
            parser.error("source executable no longer matches this build's map")
    addresses = (ORIGINAL_ADDRESSES if args.kind == "oracle" else
                 source_addresses(args.map))
    out.mkdir(parents=True, exist_ok=True)
    config = {"demo": args.demo, "level": (0, 9, 36)[args.demo],
              "frames": args.frames, "fullDemo": args.until_demo_end,
              "capturePreFlush": not args.until_demo_end,
              "sampleIntervalTicks": args.sample_ticks,
              "maxPresentations": args.max_presentations,
              "out": str(out), "addresses": addresses,
              "executableSHA256": receipt["outputSHA256"]}
    if args.kind == "source":
        config["addressMapSHA256"] = hashlib.sha256(args.map.read_bytes()).hexdigest()
    config_path = out / "capture-config.json"
    config_path.write_text(json.dumps(config, indent=2) + "\n")
    command = "\n".join([
        "set pagination off", "set confirm off", "set debuginfod enabled off",
        "set architecture i386",
        "source " + str(ROOT / "tools/gdb_capture_attract.py"),
        "continue", "kill", "quit", "",
    ])
    environment = os.environ.copy()
    environment["GEX_CAPTURE_CONFIG"] = str(config_path)
    environment["WINEDEBUG"] = "-all"
    process = subprocess.Popen(["winedbg", "--gdb", str(exe),
                                "JAchWieGutDasKeinerWeis"],
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE, text=True,
                               cwd=exe.parent, env=environment,
                               start_new_session=True)
    try:
        stdout, stderr = process.communicate(command, timeout=args.timeout)
        log = stdout + stderr
    except subprocess.TimeoutExpired:
        os.killpg(process.pid, signal.SIGTERM)
        try:
            stdout, stderr = process.communicate(timeout=3)
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGKILL)
            stdout, stderr = process.communicate()
        log = stdout + stderr
        (out / "debugger.log").write_text(log + "\nTIMEOUT\n")
        raise SystemExit(f"capture timed out; inspect {out / 'debugger.log'}")
    (out / "debugger.log").write_text(log)
    manifest = out / "manifest.json"
    if not manifest.exists():
        raise SystemExit(f"no frames captured; inspect {out / 'debugger.log'}")
    data = json.loads(manifest.read_text())
    count = len(data["frames"])
    if ((args.until_demo_end and not data.get("complete")) or
            (not args.until_demo_end and count != args.frames) or
            (out / "capture-error.txt").exists()):
        raise SystemExit(f"capture incomplete ({count} samples, {data.get('totalPresentations')} presentations, {data.get('endReason')}); inspect {out}")
    print(f"Captured {count} {args.kind} demo {args.demo} frames across {data['totalPresentations']} presentations: {out}")


if __name__ == "__main__":
    main()
