# Hand decompilation by Claude, and what it taught the tooling — 2026-09-25/26

No campaign, no provider calls from the loop: one interactive agent (Claude,
in a Nexus/Claude Code session) decompiling functions directly with a fast
scratch compiler, then publishing through the normal durable queue.

**Result: 752 → 773 exact proofs, 63,353 → 66,802 exact bytes (+21 / +3,449).**
Every proof is a current `scripts/verify` receipt under
`.work/claude-hand-decomp-20260925/` (`verify-<address>.json`, sources, prior
working sources). No project.json, compiler, binding, Ghidra or proof-status
edits; the backend kept serving throughout.

| Function | Bytes | Before | Lever |
|---|---:|---:|---|
| `0042dcf0` Object_unk | 27 | 63.0% (21 attempts, 96-variant search) | declaration order |
| `0043b9e0` ob259DoIt | 398 | 99.5% | declaration order |
| `004196e0` GOB_AddObjectByIndex | 344 | 99.4% | declaration order |
| `004237c0` pStateUnk | 53 | 92.5% | reverse declaration order (1 of 24) |
| `00419520` GOB_RemoveObject | 175 | 97.7% | 6 padding declarations |
| `00423800` pStateUnk | 264 | 99.2% | 6 padding |
| `00429190` | 102 | 98.0% | 6 padding |
| `0042e8b0` Call_Event_call | 126 | 99.2% | 1 padding |
| `00437010` RezOutDraw2 | 350 | 99.4% | 3 padding (schedule difference) |
| `00439090` GOB_ProcessXPositionChange | 63 | 85.7% | 8 padding |
| `0040f1d0` GetGlueDist | 138 | 95.7% | 1 padding |
| `004018b0` LoadVFX | 225 | 97.3% | 2 padding |
| `0041e7e0` CLD_AddObjectCollision | 157 | 93.0% | 2 padding |
| `004195d0` GOB_AddObject | 257 | 92.2% | 1 padding (also matches as C) |
| `004404b0` | 82 | 43.4% | 2 padding (also matches as C) |
| `00429b40` RemoteFindWithLevel | 63 | 90.5% | 10 padding |
| `00433590` SCRIPT_DoEvent | 85 | 95.3% | 14 padding |
| `004390d0` GOB_ProcessYPositionChange | 63 | 93.7% | natural field access |
| `004213f0` GexMovementLeftAndRight | 213 | 98.6% | natural if/else + fields |
| `00421820` pStateUnk_Duck | 127 | 95.3% | one 40-byte local buffer |
| `00431900` Movement_unk | 137 | 96.4% | natural field access (the retained source used `volatile` to force a load) |

## What the problems were

1. **The loop cannot iterate.** A model gets one compile per turn and a turn
   costs minutes; matching VC4 output needs dozens to hundreds of compiles.
   With a warm Wine server one compile costs ~0.1 s. `tools/probe.py` and
   `tools/perturb.py` exist for that; the backend now runs the perturbation
   itself (below).
2. **Most near misses were not source problems.** Operand order, register
   choice and even instruction schedule follow the compiler's internal symbol
   numbering, which unused declarations and declaration order move and body
   edits cannot ([knowledge/symbol-numbering.md](knowledge/symbol-numbering.md)).
   Semantic search families and model turns spent on these were wasted.
3. **Ghidra shapes the source badly.** `GXObject **` parameters, cached-field
   locals, goto-shaped control flow and split stack buffers each produced a
   stuck near miss; natural code with Ghidra's own member names matched on
   the first compile ([knowledge/natural-field-access.md](knowledge/natural-field-access.md)).
   Loop prompts carry no struct layouts, and the prompt forbade "padding tricks".
4. **Some residue is the compiler, not the source.** The executable was linked
   by linker 4.20 on 1996-09-12 (VC++ 4.2 era); the pinned compiler is CL
   10.00 (VC++ 4.0). Two idioms have zero proofs and a reviewed negative
   search: a narrow bit-31 mask before a shift (31 functions) and noreturn
   `_exit` tails (4). ([knowledge/toolchain-limits.md](knowledge/toolchain-limits.md))
5. **Score is not semantics.** `0042de50`'s 93.9% best passes both arguments
   swapped; the correct source scores 81.8%. Best-score preservation keeps the
   wrong one.
6. **`scripts/verify` reported five fresh exact proofs as "no current proof"
   (exit 2).** The client re-checked used bindings against project.json only;
   symbols resolved through the pinned symbol index failed that check. Fixed in
   pc-decomp `RemoteClient.ProofCurrent` (not yet deployed; the published
   proofs were always current in the service).
7. **Interactive Ghidra MCP was dead.** The Claude desktop config runs the old
   `GhidraMCP/bridge_mcp_ghidra.py --ghidra-server http://127.0.0.1:8080/`;
   Ghidra listens on 8089 with the newer plugin, which the shared bridge
   (`~/src/ghidra-mcp`, default 8089) already speaks. Agents fell back to raw
   HTTP (`/decompile_function`, `/get_struct_layout`).

## What changed

- gex-decomp: `tools/probe.py`, `tools/perturb.py`, `tools/ghidra_struct.py`,
  `tools/idiom_scan.py`; the executable knowledge base `docs/knowledge/`
  (`recipes.json` + `tests/knowledge_checks.py`, 15 checks against the real
  compiler); `docs/memory/knowledge-lessons.json` for schema-7 memory.
- pc-decomp: `Perturbation.cs` — after a compiled same-body near miss
  (operand-order, register-rename, or same-length ≥ 75% general), the loop
  searches declaration orders and padding provider-free, verifies the winner
  from scratch and publishes it like any proposal. Opt-in per project:
  `"policy": {"perturbationSearch": {"maxProbes": 160, "maxSeconds": 90}}`.
  Capability `loop-perturbation-v1`. Diagnostics and prompt now describe the
  lever instead of forbidding "padding tricks". `RemoteClient.ProofCurrent`
  fix. Selftests and every integration suite pass, plus a new
  `--perturbation-only` end-to-end suite.

Not deployed: the running service is still the staged
`function-time-b3b4984fd40aa68a`; activating needs an immutable stage, a
service restart and the project.json opt-in.

## Left alone on purpose

- CRT functions (78 unmatched in 0x449000+, 19.7 KB): Microsoft's CRT source is
  on disk (`NTSource/base/crts/crtw32`) and compiles to exact bytes as C with
  `/O2 /G3` for 16 of 19 tried, some needing bindings for CRT globals (`errno`,
  `_iob`, `__sbh_threshold`, …). Deprioritised by the operator; drafts in
  `.work/claude-hand-decomp-20260925/crt-leads/`, nothing published.
- Near misses no lever reached: `00420210`, `00431900`, `0041f860` (single
  register/schedule difference), `0042de50` (see above), `00411ff0`/`00412750`
  and the rest of the narrow-mask family.
