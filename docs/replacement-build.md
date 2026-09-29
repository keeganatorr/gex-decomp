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
`00420d30`, `00418e20` and `0041fbc0`. It gives each isolated `GEX_Target`
a unique name at compile time, links their real cross-function call and three
global variables using the recovered VC4 compiler/linker and an older SDK
`kernel32.lib`, then runs the result under Wine. Its only inputs are source,
`project.json`'s toolchain contract and local toolchain libraries. Output is
ignored under `.work/replacement-link-smoke/`.

This executable is a link and runtime smoke, **not yet Gex**. It establishes
that source-only compilation, inter-function calls, data definitions and a
Windows PE link work with this toolchain. It does not establish whole-game
linkability or gameplay parity.

`./scripts/assess-replacement-link` is the current end-to-end source-only
build assessment. It compiles all **1,193** current function files with their
per-function C/C++ flags, changes COFF *symbol references* to the exports at
their justified addresses, assembles `src/replacement/image_data.s` and
`image_resources.s`, and runs both the recovered VC4 linker and a modern LLD
link with Win32 imports. The executable and all objects stay under `.work/`.
The command exits 2 while unresolved externals remain.

At this checkpoint all 1,193 function sources compile. The normalization
resolved 2,503 function-name references and 3,544 data-name references to
shared address identities. There are **zero duplicate global definitions**.
Both linkers report **69 unresolved externals**, down from 1,748 before
source/data normalization. The formerly largest call gaps, `00444590`
(`GOB_DisplayObject`) and `00441150` (scale/rotate), now have compiling behavior
candidates. The latter emits 6,684 bytes versus 7,306 original bytes; neither
is byte exact or gameplay validated. The current gaps include file I/O,
text and graphics functions, import-style thunks, CRT/debug helpers, two
pointers to CRT code interiors and image-base labels. The new `00420e60`
bubble callback, `0043dc70` graphics command writer and `0043e2c0` palette
helper are also behavior candidates, not verifier proofs. The exact list and
object-to-address map are in
`.work/replacement-short/report.json` and `object-addresses.json`.

`image_data.s` is a **textual, generated data source**, not a recovered set of
historical declarations. It contains 1,536 raw `.rdata` bytes, 71,680 raw
`.data` bytes, the 269,536-byte zero-initialized tail, and 2,685 symbolic
pointer relocations. The one-time development generator
`tools/generate_image_data_source.py` checks the pinned EXE hash; it is not
called by the ordinary build. After assembly, every non-relocation byte in
the two raw sections was compared with the pinned PE (zero mismatches), and
the object has all 2,685 DIR32 relocations. The replacement build now
converts four source-defined globals to external references in scratch copies,
so the generated image data has sole storage ownership. The matching source
files and their verifier proofs remain unchanged.

Forty-one function sources contain original image-address literals. The
replacement build rewrites their 61 distinct in-image addresses into symbolic
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

Seven new function sources came from this work: `0041a380` is a fresh 122-byte
exact verifier proof derived from the already exact `0041a500` layout and
fallback shape; `00409740` is a behavior-focused tracked-memory free routine.
The latter uses `DebugBreak()` for the original inline `INT 3`, so its normal
path is reconstructed but it is not byte-exact. The remaining five new sources
are the bubble callback and three rendering helpers described above.

## Work to reach a playable image

1. **Link map and shared interfaces.** The temporary unique-export/COFF
   normalization now links address-bearing calls. Audit calling conventions,
   source-defined data ownership and indirect calls, then replace the
   per-function `GEX_Target` model with real shared translation units.
2. **Code coverage.** Turn provisional and parked source into compilable,
   reviewed implementations. Recover the startup, window, graphics, sound,
   input and save paths. Complete or link the CRT and import thunks through
   their appropriate libraries. Keep exact proofs as regression evidence.
3. **Data and resources.** Raw initialized/zero data and Windows resources are
   in textual source bridges. Recover semantic structures and resource scripts,
   then review the scratch-build storage/address rewrites. A clean build cannot
   extract these from the original EXE. The
   game's separately supplied asset files may remain runtime inputs.
4. **Game link.** Add the real entry point and produce a replacement PE with
   zero unresolved symbols. A link alone is insufficient: static initializers,
   resource IDs, imports and section contracts must be checked at runtime.
5. **Behavior comparison.** Run repeatable original-versus-replacement cases
   for startup, menus, input, level loading, movement, collision, audio,
   saves and exit. Record expected state/output and fix divergences. Byte
   matching remains a useful local oracle, while gameplay parity is the
   acceptance target.

## Current constraints

The hand-decompilation checkpoint was 1,101 exact functions / 180,028 bytes
(`docs/claude-hand-decomp.md`); `0041a380` added one normal verifier proof.
The live service now reports **1,102 exact functions / 180,150 bytes**.
The edited Ghidra analysis blocks three
important bodies (`WndProc`, `WinMain`, `GFX_OpenGraphics`). Original PE bytes
can be inspected read-only, but the analysis is not to be repaired in place.
The current source policy forbids inline assembly in matching translation
units, so some hand-written routines need either a justified equivalent or a
deliberate policy decision before byte-exact reconstruction.

The current full link still uses the link-smoke main. Its successful completion
will be a linker milestone, not
a playable-game claim. No model campaign, backend deployment or Ghidra
modification was part of this build milestone.
