# Smallest-first follow-up trial

2026-09-14. The operator authorized a fresh bounded pass over three previously
unattempted, non-import functions, using the previously approved reasoning lane:
Luna xhigh, Terra high, Sol medium and Astra low, one attempt per model, with a
300-second total ceiling and one pass.

## Selection

The selection was size-ordered, with known import thunks, CRT helpers, already
attempted entries and known incomplete NOP-terminated boundaries excluded:

| Address | Name | Imported span |
|---|---|---:|
| `0043bc80` | `ob261DoIt_0043bc80` | 11 bytes |
| `0042b7f0` | `MapPlayerDoIt_0042b7f0` | 11 bytes |
| `004054c0` | `FUN_004054c0_SetWindowSize` | 11 bytes |

The durable run directory is
`.work/smallest-followup-20260914-235411/`. The command is
`smallest-followup-18fea73139e34ab9` and the run is
`loop-654b212559c170bf07948390`.

## Result

The pass reached `LimitReached` after 300.532 seconds and nine model attempts.
It made **zero ExactMatch gains**, **zero byte gains**, published no source, and
left all 898 source files unchanged. Provider usage was incomplete; per-run token and cost figures are omitted. The
final usage flag is `unknownUsage: true` because the last
bounded work expired before authoritative usage arrived. No command was retried.

The model diagnostics consistently identified the same evidence problem: each
11-byte imported range ends after stack allocation, a global load, `TEST`, and
`NOP`, without an epilogue, return, or complete control-flow continuation. The
pseudocode describes a substantially larger routine. `MapPlayerDoIt` also exposed
an absent binding for the absolute operand at `00463b30`; `SetWindowSize` exposed
an absent `ScreenWidth` binding at `00487768`. These are blockers, not reasons to
trim the range or fabricate a candidate.

The retained `MapPlayerDoIt` compiler attempt scored 34.48% but was not published
as a source proof. The final backend audit reports 409 ExactMatch functions and
15,439 exact bytes, with no active tasks or campaign work. The audit and status
snapshots, full timeline, selection, policy and command receipts remain in the
run directory.
