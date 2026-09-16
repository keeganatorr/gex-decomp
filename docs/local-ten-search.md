# Ten-function local batch — nine exact

User requested ten more functions in parallel, then explicitly chose **local-only
parallel preparation/tests with serial warm-compiler searches, no provider calls**.
The service was idle, paid campaign Stopped, baseline **425 exact / 15,911 bytes**.

Selected ten additional eligible 32–42-byte functions, all with no retained source
or compiler attempts. All ten passed complete-extent/current-Ghidra preflight. No
replacement targets were introduced. Each had at most **24 candidate probes /
60 seconds**, with fresh full verification of a usable finalist. Compiler, language,
flags and bindings stayed fixed: CL 10.00.5270, C++, `/O2 /G5 /Oy /GR-`.

## Parallelism and timing

- Ten concurrent preparation jobs; **ten simultaneous host GCC test compilers**
  observed from retained start/end intervals. These are synthetic host behavior
  checks, not the pinned compiler or byte proofs.
- **240 prepared variants, 25,728 host behavior checks**, all passed. Parallel
  preparation/test execution took approximately 0.318 s, excluding authoring the
  source hypotheses and harnesses.
- Exactly one owner-locked pinned compiler/verifier at a time. Ten serial CLI
  searches took **15.524 s wall time**, including startup/backup overhead;
  individual search timers sum to **12.526 s**. Median probe compile: **45 ms**.
- **46 probes + 9 fresh finalist verifications.** Eight functions matched on the
  first candidate; VCRDoIt matched on candidate 14. The blocked target consumed
  its 24-probe budget and was not retried with a new binding/budget.
- Nine further serial current-source verifications ran through the normal live
  publication queue. Those are **not included** in the search timing above.
  Total pinned-compiler invocations for this work: **64**.
- No proposal-provider calls, automatic campaign Resume, frontend/plugin change,
  executable/Ghidra writes or existing-function byte-audit sweep.

## Outcomes

| Entry | Function | Bytes | Probes | Search including finalist | Outcome |
|---|---|---:|---:|---:|---|
| 00415b90 | InitPlayerComeOutTube | 32 | 1 | 1.134 s | Exact, published |
| 00418b30 | SCRIPT_PlaySound | 32 | 1 | 1.072 s | Exact, published |
| 00418c50 | SCRIPT_AddWorkField | 34 | 1 | 1.101 s | Exact, published |
| 004101d0 | FUN_004101D0 | 36 | 1 | 1.071 s | Exact, published |
| 0043eea0 | FUN_0043eea0 | 37 | 1 | 1.075 s | Exact, published |
| 0041b070 | VCRDoIt | 38 | 14 | 1.902 s | Exact, published |
| 00404410 | LoadAvi_Clean1 | 39 | 1 | 1.082 s | Exact, published |
| 0041be80 | AddVisualScoreFromTable | 40 | 24 | 1.950 s | Unresolved symbol; no byte verdict |
| 004202d0 | PAR_ClearParallaxs | 40 | 1 | 1.077 s | Exact, published |
| 0043abe0 | FUN_0043ABE0 | 42 | 1 | 1.062 s | Exact, published |

**Nine new exact functions / +330 bytes. Current total: 434 exact / 16,241 bytes.**

## Evidence-informed reconstruction details

- InitPlayerComeOutTube passes the object to **both** helpers. Ghidra pseudocode
  omitted the second argument, but the actual push/call/stack cleanup establish it.
- SCRIPT_PlaySound passes the address of its cursor parameter to the byte decoder,
  then returns the updated cursor. Host stubs test update/call order and sound bits.
- SCRIPT_AddWorkField uses unsigned modulo-32-bit addition and returns the advanced
  byte pointer; no signed-overflow UB or fabricated object layout.
- FUN_004101D0 tests a helper result and conditionally passes the observed object,
  `0x500000` numeric argument and zero to the second helper.
- FUN_0043eea0 reads a **signed 16-bit** index at offset `0x12`, handles negatives
  without writes, clears the observed cache word with 20-byte stride and writes
  a 16-bit `-1` sentinel. The table access uses a pinned base plus observed offset.
- VCRDoIt uses wrap-safe unsigned decrement/increment and a sign test under the
  pinned x86 two's-complement conversion convention; tests include sign boundaries.
- LoadAvi_Clean1 declares the imported PostMessageA as four-word **stdcall** and
  sets the flag before the call. Host tests replace the import with a stub; they
  never post a real message. The actual IAT relocation is resolved by the verifier.
- PAR_ClearParallaxs models eight 12-byte records as the observed word span, releases
  nonzero handles before clearing them and leaves the other words unchanged. All
  256 presence patterns are tested; it does not fabricate an endpoint binding.
- FUN_0043ABE0 copies the observed word to the global, rereads for the first helper
  and passes the same object to the second, matching the actual assembly order.

Word/byte views, scalar return types, handle types and register declarations remain
reconstruction hypotheses. Exact bytes do not establish original C types, the full
GXObject layout, original table lengths or a globally proven original compiler.

## Blocked tenth target

Every AddVisualScoreFromTable probe encountered:

```
Unresolved relocation destination: _obs_0__gdat_points
```

That Ghidra-derived field spelling did not resolve through the current configured /
pinned symbol index. No relocation masking or guessed address was used, and no
source was published. This is a **symbol-evidence/identifier problem**, not a
measured byte mismatch or provider failure. Raw report status is `Exhausted`, but
all 24 probe rows are blocked and there is no full finalist verification.

There is an existing configured nearby binding at `0045ca38`; a reviewed table-root
plus field-offset source may be a useful next experiment. It has **not** been
compiled/resolved here and must not be advertised as an exact match. Repeating 24
identical unresolved-symbol failures was wasted work; future planning should check
required symbol spelling or stop that failed family earlier. No extra attempt or
replacement target was silently added to this batch.

## Publication and retained evidence

Only the nine fully verified candidates were copied to previously absent
`src/functions/<entry>.cpp`, with exclusive creation and source-hash checks. One
journaled normal queue command, **`local-ten-publish-v1`**, recompiled/verified all
nine serially. The blocked target remains source-less.

Current-source proof IDs:

- 00415b90: `attempt-7b8dbcbdbaa34ad39e518602614163af`
- 00418b30: `attempt-ac5632d03f0145ba8fd798fc839a139c`
- 00418c50: `attempt-699e4abd43f54e14bce561e8970722ab`
- 004101d0: `attempt-2af8fa3c40cb49ec957e38e7f8c5c7a2`
- 0043eea0: `attempt-c9e5480c2dae434eb06d0c5d64e610a4`
- 0041b070: `attempt-066e52dcdfa64bd1854f684d21c56256`
- 00404410: `attempt-55ed41484140498fac3055cb1427bbc1`
- 004202d0: `attempt-9a37641a654a4f69a0d61d5c30ac48c8`
- 0043abe0: `attempt-3e2a0d2149964883a6d269d5530660be`

`.work/local-ten-search/` retains the fixed selection, parallel preflight/timing,
source generator and independent host harnesses, behavior results, manifests,
serial run intervals, all outcomes, stopped-state backup and publication intent /
receipts / current proofs. Immutable compiler artifacts remain in `.work/searches/`
and `.work/attempts/`.

Used the already-tested immutable offline CLI
`.work/backend/source-search-c4ed997dd21733a0/PcDecomp.dll`, verifying its complete
file-hash manifest before execution. The live daemon and CLI link remain on
`parallel-738d0f450e51f142`; the original service was restored after searching.
The paid campaign remains Stopped, with no queued/running work after publication.
Read-only SQLite projections confirmed **all 425 prior proof/source metadata records
unchanged**, without recompiling or byte-auditing them. `preservation.json` also
records unchanged raw configuration and pinned executable SHA, absent source for
the blocked target, and the active original service/link.
