# Full-game source coverage — phase 1

The user requested a complete game decompilation. This phase establishes source
coverage separately from exact-byte reconstruction. The pinned executable and
EditedGex remain read-only; existing `src/functions` sources are not overwritten
by automated provisional output.

## Frozen baseline

At the baseline snapshot:

- 1,323 imported function records;
- **436 exact / 16,279 bytes**;
- 887 unmatched records;
- 405 records had no `src/functions/<address>.cpp` file;
- 379 of those were reconstruction-eligible and 26 were confirmed
  library/import-thunk records;
- 824 records had caller/callee data available for prioritization.

The complete baseline and call-graph fields are in `.work/full-source-coverage/baseline.json`.
`dependency-priority.json` ranks shared callees by unresolved eligible caller count.

## Provisional coverage artifacts

For all **379 eligible source-less functions**, `.work/full-source-coverage/provisional/`
contains the fetched detail and Ghidra pseudocode. Where the deterministic
proposal adapter could produce a candidate, it also contains `provisional.cpp`;
otherwise it retains pseudocode plus an explicit blocker.

Results:

- 7 provisional candidates passed local syntax checking;
- 328 provisional candidates remain noncompiling because of missing declarations,
  object layouts or recovered types;
- 43 are pseudocode-only because ABI/register/unsupported-input checks failed;
- 1 is analysis/transport-blocked: `00409970` has an oversized 218,888-byte body.

These are review artifacts, not current sources or proofs. A pseudocode listing is
not silently promoted to compilable C++, and a guessed struct layout or function
prototype is not introduced just to improve coverage.

The main blocker classes are:

- 145 undeclared symbols or missing pinned declarations;
- 115 unknown types (graphics/Windows/CRT contracts);
- 62 incomplete `GXObject` layout/member accesses;
- 6 other source-reconstruction errors;
- plus 15 incomplete/edited extent blockers and unrecovered-register cases.

## First high-impact resolution

The most frequently called missing source was `assertfail_00405350`, called by 38
unresolved functions. Assembly inspection established its 0x100-byte local buffer,
debug gate at pinned address `004879f4`, varargs pointer, and stdcall imports. A
24-candidate bounded local search matched candidate `v000` exactly (63 bytes), then
normal durable verification published it as:

- search proof: `attempt-aedc2c7020e8463492c58c2bf08c50b6`;
- current proof: `attempt-d16cf5f900a74c1797b59924428ac917`.

This raised the project to **437 exact / 16,342 bytes**. The source is
`src/functions/00405350.cpp`. The type/varargs spellings remain source hypotheses;
exact bytes do not prove the historical API declaration.

A focused follow-up on `OBI_CheckRemoveObject_0040fce0` (23 unresolved callers)
used its observed offsets and camera bounds. Three bounded 24-candidate revisions
were retained. The best output is 108 bytes with 104/108 positions equal; the four
remaining differences are signed-versus-unsigned conditional jumps. It was not
published or labeled exact. This is useful reverse evidence, but needs one more
code-generation hypothesis rather than cosmetic retries.

## Current state and next work

The service is active, the paid campaign is Stopped and queued/running work is
zero. Existing proof/source metadata and configuration remain preserved. Current
priority is dependency contract recovery, in this order:

1. pinned declarations for shared debug/platform functions and globals;
2. shared graphics/tile contracts (`00441150`, `00444590`, `0042d2c0`);
3. opaque object field maps derived from independent instruction offsets, without
   pretending they recover the original C++ struct;
4. unrecovered register/stack inputs and incomplete extents;
5. exact-byte searches only after a source candidate has a justified contract.

The next phase should turn the provisional artifacts into reviewed, compilable
source in small dependency clusters. It must not mass-install noncompiling
pseudocode into `src/functions`, change compiler language/flags globally, repair
EditedGex, or claim full-game exactness from source coverage alone.
