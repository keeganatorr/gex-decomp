# One bounded astra campaign, then a loop audit

## Outcome

| Item | Result |
|---|---:|
| Campaign | `loop-934da8537fb606c616423ead` |
| Terminal state | **LimitReached — one-pass ceiling** |
| Model | `openai-codex / gpt-6-astra`, **high** |
| Scope / parallelism | **50 functions / 10 lanes** |
| Elapsed active time | **1,489.563 s (24m 50s)** |
| Completed job records | 184 across all 50 functions |
| Proofs / bytes gained | **38 / 9,634** |
| Before | **702 exact / 51,474 bytes** |
| After | **740 exact / 61,108 bytes** |
| Reported usage | Incomplete; per-run token and cost figures omitted |
| Usage completeness | 176 known / 8 unknown job receipts |
| Work remaining active | **0 lanes; 0 queued/running verifier tasks** |

Usage metadata is incomplete. The budget was 3,600 seconds, one pass, no token cap, eight
function iterations, stagnation threshold two, evidenceWorkflow/batchRepair and
persistWorkingCandidate/continueWhileImproving enabled. No persistentRepair policy
was silently added. All 184 jobs requested astra/high; 181 receipts confirm high,
and three lost-session receipts carry no effective model-level receipt. Those
three had no compiler attempt. No second campaign or paid retry was started.

The previous campaign was terminal `LimitReached` before Start. The initially
disconnected bridge was connected by the operator. Start used the journalled ID
`astra-loop-audit-one-authorised-campaign`; receipt and intent are retained.

## Selection

Used the requested filter, including both analysis gates, not “never attempted”:

```
status != ExactMatch && reconstructionEligible && !operatorExcluded
&& !name.startsWith("_") && extentVerified && ghidraBytesEqualOriginal
&& 200 <= size <= 900
```

Excluded the documented dead-end addresses (`0042e8b0`, `0043a7c0`, `00419520`,
`0042de50`, `00417f40`, `00412750`, `00411d70`, `00411b90`, `00429190`). Selected
50 highest **current** matches among 241 qualifying candidates, with size/address
ties. Current scores ranged from 24.9027% to 99.5283%. No flags, compiler identity,
Ghidra analysis or bindings were changed. The running backend still reordered
these lowest-first; that is part of the evidence below, not a claim that this
campaign tested the patched closest-first scheduler.

## Audit of every emitted diagnostic code

All 184 retained `loopJobs` were cross-checked with their attempt IDs/outcomes;
all 168 compiler-attempt records were inspected, including retained resolved byte
streams where available. Detailed job-to-diagnosis audit, every proof ID, scope,
policy and unresolved target are in [astra-loop-audit.json](astra-loop-audit.json).
The alternate diagnostics are an **offline audit**, not mutations to old records.

| Emitted diagnostic | Count | Does the retained evidence justify it? |
|---|---:|---|
| `EXACT_MATCH` | 38 | Yes: exact publication, retained strict proof, current source/artifact hashes and equal resolved/original streams. |
| `VERIFY_BYTE_MISMATCH` | 123 | **114 yes; 9 no.** Nine are successful `Investigated` results with no attempt ID and no compilation. |
| `VERIFY_REGISTER_ALLOCATION` | 13 | **Not justified as a whole-function register mapping.** Two are immediate-only; one displacement-only; ten have mixed fields or inconsistent register uses. |
| `COMPILE_REJECTED` | 5 | **None.** Three lost-session errors, one WebSocket error, one invalid investigation response; no compiler attempt for any of them. |
| `VERIFY_UNRESOLVED_IMPORT` | 2 | Yes: compiled COFF cannot resolve `_DAT_0045b0b0` or `_LAB_00431820`; not a byte comparison. |
| `MISSING_EVIDENCE` | 2 | Yes as **model-reported limitations**, not independently proven analysis defects. These follow the two actual unresolved-symbol attempts. |
| `VERIFY_OPERAND_ORDER` | 1 | Yes as a decoded register-to-register CMP ModRM transposition, **not** semantic equivalence. `attempt-42539a4582334d9ea9fc6549bfe53fa4`. |

Thus 27 labels were misleading: 9 investigation results, 13 register-allocation
claims, and 5 supposed compile rejections. This run had **zero real compiler
rejections**; blaming astra for the reported rejection rate would be wrong.
No deadline/extent diagnostic occurred in this run; their existing regressions
remain in the test suite.

### Concrete failures and fixes

The complete defect ledger, synthetic versus live provenance, fixes, and regression
tests are in [pc-decomp's audit](../../pc-decomp/docs/astra-loop-audit.md).
Key live anchors:

- **Mixed byte fields called register allocation:** KFBossDraw
  `attempt-f4322ccf83e24a37931fde060d2f4dd6` has 12 immediate, 7 displacement,
  21 ModRM and 4 opcode differences. Both Capstone audit and the new Iced decoder
  identify the non-register fields. Pure immediate cases are
  `attempt-c98029dfcd19457888e1cac770a2c104` and
  `attempt-422523f2557b4e8cb9efc67478a68d64`; pure displacement is
  `attempt-f85f0e45c9984cf2ba47bb62952ae531`.
- **Investigation without a compile:** `work-1ee19b6e4f1649e296ba88eeedcdbd24`
  says “Investigation findings retained; return to source analysis” and has no
  attempt ID, yet emitted `VERIFY_BYTE_MISMATCH`.
- **Malformed findings are not a compiler rejection:** KFBossDraw
  `work-1e84ae087cb148bc930318bc85911328`, turn 6, emitted
  `COMPILE_REJECTED` for “Investigation must return bounded {findings:[...]} JSON”.
- **Lost conversation retried instead of paused:** `00419870`, conversation
  `conversation-5002696c44bf4a87a89ab270c00e8e17`, turns 7/8/9 returned the same
  “Persistent session lost; manual Resume required, never replay a turn”. Jobs:
  `work-183021a19ac943e988e5210dfcfa535e`,
  `work-0bc2ccdf891e4b8f85133709ef036a4d`,
  `work-47ad009496d945299c947b866f0096c2`. Backend now pauses rather than continuing
  a lost session, including when the failure arrives during Investigation.
- **Investigation action ignored:** `work-dfe6c9c770094dd5ba55ae59ea2b8337`
  recommended `INVESTIGATE_REGISTER_ALLOCATION`, but the next job
  `work-72fc60dd300f4f1a843be88addef767a` was another Reconstruction. The scheduler
  only recognized three older investigation action names.
- **Selection inversion:** frozen order starts with `0042cc90` at 24.9027%, puts
  `00427c00` at 99.0909% in slot 49 and `00413c80` at 99.5283% in slot 50.
  All were reached this time; the demonstrated defect is prioritization, not a
  claim of an unserved function in this pass. The operator explicitly approved
  **closest-first for new campaigns**. Resume keeps its saved order unchanged.

Historical retained examples additionally establish model MissingEvidence prose
being misread as compiler-contract/source-conflict/boundary evidence, and input
validation/object extraction being labelled compiler rejection. These have
regressions too. A separate synthetic publication-race test demonstrates stale
pre-publication `EXACT_MATCH` diagnostics surviving a refused publish; it now
requires the final conflict diagnosis. We do not claim that race happened here.

Candidate identity was checked, not changed unnecessarily: **21 repeated resolved
output groups / 65 attempts** contained varying object hashes. The existing
`resolvedBytesHash` stagnation check is correct and retained. Source-level dedup
before compilation and byte-output identity after compilation are distinct.

## Preservation and proof authority

Read-only final audit verified:

- Every one of the **702 baseline exact rows** remains ExactMatch with identical
  proof metadata and sourceRevision; all current source hashes still match.
- The 38 new published sources match their immutable verifier attempts; object,
  original and resolved artifact hashes match; original/resolved streams agree.
- `project.json` is unchanged (SHA-256
  `4389620d960f7109d780df51ba4c7c5f781c1e8c3decf137f9d0e41f57fefd89`).
- No active lanes/queued compiler work at the terminal checkpoint.

This is preservation and retained-evidence checking, not a new proof authority or
whole-game build. The strict verifier alone published these 38 proofs. No
relocation masking, compiler/flag changes, Ghidra edits, executable downloads,
offline live-owner verification or bulk recompilation occurred.

The source checkpoint `360ea3b` (“740 done”) was already present on branch
`audit/astra-loop` when the final audit completed; it contains the campaign's 50
source updates. It is preserved. Only 38 are exact; retained working candidates
for the other 12 are not promoted by that Git commit.

## Remaining blockers / missing evidence

- **Actual transport-loss cause is unknown.** WebSocket failure:
  `work-210d972b9c0e41f49ec2d5a8d83078f6`, session
  `21846ea1-5797-48af-9a2b-978f4b04b2db`, transcript ending in
  `2026-09-22T12-15-24-322Z_01a0c90a-d0a2-71a8-8029-4e5f16698305.jsonl`.
  Need provider close/error details and host worker exit/teardown provenance.
  The three lost-session receipts above have empty session IDs/paths: need the
  host's lifecycle record for their conversation. Backend pause is fixed; no
  speculative host/provider patch or automatic retry was made.
- **Two real unresolved symbols:** `00431470` needs a permitted, independently
  evidenced `_DAT_0045b0b0` binding or valid inventory alias; `00431830` needs the
  same for `_LAB_00431820` or an evidenced containing symbol/offset. The verifier
  rejects both because the embedded address is absent from its permitted pinned
  inventory. Do not invent addresses or relax resolution.
- **Other retained codegen misses:** `00412630`, `004263b0`, `00423800`,
  `004195d0`, `00433ec0`, `00411a90`, `004120c0`, `00434080`, `0040ea90`,
  `00419870`. Full last-attempt identities are in the JSON. Decoding identifies
  the mismatch field, not a reachable source rewrite. A new source hypothesis
  and separate paid-run approval are needed; do not repeat the documented dead
  ends or switch compiler flags.

## Tests and activation

Backend selftests and the full synthetic integration suite pass, including
strict verifier guards, multi-lane bounds, real-socket transport pause/no-retry,
publication conflict, schema validation, closest-first dispatch and investigation
routing. Test outputs and raw audit are local in `.work/astra-loop-audit/` and
`/tmp/astra-{build,test,integration}.log`.

Fixes were committed on a backend branch, then **activated after the operator's
separate “Apply fixes” request** as immutable `astra-loop-d286452-cec8d7ff8e72`,
including `Iced.dll`. All 740 proof identities and 1,088 source hashes survived;
no model work started. See [activation and rollback](astra-loop-activation.md).
Native UI and Nexus host/runtime needed no changes.
