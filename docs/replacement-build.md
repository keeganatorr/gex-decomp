# Building a replacement Gex executable

## Goal

Build a Windows executable from reconstructed source, toolchain and separately
supplied game assets, without reading or linking any bytes from the original
`GEX.exe`. During development, the original remains a comparison oracle. The
replacement should reproduce the game's behavior as closely as practical;
exact function bytes are valuable evidence but are not the completion measure.

The first playable target is the original Win32 API environment. Portability
can be considered after the game builds and runs from source.

## First source-only link milestone

`./scripts/build-source-link-smoke` compiles three reconstructed functions:
`00420d30`, `00418e20` and `0041fbc0`. Their source definitions carry their
Ghidra-based names, and the build links their real cross-function call and three
global variables using the recovered VC4 compiler/linker and an older SDK
`kernel32.lib`, then runs the result under Wine. Its only inputs are source,
`project.json`'s toolchain contract and local toolchain libraries. Output is
ignored under `.work/replacement-link-smoke/`.

This executable is a link and runtime smoke, **not yet Gex**. It establishes
that source-only compilation, inter-function calls, data definitions and a
Windows PE link work with this toolchain. It does not establish whole-game
linkability or gameplay parity.

`./scripts/assess-replacement-link` is the current end-to-end source-only
build assessment. It compiles all **1,250** current function files with their
Ghidra-based exported names and per-function C/C++ flags. It changes COFF
*symbol references* to the exports at their justified addresses, assembles
`src/replacement/image_data.s` and
`image_resources.s`, and runs both the recovered VC4 linker and a modern LLD
link with Win32 imports. It attempts a Windows subsystem link through the
reconstructed `WinMain_00405bf0` and VC4's `WinMainCRTStartup`. The executable
and all objects stay under `.work/`.
The command currently exits 0 and writes
`.work/replacement-short/gex-source.exe` without reading the original EXE.

`./scripts/build-and-run-game` builds that executable and launches it from
`.work/replacement-run/game`. It copies only the installed asset folders,
`LOADER.WAV`, and optional settings/help files into that private directory;
it does not copy or execute the installed `GEX.exe`. The source-built WinMain
does not check for LOADER.EXE's password. A bare launch skips the AVI intro;
`--play-intro` passes `X` to play it. Supply `--assets-dir DIR` (or
`GEX_ASSETS_DIR`) if the assets are elsewhere. Runtime Wine uses the normal
Wine prefix unless `WINEPREFIX` is set. A graphical desktop is required.
The entry adapter changes to the staged executable's directory before the
game opens its relative asset paths, so `wine .work/replacement-run/game/GEX.exe`
and absolute-path launches work from another directory. The installed original
still requires its launcher token. The replacement accepts `--attract 0|1|2`
on its own command line to select and launch a demo on the first title update;
see [run-game.md](run-game.md) for exact commands.

The source-built window procedure keeps game simulation running on
`WM_ACTIVATEAPP` focus loss. The original calls `GameUnpause_004051d0` there;
despite its name, that routine freezes the game loop. Manual pause keys and
the existing sound activation handling remain in place. This is an intentional
behavior change for the replacement executable.

All 1,250 function sources compile. The game-entry LLD link has **zero
unresolved externals and zero duplicate definitions**. VC4 LINK still reports
`___ImageBase`, a linker-supplied symbol provided by the final LLD link. The
four last missing function addresses were `00416320` (player processing),
`0041d310` (angled collision), `0042eaf0` (graphics drawing) and `00434b10`
(collision event). Their source bodies are provisional translations, not byte
proofs. Several earlier sources also retain decompiler artifacts, so a
successful link does not establish gameplay parity. The exact link result and
object-to-address map are in `.work/replacement-short/game-lld-report.json`
and `object-addresses.json`.
The current pass added analog input lookup, background initialization, graphics
fill, CRT startup helpers, integer formatting and substring search. The CRT
float formatting entries forward to matching exports in the recovered VC4
archive; their behavior is delegated to that archive, not reconstructed or
byte proven. The original graphics fill bytes were inspected directly because
the Ghidra body for `00444d10` differs from the pinned executable.
The next pass added voice selection, bubble movement, camera animation,
parallax drawing, default object drawing and the intro input loop. A later pass
added the map resolver, graphics tile dispatcher and its three draw helpers,
tube transition, help box drawing, another tile helper, cel-to-quad drawing and
the hunt/dive callback. The latest pass added HUD drawing, player update,
object 261 update, text drawing, middle tile drawing and a graphics helper.
The current pass added pause handling, map player update, camera motion and two
draw paths. These remain provisional translations where the backup decompiler
lost field offsets or call arguments; the source explicitly recovers several
arguments from the original call instructions.
These are compiling behavior candidates, not gameplay or byte proofs. The
replacement data builder now creates aliases for data addresses referenced by
compiled objects, including offsets within the zero-initialized tail; it does
not need the original executable at build time. The former `00449d23` and
`00449d3e` references were interior SEH labels in the original CRT startup
body, not standalone C functions.

Earlier runtime checks confirmed that the pinned original accepts two
launcher tokens and that either skips both AVI clips. The source-built EXE now
accepts arbitrary command lines or no arguments. The token values are omitted.
Original instructions at `00405edc` write 1 to
`00487fc0` for the `J` prefix; `GameThread` passes that word to `GameMain` as
its skip-intro argument. The replacement had incorrectly written `0045633c`.
After correcting the address, both executables reach the title screen within
eight seconds with the `J` token. A fresh isolated Wine prefix initially failed to
open `AVI/GEX000.AVI` because it lacked the 32-bit Intel Indeo 3 `IV32`
codec. The pinned original EXE showed the same error in that prefix. After
copying the existing local codec into the isolated prefix and registering
`vidc.iv31`/`vidc.iv32` in its 32-bit Drivers32 registry view, the replacement
played the opening AVI. This is a runtime environment requirement; the codec
and original EXE are not build inputs or repository artifacts. At the title
screen, a reversed
branch at `004060a1` in the edited Ghidra WinMain caused the replacement to
open its 1024-by-512 debug VRAM window. The pinned PE's `test`/`je` instruction
shows the call must be skipped when `00487bc0` is zero; the source now follows
that branch. Later fixes to the 4-bit text sprite renderer and scaled and
tiled drawing paths restored the title background and Start/Password/Exit
text. The source for `0040bc70` also restored an uninitialized local into
the object's previous-Y field; original instructions restore the saved field
value, and that source is corrected.

The unattended title screen enters attract mode in both executables.
For reproducible recording selection and byte-exact per-frame visual
comparison, see `docs/attract-frame-comparison.md` and
`./scripts/compare-attract`.

Using the isolated assets and Wine prefix, the replacement renders the
graveyard demo without the earlier memory faults. Before the script and
contour-platform repairs below, a 40-second capture showed the graveyard
tiles, player sprite and HUD, but a 60-second capture found the original
farther ahead with about 20,000 points and the replacement near the start
with zero points and one fewer life. The replacement returned to the title
around 60 seconds; the original continued through the graveyard at 90 seconds.
After a help-box repair the replacement starts a second attract level by
85 seconds. It formerly faulted while walking that level: the graphics list
reached a command whose next link was zero. A temporary list trace found
both list heads pointing to the same zeroed pool entry at draw frame 2666,
while their tails pointed to newer commands. The dispatcher matched the
pinned null-pointer behavior. The `00441150` graphics writer was the source
error: the backup translation treated 16-byte command records as 4-byte
integers, wrote image and texture data over their list links, and failed to
advance either list tail. Its command allocation, fields, paired copy and
links now follow the read-only Ghidra analysis. The rebuilt replacement
passed frame 2666, continued through the second demo at 105 seconds, and
returned to the title by 120 seconds without that fault. A separate clean
build with tracing removed remained in the second demo at 110 seconds without
a memory fault. This establishes
progress through the attract sequence, not gameplay parity. The previous
`00443ae0` quad renderer also stopped after one tile and used the address of
a pool pointer as its pool; its source now writes all tiles and links both
command lists. The pinned `0043dc70` instructions show that the graphics
mode field is read 0x16 bytes into the second command; the previous source
accidentally added 0x3e *int elements* from the first. The demo overlay appears in both at some
frames; its absence in a single capture can be the normal blinking phase.
Captures and logs are retained locally under
`.work/replacement-runtime/attract-{oracle,camera,player,state,helpbox,final,collision-buffer,quad,object-scale}-*`.
Temporary output tracing in `ReadController` showed recording playback is
active: the input bits change and the player enters walk, jump and attack
states while X advances from about 12.8 million to 93.6 million fixed-point
units across demo frames 32–448. The tracing code was removed after the
local capture (`.work/replacement-runtime/attract-input-debug.log`).
Temporary ground-contact tracing confirmed that the map lookup returns zero
distance on the opening platform, and again after the player has descended to
the lower path (about X=953, Y=894 in map pixels). The player follows a
different trajectory before that descent; the trace does not identify its
cause. The tracing source was removed after the capture
(`.work/replacement-runtime/attract-glue-trace.log`). At that checkpoint, the
remaining divergence was downstream of recording input, in movement, state
processing, scoring or their timing.

Two-second captures from 28 through 44 seconds narrow the first visible
split. Both executables enter the graveyard at about 31 seconds. At 34 seconds
the original has scored 250 points and Gex is airborne; the replacement has
zero points and Gex is still on the ground. At 38 seconds the original is
above the first pit while the replacement is on its lower platform. The
read-only captures are `.work/replacement-runtime/attract-{oracle,replacement}-fine-*.png`.
Temporary pad/state tracing showed a `0x02000000` demo input at pad frame 99
mapped to the jump button, including its one-frame just-pressed flag. No
player-state processing occurred for approximately 20 pad reads around that
press; when player processing resumed, the just-pressed flag had cleared and
Gex stayed in walking state. The preceding tail attack did create its collision
object and both animation hot spots; this rules out a missing attack object
but does not establish why the original scores and the replacement does not.
The next comparison should establish why the player processing pause and first
enemy interaction differ. Traces are retained at
`.work/replacement-runtime/attract-{pad,state,tail}-trace.log`; all temporary
tracing source was removed.

A further gate trace shows the replacement's health falling from 3 to 2 at
player frame 83, immediately before the skipped jump press. Its tail collision
objects are registered, and the collision manager does compare them with
nearby objects. The retained traces are `attract-gate-trace.log` and
`attract-cld-trace.log` under the same runtime directory. The provisional
`0041d310` rotated collision source had lost almost every object field offset
and angle mask; it has been reconstructed from read-only Ghidra output into a
source-level collision path. A source-only link and 55-second and 110-second
attract runs complete with that repair, including the second demo, but the
first enemy and score still differed at that checkpoint. This collision source
is a behavioral translation, not a verifier byte proof. The later repairs
below resolve the first encounter and pit in the recorded demo.

The original `00435d90` script interpreter had been reduced by the backup
translation to a timer-clearing stub. The source now executes movement,
animation, waits, branches, object and game-variable access, and native calls
through the source-rebound dispatch table. The pinned instructions confirm that
the game-variable table at `0045b808` contains **pointers to variables**: script
opcodes `0x94` and `0xa6` dereference those pointers. The first translation of
those two opcodes instead read or overwrote the table itself. Correcting them
lets a spring script set game variable 14 (`004a2870`) and launch Gex.

Read-only Wine process tracing of the original and source-built replacement
found matching player state, position, velocity, and input through demo frame
189. At frame 190, the original attached Gex to a type 127 contour platform
and snapped Y from `0x033eb338` to `0x033f0000`; the replacement left the
platform pointer null and fell. The backup source for the `00434b10` collision
callback had erased field offsets and fixed-point constants. A focused source
translation of its static contour-platform branch now reads the frame's height
map and attaches the player at the calculated surface. The corrected build
matches the original's sampled player state, position, velocity, platform type,
and surface Y through frame 221. Both enter launch state 83 at frame 222 and
match those sampled fields through frame 225. At about 40 seconds, both show
the upper route, 500 points, and the same HUD count. Wall-clock screenshots
can differ by a few frames, so the frame-indexed process traces are the more
precise comparison. Local evidence includes
`.work/replacement-runtime/oracle-support-type-trace.log`,
`platform-correct-state.log`, `gamevar-repair-state.log`, and the corresponding
`attract-*-{38,40}.png` captures. The process reader and binaries are retained
only under `.work/`; the ordinary source-only build still does not read the
original executable. These are behavioral matches for this demo segment, not
whole-game proof. Most of `00434b10` still needs a proper translation for other
collision shapes and moving platforms.

The next exact player-state split was frame 409: the replacement lost health
to a type 53 enemy and moved differently from frame 411. The original enemy
was about 79 pixels left of the replacement at frame 408. Its `00433a70`
update calls path-motion function `00434260`; the backup translation of that
function calculated a step count but never applied any signed path deltas to
the object's coordinates. Its source now implements the original path cursor,
fixed-point speed and phase, signed X/Y steps, reversal markers and flags.
At frame 408 both enemy copies have X=`84475904`, Y=`43581440`, and previous
X=`84606976`. With that repair, every sampled demo frame from 220 through
430 matches in player state, position, velocity, facing flags, recorded input
and health. This comparison covers the sampled player fields and that one
enemy, not all objects or rendered pixels. The process traces are retained
under `.work/replacement-runtime/{type53-*,path-motion-*}`.

A longer comparison first found a `147457` fixed-point-unit X gap (about
2.25 pixels) at frame 568 and missed type 155 contact shortly afterward.
The original and pre-repair 430–850 traces are retained as
`.work/replacement-runtime/long-{oracle,replacement}-player.log`. A read-only
debugger capture of the original at timer 568 found the same 22-word collision
event as the replacement, with platform left edge `126353410` and player right
edge `126500867`. The original selects side-contact case 1 from the pinned
`0045b628` table; the backup source for `00434b10` had erased the old-frame
edge setup and every table mask. The source now restores the left-side
classification and its X/edge response. The pinned old-frame angle is at
object offset `0xc4` (`object[0x31]`). The read-only debugger receipt is
`.work/replacement-runtime/oracle-frame568-gdb.log`.

With that repair, the sampled player fields matched through frame 622. At
frame 623 the original landed on a type 148 spring at Y=`52887552`, but the
replacement fell through it. Both saw the same contour height and surface;
the replacement's close-range landing check rejected a crossing of more than
eight pixels in one frame. The static contour branch now checks the previous
Y against the surface as the pinned collision logic does. The sampled player
state, position, velocity, flags, input, health and support type match from
frame 175 through **700** in `.work/replacement-runtime/crossing-player.log`
against the original traces. These are behavioral comparisons of selected
fields; other object state and rendering still need comparison.

Extending that trace exposed a missing side-crawl transition at frame 727.
The source for `00421a00` had only summed a collision edge array and returned
it. The pinned PE first checks the recorded direction, probes the side wall
and adjacent heights, then stores the edge and calls `00414130`. The source
now follows those checks, including the separate upward ceiling path. The
replacement enters state 55 at frame 727 at exactly the original X and Y.
Fresh original and replacement runs match the selected player state, position,
velocity, facing flags, input field, health and support fields for every shared
sample from frame 700 through **940**. The runtime traces are retained under
`.work/replacement-runtime/sidecrawl-{oracle,player}.log`.

At frame 941 the replacement enters standing state while the original keeps
running. The first difference is a recorded Right input gap: the original pad
byte at `004a0281` stays set through frame 947, while the replacement clears
it for frames 941–945. Both playback run counters reached 8 at frame 940.
The replacement's default hit handler for a type 7 object called player damage
at timer 940. A held health powerup kept health at four, but damage set
`gNoProcess` to one. The level loop then stopped advancing the game timer
while it continued reading the recording. The original did not enter this
damage pause at that point. Temporary call-site and level-loop traces are
retained under `.work/replacement-runtime/frame941-*-game.log`.

A read-only scan at frame 940 found a type 7 object in each run. The
replacement object was at X=`184940544`, animation group 9, frame 7; the
original was at X=`186390272`, animation group 1, frame 2. Both had
Y=`39714816`. Earlier frame samples establish these as the same loaded
object: position, animation and script cursor matched through frame 905.
At frame 909 the original type 7 object contacted a type 93 object at
X=`185880576`, Y=`37715984`. Its work field became 192 and its script stayed
at the same cursor while another field counted upward. The replacement had
no type 93 contact in that vicinity, so type 7 continued its movement and
script. A wider scan of the replacement at frame 909 found no plausible type
93 object in the level-coordinate window (X 100–200 million, Y 10–60
million). A read-only breakpoint on the pinned PE's `GOB_AddObject` caught
the type 93 creation at timer 903, returning to `0042294d` inside the lash
callback `00422790`. The previous source for that callback had only a small
held-projectile position branch and omitted the ordinary firing path. The
reconstructed path uses the player's third hotspot, the original type and
sound tables, `GOB_AddObject`, and `00422580` for projectile motion. It also
restores the held-projectile callback and collision setup. The large fixed
point angle spread for projectile type 1 remains provisional.

In the first rebuilt attract trace, the replacement type 7 object now makes
type 93 contact at frame 909. Its X=`186390272`, animation group 1/frame 2,
hit work field 192 and paused script cursor match the original at that frame.
The subsequent long run reached frame 934, then faulted reading through a
pointer calculated by `00431fa0`, the type 93 draw helper. Its backup source
had turned fixed-point coordinate arithmetic into pointer reads, multiplied
frame counters by four, and assigned an address to a coordinate field. The
pinned instructions give the coordinate formula
`object position + stored offset - (random nibble << 16) + 0x70000`;
the source now uses those values and restores the frame and structure offsets
for this path. The rebuilt replacement completes the long trace without that
fault. The original and replacement each yielded 251 frame samples from 700
through 950, with **zero differences** in player state, next state, position,
velocity, facing flags, recorded input word, health, contact flag, support type,
support X and support Y. This establishes parity only for those sampled fields
in this one unattended playback, not for all objects, rendering or later play.
The sampled hit timer differs with wall-clock sampling. A subsequent
frame-1300 trace of the replacement faulted at timer 965 in
`GOB_RemoveObject`. A debugger caught the invalid recursive child pointer
`8de48d24` on a type 7 enemy object. Its sprite buffer begins at offset
`0x11c`; `00431fa0` had copied 14 surplus words after the original capped
count of 32 and overwritten object links at `0x160`. The pinned loop copies
`count - 1` words and fills only when `count < 16`. The source now follows
those bounds and writes the header word at `0x11c`. The rebuilt replacement
reaches frame 1300 without that fault. Comparing 601 player samples from
frames 700–1300 found no selected-field difference through **1291**. At
1292 the original lands on a vertically moving type 3 platform at
X=`271712256`, Y=`38273024`, while the replacement keeps falling and has
no support object. The original platform has the type 3 callback set
`00434a50`/`00434570`/`00434670`/`004355d0`. Its position and collision
state match the replacement around frames 1288–1291, including contact with
the player. At timer 1291 a debugger read the replacement collision event:
the frame has contour flag 2; its contour width is 96 and the active height
byte is 1. At frame 1292, that contour's top is platform Y minus nine pixels,
exactly the original player's grounded Y. The provisional contour handler in
`00434b10` wrongly required an unmoving platform, so it skipped this case.
Removing that restriction made the landing match through 1296. At frame 1297
the original carried Gex upward two pixels as he stepped off, while the
replacement left his Y unchanged. The pinned collision routine applies a
platform's position delta to an existing rider before checking the current
contour. That carry and its tile collision calls are restored. A fresh
frame-1300 run matches the platform landing, step off and ensuing jump.
The 601-frame field comparison found only one replacement sample at frame
914 that held the preceding frame's X and Y while its timer had advanced;
the following sample realigned. This appears to be a sampling race, not a
persistent game-state divergence. The original's first attract run reaches
timer 1823, where health is zero and the timer stops. A trace from 700 through
1823 found a persistent difference starting at 1618: both runs entered
inside-corner state 66 at 1616, but only the original applied the next corner
movement offsets. The backup source for `00411e40` advanced its phase by
`0x40`, where the pinned instructions use `0x8000`; it also dereferenced
position values as pointers and scaled the movement table index again. The
state handler now uses the original phase increment, five-entry movement rows,
fourth-frame exit and corner snap conditions. The rebuilt trace matches every selected player field
through frame **1768**, apart from a one-frame X/velocity sample at 1144 that
realigns at 1145. At frame 1769 the replacement faulted trying to execute
`025e4000`; the original continues. A debugger found fixed-point coordinates
`025e4000` and `027f4000` in the return-address slots above a call to
`004256e0`. That function allocated eight integers for `0041cb80`, which
writes ten edge values. The pinned function reserves 40 bytes. Its local edge
record now has ten integers; `00433170` had the same split six-plus-four
decompiler artifact and now uses one ten-integer record. That removed the
crash but exposed a missing movement sequence in `004256e0`: the replacement
stayed at the same Y in jump tongue-lash state 20 while the original fell
onto an object at frame 1775. The pinned routine calls the level movement
setup, vertical integration, Y tile collision, landing helpers and state
transitions after horizontal movement. The source now follows that sequence,
including its input and ceiling exits. A rebuilt source-only image links with
zero unresolved symbols and zero duplicates. The isolated attract run reaches
timer **1823** in both executables. Across 1,124 frame samples from 700 through
1823, state, next state, position, velocity, flags, input, health, contact,
support type and support position match at every frame except one X/velocity
sample at 1144 that realigns at 1145. Comparing every captured field adds
only raw support and script pointer differences at 26 and 20 frames,
respectively; their pointee behavior is outside this player-state trace.
The isolated replacement result is
`.work/replacement-runtime/lash-motion-player.log`. This confirms the sampled
player path in this unattended playback, not rendering, sound, every object
or other gameplay paths.

The earlier scans are retained as
`.work/replacement-runtime/type7-{oracle,replacement}.log`,
`type7-progress-{oracle,replacement}.log`,
`type7-900-{oracle,replacement}.log`, `type7-partner-oracle.log`, and
`type93-global-replacement.log`.
The isolated captures are `.work/replacement-runtime/pad-{oracle,replacement}.log`
and `record-{oracle,replacement}.log`. The input field in the earlier player
traces is a separate word, so its equality did not establish pad-byte parity.

The attract run identified source faults: a doubly scaled camera history
index; cache pointers addressed two or four bytes too early and incorrect
LRU links; quad lookup offsets scaled fourfold by C pointer arithmetic;
an old-frame animation accessor reading the wrong structure offsets; and a
player collision path and help-box animation treating fixed-point values as
pointers. The player collision processor also copied 129 words into a
20-word local array and gave fields within that copy separate uninitialized
storage; its stack-record layout is now restored. These
repairs are behavioral candidates, not verifier byte proofs. The player
state path also lacked the original's map transition and second processing
call after clearing super-speed input; these have been restored from pinned
instructions. Further timed comparisons are needed to isolate the remaining
demo movement, collision and rendering differences. Pressing Start and
normal level selection need another comparison after these fixes.

The title-screen X path now reaches the world map without the dark polygon
that previously covered its wheel. Two source errors caused the visible
differences. `0040d890` discarded the separator pointer that the help-box
drawer uses to advance through three instruction lines; its replacement source
now returns that pointer. A local 75-byte relocated probe matched the pinned
routine exactly, but this is not a published backend proof. The transparent
4-bit sprite renderer at `00445ca0` passed only one byte of a two-byte palette
identifier to `00402400`; the pinned `00445ceb` instruction reads a word.
That selected the wrong palette row for the map overlay. The rebuilt
source-only game and the pinned original were run from the same isolated assets
with the alternate launcher token, then X held at the title and pressed again on
the map. Their full 1024×768 captures matched pixel for pixel at 30 seconds
(instructions visible) and 36 seconds (instructions dismissed). Captures and
build logs remain under `.work/replacement-runtime/map-clut-{fix,oracle}-*`.
These two frames establish this focused rendering path, not complete gameplay
parity.

The cemetery world-map movement path had another source-width error in
`0042b7f0`. The four directional just-pressed flags at `004a028f` through
`004a0292`, and four related input flags, were declared as 32-bit integers.
The pinned instructions at `0042bbf2` through `0042bc87` read each flag with
`mov al, byte ptr [...]`. A Right or Up press therefore also made the
replacement's earlier Left check appear true, selecting the wrong map link.
The level access flag at `004577b1` likewise needs byte indexing; the pinned
instruction at `0042baf7` reads one byte at `004577b1 + level * 8`.
The source declarations now use byte types. With the same X, X, Right, Up
sequence in isolated Wine runs, the original and source-built game both moved
Gex from the lower path to the right TV. The 30×30 pixel region around Gex
matched exactly in the Right and Up captures. The captures and source-only
build log remain under `.work/replacement-runtime/move-{oracle2,fixed}-*` and
`map-movement-build.log`. This validates that map route and input sequence;
other map links and level transitions still need comparison.

The graveyard map's brief horizontal corruption during downward movement was
reproduced with dense captures after entering the map, then pressing Left, Up,
Right and Down. A temporary trace found horizontal scale `20497340` (about
313 times normal), producing sprite bounds from roughly -3,500 to +7,100 pixels.
`0042c860` had declared `GXObject_00463b70_gob_xScale` as a scalar even though
its binding denotes the object base. It read the object's first pointer as
the scale. The pinned loads at `0042c8a5` and the other direction branches
read `00463c38`, the member at byte offset `0xc8`. The source now indexes that
member, consistent with `0042ca40`, without changing the binding.
`tests/map_player_direction.py` compares the linked routine's complete object
updates and direction-step global with the pinned original for 867 cases.
It requires `pefile` and `unicorn`, and a fresh replacement build; it publishes
no backend proof. Temporary tracing was removed from the final source.
The clean rebuilt executable replayed the same movement sequence: eight of
30 old downward-transition captures contained a wide band, versus zero of
30 fixed captures. The final build linked with zero unresolved symbols and
was staged at `.work/replacement-run/game/GEX.exe`. This validates the
reproduced map transition, not all gameplay.

The same investigation completed repairs to `00442e50`'s rotation-table
indices, signs and quarter-turn lookup bases. This was a separate defect:
repairing rotation alone did not remove the map band.
`tests/sprite_rotation.py` compares 8,196 compiled rotation cases with the
pinned original. Build logs, diagnostic traces and before/after captures are
retained locally under `.work/map-render-debug/`.

The downward-facing wall sprite exposed another error in `00441150`'s rotated
tile writer. Its endpoint paths cast the X component alone into a packed point,
discarding Y; the interpolation paths packed both components. The original
instructions at `00442454` and `00442466` load complete 32-bit X/Y pairs.
All sixteen endpoint selections now preserve both signed 16-bit coordinates.
Previously a synthetic upside-down sprite produced Y=0 at every corner and
was clipped away; the corrected 80-byte paired draw commands agree with the
pinned original across all 44 cases in `tests/rotated_sprite_commands.py`.
Those cases cover eleven angles, full tiles and partially interpolated tiles,
using identical frame-lookup and colour-conversion stubs in both executables.

A separate Wine/GDB check forced the live graveyard player's draw angle to
`0x800000` in the old and fixed processes. Retained command traces confirm
that actual player tiles likewise lost endpoint Y values before and preserve
them afterward. Initial full-frame captures were identical and do not establish
a visual before/after result. This is a controlled rendering check, not a replay
of the user's exact wall position. The debugger-only changes are absent from
the saved executable. The clean source-only build linked with zero unresolved
symbols; captures, scripts and build logs remain local under
`.work/wall-sprite-debug/`. The corrected executable is staged at
`.work/replacement-run/game/GEX.exe`; the 867 map-direction and 8,196 rotation
cases also remain passing.

Grave4's exit-TV crash was reproduced in an isolated Wine/GDB run by loading
level ID 3 and requesting the normal completion transition through
`00456af8 = 4`. After the exit animation, `PAL_WaitForFade_0043f580` divided
by zero while processing a blue help-box rectangle on an already black frame.
The underlying error was in `HelpBoxDraw_0040d980`: hidden state 0 and closing
delay state 5 incorrectly fell through to rectangle drawing. The pinned
original's jump table at `0040dd7c` sends state 0 to its return, and the branch
at `0040dcb6` returns throughout state 5. Restoring those returns removes the
spurious rectangle without changing the fade routine.

`tests/help_box_draw.py` compares object updates and rectangle/removal calls
with the pinned original in 192 cases, four ticks per case. It covers hidden,
opening, visible and closing states with several countdowns and dimensions;
graphics calls are boundary stubs, so this is behavioral evidence, not a
byte-match proof. The fixed live run passed the formerly failing black fade,
ran 30 frames of the results level (68), then returned to graveyard map 49.
The harness set the level-done flag on results frame 30 and stopped after
three map frames. It exercises the real transition code with debugger-set
entry conditions, not a manual traversal into the TV. No debugger overrides
are included in the staged executable. Build, before/after traces and the
local receipt are retained under `.work/exit-crash-debug/`; the 867 map,
8,196 rotation and 44 rotated-command regression cases also pass.

`image_data.s` is a **textual, generated data source**, not a recovered set of
historical declarations. It contains 1,536 `.rdata` bytes, 71,680 raw
`.data` bytes, the 269,536-byte zero-initialized tail, and 2,683 symbolic
pointer relocations. The one-time development generator
`tools/generate_image_data_source.py` checks the pinned EXE hash; it is not
called by the ordinary build. Before the startup adjustment, every
non-relocation byte in the two raw sections was compared with the pinned PE
(zero mismatches), and the object had all 2,685 DIR32 relocations. The current
source clears two orphan original-CRT SEH handler pointers at `.rdata`
`00450024` and `00450028`. Only the original startup at `00449bd0` referred to
that scope table; the replacement links VC4's startup instead. Its layout is
preserved, but those two pointer values intentionally differ from the original.
The replacement build now
converts four source-defined globals to external references in scratch copies,
so the generated image data has sole storage ownership. The assembler adds
185 symbol-only aliases for source-referenced addresses within the checked-in
data; it changes no initialized bytes.

Sixty-seven function sources contain original image-address literals. The
replacement build rewrites their 270 distinct in-image addresses into symbolic
relocations in scratch copies, so relinking does not leave pointers back to the
old image base. These replacements still need semantic review, particularly
function pointers and interior code addresses.

`image_resources.s` is a second textual source bridge for the 313,856-byte
Windows resource section. Its 27 resource data pointers use image-relative
COFF relocations. After assembly, all non-pointer bytes matched the pinned PE;
`./scripts/build-resource-link-smoke` links a PE that exposes the original
bitmap, icon, menu and dialog resource IDs to `wrestool` and runs under Wine.
The one-time converter
checks the pinned EXE, but ordinary builds read only the checked-in source.
The recovered VC4 linker fails internally with a source-built `.rsrc` object
(`ZeroPad`), so the final resource-bearing link currently uses LLD plus modern
Win32 import archives. This keeps VC4 CL for per-function code generation.

## What Yodecomp demonstrates

[Yodecomp's methodology](https://github.com/shinyquagsire23/Yodecomp#methodology)
uses Ghidra, recovered toolchain settings, buildable source and a running game
as a milestone; its author says byte matching was paused after diminishing
returns. Its [build guide](https://github.com/shinyquagsire23/Yodecomp/blob/main/BUILDING.md)
also shows a separate resource pipeline and gameplay validation. Gex needs the
same whole-game and behavior work. Our requested build is stricter on inputs:
Yodecomp currently extracts resources from a supplied original executable at
configure time, while Gex's replacement build must carry resource source and
compile without the original executable.

`./tools/link_inventory.py` remains a quick source-only lexical survey. Its
counts are leads, not linker results; use the COFF census and full link above
for build readiness.

`./scripts/name-ghidra-functions` reads the live Ghidra function list and
matches each source filename's eight-digit address to a function name. It
renames the definitions in `src/functions/` and writes the name map to
`src/replacement/function_names.tsv`. It retains a snapshot under
`.work/replacement-named/`. An offline Ghidra inventory can be supplied with
`--inventory JSON`. The current map names 1,236 sources from Ghidra and gives
14 source addresses without Ghidra entries an address-based fallback. It
sanitizes three names that are not C identifiers and disambiguates the two
Ghidra functions both named `__atodbl`.

The build exports the mapped names. `_exit` at `00449780` gets an address
suffix because VC4's `libc.lib` defines the same decorated `__exit` symbol.
Current callers use several different names and calling conventions for the
same address. The COFF address rebinder reconciles their shared address
identities for the source-only game link.

The current pass wired the pinned DirectDraw and DirectSound import thunks to
their stdcall import-library entries, mapped original image-base references to
LLD's actual PE image base, and resolved four known CRT/debug aliases. Source
implementations now cover the 13-byte `00431820` callback that sets
`DAT_00463fe0` and the 15-byte `00437f00` async-read completion callback.
Both were recovered from their complete original instruction spans; neither
is claimed as an exact verifier proof or as gameplay validation.

The Windows startup path now has compiling sources for `WinMain`, `WndProc`,
registry settings, GDI setup, graphics flush, CDIO open/seek and HSV conversion.
The source
removes the original launcher token check and uses the pinned PE bytes to recover
WndProc's F4 branch missing from edited Ghidra memory. These are behavioral
candidates, not exact matches. The game entry adapter is a separate source
file; LLD links with a scratch copy of VC4 `libc.lib` that retains its Windows
startup member and removes four conflicting alternative startup members.
The current link produces `gex-source.exe`. Its startup path reaches the
opening AVI and title sequence; gameplay behavior is still under review.
Source bodies for VC4 `_x_ismbbtype`, `_flsall` and `_doexit` now resolve the
multibyte, stream-flush and exit references. They are source reconstruction
candidates and have not been promoted to verifier proofs.

Seven new function sources came from this work: `0041a380` is a fresh 122-byte
exact verifier proof derived from the already exact `0041a500` layout and
fallback shape; `00409740` is a behavior-focused tracked-memory free routine.
The latter uses `DebugBreak()` for the original inline `INT 3`, so its normal
path is reconstructed but it is not byte-exact. The remaining five new sources
are the bubble callback and three rendering helpers described above.

## Work to reach a playable image

1. **Link map and shared interfaces.** Ghidra-named exports and COFF
   normalization now link address-bearing calls. Audit calling conventions,
   source-defined data ownership and indirect calls, then form real shared
   translation units.
2. **Code coverage.** Turn provisional and parked source into compilable,
   reviewed implementations. Continue the startup, window, graphics, sound,
   input and save paths. Complete or link the CRT and import thunks through
   their appropriate libraries. Keep exact proofs as regression evidence.
3. **Data and resources.** Raw initialized/zero data and Windows resources are
   in textual source bridges. Recover semantic structures and resource scripts,
   then review the scratch-build storage/address rewrites. A clean build cannot
   extract these from the original EXE. The
   game's separately supplied asset files may remain runtime inputs.
4. **Game link.** The PE now links with zero unresolved symbols. Static
   initializers, resource IDs, imports and section contracts need runtime review.
5. **Behavior comparison.** Run repeatable original-versus-replacement cases
   for startup, menus, input, level loading, movement, collision, audio,
   saves and exit. Record expected state/output and fix divergences. Byte
   matching remains a useful local oracle, while gameplay parity is the
   acceptance target.

## Current constraints

The hand-decompilation checkpoint was 1,101 exact functions / 180,028 bytes
(`docs/claude-hand-decomp.md`); `0041a380` added one normal verifier proof.
Before renaming, the live service reported **1,102 exact functions / 180,150
bytes**. The retained records are historical evidence; their source hashes
changed, so current byte-match status requires fresh verification under a
compatible verifier.
The edited Ghidra analysis blocks three
important bodies (`WndProc`, `WinMain`, `GFX_OpenGraphics`). Original PE bytes
can be inspected read-only, but the analysis is not to be repaired in place.
The current source policy forbids inline assembly in matching translation
units, so some hand-written routines need either a justified equivalent or a
deliberate policy decision before byte-exact reconstruction.

The assessment retains a diagnostic-main link and links the real Windows
startup path. The title and attract demo now run, but matching gameplay is
unfinished. No model campaign, backend deployment or Ghidra modification
was part of this build milestone.
