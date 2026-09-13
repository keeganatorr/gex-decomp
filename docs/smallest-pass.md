# Smallest-first reconstruction pass

## Scope and result

The operator chose **one reconstruction-and-verification pass over all remaining
functions, retaining unresolved cases with specific blockers**, rather than an
unbounded effort to make the whole game exact.

The frozen starting inventory contained **981 non-exact functions**. All 981 were
assessed in ascending imported enclosing-span size, with address as the tie-breaker.
This was a conservative, mostly mechanical proposal/adaptation pass with a few
instruction-reviewed reconstructions—not 981 hand-written implementations.

| Pass outcome | Functions |
|---|---:|
| New strict ExactMatch | **18** |
| Nonmatching proposed candidates retained | **31** |
| Previous source restored after an unsuccessful/worse proposal | 26 |
| Compiler/verification blocked; no previous source to retain | 7 |
| Unchanged proposal; existing comparison retained without a redundant trial | 4 |
| Reconstruction unresolved before a new compiler trial | 858 |
| Analysis, termination, import-thunk or detail-transport blockers | 37 |
| **Total assessed** | **981** |

There were **82 new candidate verification trials** and **26 restoration
verifications**, all retained as immutable attempts. There was no new compiler
trial for the other 899 entries. In particular, the 858 reconstruction blockers
are limitations of the proposal adapter and unresolved declarations/types/ABI,
not evidence that these functions cannot be decompiled.

The 18 exact matches add **633 bytes**. Project totals are now **372 / 1,335
ExactMatch functions and 14,177 exact bytes**; 33 are NearMatch. There are **870
active source files**, up from 828: 42 additions and seven changed prior candidates.
All 354 previously exact sources remain byte-for-byte unchanged and current.
Five of the new matches are one-byte empty routines; the other 13 total 628 bytes.

The complete, size-ordered account is [smallest-pass-index.json](smallest-pass-index.json).
It records outcomes, specific diagnostics, source hashes, attempt IDs and first
byte-difference offsets. These are **pass outcomes**, not edits to backend statuses.
A reconstruction-blocked entry can still have a useful older Compiles candidate.

## New exact matches

| Address | Imported analysis name | Bytes |
|---|---|---:|
| 00405390 | TracePrintf_Debug | 1 |
| 00417960 | FUN_00417960 | 1 |
| 0041bce0 | FUN_0041BCE0 | 1 |
| 0041feb0 | FUN_0041FEB0 | 1 |
| 00449a90 | FUN_00449A90 | 1 |
| 00418af0 | SCRIPT_GetLevelStatus | 24 |
| 0040f780 | FUN_0040f780_Input | 25 |
| 004189e0 | SCRIPT_BreakTiles | 25 |
| 00418770 | SCRIPT_GetXDir | 26 |
| 00418080 | SCRIPT_LookupObjectData | 31 |
| 00418c80 | SCRIPT_SubWorkField | 34 |
| 00445350 | CalculateTileOffset_Clean1 | 38 |
| 004317b0 | FUN_004317b0_prev_gOb | 39 |
| 00418ee0 | SCRIPT_GetGlobalArrayValue | 40 |
| 00423c80 | GX_ResetRotAndScale | 42 |
| 0043f290 | FUN_0043f290_DrawWindowAlways | 63 |
| 0041a030 | GOB_DisplayObjectAtPos | 88 |
| 0040eea0 | FUN_0040eea0 | 153 |

Names are inherited analysis labels, not independently established source APIs.

## What the pass did

`scripts/smallest-pass` / `tools/smallest_pass.py` snapshot the inventory,
configuration, analysis epoch and all existing source hashes before processing.
Private copies of all 828 initial translation units preserve their exact contents.

For each entry, the client reads backend-owned detail, checks the available
instruction extent, and constructs a proposal from existing Ghidra pseudocode.
It reuses existing self-contained declarations where possible. The read-only
1,093-entry Ghidra globals snapshot provides explicit identity/address/type
metadata for additional declaration reuse. **Only already configured symbol
bindings are used**; the compiler, flags, binding map and analysis epoch did not
change. Missing bindings remain blockers instead of being replaced with hardcoded
function calls or a weakened relocation test.

Simple primitive typedefs and forward declarations can make a proposal usable.
An opaque `GXObject` declaration permits pointer-slot operations; it does **not**
invent the object's layout or permit unchecked member access/`sizeof` arithmetic.
Conflicting prototypes, missing compound types, unrecovered register inputs,
unsupported calling conventions and unresolved decompiler operations remain
explicit diagnostics. Clang checks syntax only; the historical compiler and
backend still decide every match.

Three additional candidates were reviewed directly against instructions:
`LST_InsertBefore` uses only the observed two-pointer node prefix; `SCRIPT_ShiftRight`
uses signed shift because the original is SAR; the CRT short-argument reader
returns a short rather than treating Ghidra's upper-EAX bookkeeping as source intent.
All three compiled but **remain nonmatching** after their single trial.

Unattempted declaration blockers among the first 100 entries were explicitly
reprepared as declaration support improved, preserving the earlier diagnostics.
Thus first assessments were strictly size-ordered; early preparation refinements
are not claimed to be a globally monotonic sequence of compiler dispatch sizes.
Compiled candidates did not receive an open-ended optimization search.

Each source mutation has a flushed, atomic intent checkpoint and expected source
hash. Verification uses `scripts/verify` and stable payload-bound IDs. An uncertain
operation stops the client; resuming queries that same ID. An unsuccessful proposal
restores and reverifies the prior source, not its database status. Current selection
uses exactness and positional byte score only; a higher non-exact score is **not**
a semantic improvement claim. No mismatching empty placeholder is retained as new
recovery. Source/configuration drift is refused.

## Important blockers and feedback

- **Compound types and ABI are the main remaining work.** The conservative adapter
  could not turn 858 proposals into acceptable self-contained translation units.
  Many already have compiling historical candidates. Further bulk reruns without
  recovering layouts, prototypes and decompiler operations will add little.
- **Small imported size does not always mean a small function.** Several 10–14-byte
  spans contain only a prologue and NOP, while pseudocode describes a much larger
  function. Fourteen entries need control-flow/boundary review. Another three end
  in calls and need their callee's noreturn contract established; a terminal call
  can be legitimate and is not automatically a truncated body.
- Thirteen more entries lack a proven contiguous instruction extent. Three are
  linker-generated six-byte indirect import thunks rather than ordinary C++ bodies.
- The original three edited Ghidra bodies remain blocked. No repair, reimport,
  rename or analysis mutation was performed. Any original-byte analysis should be
  separate and explicitly approved.
- `00409970` has an imported **218,888-byte enclosing span** and exceeds the
  backend's 900 KiB detail-response budget. It needs bounded artifact/extent access,
  not a larger unchecked message or an enclosing-span exactness shortcut.
- The 525,887-byte inventory total includes overlapping/enclosing spans. It is
  **not unique code coverage**, and the extreme span above materially distorts it.
- The next useful work is layout/prototype reconstruction and instruction-aware
  refinement of retained candidates, alongside bounded detail access and boundary
  review—not claiming that this pass completed the remaining game code.

## Validation and evidence

`scripts/report-smallest-pass` refuses an incomplete pass or active queued/running
work. It checked **all 372 current exact proofs**, including:

- active source hashes and immutable attempt source copies;
- retained object hashes, flags, full binding maps and compiler component hashes;
- equal original/resolved bytes, independently sliced from the pinned PE image;
- exact-set and byte-total agreement with the live backend/Atlas inventory;
- preservation of all 354 previously exact sources;
- unchanged installed GOG executable and pinned target SHA256.

All **2,461 audited backup hashes** also remain unchanged. The existing backup
safety tests and byte-reader behavioural tests pass, as do 13 new synthetic
smallest-pass tests (including external-edit refusal, interrupted installation,
uncertain-ID reuse, opaque types and independent PE slicing).

The production Nexus `LocalService` probe read all ten resource types and three
Atlas pages at the final totals. The backend remains active, with **zero running
or queued verification tasks**. Historical failed/blocked tasks remain visible;
they were not erased to make the queue look successful.

Generated translation-unit formatting is retained exactly as verified; cosmetic
whitespace cleanup was not applied after recording source hashes.

Private evidence lives under `.work/smallest-pass/` (manifest, initial sources,
details, proposals, results, command responses, validated proof index and live
probe) and `.work/attempts/`. The committed index omits original byte windows and
Ghidra exports. No game/compiler binaries, databases or compiled artifacts are
committed. No backend deployment, Nexus restart, extra agent, or autonomous
provider campaign was needed.

```sh
# Read the completed pass; a completed run is idempotent, not a fresh campaign.
./scripts/smallest-pass report
./scripts/smallest-pass run
./scripts/report-smallest-pass
python3 tests/smallest_pass.py

# To pause a run safely between functions:
touch .work/smallest-pass/pause
# Remove that marker to resume the same checkpoint, not to start a new pass.
```

This is per-function byte reconstruction. It does not establish source-level
semantics/types, a globally proven original compiler configuration, or a linked,
working reconstruction of the whole executable.
