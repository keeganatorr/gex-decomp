# Gex decompilation

## Done — reproducible first baseline
- [x] Preserve GOG executable and existing edited Ghidra project; pin original hash
- [x] Update GhidraMCP for the installed Ghidra and reconnect after user save/restart
- [x] Recover historical compiler flags; identify actual CL 10.00.5270 rather than MSVC 2010
- [x] Import 1,335 non-external functions and 1,116 inherited type inventory entries
- [x] Identify five edited code bytes in three functions and block those matches
- [x] Verify 00420d30 (7 bytes, DIR32) and 00418e20 (10 bytes, REL32) exactly
- [x] Run the separate durable pc-decomp service and register its Nexus service identity
- [x] Provide online verification/build scripts and retain immutable attempts
- [x] Validate live protocol/schema, backend restart/reconnect and idempotent build queries

## Operator UI
- [ ] In Decomp select Data source = real, service = pc-decomp, project ID blank; inspect live Functions and Function Lab

## Next — manual source reconstruction, not an autonomous campaign
- [ ] Choose a nontrivial unpatched function and reconstruct self-contained C/C++ with justified bindings
- [ ] Verify calling conventions, signedness and struct layouts independently of byte equality
- [ ] Approve a separate original-byte Ghidra analysis for WndProc, WinMain and GFX_OpenGraphics
- [ ] Benchmark additional compiler/flag candidates on a representative corpus before claiming original toolchain identity
- [ ] Add complete compiler-input/header dependency capture in pc-decomp before introducing shared headers
- [ ] Import detailed existing type members/references and improve unique-byte coverage accounting
- [ ] Design full-game link/run validation separately from per-function verification
- [ ] Approve explicit Nexus profiles/budgets/worktrees before implementing any autonomous campaign
