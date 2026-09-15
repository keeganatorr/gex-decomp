# Five-function DeepSeek pass — 2026-09-15

User-authorized bounded run: `loop-9fc5ea4cab837f8fcb6a9d45`.
Provider/model `openrouter` / `deepseek/deepseek-v4.1-flash`, reasoning `high`.
Five explicitly selected unresolved functions, one attempt each, one pass,
240-second attempt deadlines, 1,300-second overall ceiling. No subsequent paid
retry or whole-project run was started.

## Results

| Address | Target | Result |
|---|---|---|
| 00423760 | FUN_00423760_pStateUnk | ExactMatch, +23 bytes; four 32-bit global zero stores |
| 00445180 | CacheInitInner_takes_x_and_y | Compiles, not exact: 24 bytes vs 23; reversed initial argument-load order and 16-bit ECX load instead of 32-bit |
| 00449a70 | __fpmath | Model reported missing evidence for compiler-supported trailing `fnclex`; no source proposal |
| 0044a210 | fpMathInnerInner | ExactMatch, +23 bytes; compiler-generated x87 comparison |
| 0044a9a2 | FUN_0044a9a2 | Work deadline/service lease expired; no returned proposal |

Run reached `LimitReached` at its single-pass ceiling after five attempts, about
469 seconds. Recorded tokens: 148,691; `unknownUsage=true` after the final timeout,
so that is not a complete usage total. No extent or unresolved-symbol failure.
All five have complete verified extents and Ghidra bytes equal the pinned original.
The last function uses incoming EAX/EBP state that ordinary C/C++ arguments do not
explain; this remains an evidence-recovery issue, not a reason to invent an ABI.

Only `src/functions/00423760.cpp` and `src/functions/0044a210.cpp` were published.
The three other target source paths remained unchanged. Current and historical
exact totals rose **417 -> 419**, adding **46 bytes**, and remained 419 after the
backend restart. No existing exact function was recompiled and no audit sweep ran.
Byte equality does not establish original source types or IEEE edge-case semantics
beyond this compiler/flags/target combination.

Retained verification attempts:
- `00423760`: `attempt-0f1de3a610f243e6825023fb0b0b6641`
- `00445180`: `attempt-327de43a54cb4c6b9c77a835422ba65e`
- `0044a210`: `attempt-cc20b7c741ee4e4684cefb8f1a2e1808`

## Loop fix

The pass exposed a model evidence-gap response recorded as generic `Failed`.
Inspection also showed that authentication-related words inside such model prose
could incorrectly pause the entire campaign. `DecompLoop` now classifies parsed
`{"blocked":"..."}` as `MissingEvidence`, retains its reason, and permits the
configured next tier. It does not turn the model's claim into a verified analysis
blocker or change source/proof status. Real host/provider authentication errors
still pause. Existing historical outcomes, including this pass, are not rewritten.

Future prompts include the configured compiler ID/version and separately labeled
original-compiler hypothesis. The prompt warns against modern unsupported
intrinsics/attributes and fabricated bindings for inline instructions. This
improves evidence supplied to future models; it does not solve `fnclex` codegen.

Release build, SelfTest and synthetic integration pass. New integration coverage
checks compiler metadata, missing-evidence escalation despite authentication words,
unchanged source/no compile attempt, and a real 401 still pausing.

Deployed immutable backend: `.work/backend/loop-evidence-dfec7d0c48bebaff`.
Rollback backend: `.work/backend/thunk-extent-b125c7caa11ecf09`.
Activation record and pre-restart DB/unit backup:
`.work/five-loop-fix-activation-20260915-184442/activation.json`.
Service and authorized host bridge are connected; campaign remains `LimitReached`
with no active job. No Nexus restart, project configuration change, Ghidra write,
relocation masking or verifier relaxation occurred.

Private evidence: `.work/five-deepseek-20260915-183223/` (selection, durable command
and receipt, job outcomes, before/after progress and five-target source checks).
Artifacts/DB/binaries remain uncommitted.
