# Luna three-function trial

Completed 2026-09-14 as a new run after the earlier multi-model trial. The live
project configuration was unchanged.

## Policy

- Model: `openai-codex/gpt-5.6-luna`
- Reasoning: `xhigh` (verified in every completed response)
- One attempt per function, one pass (`maxPasses:1`)
- 300-second overall limit; 60-second attempt ceiling
- No token cap or claimed subscription dollar cap

Run: `loop-bf9800051ba264f815c6cdff`.
Start command: `luna-three-034c892e-f335-429e-89f8-5704f9921254`.

## Results

| Function | Size | Result |
|---|---:|---|
| `FUN_0044e7e0` | 11 | Blocked: missing authoritative ABI/signature/binding for `_flsall` at `0044e7f0`. |
| `VSIT_ForcedVoiceSituationReady_0041fba0` | 18 | Compiled but bytes differed. Candidate compared 10/18 byte positions; current best historical score remains 88.89%. |
| `__ismbblead` | 18 | The bounded attempt hit its work deadline with unknown/incomplete usage; no proposal was submitted. |

The run ended at `LimitReached` after **3 attempts**, approximately 115 seconds
elapsed, with **0 exact functions and 0 bytes gained**. Reported usage was 55,655
tokens before the incomplete final request; the run is marked `unknownUsage:true`.
No repeat pass was dispatched.

The VSIT candidate's full strict comparison was:

- Pinned: `33c08b0ddc3946003b0dd0024a000f94c0c3`
- Candidate: `33c08b15d0024a003b15dc3946000f94c0c3`

The differing register allocation is retained as a NearMatch attempt; it was not
promoted. No source was published for any function.

## Preservation

Independent final audit: **409 ExactMatch proofs / 15,439 bytes**. All **898
active source-file hashes** remained unchanged. The pinned/installed executable
hash remains `e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`.
The previous trial and its evidence remain intact. No Ghidra changes were made.

Evidence directory:
`.work/luna3-20260914-221451/`

It contains the selected-function inspection, policy, command/receipt, run
snapshots/timeline, retained proposal work IDs and responses, before/after source
hashes, and the final independent audit.

The Luna attempt artifacts are retained under `.work/loop/` and the backend's
immutable `.work/attempts/` records. The backend is idle with no active job.
