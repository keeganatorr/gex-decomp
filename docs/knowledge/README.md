# Gex decompilation knowledge base

What we have learned about making CL 10.00 emit the original bytes, written so
the next agent starts from it instead of rediscovering it. Every recipe in
[recipes.json](recipes.json) carries executable checks that
`python3 tests/knowledge_checks.py` re-runs against the pinned compiler: a
recipe is only as good as its checks, and a failing check means the recipe is
stale.

## The fast loop

The durable queue is the only way to publish, but it is the slow way to
experiment. Iterate with probes first:

```sh
tools/probe.py 0042dcf0 candidate.cpp -d      # compile + relocated byte diff, ~0.1 s warm
tools/probe.py 0042dcf0 candidate.cpp --lang both -q
tools/perturb.py 0042dcf0 candidate.cpp --moves --write exact.cpp
tools/solve.sh 0042dcf0 candidate.cpp          # everything below in one go; prints SOLVED:<file>
tools/blockperm.py 0042dcf0 candidate.cpp       # every order of each 2-6 statement run
tools/mvperm.py / tools/lperm.py / tools/stperm.py  # single moves / local declaration orders / adjacent swaps
tools/best_attempt.py 0042dcf0                  # the best recorded loop attempt's source, to start from
tools/sweep_attempts.py                         # after a verifier or binding change: old attempts now exact
tools/idiom_scan.py 00412750                   # is the rest a known toolchain limit?
tools/ghidra_struct.py GXObject --only 8c,90,94 # real member names for a self-contained TU
./scripts/verify 0042dcf0 my-stable-command-id  # publish: the only step that creates proof
```

`probe.py` mirrors the verifier (same compiler, flags, overrides, COFF section
rules, DIR32/REL32 resolution through bindings then the pinned symbol index),
reads the backend database read-only and writes nothing outside
`.work/probes/`. A probe at 100% should verify; only `scripts/verify` proves.

## Triage: what the diff says to do

| Diff after the body is logically right | Do this | Recipe |
|---|---|---|
| `cmp a, b` vs `cmp b, a` (mirrored jcc), SIB base/index swapped, different scratch register, one independent instruction moved | Stop editing the body. `tools/perturb.py --moves`, then `--languages cpp,c` | [symbol numbering](symbol-numbering.md) |
| Ghidra-shaped locals (`int a = p[0x25]`) or goto-shaped if/else; compares, loads or one branch inverted | Real member names, re-read fields through the pointer, plain if/else | [natural field access](natural-field-access.md) |
| `sub esp, N` and every `[esp+k]` differ, instructions the same | One local aggregate has the wrong size: size it from the frame and the `lea` passed to the callee | [natural field access](natural-field-access.md#stack-frames) |
| Registers differ and the arguments pushed are in the other order | Check the push order first: a higher-scoring source can be semantically wrong (0042de50) | `score-rewards-wrong-semantics` |
| `and r, 0x80000000` vs `0x8fffffff` before a shift | Toolchain-limited. Record and move on | [toolchain limits](toolchain-limits.md) |
| Body ends in `call _exit`, candidate adds `add esp; ret` | Toolchain-limited and verifier-refused | [toolchain limits](toolchain-limits.md) |
| Same instructions, blocks in another order; a branch placed at the end; a jump table of another length; a load/store moved across another | A source shape, not numbering: see the tables | [source shapes](source-shapes.md) |
| Different instructions, lengths or constants | Semantic difference: read the target asm, not only the pseudocode (widths, hidden stack arguments, signedness of shifts/compares) | `docs/memory/historical-lessons.json` |

Order matters: perturbation only helps once the body compiles to the right
instruction multiset, and it is cheap enough to try on every compiled near miss.

## Recipes

| Recipe | Status | Result so far |
|---|---|---|
| `symbol-numbering-padding` | verifier-proved | 13 functions exact |
| `symbol-numbering-declaration-order` | verifier-proved | 4 functions exact, incl. 0042dcf0 after 96 failed semantic variants |
| `front-end-language-switch` | probe-observed | 2 functions (both later also matched in C++) |
| `natural-field-access` | verifier-proved | 004390d0, 004213f0, 00431900 (first try each) |
| `stack-frame-aggregate` | verifier-proved | 00421820 |
| `score-rewards-wrong-semantics` | probe-observed | 0042de50: the 93.9% best has swapped call arguments |
| 14 source-shape recipes (`abs-branch-vs-ternary`, `if-else-source-order`, `explicit-empty-case-labels`, `com-c-style-vtable`, …) | verifier-proved | each one an exact function plus a counterexample check; [source shapes](source-shapes.md) |
| `narrow-mask-shift` | toolchain-limited | 31 unmatched functions, 0 exact |
| `noreturn-tail` | toolchain-limited | 4 unmatched functions, 0 exact |

Older lessons from the EditedGex checkpoint (inlined `memset` for zero fills,
wrappers forwarding a hidden stack argument, the `/G3` argument-reader contract)
live in `docs/memory/historical-lessons.json`; `docs/iterative-editedgex.md`
has their evidence.

## Adding knowledge

A lesson belongs here when it would have saved a future attempt, with:

1. an entry in `recipes.json`: symptom, action, the functions it fixed, and
   caveats about what it does *not* prove;
2. at least one executable check — an `exact` check on a published source and,
   where the lever is the point, a `differs` counter-example showing that
   without it the bytes do not match;
3. a short doc page with the evidence and the experiments that failed.

Negative knowledge counts: a reviewed family with zero proofs
(`toolchain-limited`) saves as much time as a new trick. Never record a probe
percentage, a model's claim or a historical best score as proof.

`docs/memory/knowledge-lessons.json` restates these recipes in pc-decomp's
`pc-decomp-historical-lessons-v1` format so the schema-7 project memory can
retrieve them into loop prompts. Keep the two in step.
