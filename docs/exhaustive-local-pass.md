# Exhaustive eligible local pass — completed

The user authorized an exhaustive **local-only** pass over every currently
reconstruction-eligible unresolved function, with the previous bounded policy of
up to **24 candidates and 60 seconds per function**. Confirmed libraries/import
thunks were excluded. No providers, campaign Resume, executable/Ghidra changes,
configuration changes, relocation masking or full existing-proof audit were used.

## Baseline and coverage

At the frozen inventory (stored in `.work/exhaustive-pass/inventory.json`):

- 1,323 imported records; **434 exact / 16,241 bytes**.
- 889 unmatched records.
- 858 reconstruction-eligible unresolved records.
- 31 excluded records: 28 confirmed library functions and 3 import thunks.
- Campaign Stopped, no queued/running tasks.

All 858 eligible records received a durable outcome:

- **485** received bounded local searches.
- **373** were safely blocked before compilation: 357 reconstruction/declaration
  blockers, 15 incomplete/edited analysis preflight blockers, and one oversized
  `00409970` detail/body that exceeds the transport/search bounds.

The 15 preflight blockers include edited-Ghidra or incomplete/nonterminal extents;
those were not trimmed or treated as complete. The 357 reconstruction blockers
include unrecovered register/stack inputs, incomplete object layouts, unsupported
CRT types, and unresolved declarations. No guessed binding was added.

## Search and publication results

Searches ran in 20 checkpointed batches of 25 (the last had 10). Preparation and
synthetic host checks were separate from proof. The pinned CL 10.00.5270 C++
compiler remained the sole serial compiler owner with `/O2 /G5 /Oy /GR-`.

- **3,568 bounded probe compilations** and 487 distinct resolved output hashes.
- 482 usable finalists received a fresh full verification; 3 targets had no
  resolvable output and no finalist.
- Summed search timers: **789.505 seconds** (~13m10s), including preflight,
  warm setup and finalist verification; batches were serial and service downtime
  was restored between batches.
- 480 finalists were verified non-exact; 3 searches exhausted/blocked without a
  finalist. Heuristic shape/byte-position scores never established proof.
- Two new exact results, both candidate `v000`, were published via the normal
  durable queue command `exhaustive-local-publish-v001-retry`:

| Entry | Bytes | Search proof | Published current proof |
|---|---:|---|---|
| `0044a0a0` | 18 | `attempt-aedc2c7020e8463492c58c2bf08c50b6` | `attempt-66011cdea5434489ae5c2ed1e4e045de` |
| `0040f500` | 20 | `attempt-ccb0ec59382a4c62bc18114288cb9156` | `attempt-8b2d81707f2d401b8af0224057c551a5` |

Both already had source files; the exact candidates matched those retained source
bytes, and normal verification confirmed their current proofs. No source file
was changed by the search batch.

**Final: 436 exact / 16,279 bytes; 887 unmatched records.** The reconstruction
projection is 436 exact / 856 unmatched. The service is active, the paid campaign
is Stopped, and queued/running work is zero.

## Important limitation

This was exhaustive with respect to the approved deterministic local pipeline, not
a guarantee that every function can be reconstructed. The generic candidate
adapter could safely prepare only 485 functions. It mostly tested retained or
Ghidra-derived proposals plus conservative source/code-generation spellings;
repeated output hashes were deduplicated and family saturation was reported as
uncompiled, not disproved. The 373 blocked functions need new evidence, explicit
ABI/layout recovery, symbol resolution or independent extent work. In particular,
`0041be80` remains blocked by unresolved `_obs_0__gdat_points`; no address was
fabricated.

The exhaustive pass does not authorize changing compiler language/flags, repairing
EditedGex, or rerunning the blocked functions with guessed declarations. Any new
attempt requires a genuinely new reviewed hypothesis and a new bounded command.

## Evidence and preservation

`.work/exhaustive-pass/` retains the inventory, all fetched details, deterministic
candidate manifests, generation blockers, 20 batch selections/results, immutable
search reports, stopped-state backups, publication intent/receipt, and
`final.json`. Read-only preservation checks confirmed:

- all 434 pre-pass exact proof metadata records unchanged;
- project configuration unchanged;
- pinned executable SHA remains
  `e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`;
- no source set changes during searching;
- service active, campaign Stopped, no queued/running jobs.
