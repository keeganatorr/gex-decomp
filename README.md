# Gex: matching decompilation

An ongoing source reconstruction of the 32-bit Windows version of **Gex**. This
repository contains C/C++ function candidates, reconstruction notes, and tools
for checking whether each candidate compiles to the original function's bytes.
It is a research project and an incomplete work in progress.

> **Bug disclaimer:** This project may be quite buggy. Reconstructed code is
> incomplete, and the source-built executable can behave incorrectly, crash, or
> fail to run. Use it for experimentation, not as a dependable replacement for
> the original game.

## Reconstruction progress

Documented checkpoint at commit [`647eb5f`](https://github.com/keeganatorr/gex-decomp/commit/647eb5fb2adaefe922d4bc2dfbed655a6a559876):

| Measure | Matched | Inventory | Percentage |
|---|---:|---:|---:|
| Functions with an exact byte match | 1,074 | 1,335 | **80.4%** |
| Bytes in exactly matched functions | 166,735 | 525,887 | **31.7%** |

“Exact” means the reconstructed function compiled and its resolved machine code
matched the corresponding bytes in the pinned original executable. The byte
total is the sum of Ghidra function spans; spans can overlap or include gaps, so
it is not a count of unique executable bytes. These figures do not mean that
80.4% of the game is playable or that 31.7% of the original executable has been
patched. They describe functions whose reconstructed source compiled to matching
machine code; no patch is applied to the original executable. Most functions
remain unfinished, and an exact machine-code match does not by itself prove that
the recovered C/C++ types or intent are historically correct.

The exact-match totals come from the
[checkpoint report](https://github.com/keeganatorr/gex-decomp/blob/647eb5fb2adaefe922d4bc2dfbed655a6a559876/docs/claude-hand-decomp.md);
the inventory denominator is recorded in the
[pinned inventory](https://github.com/keeganatorr/gex-decomp/blob/647eb5fb2adaefe922d4bc2dfbed655a6a559876/docs/iterative-editedgex-index.json).
The private verification database is not included in this repository; see the
report for scope and audit limits.

## What is included

- Current per-function C/C++ reconstruction candidates in `src/functions/`.
- Research notes and byte-matching lessons in [`docs/`](docs/).
- Scripts for inspecting candidates, building the source-linked replacement,
  and submitting explicit verification requests.
- A pinned target identity. The original executable's SHA-256 is
  `e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`.

The repository does **not** include the original game executable, game assets,
compiler binaries, private verification database, or retained binary artifacts.
You must obtain the game files and required build tools separately. Nothing here
is a complete or standalone distribution of Gex.

## Build and run

The source build does **not** read or require the original `GEX.exe`. From the
repository root, build the replacement, then copy it into your Gex install
folder under a different name so the original stays intact:

```bash
./build.sh
cp .work/replacement-short/gex-source.exe "/path/to/Gex/GEX-source.exe"
```

The build writes `.work/replacement-short/gex-source.exe`. To run it, use Wine
or Windows and point it at the game folder containing the asset directories:

```bash
wine "/path/to/Gex/GEX-source.exe"
```

Launch directly into a level with `--level`, using the level-select name:

```bash
wine "/path/to/Gex/GEX-source.exe" --level grave4
```

Use `--list-levels` to print all available names. These arguments also work with
`./scripts/build-and-run-game --level grave4`.

The replacement adds a backtick (\`) shortcut to return to level select and
an **Options** entry below Password on the title screen. Options uses the
original menu font. Left/Right changes the display ratio (4:3, 16:10, 16:9,
or 21:9) and immediately resizes the window, preserving its height. Back or
Escape applies the gameplay viewport and saves it in `gex-source.ini` beside
the executable. The title artwork stays centered; gameplay uses the wider view.

`GEX_WIDESCREEN=16:9` can override the saved setting at launch. It also accepts
`W:H` or a pixel width from 320 to 672 (rounded down to a multiple of four).
A fresh configuration defaults to 4:3.

During gameplay, **numpad + / -** smoothly zoom the scene from **0.5× to 2×**;
**numpad 0** resets it. The HUD keeps its normal size, and Rez's automatic camera
continues to work. See [zoom controls](docs/run-game.md#manual-zoom).

Press **F8** during a level to open the in-game sprite viewer. You can also
enable it with F8 on level select, then start each level to inspect its loaded
objects and animation frames. See [viewer controls](docs/run-game.md#sprite-viewer).

The build needs the recovered compiler/linker and supporting build tools; the
game assets are needed at runtime, not at compile time. See
[`docs/replacement-build.md`](docs/replacement-build.md) and
[`docs/run-game.md`](docs/run-game.md) for prerequisites and known limitations.
A graphics-capable environment is required to run the game.

The reconstructed build is not equivalent to the original game. It may have
missing or incorrect behavior even where individual functions match exactly.

## Verification

Exact matches require the project's pinned compiler setup and original target
for comparison. Function candidates are verified individually; the repository
does not claim a fully reconstructed executable or full gameplay parity. See
[`docs/baseline.md`](docs/baseline.md) for target and toolchain evidence, and
[`docs/knowledge/README.md`](docs/knowledge/README.md) for the byte-difference
workflow.

## Disclaimer

Gex is the property of its respective rights holders. This project is an
unofficial reverse-engineering and source-reconstruction effort. It is not
affiliated with or endorsed by those rights holders. Do not use this repository
to distribute copyrighted game files or proprietary tools.

The replacement supports persistent save states: **0–9** select a slot, **F5** saves, and **F9** loads. See [save-state controls and compatibility](docs/save-states.md).
