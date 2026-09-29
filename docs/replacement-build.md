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

The PE starts under Wine with the original launcher token
`XAchWieGutDasKeinerWeis`. The alternate token
`JAchWieGutDasKeinerWeis` also passes the launcher gate and skips both AVI
clips in the pinned original. Original instructions at `00405edc` write 1 to
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
million). The next target is the type 93 introduction or its precursor, not
the faithful default hit-handler condition. The scans are retained as
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
keeps the original launcher token check and uses the pinned PE bytes to recover
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
