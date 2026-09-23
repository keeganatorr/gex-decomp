# GPT-6 Luna / max: ten-function feedback-guided batch

## Result — 2026-09-23

One explicitly approved campaign, `loop-f2cf827017ec5bb6a8f10f57`, finished **Blocked / drained**, not still running: six functions exhausted their repair budgets. No Resume, replacement scope or second campaign was started.

- Model: **openai-codex / gpt-6-luna**, pinned **max**, verified on all 71 result receipts.
- Scope: ten closest current eligible non-exact candidates, shortest/address tie breaks; verified extents and unchanged pinned Ghidra bytes. Known dead ends, unresolved-binding targets and underscore-prefixed names excluded. Unlike the earlier Astra batch, there was no 200-byte minimum.
- Limits: ten proposal lanes, one serial verifier, eight reconstruction iterations per function, stagnation threshold two, one pass, 1,800 seconds overall. Evidence/batch repair, retained working candidates and continuation enabled; no provider fallback or compiler/config change.
- Elapsed: **1,061.207 seconds (17m 41s)**.
- Results: **4 new exact functions / 545 bytes**; **748 / 62,808 → 752 / 63,353**.
- 71 jobs: **64 compiler attempts** (4 exact, 58 byte mismatches, 2 actual compiler rejections) and **7 investigation replies**. An investigation does not consume a reconstruction iteration, so a function can have nine jobs within the eight-iteration limit.
- Provider-reported usage: **6,013,234 tokens**, **$0.29109044**, `unknownUsage=false`. This is provider metadata, not a subscription bill.
- Final state: zero active lanes, zero queued/running verification tasks.

Pi's cached catalog initially lacked GPT-6 Luna. At the operator's request, `pi update --models` refreshed the actual catalog; GPT-6 Luna and max were present afterward. A fresh, unprompted Nexus session exposed that catalog to the host bridge without restarting the active coding session. No GPT-5.6 substitution or hand-written model alias was used.

## Exact publications

| Address | Function | Bytes | Compiler iterations | Strict proof |
|---|---|---:|---:|---|
| `00433900` | GOB_ProcessEvents | 189 | 1 | `attempt-d106240b268b4c3caccaea10ae83d6c4` |
| `004212d0` | pStateUnk_yVel | 104 | 2 | `attempt-203affe7db4d4ac5ad5468b89b0fec24` |
| `004097f0` | ProcessCheatInputs | 127 | 5 | `attempt-4bd4553a9a8646c7b807d6a377d16e1d` |
| `00430ea0` | ob231Draw | 125 | 8 | `attempt-7ceff3c3294040d691ddd85ec322a532` |

The strict backend published these results. The follow-up read-only audit checked source/object/original/resolved hashes, compared complete resolved streams to independently sliced pinned PE bytes, and verified all **748 baseline proof identities, source revisions and source hashes** remained unchanged. Only the ten scoped source paths changed: nine existing files and the newly materialized `00431900.cpp` (previous candidates were retained artifacts, not an existing source file). `project.json`, compiler/flags/bindings and the executable were unchanged; Ghidra was not edited. This was not a bulk recompile or a whole-game proof.

## Lessons from successful repairs

1. **Separate declarations from initialization when investigating register choices.** Reordering loop locals while preserving initialization order matched GOB_ProcessEvents. Capturing the global velocity only in its relevant branch, then changing local declaration order, matched pStateUnk_yVel. These are measured results for CL 10.00.5270, not a universal register-allocation rule.
2. **Use a narrow, testable scheduling constraint rather than broad rewrites.** ProcessCheatInputs progressed from copy-loop/type/order changes to a two-byte load-register residual. A volatile byte access preserved the needed read order and produced exact output. It is a code-generation device here, not proof that the original program declared volatile memory; volatile did not solve the other scheduling failures below.
3. **Comparison reversal alone can be a dead end without the whole function being impossible.** ob231Draw's equivalent conditions repeatedly emitted the same two-byte CMP/Jcc residual. The eighth reconstruction used the reference's pointer-array representation and explicit integer casts and matched. This establishes byte fidelity under the pinned compiler, not historical pointer types or portable semantics.

## Failed functions: preserve the evidence, do not replay the same families

All six remain non-exact. Their **historical best** values below must not be presented as current-source proof or current live percentages: final service rows are `Stubbed`, with `matchPercent=null`, while retained best/iteration evidence still exists.

| Address | Historical best | Measured residual / next requirement |
|---|---:|---|
| `0041a0a0` GOB_LandedOnContours | 98.9418% | Signed lower-bound CMP/Jcc operand ordering: 187/189 bytes. Equivalent negation and condition splitting did not solve it; goto/nested control-flow rewrites degraded layout. Needs a genuinely different evidenced type/lifetime hypothesis, not another spelling of the same inequality. |
| `00420210` PAR_LoadParallaxs | 98.6301% | Initial next-pointer load/test uses EAX instead of ECX, differing at offsets 76/78. Explicit pointer temporaries, typed fields, register hints and if/do form repeatedly retained the mismatch; moving the next-pointer read before assignment made it worse. |
| `00438e40` event_hitContour | 96.4286% | Desired byte load into AH; closest candidate uses a dword load followed by the right AH test. Narrow/shifted/volatile/signed-byte expressions choose AL or a memory TEST and alter length. |
| `00438ea0` event_contourGone | 96.4286% | Same AH-load family. Eight compilations yielded only four distinct resolved outputs (each repeated twice). Union/word/narrow-load probes did not solve it. |
| `00438f00` event_flamed | 96.4286% | Same AH-load family; byte reads choose AL, bitfields tend to become direct memory tests. Eight compilations yielded five outputs. Last candidate returned to the old 81/84-byte result, not an improvement. |
| `00431900` Movement_unk | 96.3504% | Target decrements EAX before loading `[ESI+0x8c]`; candidate loads first. All six successful compilations produced the same resolved output despite separate decrement, comma sequencing, volatile and branch experiments. Two additional attempts genuinely failed compilation. |

The two real compiler errors for `00431900` were **C2065** (changed case of `DAT_00463fe0`) and **C2362** (goto skipped initialization of `yv`). Both were repaired in the next reply, but that only recovered compilation, not byte progress. Preserve exact symbol spelling and avoid introducing illegal initialization-crossing gotos.

The seven investigation responses were retained and supplied to continuation prompts. Their findings were function-local; no unreviewed claim was promoted to a shared ABI/layout contract. Source variants producing identical resolved-byte hashes are one code-generation result, irrespective of differing object hashes or explanatory prose. A poor positional score after a one-byte length change is also not a semantic correctness measurement.

### Follow-up work, not performed here

- Detect already-tried resolved-output families across the three AH-load functions so future scoped runs can transfer negative findings without spending the same eight attempts three times. Shared findings need explicit provenance and review, not an automatic type assertion.
- Review terminal non-exact working-candidate handling: this run's six deferred rows lost their current match projection (`Stubbed`/null) while best evidence survived. Do not silently overwrite sources with historical candidates or promote history into live proof; any restoration needs the normal service verification path.
- Do not turn the ob231Draw success into a claim that every operand-order failure is solved by pointer typing. The remaining failures require new hypotheses and fresh run authorization.

## Retained receipts and reproducibility

Local evidence directory: `.work/luna6-ten-20260923/`.

- `start-intent.json` / `start-receipt.json`: one journalled Start, command ID `luna6-ten-20260923-one-authorised-batch`.
- `scope.json`, `before-functions.json`, `before-source-hashes.json`, `config-sha256.txt`: frozen selection and preservation baseline.
- `timeline.jsonl`, `final-loop.json`, `final-snapshot.json`, `jobs.json`, per-function before/after details and `audit.json`: results and diagnostics.
- `audit.py`: read-only preservation and four-proof artifact/PE checks, no database writes or recompilation.
- Immutable requests/replies under `.work/loop/<work-id>/`; compiled artifacts under `.work/attempts/<attempt-id>/`. These local binaries, database records and Ghidra-derived exports are not committed.

No paid work remains active. A subsequent run requires new explicit scope/budget approval; it must not replay this Start or automatically renew exhausted budgets.
