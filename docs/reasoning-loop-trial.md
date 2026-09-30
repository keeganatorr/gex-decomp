# Five-minute reasoning-pinned loop trial

Completed 2026-09-14. This is a new bounded trial, not the earlier stopped
nine-attempt run (`loop-a9716bb87f61e0081dfb9bf8`).

## Policy and deployment

The user approved five smallest eligible non-exact functions, 300 seconds,
one attempt per model/function, in this order:

1. `openai-codex/gpt-5.6-luna`, `xhigh`
2. `openai-codex/gpt-5.6-terra`, `high`
3. `openai-codex/gpt-5.6-sol`, `medium`
4. `openai-codex/gpt-6-astra`, `low`

Each attempt had a 60-second ceiling within the overall budget. `maxPasses:1`
prevented repeats; there was no token cap or claimed subscription dollar cap.

Release `a69d4faec306ceb1` was activated after a full Nexus restart and matching
frozen host/module/runtime hashes. Backend and CLI link now use the immutable
`reasoning-a525e25343cd1425` backend. The release extension passed rendered reload;
the operator connected the work bridge, which advertised reasoning support and
all four available models. No campaign was started by activation itself.

New run: `loop-b6dca950c58ed048523a7ad6`.
Durable start command: `reasoning-five-c8393337-0614-4948-8ad5-78079d996e83`.
Its completed receipt was reconciled again after the run; it was submitted once.

## Results

**No new ExactMatch functions or bytes.** Time stopped the run in pass 1 at
300.862 seconds, with 12 model attempts across three of the five scoped functions.
All observed effective reasoning levels matched the requested levels.

| Function | Size | Attempts | Outcome |
|---|---:|---:|---|
| DirectSoundCreate `00409870` | 6 | 4 | All models reported missing IAT-slot binding at `004a53d4`. |
| DirectDrawCreate `00409876` | 6 | 4 | Three model blockers; Sol produced the only source candidate. Compilation produced an object, but strict verification rejected unresolved `__imp__DirectDrawCreate`. IAT slot: `004a53cc`. |
| RtlUnwind `0044f5ea` | 6 | 4 | Three completed blockers for missing IAT binding at `004a54e4`; the final Astra attempt hit the overall deadline. Its partial/late response is retained, not promoted. |
| timeSetEventInner `00406fd0` | 8 | 0 | Not reached before the time limit. |
| `___initmbctable` `0044b370` | 11 | 0 | Not reached before the time limit. |

Thus: ten completed blocker responses, one compiler/verification attempt, one
deadline-interrupted attempt. The retained compiler attempt is
`attempt-9d2b909376384b25a682d939e3e48d12`. No candidate was published.

Provider usage was incomplete because the final request was interrupted. Per-run
token and cost figures are omitted from this public summary.

## Selection and limitations

Selection required backend-proven contiguous instruction extents, unchanged bytes
against the pinned executable, and a terminal return or unconditional jump. The
three import thunks meet those byte/extent conditions but lack usable bindings;
this trial demonstrates that extent eligibility alone is not reconstruction
readiness. Supplying a stronger model did not repair missing permitted inputs.

Preflight excluded `0041fdd0`, `00402fb0`, and `00402140`: their imported bodies end
in NOP/fall-through while their reference pseudocode continues beyond the span.
The backend currently labels those instruction spans `extentVerified:true`;
that establishes contiguous decoded bytes, not a complete function boundary.
Automatic loop preflight should conservatively exclude such bodies too, without
altering EditedGex or guessing a replacement extent.

Before another trial, independently recover and explicitly approve missing import
bindings, or select ordinary complete functions instead of these import thunks.
Do not repeatedly spend model attempts on the same missing-input condition.
No additional run or binding change is authorized by this report.

## Preservation and evidence

The independent audit still verifies **409 exact proofs / 15,439 bytes**;
project totals remain 1,335 functions, 34 near and 892 other non-exact.
All **898 source-file hashes are unchanged**. Installed and pinned executables
still hash to `e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`.
EditedGex was read only. Historical evidence and the old stopped run remain intact.

Local evidence directory:
`.work/reasoning-trial-20260914-204750/`

- `activation.json`, previous service/link configuration and stopped database backup
- `selection.json`, inspected function details, before/after source hashes/audits
- `start-command.json`, original and reconciled receipts, `run-id`
- `timeline.jsonl`, `final-loop.json`, `reconciled-loop.json`, `results.json`
- Immutable proposal requests/responses and session paths referenced by `results.json`

The final backend state is **LimitReached**, with no active job. No run was
resumed or started after the limit.
