# Pinned binding resolution and per-used proof currency

2026-09-15. Root cause of the recurring "required bindings are missing" blockers:
the loop handed models only the global `symbolBindings` map, so any referenced
CRT helper or data global absent from that map made a model stop (for example
`_malloc` at `0044d970` needed `__nh_malloc @ 0044d990` and `DAT_00462270`).
Adding bindings was also destructive: proof currency hashed the whole map, so one
new binding retired every exact proof and forced a full re-verification.

Two backend changes fix both halves. Neither recompiles a matching function and
neither audits decompiled code.

## 1. Pinned-evidence symbol resolution

`import` (and the new `symbols` command) records a symbol index of 1,335 Ghidra
function labels and 22,927 data labels. During verification an unresolved COFF
relocation symbol resolves in this order:

1. explicit `symbolBindings` (unchanged), then
2. the symbol index, when the symbol name embeds an eight-hex address that the
   pinned inventory confirms, or when the name is a **unique** match after
   trimming leading cdecl underscores.

Unknown or ambiguous symbols still fail closed (`Unresolved relocation
destination: ...`). No address is fabricated and no relocation byte is masked.
The loop prompt now also lists each function's `referencedTargets` — the pinned
call/data addresses from its own listing — so models declare real names.

## 2. Per-used binding currency

Every proof records `usedBindings`: the exact symbol->address subset the attempt
resolved. `BindingsCurrent` re-checks only those symbols. Adding or removing an
unrelated binding leaves every proof current. Legacy proofs without
`usedBindings` keep whole-map-hash semantics until `backfill` derives the subset
from the retained relocation list and immutable attempt map. That migration is
metadata-only: 416 proofs migrated with no compiler run, no byte comparison and
no Ghidra write.

## Activation

Backend `bindings-e8ca481c174abbb5` (`PcDecomp.dll` sha256
`e8ca481c…5f03cb`) replaced `tail-8585abe189c88067`. The project service was
stopped, `symbols` and `backfill` ran offline under the owner lock, the unit and
`backend-current` were repointed, and the service restarted. Before/after unit,
database and project backups plus rollback steps are in
`.work/binding-fix-activation-20260915-104926/activation.json`.

## Retest evidence

Run `loop-a9c24ff7b7e6e66327fa69b4`, one pass, `openrouter/deepseek/deepseek-v4.1-flash`
at `high` (`.work/binding-fix-retest-20260915-105032/`):

- `_malloc` (`0044d970`): **ExactMatch, +20 bytes**, source published to
  `src/functions/0044d970.cpp`. Used bindings were
  `___nh_malloc -> 0044d990` and `?DAT_00462270@@3HA -> 00462270`; both were
  resolved from the pinned index, not from a pre-seeded config entry.
- `FUN_00406fd0_timeSetEventInner`: the model hit its deadline and returned
  nothing. There was **no** binding blocker. Its true requirement is inline `bsf`
  under CL 10.00 (attempts that declare `_BitScanForward` emit a call to
  `__BitScanForward`; `__declspec(intrin_type)` is C2485), which is a separate
  compiler-contract problem and is not claimed solved here.

Exact proofs moved 416 -> 417. No unrelated proof was retired, and no source
other than the new exact candidate changed.

## Honest limits

- String-literal (`??_C@…`) and compiler label (`$L…`) relocation blockers are
  not bindings; they remain blocked.
- Index resolution is deterministic for a given import epoch. Re-importing
  Ghidra changes the analysis epoch and legitimately retires proofs; adding
  ordinary project bindings no longer does.
- `scripts/audit-current*` re-resolve from `config['symbolBindings']`; they must
  use the proof's recorded `usedBindings` (plus the index) to reproduce a
  relocated candidate. Update them before the next independent audit sweep.
