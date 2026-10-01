# Run the source-built Gex

From the repository root, build and stage the replacement with the game's
asset folders:

```bash
./scripts/build-and-run-game
```

The script starts the game after building it. On later runs, launch the staged
executable directly from any working directory:

Set `GEX_REPO` to the path where this repository is checked out.

```bash
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe"
```

To launch directly into any level available in level select, use its name:

```bash
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe" --level grave4
./scripts/build-and-run-game --level grave4
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe" --list-levels
```

Names are case-insensitive. Use the first word of the level-select label:
`grave7` for `grave7 (boss)`, or `mainmap1` for `mainmap1 (grave)`. The list
includes both ordinary and Planet X levels. The chosen level starts with normal
player input and three hit points. The choice is consumed once; subsequent
title-screen visits work normally. Backtick (`) still returns to level select.
`--play-intro` also works with `--level`. Choose either `--level` or `--attract`;
combining them, repeating `--level`, or using an unknown name exits with code 2.
`--help` and `--list-levels` work without the game assets installed.

Launch checks on 2026-10-01 loaded `grave4`, `mainmap1`, and `scifi1` under
an isolated Wine desktop, including movement and backtick level-select return
from `grave4`. Captures remain local under `.work/level-cli-runtime/`.
`tests/level_cli.py` exercises all 44 name-to-ID mappings and argument validation
against the compiled executable; these checks do not establish gameplay parity
for every level.

To start a chosen attract recording on the first title update, append
`--attract` and its number:

```bash
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe" --attract 0
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe" --attract 1
wine "$GEX_REPO/.work/replacement-run/game/GEX.exe" --attract 2
```

| Number | First level | Recording part |
| ---: | ---: | ---: |
| 0 | 0 | 4 |
| 1 | 9 | 5 |
| 2 | 36 | 6 |

The replacement skips the AVI intro by default. Add `--play-intro` to play it,
or use `--help` to print the command syntax. Both options can be combined with
`--attract N`. The same options work when rebuilding:

```bash
./scripts/build-and-run-game --attract 1
./scripts/build-and-run-game --attract 2 --play-intro
```

The CLI choice is consumed once. Returning to the title screen later uses its
normal idle timer. The `--attract` CLI is specific to the source-built EXE;
use [`tools/patch_attract.py`](attract-frame-comparison.md) to make a separate
attract-modified copy of the pinned original. The installed game is not edited.

The staged game needs a graphical desktop and the asset folders copied by the
build script. If the assets are elsewhere, build with
`./scripts/build-and-run-game --assets-dir "/path/to/Gex"`. Set `WINEPREFIX`
before either command to select another Wine prefix.

The three direct CLI launches were checked under an isolated Wine desktop on
2026-09-30. Their screens showed the selected graveyard, moon, and castle
recordings, respectively. Local screenshots are retained under
`.work/replacement-run/cli-final-{0,1,2}.png`; this launch check is separate
from the frame comparison report.

## Widescreen and level select

Press backtick (`) during play to return to level select. On the title screen,
choose **Options** below Password. Use Left/Right to choose 4:3, 16:10, 16:9,
or 21:9; the window resizes immediately while keeping its height. Select Back
(or press Escape) to apply the gameplay viewport. The setting is saved in
`gex-source.ini` beside the staged executable. The title uses its original
centered composition, and gameplay fills the selected wider view.

`GEX_WIDESCREEN=16:9 wine "$GEX_REPO/.work/replacement-run/game/GEX.exe"`
overrides the saved ratio for startup. A saved choice otherwise persists between launches.

## Save states

Press **0–9** to select a persistent slot, **F5** to save, and **F9** to load.
Slot 0 is selected initially. States include the world and audio playback and
survive restarting or changing levels. Files are stored in
`%LOCALAPPDATA%\GexSource\states`. Saving requires gameplay or world-map play;
loading also works from the title and level select, and closes the sprite viewer.
F5 replaces the old window-size shortcut. See [save-states.md](save-states.md)
for compatibility, failure handling, implementation and validation.

## Sprite viewer

Build with `./scripts/build-and-run-game`, then press **F8** in a level. The
viewer holds gameplay still and draws frames through the source-built game's
normal sprite renderer. Alternatively, press backtick (`) to open level select,
toggle **F8 SPRITE VIEWER: ON**, and start a level with the configured Jump button
(Z by default). The viewer stays enabled when returning to level select, so you
can inspect levels in succession.

| Key | Action |
| --- | --- |
| Left / Right | Previous / next frame, continuing across animations and objects |
| Up / Down | Previous / next animation in the current object |
| Page Up / Page Down | Previous / next loaded object |
| Space | Automatically advance through frames, animations, and objects |
| Home | Return to the first object and frame |
| B | Toggle black / white background |
| N | Toggle fit-to-view / native size (large native frames can clip) |
| F8 / Escape | Close the viewer and resume the level |
| Backtick (`) | Return to level select with the viewer still enabled |

The counters include every frame slot in the resolved level object tables,
plus separately loaded Gex and idle animation objects. Identical object pointers
are listed once; animation and frame indices are zero-based, followed by their
counts. Empty slots remain inspectable instead of falling back to frame zero.
The viewer labels empty images, invalid metadata, and frames that submit no draw
commands. `ERR` counts catalogue/table problems; a nonzero count means the
inventory is incomplete. It rebuilds the catalogue after level teardown and
does not edit objects or run their scripts.

This is a visual inspection aid for loaded object animation assets. Tiles and
parallax backgrounds are outside this inventory. Drawing a frame here does not
prove that an object spawns, uses the same scripted palette/transform, or passes
camera culling during gameplay. `ERR 0` is not a claim that every frame contains
visible pixels; use stepping, playback, and both backgrounds to inspect them.

The replacement implementation is in `src/replacement/sprite_viewer.cpp`, with
small hooks in input, level playback, teardown, and level select. These are
replacement features, not matching-decompilation proofs. After building,
`python3 tests/sprite_viewer.py` exercises the compiled viewer with synthetic
assets under x86 emulation (requires `pefile` and `unicorn`), covering navigation,
empty and invalid frames, scaling selection, playback, and teardown.

Live Wine checks on 2026-10-01 covered levels 0, 9, and 36, frame/object
navigation, playback, both backgrounds, native size, and resuming gameplay.
Level-select activation and rebuilding the catalogue on a transition to level
63 were also checked. Local captures are under `.work/sprite-viewer/`.
These sampled checks do not establish visibility of every frame in every level.
