# Gex matching decompilation

This is the new source-reconstruction project, not the existing SDL/pemod port.
Do not modify ../pc-decomp-agent-csharp, GexReverseProject, backups or the installed
GOG game. Do not use removed legacy C# commands or its claimed MSVC 2010 version.

Target SHA256: e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86.
Source EXE: /home/keegan/.wine/drive_c/GOG Games/Gex/GEX.exe.
The backend owns a read-only pinned copy under .work/. No binaries, database,
Ghidra exports or compiled artifacts may be committed or published.

## Latest bounded campaign / loop audit

Latest run: `docs/luna6-ten-functions.md`, `loop-f2cf827017ec5bb6a8f10f57`:
GPT-6 Luna/max, ten closest eligible functions, eight reconstruction iterations
plus investigation, ten lanes, one pass/30-minute ceiling. Finished **Blocked /
drained** after 17m 41s, **4 exact / +545 bytes → 752 exact / 63,353 bytes**.
All 748 pre-run proof/source identities preserved; zero active/queued work, no
automatic Resume or renewal. Catalog refreshed with `pi update --models`; do not
substitute GPT-5.6 or invent an alias. Retained local audit:
`.work/luna6-ten-20260923/`. Successful declaration-order and typed-pointer repairs
are compiler-specific, not recovered historical types. AH-load variants and
`00431900` scheduling rewrites saturated identical resolved outputs: read the
failure ledger before another run. Six deferred rows ended `Stubbed`/null current
match; their historical best scores are NOT current proof. The Astra audit below
is an earlier checkpoint, not the current count.

`docs/astra-loop-audit.md` records `loop-934da8537fb606c616423ead`, one authorised
50-function astra/high campaign with 10 lanes, terminal LimitReached at its first
pass after 24m 50s. **740 exact / 61,108 bytes**, +38 / +9,634; all 702 baseline
proof/source identities preserved. Reported $61.247258 / 13,890,903 tokens is
provider metadata with unknownUsage=true, not a subscription bill. No second run
is authorised. Diagnostic/closest-first fixes (d286452) are now activated as
immutable `astra-loop-d286452-cec8d7ff8e72`; systemd service, Nexus service launch
and `.work/backend-current` all point there. All 740 proof identities and 1,088
source hashes survived activation. See `docs/astra-loop-activation.md` for receipt
and rollback. Historical deployment sections below are not current proof counts;
always query the socket before controls. The source checkpoint is 360ea3b.

## Authority

Nexus owns agents/sessions/MCP/UI. ../pc-decomp owns compiler jobs, SQLite and proof.
Use scripts/backend (offline read/import/verify) or scripts/verify (online queue).
Never manipulate decomp.db directly or claim a match by editing its status.
The service runs as pc-decomp-gex.service with one verifier. Its optional bounded
proposal loop uses Nexus-owned agents and requires explicit models, limits and
Play. Activation alone never starts a campaign.

## Current match-priority deployment (schema 6)

Backend/UI `match-priority-32f300ed5eb81d03` activated; service and CLI link use
`/home/keegan/.local/state/pc-decomp/staged/match-priority-32f300ed5eb81d03/backend`.
Function selection and automatic dispatch now sort lowest current relocated
byte-match percentage first (unknown/stale first), then shortest function, then
address. The Functions sort menu also exposes `matchPercent` with the same length
secondary key. Receipt `.work/match-priority-activation-32f300ed5eb81d03/activation.json`.
No campaign was started/resumed; current campaign remains Stopped with zero work.

## Previous same-session repair deployment (schema 6)

Backend/UI `session-repair-e3b19e240e398dd4` activated; service and CLI link use
`/home/keegan/.local/state/pc-decomp/staged/session-repair-e3b19e240e398dd4/backend`.
Live Nexus host/runtime `stable-30eea9c66bb1` matches the frozen staged hashes.
Only project schema changed (5→6); compiler, bindings and other config are unchanged.
All 641 current exact proofs / 35,146 exact bytes, their histories and all source
hashes were preserved. Receipt `.work/session-repair-activation-e3b19e240e398dd4/`;
see `docs/session-repair.md` and `../pc-decomp/docs/session-repair.md`.
No campaign was started/resumed: `loop-77482146e96fa7384514b060` remained Stopped,
zero active/queued work. Recheck live state before any control. Same-session repair
must be selected explicitly for a new run: one model, default 600-second shared
function budget under the overall limit. Existing policies are not reinterpreted.
Do not automatically start paid work or reset budgets. Stop/drain persistent runs
with this compatible backend before any rollback; never restore an old DB over
new durable commands. All deployment sections below are historical.

## Prior batch reconstruction deployment (schema 5)

Previous backend `function-prompt-1965650bce139a03`, project schema **5**; extension
`atlas-tint-2b923e55c8e5e9e8` tints whole cells grey→green. Service and CLI link use
`/home/keegan/.local/state/pc-decomp/staged/function-prompt-1965650bce139a03/backend`.
Function-sized prompts now contain code/target asm/compiler feedback and relevant
bindings only, with cited (not dumped) evidence. Verifier still owns the full map
and all proof/receipt checks. Retained-request audit: 74,457→3,771 characters,
2,127→0 irrelevant bindings; no new model run. Receipt `.work/function-prompt-fix/`;
see `../pc-decomp/docs/function-prompts.md`. The WebSocket error is not proven fixed.
This backend fixes smallest-first batch ordering and schema >=3 ownership validity
(31 excluded records restored; 847 unresolved eligible functions before this run).
One explicitly approved run is `loop-2a359fd951223a7126881ceb`: first 100 eligible
unresolved functions (8–61 bytes), Luna/max, one lane, 300s/request, 3600s total,
200,000 reported tokens, bounded repair/revisit. Durable monitor, command receipts
and eventual summary live in `.work/smallest-batch-bd58b165f8a55359/`. Never replay
its Start or automatically resume/extend it. Consult live state/summary before
claiming it is active or terminal. Outcome is terminal **LimitReached** after the
first request failed with **WebSocket error** (~165s, unknown usage); no proposals,
compiler jobs, source changes or new matches. All 445 proofs preserved. Worker
and monitor exited. `docs/smallest-batch-luna.md` records the result and the separate
65 KB full-binding-map prompt overhead. Do not retry/Resume without fresh approval.
Recovered 453 partial current-source candidate comparisons from validated retained
attempt history; `00427b80` now paints 96.58% green. All 445 exact proofs, source
hashes and terminal campaign preserved. Receipt:
`.work/atlas-recovery-02996291cf2ccbbb/activation.json`.
`../pc-decomp/docs/batch-repair.md` explains pseudocode-first
reconstruction, private hypotheses (never auto-shared), bounded evidence repair,
deferred blockers and dependency revisits. Atlas uses current-basis matchPercent,
not historical bestScore, for proportional green. All 445 proofs / 16,730 bytes
and all source hashes survived activation. Receipt:
`.work/batch-activation-f5934f4a1e98b791/activation.json`. No paid batch was started.
Older release paths below are historical. Stop/drain with a schema-5-capable backend
before rollback; never Resume batchRepair on an older binary.

## Prior evidence workflow deployment

`docs/evidence-workflow.md` records activated candidate `evidence-a901b74f868a6b12`.
Project schema is now 4; compiler/bindings and all 445 exact proofs / 16,730 bytes
were preserved. Service and `.work/backend-current` use the immutable backend at
`/home/keegan/.local/state/pc-decomp/staged/evidence-a901b74f868a6b12/backend`.
Earlier DLL paths below are historical. Nexus was restarted with the matching
host/runtime, and the matching release extension was activated. Old campaign stays
Stopped; a separately approved one-function Luna/max analysis smoke timed out at 120s,
with no result/proposals and unknown usage. Its run is terminal LimitReached, no
active jobs and no automatic retry. Expanded/live batch work requires new explicit
scope/model/budget approval.
Read-only collection for 00444590 succeeded; inferred layouts remain unreviewed,
and non-file-backed data windows remain omissions. No Ghidra writes or proof changes.

## Compiler

Recovered CL 10.00.5270, VC4.0-era, with /O2 /G5 /Oy /GR- through a dedicated Wine
prefix. Tool binaries and flags are fingerprinted in project.json. Original GEX
linker version is 4.20. The old notes' 'MSVC 2010' label is wrong; per-function
exact matches do not prove the compiler/version/flags for the entire game.

## Ghidra warning

MCP project Gex, active program name GEX.exe, actual DomainFile /EditedGex.
Its original-import SHA matches, but FIVE current code bytes differ from the
original across WndProc, WinMain and GFX_OpenGraphics. Do not repair, overwrite,
reimport or rename that Ghidra analysis without explicit approval. The backend
blocks those bodies. Read docs/baseline.md before reasoning about a mismatch.

## Library ownership (schema 3)

Before reconstructing, check backend `ownership` and `reconstructionEligible`.
Confirmed CRT/library and pinned-PE import thunks stay visible but are excluded
from proposals. Never infer ownership from the legacy Library status or a name.
Unknown/candidate-library functions remain eligible. Ownership does not change
source-match status or erase proofs. `docs/library-ownership.md` and its JSON
report document 28 CRT functions + 3 import thunks, leaving 873 unfinished
reconstruction targets; all 419 source proofs remain current. __fpmath is excluded
by corroborated custom-toolchain FID, NOT an exact archive-byte claim.

`library-scan`/`library-apply` run through scripts/backend under the owner lock;
stop/drain the service first. No direct DB edits. Schema 3 pins the recovered
c1032 archives and custom FID report so old backends cannot ignore exclusions.
FID scratch tooling and provenance: `docs/crt-fid.md`. No Ghidra reference writes,
assembly injection, fabricated bindings, relocation masking or bulk recompilation.
The active immutable backend is `.work/backend/parallel-738d0f450e51f142`;
activation/rollback: `.work/decomp-loop-staging/c0311f3a351aa137/activation.json`.
The prior ownership deployment remains retained for a deliberate stopped rollback.
Earlier deployment notes below are historical.

## Parallel proposal release (activated; trial stopped)

`docs/parallel-loop.md` records activated release `c0311f3a351aa137` and trial
`loop-0fbc8c03e1a344ff2a48fede`: up to ten lanes, serial compiler, 2 Luna → 2 Terra
→ 2 Sol at max, 5,400 seconds / one pass, only the eight remaining original targets.
The user relaunched Nexus; frozen host/runtime hashes and release activation were
verified. All 421 exact / 15,798 bytes were preserved before the trial. Final:
Stopped, 40 attempts, 2 exact / +56 bytes, zero active lanes. Read live
`decomp.loop` before any control; never start overlapping work.
Never start on activation alone, silently fall back, or replay an uncertain start.
Before any rollback, Stop/drain and terminalize parallel runs with the NEW backend;
an older backend cannot safely Resume a parallel policy. No bulk proof audit or
recompilation is authorized by this deployment.

## Latest exact checkpoint

`docs/smallest-hundreds.md` records the latest user-authorized smallest-first
batch: all **302** never-attempted eligible functions were covered—254 bounded
searches and 48 fail-closed blockers. The serial pinned compiler performed 5,798
probes; four exact results (`00449e10`, `004397c0`, `004187f0`, `0041fbd0`) were
published through normal verification. Alongside the focused `_flsall`,
`__ismbblead` and `assertfail` results, dependency work published
`0040fce0 OBI_CheckRemoveObject` and `00419840 GOB_RemoveMapObject`; current state
is **445 exact / 16,730 bytes**, 878 unmatched. No provider calls,
executable/Ghidra/config changes or relaxed proofs. Service active, campaign
Stopped, zero queued/running tasks. Do not interpret generic-family saturation as
disproving skipped candidates. Evidence: `.work/smallest-hundreds/` and
`.work/full-source-coverage/`.

Previous checkpoint: `docs/full-game-source-coverage.md`, provisional artifacts for
379 source-less functions and 437 exact / 16,342 bytes. Older totals below are
historical. The live service still uses the immutable parallel release.

## Bounded compiler-guided search

`docs/compiler-guided-search.md` records the approved two-target, no-provider
benchmark. `0040bc50` became exact on variant two; `0042dcf0` stayed unresolved
(96 variants, five outputs). Published through the normal queue: **424 exact /
15,882 bytes**, all previous 423 proof/source metadata records preserved without
recompilation or byte-audit sweep. No flags, bindings, executable or Ghidra changes.
`tools/source_variants.py` holds reviewed Gex-only families; host behavior tests
are not byte proofs. Backend probes never publish and must end in fresh full
verification. Optional dedicated-Wine cache cut measured compiler latency from
~3.3 s to 45–47 ms, with identical outputs. Working offline CLI:
`.work/backend/source-search-c4ed997dd21733a0/PcDecomp.dll`; live service/link stay
on the parallel release. Not yet integrated into automatic campaigns/UI. Do not
rerun the exact target or invent another budget; remaining mismatch needs a new
hypothesis. Evidence and failed cache experiments: `.work/compiler-search-transition/`.
`docs/search-hypotheses.md` records the follow-up on 20-byte `0044c690`: EAX/partial-
register provenance, resolved (not placeholder) transfer diagnostics and optional
family-local duplicate cutoffs. Return-preserving and qualified byte-read families
still emit 21 bytes, not exact; total stays 424. Latest-feedback generation refuses
an already explored hypothesis. Skipped candidates are uncompiled, never disproved.
No compiler-language or flag switch is authorized by those completed experiments.

## Source loop

1. Choose an unpatched function; inspect Ghidra via Nexus MCP with program=GEX.exe
   and verify the DomainFile/hash. Existing names/types are evidence, not proof.
2. Write src/functions/<eight-digit-lowercase-address>.cpp. Emit the symbol
   GEX_Target with a justified calling convention. Keep this baseline translation
   unit self-contained: no headers/preprocessor directives, inline assembly or
   raw-byte emission. No PCH/forced includes. Dependency snapshots are future work.
3. Declare external globals/functions explicitly. Their COFF names must have
   justified original addresses in project.json's symbolBindings. Config changes
   require stopping/restarting the service; do not change another job's environment.
4. Run ./scripts/verify ADDRESS STABLE_COMMAND_ID. Reusing an ID queries its result;
   it NEVER resends. For another intentional source attempt, use a new ID only
   after resolving any earlier uncertain operation. No new ID to hide a timeout.
5. Inspect retained attempt, compiler output and resolved-byte comparison. Do not
   mask relocations, trim inconvenient bytes or use the first RET as a boundary.
6. Commit the candidate and evidence notes. An exact match means current compiled
   function bytes including destinations matched, not proven source types or a
   reconstructed whole executable. Preserve near misses and failed attempts.

## Reconstruction notes

- Read docs/ten-functions.md for the first ten-function expansion and retained
  attempt IDs. The two byte readers are Compiles, NOT ExactMatch; ECX/EDX differ.
  Positional byte scores are not semantic scores. tests/byte_readers.py is a
  host-only behavioural check and must never promote backend proof status.
- Ghidra's EVENT_ExtractUShort pseudocode suggests a wider memory load than the
  assembly actually performs. Read instruction access widths before copying types.
- Proof currency uses the recorded per-used binding subset; unrelated binding
  changes and ownership metadata do not retire source proofs. Old whole-map proofs
  retain legacy semantics until metadata migration. Never restore status by hand.
- Import bindings name IAT pointer storage, not the local jump thunk or code in
  a DLL. `docs/iat-binding-review.md` records three pinned-PE slot identities,
  SDK-corroborated stdcall import names and the activated 179-entry PE import map.
  DirectDraw cdecl candidate uses a different COFF name and is 25 bytes versus
  the original 6 even after diagnostic relocation resolution: removing an
  unresolved-symbol error is not evidence of a match. The corrected stdcall
  revision (`.work/retained-candidate-fixes/00409876-stdcall-v1/`) still emits a
  24-byte forwarding call under baseline CL flags, not the 6-byte jump; its
  decorated target/import names are verified, but it is not a current proof.
  An opaque-entry revision *does* emit the exact 6-byte jump under the unchanged
  baseline (`docs/isolated-import-thunk-match.md`), verified twice in a separate
  project and independently audited. It retains the canonical stdcall import
  declaration but uses a C-style function-pointer cast for the private entry;
  this is a compiler-specific byte-matching surrogate, not a portable type-safe
  API wrapper. CL 10 rejects the analogous reinterpret_cast with C2152. Never
  silently turn that machine-level proof into a source-level semantics claim.
  The live binding map now includes the complete pinned-PE import map. All 409
  prior proofs were reverified under its new binding hash; no proof was restored
  manually. Former NearMatch entries remain unmatched until separately reviewed.
- CoffCode resolves unique symbols in the target section relative to the target
  entry point and COFF absolute symbols locally. Other-section symbols still
  require explicit bindings, so object-local labels are not fabricated project
  bindings. `tools/import_bindings.py` validates the pinned PE hash and SDK
  import-library spelling, then emits a read-only provenance map.
- scripts/build-baseline and the Nexus Build button still cover only the original
  two functions. They are not an all-source verification gate.

- Backup recovery is indexed in docs/backup-import-index.json and explained in
  docs/backup-import.md. Sources retain their archive path/hash. Do not trust old
  objdiff 100% reports: many mod wrappers literally emit original bytes. Compiles
  and NearMatch sources are retained starting points, never proof of fidelity.
- scan-backup stages files; verify-backup uses the existing durable queue and
  refuses external source edits. Never rerun the scanner during a running import.
  To pause, create .work/backup-import/pause and wait for the current function.
  Delete that marker to resume. tests/backup_tools.py covers uncertainty recovery.
- Live binding metadata uses a hash plus usedBindings; immutable attempt.json
  retains its original evidence. Only changed used destinations retire migrated
  proofs; exact history remains historical.

- The bounded smallest-first pass is documented in docs/smallest-pass.md and its
  per-function index. A pass outcome is not a backend status: a reconstruction
  blocker can still have an older compiling source. scripts/smallest-pass resumes
  its frozen .work/smallest-pass checkpoint; it does not start a new campaign.
  Its source/config guards and stable verification IDs must not be bypassed to
  get past an uncertain result. The runner lock scopes this pass client, not every
  possible editor or other verification client.
- Imported sizes are enclosing spans, not guaranteed complete functions. Some tiny
  entries contain only prologues; 00409970 spans 218,888 bytes and its detail exceeds
  the transport budget. Do not trim bytes or repair Ghidra in place to fit a test.
  A body ending in a call may instead be a legitimate noreturn wrapper: recover
  that callee contract rather than automatically declaring its bounds corrupt.
- Fresh proposals may use an opaque GXObject declaration for four-byte pointer-slot
  accesses. That is not a recovered object layout. Missing member layouts,
  conflicting declarations and unrecovered register inputs stay diagnostics;
  syntax checks, higher positional scores and inherited type names are not proof.
- scripts/report-smallest-pass validates its historical frozen checkpoint and now
  intentionally refuses the changed configuration. scripts/audit-current is the
  current-phase read-only auditor: it independently parses retained COFF, resolves
  DIR32/REL32, slices the pinned PE and checks source/config/compiler identities.
  The 2026-09-14 smallest follow-up confirmed that the first three unattempted
  non-thunk entries are only 11-byte NOP-terminated prefixes; preserve these
  boundary diagnostics and do not trim or retry them until complete extents and
  missing bindings are established (`docs/smallest-followup-trial.md`).
  Its report stays in .work; tests/proof_audit.py uses synthetic binaries.
- Project schema 2 enables functionOverrides (flags, c/cpp language, targetSymbol).
  Flags replace the whole global list. Source files keep the .cpp suffix even for
  C; the trusted /Tc selector and proof language field are authoritative. Old
  proofs without language mean C++. An unrelated override does not retire proof,
  but a selected override change does; migrated proofs use per-used bindings.
  Old backends must reject schema 2 rather than silently ignore overrides.
- docs/iterative-editedgex.md records the next nine matches and preserved failures.
  SCRIPT_KillPlayer forwards a second argument hidden by the callee's decompiled
  signature; inspect stack accesses, not only pseudocode. LST_InsertBefore models
  the predecessor left in EAX without claiming its historical API return type.
  SCRIPT_ShiftRight's unmasked expression is target-specific: C++ requires a count
  below 32, while the verified x86 instruction masks CL for every byte value.

The immutable backend currently runs from .work/backend/bindings-bba8b3e1a75c1d1f
(scoped compiler contracts, bounded loop, pinned reasoning and pass ceiling, plus
fail-closed local COFF resolution and the activated PE import map).
Release and rollback record: .work/reasoning-trial-20260914-204750/activation.json. The Nexus work
bridge is authorized; model order/limits and Play remain explicit user choices.
The .work/backend-current symlink is what scripts/backend resolves. The Luna
three-function trial is documented in docs/luna-three-trial.md: it ended at the
one-pass ceiling with zero gains; `_flsall` lacked a binding, VSIT retained an
18-byte NearMatch, and `__ismbblead` timed out with unknown usage. Do not repeat
those model calls without new evidence or a changed scope. Rebuild its repo
separately, test it, stage a new immutable copy and deliberately restart the user
service to deploy. Never overwrite an active DLL. Never restart Nexus to deploy it.
