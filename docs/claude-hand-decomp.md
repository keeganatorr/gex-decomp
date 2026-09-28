# Hand decompilation by Claude, and what it taught the tooling — 2026-09-25/28

No campaign, no provider calls from the loop: one interactive agent (Claude,
in a Nexus/Claude Code session) decompiling functions directly with a fast
scratch compiler, then publishing through the normal durable queue.

**Result: 752 → 1074 exact proofs, 63,353 → 166,735 exact bytes (+322 / +103,382),
all game code (CRT at 0x449000+ skipped on purpose).**
Every proof is a current `scripts/verify` receipt under
`.work/claude-hand-decomp-20260925/` (`verify-<address>.json`, sources, prior
working sources). Compiler, Ghidra and proof status were never edited. The
project.json changes are ten reviewed config batches (`config-batch-1..10/`,
each with a backup and a README naming the evidence): symbol bindings proved
by original operands, and per-function `language: c` or `targetSymbol`
overrides for bodies that only C compiles or that are `__stdcall`.

The first pass (752 → 773, table below) was mostly symbol numbering. The later
passes were mostly *source shapes*: code that means the same thing but compiles
differently. They are written up as executable recipes in
[knowledge/source-shapes.md](knowledge/source-shapes.md) and
[knowledge/recipes.json](knowledge/recipes.json) (56 checks against the pinned
compiler, `tests/knowledge_checks.py`).

| Function | Bytes | Before | Lever |
|---|---:|---:|---|
| `0042dcf0` Object_unk | 27 | 63.0% (21 attempts, 96-variant search) | declaration order |
| `0043b9e0` ob259DoIt | 398 | 99.5% | declaration order |
| `004196e0` GOB_AddObjectByIndex | 344 | 99.4% | declaration order |
| `004237c0` pStateUnk | 53 | 92.5% | reverse declaration order (1 of 24) |
| `00419520` GOB_RemoveObject | 175 | 97.7% | 6 padding declarations |
| `00423800` pStateUnk | 264 | 99.2% | 6 padding |
| `00429190` | 102 | 98.0% | 6 padding |
| `0042e8b0` Call_Event_call | 126 | 99.2% | 1 padding |
| `00437010` RezOutDraw2 | 350 | 99.4% | 3 padding (schedule difference) |
| `00439090` GOB_ProcessXPositionChange | 63 | 85.7% | 8 padding |
| `0040f1d0` GetGlueDist | 138 | 95.7% | 1 padding |
| `004018b0` LoadVFX | 225 | 97.3% | 2 padding |
| `0041e7e0` CLD_AddObjectCollision | 157 | 93.0% | 2 padding |
| `004195d0` GOB_AddObject | 257 | 92.2% | 1 padding (also matches as C) |
| `004404b0` | 82 | 43.4% | 2 padding (also matches as C) |
| `00429b40` RemoteFindWithLevel | 63 | 90.5% | 10 padding |
| `00433590` SCRIPT_DoEvent | 85 | 95.3% | 14 padding |
| `004390d0` GOB_ProcessYPositionChange | 63 | 93.7% | natural field access |
| `004213f0` GexMovementLeftAndRight | 213 | 98.6% | natural if/else + fields |
| `00421820` pStateUnk_Duck | 127 | 95.3% | one 40-byte local buffer |
| `00431900` Movement_unk | 137 | 96.4% | natural field access (the retained source used `volatile` to force a load) |

Later passes, by the lever that decided the last bytes (examples; the full
list is the `sources/` directory):

| Lever | Examples |
|---|---|
| ternary select for a bit move (`(f & 0x80000000 ? 8 : 0)`) | 20 `InitPlayerSide*` functions |
| cast of the shifted value (`(unsigned char)(x >> 8) & 8`) | `00438e40`, `00438ea0`, `00438f00` |
| PSX GPU macros: `setlen` bitfield through the tag pointer, `p++; *p = p[-1]` prim copies, pool allocator | `0043fb40`, `0043f080`, `0043f7f0` |
| join-point returns, else branches placed last, `if (a && b); else if (a)` | `0040b460`, `00403030`, `00423dc0` |
| reusing a spilled local for a second value (frame one slot smaller) | `00437790`, `00417500` |
| joint statement × declaration order (`tools/jointperm.py`) | `00437790`, `00419870`, `00433ec0` |
| `unsigned short` field for `test byte ptr [mem], k` | `0040a660` |
| separate `hits \|= f() ? k : 0;` statements (a `\|` chain evaluates right to left) | `00420960` |
| `__stdcall` DLGPROC with `targetSymbol _GEX_Target@16` | `00407330`, `00407710`, `00407f80` |

## What the problems were

1. **The loop cannot iterate.** A model gets one compile per turn and a turn
   costs minutes; matching VC4 output needs dozens to hundreds of compiles.
   With a warm Wine server one compile costs ~0.1 s. `tools/probe.py` and
   `tools/perturb.py` exist for that; the backend now runs the perturbation
   itself (below).
2. **Most near misses were not source problems.** Operand order, register
   choice and even instruction schedule follow the compiler's internal symbol
   numbering, which unused declarations and declaration order move and body
   edits cannot ([knowledge/symbol-numbering.md](knowledge/symbol-numbering.md)).
   Semantic search families and model turns spent on these were wasted.
3. **Ghidra shapes the source badly.** `GXObject **` parameters, cached-field
   locals, goto-shaped control flow and split stack buffers each produced a
   stuck near miss; natural code with Ghidra's own member names matched on
   the first compile ([knowledge/natural-field-access.md](knowledge/natural-field-access.md)).
   Loop prompts carry no struct layouts, and the prompt forbade "padding tricks".
4. **Less residue is the compiler than it looked.** The executable was linked
   by linker 4.20 on 1996-09-12 (VC++ 4.2 era); the pinned compiler is CL
   10.00 (VC++ 4.0). The two idioms first listed as toolchain limits after a
   "reviewed negative search" — the narrow bit-31 mask (31 functions) and the
   high-byte bit test (3) — were both source shapes the search had not tried:
   a ternary and a cast. What remains is inline assembly (policy), noreturn
   `_exit` tails and a few schedules
   ([knowledge/toolchain-limits.md](knowledge/toolchain-limits.md)). A negative
   search over arithmetic spellings says nothing about control-flow or cast
   spellings.
5. **Score is not semantics.** `0042de50`'s 93.9% best passes both arguments
   swapped; the correct source scores 81.8%. Best-score preservation keeps the
   wrong one.
6. **`scripts/verify` reported five fresh exact proofs as "no current proof"
   (exit 2).** The client re-checked used bindings against project.json only;
   symbols resolved through the pinned symbol index failed that check. Fixed in
   pc-decomp `RemoteClient.ProofCurrent` (not yet deployed; the published
   proofs were always current in the service).
7. **Interactive Ghidra MCP was dead.** The Claude desktop config runs the old
   `GhidraMCP/bridge_mcp_ghidra.py --ghidra-server http://127.0.0.1:8080/`;
   Ghidra listens on 8089 with the newer plugin, which the shared bridge
   (`~/src/ghidra-mcp`, default 8089) already speaks. Agents fell back to raw
   HTTP (`/decompile_function`, `/get_struct_layout`).

## What changed

Later passes added: `tools/shapes.py` (expression-shape hill climb),
`tools/jointperm.py` (statement × declaration order), a staged
`tools/solve.sh` pipeline (perturb → lperm → jointperm → shapes → statement
moves → perturb), `PROBE_BIND` / `PROBE_OVERRIDE` environment trials in
`tools/probe.py` (a binding or a functionOverrides entry tried before it is
added to project.json), and `tools/idiom_scan.py` rules.

The last pass (1036 → 1061) added `PROBE_METRIC=aligned` (score by instruction
text with branch targets normalised, so a fix that shifts later code does not
read as a regression), `tools/rankvariants.py` (rank whole-file variants by
normalised instruction diff), `tools/storeperm.py` (every order of each run of
up to seven straight-line assignments) and `tools/sinmacro.py`. Its wins were
mostly structural: a callback message that was really the head of a
`HitRecord` (0041e190, 1064 bytes), `if (g) m = 1; else m = 0;` for a
store-before-test (0040c4d0, 0040c210), a nested struct behind an unfolded
`lea` (0040f740), a spilled loop invariant mistaken for a short local
(00441010), and re-running `storeperm` and large pad counts over old near
misses (004248e0, 004263b0, 00442de0, 0040f170, 0041d0e0). See
[knowledge/source-shapes.md](knowledge/source-shapes.md), "Stack frames" and
"Search order that worked".

The pass after that (1061 → 1072) added `tools/declshuffle.py`, which
shuffles whole declaration groups (locals, extern data, prototypes) rather
than moving one line, plus config batch 10 (two bindings and a C front-end
override for 00420300). Most of its wins came from reading the target for code
the original kept: a macro expansion whose results one path never uses
(00438470), a tail written out twice (00437f40), an assignment repeated in
both arms so CL hoists it (00426690), a range test that is a `switch`
(00415e80, still one line off), and call results or loop indices routed
through a local or an index so CL picks the target's register (00438470,
0040c110). Two operand-order diffs were settled by the order of two `extern`
lines (0040a010). New shapes are in the source-shapes tables.

The next pass went to the largest open game function, `00435d90`
GOB_RunScript (3.6 KB, a 61-case script interpreter), and to the tooling a
function that size needs. Whole-function scores were useless there: the
positional match stayed near 30% whatever changed, because one register
choice shifts every later offset. `tools/casediff.py` splits both sides at
the jump table and scores each case separately, optionally through an
`esi`/`edi` rename. A throwaway generator with alternative bodies per case,
searched jointly with local and `extern` declaration order and local types,
took the per-case mismatch count from 231 lines to 2. The source-shapes
tables record what moved it: `p++; v = p[-1]` versus `v = *p++`, the flag
assignment order, an `int` loop index, integer address arithmetic, a local
copy of the object parameter, one `unsigned char` temporary per case, and
above all conversions: a cast or an implicit `int`/`unsigned` conversion puts
its operand second in a `cmp` or `xor` and decides what CSE may reuse.
The two instructions left (an `and`/`inc` order at the dispatch and one
reload) are in the parked list. The same method, packaged as
`tools/altsearch.py` (alternatives marked inline with `/*ALT*/ … /*OR*/ …
/*END*/`), then matched `00427d30` PlayerSideCrawl (3,820 bytes, 16-case
switch) in one pass: 166 lines to exact from one initialisation order and
one pair of argument temporaries. `tools/shapes.py` learned the
single-bit-test spelling that matched `00421740`.

First pass:

- gex-decomp: `tools/probe.py`, `tools/perturb.py`, `tools/ghidra_struct.py`,
  `tools/idiom_scan.py`; the executable knowledge base `docs/knowledge/`
  (`recipes.json` + `tests/knowledge_checks.py`, 15 checks against the real
  compiler); `docs/memory/knowledge-lessons.json` for schema-7 memory.
- pc-decomp: `Perturbation.cs` — after a compiled same-body near miss
  (operand-order, register-rename, or same-length ≥ 75% general), the loop
  searches declaration orders and padding provider-free, verifies the winner
  from scratch and publishes it like any proposal. Opt-in per project:
  `"policy": {"perturbationSearch": {"maxProbes": 160, "maxSeconds": 90}}`.
  Capability `loop-perturbation-v1`. Diagnostics and prompt now describe the
  lever instead of forbidding "padding tricks". `RemoteClient.ProofCurrent`
  fix. Selftests and every integration suite pass, plus a new
  `--perturbation-only` end-to-end suite.

Not deployed: the running service is still the staged
`function-time-b3b4984fd40aa68a`; activating needs an immutable stage, a
service restart and the project.json opt-in.

## Left alone on purpose

- CRT functions (78 unmatched in 0x449000+, 19.7 KB): Microsoft's CRT source is
  on disk (`NTSource/base/crts/crtw32`) and compiles to exact bytes as C with
  `/O2 /G3` for 16 of 19 tried, some needing bindings for CRT globals (`errno`,
  `_iob`, `__sbh_threshold`, …). Deprioritised by the operator; drafts in
  `.work/claude-hand-decomp-20260925/crt-leads/`, nothing published.
- Inline assembly: every open function with an `ebp` frame under `/Oy`
  (DrawTilesInner*, InnerGraphicsTiles*, the `int 3` asserts, `bsf`) and the
  hand-written span loops (`shr ecx, 1; je; jae`). Policy forbids inline asm.
- Parked near misses with the reason recorded: `00447680` (97.8%, param load
  order), `00434260` (97.4%, one load one slot early), `00421a00` (91.9%,
  a reload after a store through the object), `00440a30`, `00444590`,
  `004256e0` (block placement of a goto target), `0040ad40` (constant held in
  a register across the loop), `00434190`, `00428e50`, `004130a0` and others.
