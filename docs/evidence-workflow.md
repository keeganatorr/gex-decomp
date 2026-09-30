# Evidence workflow activation

**Superseded by schema-5 batch deployment `batch-f5934f4a1e98b791`.** The active
service/CLI path is now `$HOME/.local/state/pc-decomp/staged/batch-f5934f4a1e98b791/backend`.
See `../../pc-decomp/docs/batch-validation.md` and
`.work/batch-activation-f5934f4a1e98b791/activation.json` (project-relative).
Batch mode starts from pseudocode and uses private hypotheses without waiting for
shared review; partial green is current-basis byte similarity, not historical best.
All 445 proofs/source hashes remain preserved; no paid batch started.

The following records the prior schema-4 evidence activation.

Activated immutable candidate `evidence-a901b74f868a6b12` after the operator restarted
Nexus. The loaded host bundle `stable-5bdf69b4154e` matches the staged host modules
and native runtime. The release extension passed its rendered-frame activation.
Backend/service and `.work/backend-current` now use:

`$HOME/.local/state/pc-decomp/staged/evidence-a901b74f868a6b12/backend/`

Only `schemaVersion` changed in `project.json` (3 → 4). Compiler, flags, bindings,
original executable and Ghidra were not modified. Before/after captures confirmed
all **445 exact proof/history records**, **16,730 exact bytes**, and **all source
file hashes** preserved. Original campaign remains **Stopped**, with unchanged
attempt count and zero queued/running jobs.

Activation record and stopped-owner backups:
`.work/evidence-activation-a901b74f868a6b12/activation.json` and `before-files/`.
Old parallel deployment notes describe historical versions, not the active DLL.

## Read-only collection preflight

Durable command `evidence-preflight-a901-00444590` completed without model calls or
compilation. Immutable bundle:
`ev-7e3e7a800033a76cd25fb48a219b7b5d69831e87e6c06a4d7fb574ed35296505`.

Collected pinned function observations for `00444590 GOB_DisplayObject` (615 bytes),
`0043dc70` (1,610) and `0041a500` (142), plus explicitly **unreviewed** Ghidra layout
references `DrawStructUnk` and `GXObject`. DomainFile is `/EditedGex`.
Four referenced data windows were not file-backed and remain explicit omissions;
no runtime data or guessed table contents were substituted. Other neighbors and
types remain bounded omissions, not disproved hypotheses.

The operator connected the bridge and separately approved a one-function Luna/max
analysis smoke (120s/request, 240s overall, 32,768 reported tokens, no source work).
Run `loop-52153a0e5f2c6a4ff4eafee6` ended `LimitReached` after one ~121s timeout,
empty response and unknown usage. No contracts, compilations or publication; worker
teardown confirmed, no retry/renewal. Reported transcript path did not exist; the
immutable request/response and `.work/evidence-activation-a901b74f868a6b12/smoke/summary.json`
remain. The prior campaign stays Stopped. No enlarged budget is implied.

## Safety/recovery

Schema 4 requires a compatible backend. Never roll back a live evidence/parallel
campaign into a binary that cannot understand it. Stop and drain with the new
backend first. Before any evidence campaign is created, the retained schema-3
configuration/unit/link can support a deliberate stopped rollback; do not restore
an old database over new durable commands. Do not delete uncertain command receipts.
No automatic budget renewal, campaign Resume or inferred-contract acceptance.

Backend limits and CLI: `../../pc-decomp/docs/evidence-workflow.md`.
