# Persistent save states

The source replacement has ten disk-backed emulator-style slots. Press **0–9**
to select one (initially 0), **F5** to replace its state, and **F9** to load it.
F5 replaces the old window-size shortcut; F6 still selects the larger window.
The sprite-font overlay reports selection, completion, deferred requests, and
errors. Holding a key does not repeatedly save or load.

Files live at `%LOCALAPPDATA%\GexSource\states\slot-N.gxs`. Wine uses the selected
prefix's Windows Local AppData directory. Slots survive quitting, work from
another level, and can be loaded from the title or level select. Loading closes
the sprite viewer. Saving requires gameplay or world-map play; menus, the title,
attract recordings, AVI playback, and the viewer report that saving is unavailable.
Video and paused-game notices also appear briefly in the window caption.

## Capture and restore

`src/replacement/save_states.cpp` owns the game-thread request queue, graph codec,
staging, files, and commit. `state_audio.cpp` owns DirectSound reconstruction.
`tools/save_state_hooks.py` instruments only the replacement compile; the normal
probe/verifier compilation is unchanged. Hook sites are checked when building,
and transformed-source hashes participate in the replacement object cache.

The window procedure queues requests and rejects keyboard repeats. Playback
handles them before simulation advances; the manual-pause loop also polls.
Unfinished level requests are completed through the normal loader or deferred
until the loader and transition flags are clear. The audio thread acknowledges
a cooperative pause before capture/preparation. Window and timer callbacks use
an interlocked mutation guard. Capture waits
until callbacks already in progress finish; new callbacks cannot mutate the
world or recreate audio devices during staging. Focus activation is deferred
and reapplied on the window thread after the operation.

Manual pause is retained when loading a paused state, including the saved pause
image in the software backing and the music worker pause flag. Requests continue
to work without advancing simulation while paused.

Load validates and allocates the entire graph, reopens logical files, checks
asset fingerprints, and creates/configures every replacement audio buffer before
unwinding the old gameplay entry. Normal teardown is suppressed during that
unwind. Commit replaces the owned allocations and globals, rebuilds texture-cache
metadata, clears transient loader/input records and timing, closes inspection/menu
modes, and resumes the normal playback entry. Sequence playback saves its level
sequence index, and temporary cutscene playback retains its return level. Both
resume their gameplay entry without restoring a native stack.

Failed preparation discards staged resources and resumes the old audio buffers;
the live graph is retained. Saves write a temporary file, flush it, then use
`MoveFileEx(REPLACE_EXISTING | WRITE_THROUGH)`. An unsuccessful write or replacement
leaves the previous slot intact.

## World ABI inventory

The ABI retains the original game's logical memory layouts. A scalar field ID is
its stable region ID plus byte offset. These IDs are independent of replacement
link addresses. Region boundaries, offsets, descriptor kinds, and callback IDs
are persisted contracts: changing a reconstructed C++ declaration does not change
the saved layout. A future change to these layouts needs an ABI migration.

| Stable region IDs | Owned state |
| --- | --- |
| `455b00`, `455998` | Level/player settings, progress, passwords, directory and map roots, callbacks and lookup tables |
| `461180` | MSVC game RNG seed; replacement calls to CRT `rand` use this saved seed |
| `4626d0` | Loader ownership/free-block tables, script registers and flags, collision/free lists, tile and parallax state, custom RNG seeds |
| `46a530` | Animation, image/texture cache counters and logical metadata |
| `4a0200` | Input records, tile tables, player/object lists, health, pickups, timer, camera, level/map/intro and gameplay flags |
| `47ef70` | Original memory allocator bookkeeping and IDL root |
| `49f6b0`, `49fb54` | All 281 sample pointers and SFX allocation root |
| `49fb90` | Script work register, object/resource links and script-visible roots |
| `70000001` | Persistent font file record, formerly a startup stack local |
| `70000002` | Shared software texture/palette pixel backing |
| `80000000 + allocation ID` | MEM-owned allocations and the separately allocated SFX data |

References are explicit descriptors, never inferred by scanning integers for
address-like values. Sources supply initially relocated pointer globals and
callback-specific object fields; runtime hooks describe resource relocation,
script pointer copies/stores/swaps, file handles, and transient cache slots.
The generated schema uses source and replacement COFF only.

The object schema covers next/previous nodes, load data, four callbacks, parent
and child links, attack/defend/object links, script PCs/return stacks/event PCs,
animation pointers, typed callback work fields, and script-created references.
Free objects discard unused payloads. Collision allocations are identified by
collision-list ownership, with descriptors for their links and object payloads.
Introduction trackers retain data and callback identities. Map/block/tile,
parallax, animation, resolved object/script data, and modified resources retain
both their scalar contents and their explicit references.

Pointer values encode allocation/region IDs plus offsets, asset-segment IDs plus
offsets, original callback addresses, registered replacement callback IDs, or
logical file IDs. Asset segments retain relative file identity, file offset,
allocation/region owner, and length. Restoration allocates first and resolves
references in a second pass. A scalar resembling an old pointer stays scalar.
Replacement callbacks use reserved IDs `60000000`–`6fffffff`; register them with
`GEX_StateRegisterCallback` before accepting states that use them.

Native thread, window, GDI, DirectSound, and file handles are runtime resources.
The codec reopens files at their logical offsets and recreates audio buffers;
it uses the current graphics device/pixel backing and rebuilds draw/cache state.
Transient LRU slots are invalidated. Persistent preloaded texture indices remain
part of the world because their pixel contents are restored.

## Audio ABI

The audio record contains music, voice, and eight overlapping effect buffers.
Each retains PCM bytes, PCM format, play cursor in bytes, playing/looping status,
volume, pan, and frequency. It also retains the 64 KiB streaming ring and its
read/write/available counters, music half-buffer/file position and fingerprint,
pending music/voice requests, loop position, and sound selection/volume state.
The worker remains held during graph replacement. Prepared buffers are filled,
positioned, and configured before commit and resume with their saved status.
Loading necessarily introduces a brief silence.

## File compatibility

All integers are little-endian. The envelope is `GXS2`, wire version **5**, world
ABI **1**, followed by level and bounded table counts. Length-delimited regions
contain their descriptors and scalar payload. Resource, reference, fingerprint,
logical-file and audio tables follow. Length-delimited audio identity metadata
is required in version 5. Optional
metadata includes pause state, sequence position, temporary-level return identity,
and an executable CRC32 for diagnostics. A final CRC32 covers
the preceding file. Executable identity does **not** gate compatibility.

Readers accept wire versions 1–5. Version 1 PCM frame cursors migrate to byte
cursors; versions 1–2 have no optional metadata, and versions 1–3 have no resource
segment table. Version 5 adds a required audio asset identity table; older states
retain their legacy PCM/file representation. Each buffer identifies its source
file fingerprint and sample segment, and pending voice/music requests retain
their asset identities too. The retained public fixture is
[`tests/fixtures/save_states/v1.json`](../tests/fixtures/save_states/v1.json);
tests construct its historical bytes without proprietary game data. Unsupported
wire/world versions, changed/missing assets, invalid tables/references, checksum
failures and allocation failures are rejected before commit. Unknown optional
metadata is skipped using its length.

Bounds are 32 MiB per state, 40 owned allocations, 512 asset identities, 2,048
resource spans, eight logical CDIO files, and ten audio buffers. Tracking overflow
fails the save instead of dropping state. Asset identity is relative filename,
length and CRC32. Editing game assets invalidates states depending on them.
Compatibility promises retain the frozen world ABI and asset contents; arbitrary
future gameplay-layout changes require migrations and new retained fixtures.

## Validation

Build with `./build.sh`, then run `python3 tests/save_states.py` in an environment
with `pefile` and `unicorn`. Tests execute the actual linked x86 serializers,
script interpreter and commit code with synthetic Win32/DirectSound resources.
They cover all slots/repeats, atomic write failure, menu/video/viewer requests,
transition deferral, restart with different allocation addresses and another
level, explicit scalar preservation, collision/intro/object/script references,
health/pickups/camera/timer/animation/RNG state, deterministic script input replay,
all ten audio buffers/cursors/settings, streaming-ring wrap state, logical music
file position, asset changes/missing assets, truncation/corruption, malformed
schemas/reference tables and staged memory/audio allocation failures.

The tests relink a second executable at `800000` instead of `400000`, load the
retained version-1 fixture, and verify the restored callback resolves at its new
address. Normalized portable snapshots after replaying identical inputs compare
byte-for-byte. Generated executables and states stay under `.work/`.

Wine checks on 2026-10-01–02 used a private prefix and staged assets: `grave4`,
`mainmap1`, `grave7` (boss), and `scifi1` (Planet X); paused save/load, viewer
rejection/exit, level-select rejection/loading, title loading, and a restart into
Planet X followed by loading graveyard in the executable linked at `800000`.
Local notices and captures remain in `.work/save-states-runtime/`.
These are sampled gameplay checks; the precise simultaneous voice/effect cursor
and allocation-failure assertions are provided by the linked-code harness.

Replacement build, level CLI, sprite viewer, sprite rotation, rotated commands,
map direction, help-box, and widescreen raster checks pass. The knowledge suite
has 44 passing checks and 12 refused source-file cases: those files export their
named functions, while the scratch probe requires `GEX_Target`. This feature does
not change or publish byte-match proofs.
