# Gex decompilation

## Done — reproducible first baseline
- [x] Preserve GOG executable and existing edited Ghidra project; pin original hash
- [x] Update GhidraMCP for the installed Ghidra and reconnect after user save/restart
- [x] Recover historical compiler flags; identify actual CL 10.00.5270 rather than MSVC 2010
- [x] Import 1,335 non-external functions and 1,116 inherited type inventory entries
- [x] Identify five edited code bytes in three functions and block those matches
- [x] Verify 00420d30 (7 bytes, DIR32) and 00418e20 (10 bytes, REL32) exactly
- [x] Run the separate durable pc-decomp service and register its Nexus service identity
- [x] Native Atlas treemap and compact live feed: 1,335 functions, 2 exact / 17 bytes retained after deployment; backend 13286c8, evidence .work/atlas-live-proof.json
- [x] Provide online verification/build scripts and retain immutable attempts
- [x] Validate live protocol/schema, backend restart/reconnect and idempotent build queries

## Done — ten-function reconstruction batch
- [x] Reconstruct ten additional unpatched functions: eight ExactMatch / 364 new bytes, two Compiles (`src/functions/`, `docs/ten-functions.md`)
- [x] Cover nontrivial pointer/list traversal, branches, random-state loops, tracing and recursion with resolved relocation proofs
- [x] Retain all 21 attempts and reverify the original baseline after binding changes; project total 10 exact / 381 bytes
- [x] Check byte readers on 65,536 exhaustive 16-bit and 11,048 directed/seeded 32-bit inputs (`tests/byte_readers.py`; host tests, not ExactMatch proof)

## Done — historical backup recovery
- [x] Audit 2,461 main source files and 977 assembly/raw-byte mod wrappers without modifying the backup
- [x] Compare 882 additional addresses; import 344 exact, 32 near and 440 compiling candidates with source/attempt provenance (`docs/backup-import.md`, `docs/backup-import-index.json`)
- [x] Retain 1,005 attempt records and all failures; preserve the original 12 sources and their current proofs
- [x] Add 13,163 exact bytes; project total 354 exact functions / 13,544 bytes; validate live Atlas and function details
- [x] Compact binding metadata for large imports without changing validity rules; full maps remain in immutable artifacts (pc-decomp 544312b)
- [x] Test backup preservation, explicit declaration adaptation, uncertain-command recovery, idempotency and config-change retry (`tests/backup_tools.py`)

## Done — operator-requested smallest-first pass
- [x] Assess all 981 initially non-exact entries in imported size order; retain a complete per-function outcome index (`docs/smallest-pass.md`, `docs/smallest-pass-index.json`)
- [x] Run 82 fresh candidate trials and 26 restoration verifications; add 18 exact / 633 bytes and retain 31 other proposed candidates
- [x] Preserve all 354 previously exact sources; independently validate all 372 current proofs / 14,177 exact bytes against pinned PE bytes
- [x] Add checkpointed pass/recovery/report tools and 13 synthetic safety tests (`scripts/smallest-pass`, `scripts/report-smallest-pass`, `tools/smallest_pass.py`, `tests/smallest_pass.py`)
- [x] Record 858 pre-trial reconstruction blockers, 37 analysis/termination/transport blockers, seven compiler blockers and unchanged/unsuccessful proposals honestly; this completes the pass, not the game

## Done — first EditedGex iterative checkpoint
- [x] Keep EditedGex read-only; add nine exact / 163 bytes from instruction-aware reconstruction, not a reset of the completed pass (`docs/iterative-editedgex.md`)
- [x] Deploy scoped compiler contracts with C/C++ mode, allowlisted per-function flags and COFF symbols; preserve all 372 earlier exact sources/proofs (backend 3545257)
- [x] Retain 31 attempts, including six restoration verifications; restore unsuccessful byte-reader, BSF and voice-state proposals
- [x] Independently reconstruct all 381 exact COFF byte streams and relocation destinations against pinned PE bytes (`scripts/audit-current`, `tools/proof_audit.py`, six synthetic test groups)
- [x] Record target-specific shift semantics, provisional list return type and hidden SCRIPT_KillPlayer stack argument; totals now 381 exact / 14,340 bytes, 874 sources

## Done — bounded loop activation
- [x] Activate immutable backend `loop-cc6be762d054e328`, compatible Nexus host/runtime and native loop controls; authorize the bridge without starting a campaign (`.work/decomp-loop-activation-20260914-200335/activation.json`)
- [x] Independently re-audit all 409 current exact proofs / 15,439 bytes after deployment; preserve source, pinned executable and EditedGex

## Done — approved reasoning-pinned trial
- [x] Implement/test and immutably stage reasoning support and a single-pass ceiling (`.work/decomp-loop-staging/a69d4faec306ceb1/manifest.json`); 38/38 Nexus harness tests, backend synthetic integration, extension CTest/rendered persistence pass; all 409 proofs preserved
- [x] Verify restarted host/runtime and activate release `a69d4faec306ceb1`; record immutable deployment/backups in `.work/reasoning-trial-20260914-204750/activation.json`; old stopped run untouched
- [x] Run the approved 300-second, one-pass Luna xhigh → Terra high → Sol medium → Astra low trial: 12 attempts on three import thunks, no gains, two functions not reached; levels verified, all 898 sources/409 proofs unchanged (`docs/reasoning-loop-trial.md`)

## Done — read-only IAT binding review
- [x] Prove pinned-PE IAT identities and SDK COFF spellings; generate/apply the 179-entry import map and reverify all 409 prior proofs under the new binding hash (`docs/iat-binding-review.md`, `.work/binding-activation-20260914-223323/`)
- [x] Resolve the retained DirectDraw object's relocation diagnostically: still 25 bytes versus the original 6; cdecl declaration differs from canonical stdcall ABI. No configuration/source changes or new AI/compiler run; all 409 proofs retained

- [x] Correct retained DirectDraw candidate to stdcall with opaque API pointer types; isolate the new revision and compile under unchanged baseline flags. Actual decorated symbols verified; 24-byte wrapper still differs from the 6-byte thunk, so no ExactMatch claim or active config/source change (`.work/retained-candidate-fixes/00409876-stdcall-v1/`, `docs/iat-binding-review.md`)

## Done — isolated DirectDraw thunk byte match
- [x] Find compiler-generated six-byte tail-jump source under unchanged CL baseline flags; correct import symbol and resolved IAT address, no assembly/byte injection or relaxed comparison (`docs/isolated-import-thunk-match.md`)
- [x] Verify twice through the normal backend in a separate project and independently audit both COFF/PE proofs; opaque-entry cast is compiler-specific, not a portable type-safe API wrapper. Live 409 proofs, 898 sources and configuration unchanged

## Done — Luna three-function trial
- [x] Run one-pass Luna xhigh trial on three new smallest eligible non-thunk functions: 3 attempts, 0 exact gains; `_flsall` binding blocker, VSIT 18-byte NearMatch, and `__ismbblead` deadline/unknown usage. No source published; 409 proofs and 898 sources unchanged (`docs/luna-three-trial.md`)

## Done — per-used binding currency and pinned symbol resolution
- [x] Keep current proofs when unrelated bindings change: proofs record the exact symbol->address subset they used (`usedBindings`), and `BindingsCurrent` validates only those. Legacy proofs migrated metadata-only from retained relocations + immutable maps (416 proofs, zero byte audits, zero compiler runs)
- [x] Resolve missing relocation symbols from a pinned-evidence symbol index (1,335 Ghidra functions + 22,927 data labels) by unique normalized name or confirmed embedded address; unknown/ambiguous stay blocked and no address is fabricated (`pc-decomp/src/PcDecomp/Symbols.cs`, `symbols`/`backfill` CLI)
- [x] Supply each function's pinned `referencedTargets` to the loop prompt so models declare real names; activate the new backend and confirm 416 exact proofs stay current across an unrelated binding addition
- [x] Re-test with deepseek-v4.1-flash/high: `_malloc` 0044d970 became ExactMatch (+20 bytes, published) with auto-resolved `___nh_malloc`->0044d990 and `?DAT_00462270@@3HA`->00462270; FUN_00406fd0 hit the model deadline with no binding blocker (its inline-BSF requirement remains open). 416 -> 417 exact, 0 unrelated proofs retired (`.work/binding-fix-activation-20260915-104926/`, `.work/binding-fix-retest-20260915-105032/`, `docs/binding-resolution.md`)

## Done — import-thunk extent and per-used binding resolution

### Per-used binding currency and pinned symbol resolution
- [x] Proofs record `usedBindings` (exact symbol->address subset); currency checks only those, so unrelated binding changes never retire a proof. 416 legacy proofs migrated metadata-only (`symbols`/`backfill`), zero compiler runs and zero byte audits
- [x] Resolve missing relocation symbols from a pinned symbol index (1,335 functions + 22,927 data labels) by unique normalized name or confirmed embedded address; unknown/ambiguous stay blocked, no fabricated addresses (`pc-decomp/src/PcDecomp/Symbols.cs`)
- [x] Supply each function's `referencedTargets` to the loop prompt; `_malloc` 0044d970 became ExactMatch (+20 bytes) via auto-resolved `___nh_malloc` and `?DAT_00462270@@3HA`; 416 -> 417 exact, 0 unrelated proofs retired (`docs/binding-resolution.md`)

### Import-thunk extent blocker
- [x] Accept an absolute-indirect tail jump (`jmpl *0x...`) as a complete external transfer, like a direct tail jump; register/index-indirect forms stay rejected (`pc-decomp/src/PcDecomp/Verifier.cs`)
- [x] Unblock `00409870 DirectSoundCreate`, `00409876 DirectDrawCreate`, `0044f5ea RtlUnwind` with blockedCount 0 and persist their verified extent; none exact yet, source matching remains (`docs/import-thunk-extent.md`)

## Done — five-function DeepSeek/high pass
- [x] Run five explicit targets, one attempt each: 00423760 and 0044a210 exact (+46 bytes); 00445180 compiled mismatch, __fpmath missing instruction-generation evidence, 0044a9a2 timeout. 417 -> 419 exact; no bulk recompilation/audit (`docs/deepseek-five-functions.md`)
- [x] Distinguish model `MissingEvidence` from provider/auth failures; retain configured tier escalation without falsely pausing on model prose. Supply configured compiler ID/version to future prompts; synthetic regressions pass, immutable backend deployed, no additional paid run

## Operator UI
- [ ] In Decomp select Data source = real, service = pc-decomp, project ID blank; inspect live Functions and Function Lab

## Next — iterative reconstruction, not an autonomous campaign
- [x] Add fail-closed section-local/absolute COFF relocation resolution and a read-only PE import-binding generator; no object-local/compiler symbols were fabricated as project bindings (`pc-decomp/src/PcDecomp/Binary.cs`, `tools/import_bindings.py`)
- [ ] Source-match the remaining import thunks only as isolated candidates; DirectDraw has an exact opaque-thunk candidate with documented type-level limits, while DirectSound/RtlUnwind have no source match (`docs/isolated-import-thunk-match.md`)
- [ ] Add complete-boundary preflight to the automatic loop: `extentVerified` currently accepts contiguous NOP-terminated fragments such as 0041fdd0; never repair EditedGex or guess larger extents
- [x] Run a fresh bounded smallest-first three-function trial with the approved reasoning lane; nine attempts reached the 300-second limit, zero gains, and no source publication (`docs/smallest-followup-trial.md`)
- [x] Continue after boundary repair with the next three complete smallest-first functions; `00404f70` and `00404440` became exact (+45 bytes), while `00401f90` initially remained blocked on global `0049fb54` (`docs/smallest-followup-trial-2.md`)
- [x] Add the evidence-backed `0049fb54` binding as part of reconstruction and retry `00401f90`; it became an exact 27-byte match, then restore all 412 current proofs through 32-function durable verification batches (`docs/binding-enabled-trial.md`)
- [x] Expose the immutable historical ExactMatch count separately from current-valid proof status; the Overview now reports 412 historical functions / 15,511 bytes without promoting stale proofs
- [ ] Continue toward exact matches for the remaining 912 functions, smallest first; preserve unresolved evidence rather than declaring the project complete
- [ ] Refine retained historical NearMatch candidates with instruction-aware comparisons; current binding activation reset un-reverified NearMatch statuses to unmatched, and pass diagnostics remain historical starting points
- [ ] Recover complete function boundaries, compound layouts, callee prototypes and remaining explicit bindings before another bulk proposal pass; the smallest follow-up confirmed 11-byte NOP-terminated prefixes are incomplete
- [ ] Review 14 terminal/boundary cases and three possible noreturn-call endings; do not assume imported small spans describe complete functions
- [ ] Add bounded function detail/artifact access: the 218,888-byte enclosing span at 00409970 exceeds the 900 KiB response budget
- [ ] Review deferred backup types/conventions, embedded strings/data, compiler helpers and local COFF label/jump-table support without masking differences
- [ ] Resolve byte-reader register-allocation differences at 00417f00 and 00417f40 without weakening ExactMatch
- [ ] Add register-aware diagnostic diffs and concise batch reports in pc-decomp/Nexus (feedback: docs/ten-functions.md). Per-used binding dependencies are now done.
- [ ] Add an explicit all-source verification gate; build-baseline intentionally remains the original two-function smoke test
- [ ] Verify calling conventions, signedness and struct layouts independently of byte equality
- [ ] Resolve the three edited bodies without changing the EditedGex reference; separate original-byte analysis remains unimplemented
- [ ] Benchmark additional compiler/flag candidates on a representative corpus before claiming original toolchain identity
- [ ] Add complete compiler-input/header dependency capture in pc-decomp before introducing shared headers
- [ ] Import detailed existing type members/references and improve unique-byte coverage accounting
- [ ] Design full-game link/run validation separately from per-function verification
- [ ] Distributed worktrees/tool-using agents beyond the bounded proposal loop; the separately approved limited trial is tracked above
