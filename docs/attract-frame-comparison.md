# Chosen attract mode and frame comparison

`./scripts/compare-attract --demo 0 --full` builds the source-only game,
stages game assets under `.work/attract-compare/game`, patches separate copies
of the pinned original and source executable, and runs both through the same
recording through its end. It samples the first presented frame at each 30-tick
boundary (about 0.99 seconds of game time) just before Gex clears its display
buffer, under Wine/GDB, and
writes a report under a timestamped `.work/attract-compare/runs/` directory.
The comparison command exits nonzero on a mismatch after writing the report.
Use `--no-build` to reuse the current source executable and symbol map while
iterating on the comparison tool. A game build still reads only source and
toolchain inputs; the original executable is a separate read-only oracle.

The standalone binary mod can be applied to a copy of either executable:

```bash
python3 tools/patch_attract.py --demo 1 \
  --output .work/attract-mod/GEX-original-demo1.exe
python3 tools/patch_attract.py --demo 1 \
  --input .work/replacement-short/gex-source.exe \
  --output .work/attract-mod/GEX-source-demo1.exe
```

The source-built EXE also accepts `--attract 0|1|2` directly, without
changing its saved bytes. See [run-game.md](run-game.md) for commands, or
build and run a chosen recording with `./scripts/build-and-run-game --attract 1`.

The patcher checks the pinned hash when reading the installed original,
validates one title-idle instruction sequence and its initial recording
cursor, then writes an atomic copy and JSON receipt under `.work`. It changes
the title idle threshold from `0x384` to zero, so the existing attract path
starts on its first title update. It sets the prior cursor value so the next
increment selects the requested recording. The three choices are:

| `--demo` | first level ID | IDL recording part |
| --- | ---: | ---: |
| 0 | 0 | 4 |
| 1 | 9 | 5 |
| 2 | 36 | 6 |

The title and normal startup still initialize first; this skips the 900-frame
idle wait, not the game's loaders. The patched original copy reached the first
graveyard attract sequence within ten seconds under Wine. The installed EXE
retained its pinned SHA256.

For capture, GDB changes `UpdateTimer_00405120` **in each process's memory**
to return 1. This makes frame stepping deterministic while the debugger reads
the buffers. That timer change is absent from both saved executable copies.
The full-demo tool counts every completed `GFX_Flush` presentation while the chosen demo
is active, including presentations with the same game timer. It captures pixels
only at the one-second sample points, and stops when the demo flag clears or the
selected level changes. The report checks both captures' total presentation
count and final game timer as well as the samples. Use `--frames N` instead to
capture and compare every presentation for a short interval. It compares:

1. For `--full`, the 320×224 DIB pixel rows at the entry to the routine that
   clears them. `GFX_Flush` has already converted the colors and issued the
   display blit. This is 143,360 bytes per sample, with no tolerance or encoding.
2. For bounded `--frames N` runs, the native Gex framebuffer at the entry to
   `GFX_Flush` is captured as well, before display conversion.
3. Sampled controller bytes, camera, and player position/animation fields to
   locate state divergence that can precede the first changed pixel.

`report/comparison.json` records every sampled frame's timer, changed-pixel count,
and exact status. It identifies the first state, native-buffer (if captured),
and post-flush DIB mismatch separately. For native differences it saves oracle,
source, and magenta difference PNGs, a bounding rectangle, the busiest 16×16 screen
tiles, and candidate source functions. `report/triage.md` packages the first
divergence and source-file leads for the next reconstruction pass. Those
function suggestions are leads from the changed region and sampled state, not
proof of ownership. Frame and
screen files remain under `.work`; no original binary, capture, or compiled
artifact belongs in Git.

The full-demo check covers sampled frames throughout the recording; it cannot
prove that unsampled frames are identical. It checks the DIB memory that feeds
presentation, not pixels read back from the desktop. Earlier Xvfb screen grabs
remained frozen while the native buffer changed, so they are not evidence of displayed
frame equality. These captures exercise a controlled fixed-step clock. Other game code can
still consult real time, and the result does not by itself prove parity at
normal wall-clock speed. Both runs must use the same Wine configuration.

The complete demo 0 comparison is retained at
`.work/attract-compare/runs/20260930T113958Z-demo-0/`. Both builds completed
after 1,855 presentations and at game timer 1,822. All 61 sampled frames had
different content over time in each build. The first display-buffer difference
is sample 25, game timer 754: 34 changed 16-bit pixels at x=242–248,
y=176–185. Input, player, camera, RNG, and sampled game state matched at that
point. The original and source outputs are **not** byte-identical for the full
recording. `report/comparison.json` and `report/triage.md` give the exact
locations and candidate drawing functions. The earlier native-buffer capture
of the same complete demo found the same first difference.

Initial focused validation: demo 0's first five frames had consecutive timer
values 4–8, identical native buffers, and
matching sampled player/camera fields. A separate 600-frame native-buffer run
also matched byte for byte at every captured frame. A complete 60-frame run
matched native buffers on every frame. Its desktop screenshot crop was later
found to remain frozen across changing game frames and cannot support a visual
equality claim. These bounded runs do not establish whole-game parity or
behavior outside the selected recording.

Demo 1 (level 9) and demo 2 (level 36) each launched the selected recording
in both executables; their first three native frames also matched exactly.

The retained comparison receipts are
`.work/attract-compare/runs/20260930T061032Z-demo-0/` (600 native frames),
`20260930T063214Z-demo-0/` (60 native and screen frames),
`20260930T063433Z-demo-1/`, and `20260930T063519Z-demo-2/`.

For a controlled report check, a scratch copy changed one native pixel at
frame 3, coordinate (12,30), and updated that scratch frame's hash. The
comparator reported frame 3, the exact one-pixel bounds, its 16×16 tile, and
HUD/overlay candidates. A separate scratch change to one displayed RGB pixel
at frame 2 was reported as a screen-only mismatch. The original captures were
not changed.
