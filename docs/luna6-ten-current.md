# Luna/max: ten highest live-current, source-present functions — 2026-09-23

**One authorized campaign:** `loop-f0e3a9aab41bc12ca468d408`. GPT-6 Luna (`openai-codex/gpt-6-luna`) at **max**, six proposal lanes, one serial verifier, up to eight reconstruction iterations per function, 180 seconds per turn, one pass, 1,800 seconds of backend active time. The operator selected the ten highest *live-current* eligible functions with existing source files, and later explicitly required the **original 30-minute wall deadline**. No fallback, second campaign or automatic repeat was started.

Raw SQLite scores were stale: `00437010`, `004196e0`, `00423800` and `004213f0` looked closest from stored `matchPercent` but the live service correctly projected null. The top live 99.22% candidate `0043a7c0` has no working source file; the operator chose to skip source-less functions rather than send an empty `currentSource`. Scope and per-file hashes are frozen under `.work/luna6-ten-sourcepresent-20260923/scope.json`.

| Address | Start current % | Jobs | End current % | Outcome |
|---|---:|---:|---:|---|
| `0042e8b0` | 99.206 | 6 | 99.206 | Non-exact; operand-order residual, investigation and missing evidence |
| `00429190` | 98.039 | 3 | 98.039 | Non-exact; lower first revision repaired to retained best |
| `00419520` | 97.714 | 4 | 97.714 | Non-exact; two comparison-order mismatches, provider loss/expired lease |
| `00412750` | 97.701 | 3 | 97.701 | Non-exact; lower first revision repaired to retained best |
| `00411d70` | 97.590 | 1 | null | Missing-evidence reply, no compiler attempt; current projection subsequently unavailable |
| `00411b90` | 97.576 | 2 | 97.576 | No compiler reply; two expired leases |
| `0040f1d0` | 95.652 | 3 | 95.652 | Three non-exact compilations |
| `00433590` | 95.294 | 1 | 95.294 | Expired lease, no compilation |
| `00421820` | 95.276 | 1 | 95.276 | Non-exact compilation |
| `0042a5d0` | 95.238 | **0** | null | Not reached before safety stop; no reply or source publication |

**Terminal state: Stopped**, 24 jobs, zero exact publications. Twelve byte-mismatch compilations (five classified operand order), six model-reported MissingEvidence replies, one investigation, four expired leases and one persistent-session loss. Provider usage was incomplete; per-run token and cost figures are omitted. All 24 requested model tiers said `max`; one failed turn had no actual thinking receipt. A model-reported evidence gap is not an independently verified compiler/Ghidra blocker. The campaign used 628.142 s active time. No work remained queued/running at Stop.

An early regression exposed a missing part of the best-source rule: before this campaign, most high-ranked functions had a **retained-candidate** byte score for source *different from the on-disk file*, and `bestCandidateSource` was not initialized until the first loop compilation. The old backend therefore let `00429190` fall from 98.039% to 6.422% and `00412750` from 97.701% to 3.743%. It was immediately Paused and drained. The repaired backend validates each retained attempt's source/object/original/resolved hashes and live compiler/binding basis, selects the highest valid candidate, and materializes its actual source before the next prompt. Synthetic end-to-end tests cover both an earlier-loop regression and a different-source retained candidate; full backend integration passed. Immutable backend `source-baseline-1f599aca2c3698b2` was activated only after the drain. A **single** manually approved Resume stayed in the original campaign/budget; observed resumed prompts carried high-scoring working sources with current and best equal. No proof status was fabricated by the restoration.

That Resume later suffered another persistent-session loss. The backend safely stopped offering turns and drained; no uncertain turn was replayed. The wall guard issued one journaled Stop after drain, about 110 seconds before the original 30-minute wall deadline. There was no further Resume. Only seven scoped non-exact working-source files changed; the audit verifies that **all 752 old exact proofs / 63,353 bytes** retain identical proof/source identities, object/source/byte artifact hashes and full resolved bytes equal the pinned PE. Configuration and pinned executable hashes did not change, and no unscoped source changed. This is an artifact/PE preservation audit, not independent COFF re-relocation: `scripts/audit-current` still cannot resolve `_PTR_ARRAY_00457c48` via its pinned symbol index.

Local evidence: `.work/luna6-ten-sourcepresent-20260923/` (scope, baseline DB/source hashes, start/pause/Resume/Stop command receipts, both frozen snapshots, time-series monitoring, upgrade hash, `terminal-loop.json`, `result.json`, `audit.py` and `audit.json`). `luna6-ten-current-20260923/` was a superseded **read-only** selection including the source-less candidate; it submitted no Start. Immutable model requests/replies and verification artifacts remain under `.work/loop/` and `.work/attempts/`; never commit them. Current scores and historical best scores are not exact proofs. Another model run requires fresh scope and budget approval.
