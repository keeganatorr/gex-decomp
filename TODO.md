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

## Operator UI
- [ ] In Decomp select Data source = real, service = pc-decomp, project ID blank; inspect live Functions and Function Lab

## Next — manual source reconstruction, not an autonomous campaign
- [ ] Prioritize the 32 imported NearMatch candidates; retain the 440 other compiling sources as unverified starting points
- [ ] Review deferred backup types/conventions, embedded strings/data, compiler helpers and local COFF label/jump-table support without masking differences
- [ ] Resolve byte-reader register-allocation differences at 00417f00 and 00417f40 without weakening ExactMatch
- [ ] Add register-aware diagnostic diffs, per-used-binding proof dependencies and concise batch reports in pc-decomp/Nexus (feedback: docs/ten-functions.md)
- [ ] Add an explicit all-source verification gate; build-baseline intentionally remains the original two-function smoke test
- [ ] Verify calling conventions, signedness and struct layouts independently of byte equality
- [ ] Approve a separate original-byte Ghidra analysis for WndProc, WinMain and GFX_OpenGraphics
- [ ] Benchmark additional compiler/flag candidates on a representative corpus before claiming original toolchain identity
- [ ] Add complete compiler-input/header dependency capture in pc-decomp before introducing shared headers
- [ ] Import detailed existing type members/references and improve unique-byte coverage accounting
- [ ] Design full-game link/run validation separately from per-function verification
- [ ] Approve explicit Nexus profiles/budgets/worktrees before implementing any autonomous campaign
