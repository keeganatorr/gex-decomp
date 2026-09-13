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

## Operator UI
- [ ] In Decomp select Data source = real, service = pc-decomp, project ID blank; inspect live Functions and Function Lab

## Next — iterative reconstruction, not an autonomous campaign
- [ ] Continue toward exact matches for the remaining 954 functions, smallest first; preserve unresolved evidence rather than declaring the project complete
- [ ] Refine the current 33 NearMatch candidates with instruction-aware comparisons; keep historical nonmatches and pass diagnostics as starting points
- [ ] Recover compound layouts, callee prototypes and missing explicit bindings before another bulk proposal pass; conservative adaptation could not reconstruct 858 entries
- [ ] Review 14 terminal/boundary cases and three possible noreturn-call endings; do not assume imported small spans describe complete functions
- [ ] Add bounded function detail/artifact access: the 218,888-byte enclosing span at 00409970 exceeds the 900 KiB response budget
- [ ] Review deferred backup types/conventions, embedded strings/data, compiler helpers and local COFF label/jump-table support without masking differences
- [ ] Resolve byte-reader register-allocation differences at 00417f00 and 00417f40 without weakening ExactMatch
- [ ] Add register-aware diagnostic diffs, per-used-binding proof dependencies and concise batch reports in pc-decomp/Nexus (feedback: docs/ten-functions.md)
- [ ] Add an explicit all-source verification gate; build-baseline intentionally remains the original two-function smoke test
- [ ] Verify calling conventions, signedness and struct layouts independently of byte equality
- [ ] Resolve the three edited bodies without changing the EditedGex reference; separate original-byte analysis remains unimplemented
- [ ] Benchmark additional compiler/flag candidates on a representative corpus before claiming original toolchain identity
- [ ] Add complete compiler-input/header dependency capture in pc-decomp before introducing shared headers
- [ ] Import detailed existing type members/references and improve unique-byte coverage accounting
- [ ] Design full-game link/run validation separately from per-function verification
- [ ] Approve explicit Nexus profiles/budgets/worktrees before implementing any autonomous campaign
