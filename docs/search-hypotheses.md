# Search improvement: exit-register evidence and bounded hypothesis families

Follow-up to the failed [20-byte fresh-function test](fresh-small-search.md).
Scope stayed on **0044c690**. No proposal-provider calls or automatic campaigns,
no compiler/flag/language/binding changes and no source publication.

## What changed

1. **Architectural exit provenance.** `tools/search_feedback.py` follows bounded,
   supported x86 control flow and tracks whether EAX still contains a helper's
   result at each return. Writes to EAX/AX/AL/AH invalidate that provenance;
   writes to CL do not. Cycles, unknown instructions, indirect transfers, gaps and
   incomplete extents fail closed. This is a diagnostic, **not an ABI/type proof**.
2. **Relocation-aware diagnostics.** Direct transfer destinations are lifted from
   retained **resolved bytes**, not zero COFF relocation placeholders. LLVM still
   supplies instruction extents/opcodes/register operands. A regression verifies
   that a relocated tail jump is not mistaken for a jump to the following RET.
3. **Reviewed source hypotheses before syntax permutations.** The conditional
   cleanup template requires the actual complete call/byte-compare/branch/tail/
   return pattern and pinned targets. The initial void assumption is no longer
   the final generator's fallback: both final families preserve first-helper or
   tail-callee return bits.
4. **Optional empirical family saturation.** Backend manifests may give candidates
   a `family` and set `familyDuplicateLimit` (2–16; default 0/disabled). After that
   many consecutive repeated outputs within one family, its remaining candidates
   are marked `SkippedFamilySaturation`, **not tested or disproved**. A new output
   resets the streak; other families still get their own opportunities. A novel
   source still needs compilation to discover its output. This heuristic may skip
   an unseen exact candidate; the manifest retains all skipped inputs.
5. **No automatic repeated hypothesis.** With retained feedback showing that the
   return-preserving family was already explored, or no lost call result, the
   generator refuses to emit another cosmetic retry. It does not invent another
   source family, switch compiler contracts, call a model or dispatch a campaign.

The source generator records its evidence/priority plan separately from the
backend manifest. The backend's exact-byte verdict, fresh full finalist Verify,
owner lock, source/config guards and publication separation remain unchanged.

## Actual benchmark — still no exact match

Original architectural behavior: first helper runs; one byte is tested; zero
returns with that helper's EAX bits intact, nonzero tail-transfers to the second
helper. This does **not** prove the historical C function returned an integer.

**Initial improved pass:** up to 12 candidates / 60 seconds; 6 compiled,
6 explicitly skipped, 2 distinct outputs, **1.376 s including full verification**.
The ordinary return-preserving family changed the compiler output from loading
AL (corrupting the low return byte) to loading CL, preserving EAX. But it still
used MOV/TEST rather than the original direct memory comparison: **21 vs 20
bytes**, not exact. The initial pass retained a void control family, which had the
old 20-byte mismatch and a better purely structural score. The final generator
removes that weaker control rather than prefer lost register fidelity because it
is shorter. Search: `search-af7698882f25c412cdecc938`.

**One access-family follow-up:** 3 compiled / 3 explicitly skipped, **1.222 s
including full verification**. It requests one observable byte read through a
volatile-qualified lvalue, while preserving the same return bits and call order.
This is a provisional access model, **not a recovered volatile global declaration
or synchronization guarantee**. It introduced no extra memory access, raw address,
assembly or setting change. It emitted the same 21-byte return-preserving output,
so it did **not** solve the mismatch. Search: `search-f74b600d839eb732ddb6443c`;
full verification `attempt-ded1d6445f81495dbc4a1fda0bd5a160`.

Across both phases: **9 probe compilations + 2 full verifications**, 2.598 s of
recorded search time, below the announced 12-probe/60-second bounds. Timings exclude
implementation, tests and service restart overhead. The final generated source
corpus was compared against the retained evaluated family corpora; it was not
rerun simply to produce a better headline number.

The ordinary and qualified-read hypotheses preserve EAX, but both still compile:

```
movb flag, CL
testb CL, CL
```

instead of `cmpb $0, flag`. All three relocations resolve. The experiment establishes
better diagnosis and less repeated work, **not a new exact match**. No source was
published; **424 exact / 15,882 bytes** remain. The live service was restored after
each owner-locked experiment; the paid campaign remains Stopped.

A further test needs a genuinely reviewed hypothesis, potentially the C versus
C++ compiler contract given the runtime-like function. That is **untested** and
must not silently change the pinned project contract. No such run is started.

## Tests and artifacts

- Release build: zero warnings/errors; backend selftests pass.
- Full synthetic backend suite: `/tmp/pc-decomp-test-noozaqq4`.
- Focused search tests: `/tmp/pc-decomp-test-3brfx2qb`; test family-local saturation,
  new-output reset, legacy-disabled behavior, another family's chance to match,
  explicit skipping even of a synthetic exact candidate, no publication, receipts
  and preserved current source/proof. No real Wine/game in backend integration.
- `tests/search_feedback.py`: **6 tests**, including **98,304 host behavior cases**
  for the 12 final variants, all flag bytes, helper-updated flags, call ordering and
  arbitrary first/tail return bits. These are not exact-byte proofs.
- Existing `tests/source_variants.py`: **2 tests** pass.
- Feeding the latest retained result back to the generator correctly refuses a
  repeated hypothesis before writing a new manifest or invoking a compiler.

Evidence: `.work/liveout-search/` and its `access/` subdirectory. The old staged
plan with uncorrected COFF-placeholder diagnostics remains explicitly named
`manifest.plan-before-relocation-fix.json`; it is superseded, not current evidence.
All compiler/verification artifacts are retained under `.work/searches/` and
`.work/attempts/`.

New **offline-only** CLI: `.work/backend/source-search-c4ed997dd21733a0/PcDecomp.dll`.
The live daemon/link still use `parallel-738d0f450e51f142`; no Nexus/plugin deployment
or restart was needed. Old search CLIs reject the new family fields rather than
silently ignore the policy. Game-specific templates remain outside backend src/.
