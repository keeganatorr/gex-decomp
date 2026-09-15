# Smallest-first follow-up trial 2

2026-09-15. After repairing split fall-through extents and adding the proven
`ScreenWidth` binding, a fresh bounded pass targeted the next three complete,
unattempted non-CRT functions:

| Address | Function | Size |
|---|---|---:|
| `00404f70` | `FUN_00404f70_PostMessage_Unk` | 21 |
| `00404440` | `CloseVideoWindow_00404440` | 24 |
| `00401f90` | `SND_Destroy_00401f90` | 27 |

The pass used the approved Luna/Terra/Sol/Astra lane, one pass, one attempt per
model, and a 300-second ceiling. Durable run evidence is in
`.work/smallest-followup-20260915-013225/`.

## Result

Two functions became strict ExactMatch:

- `00404f70`: 21 bytes
- `00404440`: 24 bytes

`00401f90` remained unmatched. Models identified the remaining missing binding
for its global `gSFXTable_0049fb54` at address `0049fb54`; no fabricated address or
source was accepted. The run reached `LimitReached` after eight model attempts,
153,164 reported tokens, and `$0.3991094` reported cost (`unknownUsage: true` for
the final expired work). No unsafe source publication occurred.

Current status is **411 ExactMatch functions / 15,484 bytes**, with no running or
queued tasks. No full audit was rerun at the operator's request; existing audit
artifacts remain preserved.
