# Run the source-built Gex

From the repository root, build and stage the replacement with the game's
asset folders:

```bash
./scripts/build-and-run-game
```

The script starts the game after building it. On later runs, launch the staged
executable directly from any working directory:

```bash
wine "/home/keegan/Repos/gex-decomp/.work/replacement-run/game/GEX.exe"
```

To start a chosen attract recording on the first title update, append
`--attract` and its number:

```bash
wine "/home/keegan/Repos/gex-decomp/.work/replacement-run/game/GEX.exe" --attract 0
wine "/home/keegan/Repos/gex-decomp/.work/replacement-run/game/GEX.exe" --attract 1
wine "/home/keegan/Repos/gex-decomp/.work/replacement-run/game/GEX.exe" --attract 2
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
