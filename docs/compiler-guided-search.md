# Bounded compiler-guided search: two-target benchmark

User-approved after the parallel trial was already **Stopped**, zero active jobs.
No additional proposal-provider calls, compiler/flag changes, fabricated bindings,
Ghidra writes, raw-byte injection, inline assembly or whole-project byte audit.

## Results

Fixed recovered CL **10.00.5270**, C++, `/O2 /G5 /Oy /GR-` throughout.

| Target | Initial local search | Distinct outputs | Result |
|---|---:|---:|---|
| `0042dcf0 Object_unk` | 96 candidates, 321.6 s including final verification | 5 | No exact; current source untouched |
| `0040bc50 PrintStringInner` | **2 candidates, 10.54 s including full verification** | 2 | **28-byte exact candidate** |

The arithmetic target had exhausted six provider attempts in the preceding
Luna/Terra/Sol trial: four compiling mismatches and two failures. The finite local
family found an exact candidate on its second variant. This is one success out of
two targets, not a claim of a universal search solution.

The winning source preserves the `-1` sentinel/no-store path and uses an unsigned
32-bit addition before masking to 31 bits. It varies operand order and a register
parameter declaration. All these are provisional source/type choices, **not proof
of the original author's declarations**. The previous signed-add source also had
a potential signed-overflow issue; the reviewed family avoids signed-overflow UB.
No layout is guessed or dereferenced for the pointer-identity target.

## Measured speed improvement

Wine/background services inherited compiler capture pipes, delaying EOF by about
three seconds even after CL exited. The optional backend-owned cache now starts a
bounded persistent server and bootstraps Wine with null descriptors. It preserves
all actual compiler arguments, source inputs and relocation checks, then stops its
own cache after serial compilation drains.

Same-input cold/warm comparison:

| Target / same input prefix | Cold median compiler | Warm median compiler | Warm whole search + full verification |
|---|---:|---:|---:|
| `0042dcf0`, 16 candidates | ~3.3 s | **45 ms** | **2.022 s** |
| `0040bc50`, first 2 candidates (exact stop) | 3.303 s | **46.5 ms** | **1.180 s** |

All **18 resolved output hashes were identical** to their cold counterparts.
Roughly **70× less per-compile overhead** is a local microbenchmark, not a guarantee
for model latency, other compilers or whole-project decompilation. The 96-candidate
search was not rerun warm merely to improve the headline number.

Two earlier cache-wiring experiments failed: one held daemon capture pipes open,
and the second exposed bootstrap-service pipe inheritance and timed out its first
probe. They are retained as failures, **not** included in the successful timing
comparison. The failed orphan was explicitly reconciled/cleaned up. All services
were restored. Including diagnostic repeats, there were 132 probe launches (one
failed deadline) and six full verifications, including publication: **138 local
compiler invocations**. There were still only 96 distinct tested source variants
for the first target and two for the second.

## Publication and preservation

- Cold candidate proof: `attempt-276f64568e4a4ce2af01baefddb975dd`.
- Warm candidate proof: `attempt-43faba3ec57740008ed387c290290902`.
- Source SHA256: `8b37601d80957b2079d215a09a6e147101d49c497ca13ab9f53776d5f0be7b9c`.
- After verifying the current source/config basis and retaining the old source,
  copied the exact candidate into `src/functions/0040bc50.cpp` and submitted one
  normal durable verification job: `compiler-search-publish-v1-0040bc50`.
- Current-source proof: **`attempt-8f33c077326c4e6582bf8fe00019f61a`**.
- Both DIR32 relocations resolve `_DAT_00456034` to pinned **`00456034`**.
- **423 → 424 exact functions; 15,854 → 15,882 exact bytes.**
- Read-only SQL projection confirmed every prior exact match/source-revision
  metadata record unchanged. No existing source was recompiled for this check.
  Previous-proof metadata digest:
  `60503fd0439e91f479eb962602960da551b22faf3e36c66af4744087d565faf6`.
- Pinned executable and `project.json` hashes unchanged; `0042dcf0` source
  unchanged. Ghidra/EditedGex remained read-only. Prior parallel run remains
  Stopped and no campaign was resumed.

## Implementation and usage

- `pc-decomp/src/PcDecomp/SourceSearch.cs`: owner-locked finite probing, durable
  receipts, exact-source/output caches, instruction ranking and full finalist
  verification. Probes never become current proofs or publish source themselves.
- `tools/source_variants.py`: **Gex-specific** reviewed semantic families. No game
  identities or source templates were added to backend `src/`.
- `tests/source_variants.py`: deterministic/unique generation plus host C++98
  behavior checks of 256 bounded variants per family against directed and seeded
  inputs (including equal/unequal pointers, call arguments, sentinel and wrap).
  Host tests are explicitly not byte proofs.
- Backend Release/selftests and full synthetic integration passed
  (`/tmp/pc-decomp-test-zo4e81xf`); latest focused checks
  (`/tmp/pc-decomp-test-dai021wr`) cover unsafe inputs, owner lock, pinned basis,
  duplicate source/output, exact stop/full verification, source preservation,
  replay, changed payload and interrupted-command refusal. Tests never use game
  assets or actual Wine. Native Wine timing was separately checked above.

Successful final immutable **offline CLI**:
`.work/backend/source-search-71798fd69a6e50ae/PcDecomp.dll`.
The live daemon and `backend-current` remain on the previously activated parallel
release. This prototype is **not yet integrated into automatic campaigns/UI**.

Example for a future explicitly approved unresolved-target experiment:

```sh
python3 tools/source_variants.py --project . --detail /saved/function-detail.json \
  --output /new/manifest.json --limit 96 --seconds 600 --keep-compiler-warm
# Drain campaigns/manual work, stop the service, acquire owner through the CLI:
dotnet .work/backend/source-search-71798fd69a6e50ae/PcDecomp.dll search \
  --project . --manifest /new/manifest.json --command-id NEW_STABLE_ID
# Restart the original service afterward; do not blindly replay uncertain work.
```

Do not rerun the published arithmetic target or invent replacement targets/budgets.
The generic [backend search contract](../../pc-decomp/docs/source-search.md)
describes all bounds and recovery behavior.

## Evidence and next limitation

`.work/compiler-search-transition/` retains stopped loop/target snapshots,
manifests, immutable CLI identities, stopped-state backup, cold/warm results and
failures, publication intent/receipts, final live state, test logs, `implementation.json`
(file hashes) and `preservation.json`. Individual artifacts
live under `.work/searches/` and `.work/attempts/`.

The unresolved compare/call function canonicalized 96 variants to just five
outputs. Its best remains 27/27 bytes with 17 equal positions; global/argument load
and compare-operand ordering differ. Repeating cosmetic syntax or escalating the
same model prompt is poorly justified. A next experiment needs a new assembly-
derived source family or an explicitly approved compiler-contract hypothesis,
not fabricated semantics or a looser verifier. No such next run is started here.
