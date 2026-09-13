# Ten-function reconstruction batch

Ten **additional** functions were reconstructed as self-contained C++ candidates.
Eight are verified ExactMatch; two compile but do not match. These were deliberately
small, unpatched gameplay/support routines, not a representative random sample of
the executable. No CRT stubs were selected to inflate the count.

## Results

| Address | Existing analysis name | Bytes | Current result | Attempts |
|---|---|---:|---|---:|
| 0040b390 | LINK_RESOLVE | 31 | ExactMatch | 1 |
| 0040f5e0 | FilterInputForJustOn | 37 | ExactMatch | 1 |
| 00417f00 | SCRIPT_GetUInt | 49 | Compiles; 83.67% positional bytes | 6 |
| 00417f40 | EVENT_ExtractUShort | 28 | Compiles; 78.57% positional bytes | 6 |
| 00420bc0 | GOB_ResetState | 74 | ExactMatch | 1 |
| 00428c60 | UTL_ReallyRandom32 | 30 | ExactMatch | 1 |
| 00428c80 | UTL_ReallyRandom | 58 | ExactMatch | 1 |
| 00429c60 | GOB_FindFirstWithType | 46 | ExactMatch | 1 |
| 0042cc20 | LST_RemTail | 34 | ExactMatch | 2 |
| 004317e0 | GOB_ResetPos | 54 | ExactMatch | 1 |

**364 new exact bytes**, out of 441 selected bytes. Together with the two original
baseline functions, the project now has **10 / 1,335 exact functions, 381 exact
bytes**. The denominator 525,887 remains the sum of imported enclosing spans,
not unique code coverage. The two remaining candidates are `Compiles`, not
`NearMatch`: the backend reserves that label for positional scores of at least 90%.

All 21 attempts compiled; seven functions matched on their first attempt and the
list-tail routine on its second. Attempt execution (start to result, excluding
queue wait) was 3.49–3.59 seconds, median 3.51 seconds. No uncertain commands,
compiler-flag changes, new compiler deployment, or autonomous model workers were
needed. The backend was stopped while idle once to add explicit symbol bindings.
That safely retired the old baseline proofs; both baseline functions were then
reverified with the new configuration.

## What was recovered

- **Packed links:** bits 20..30 select a four-byte table entry; bits 1..19 give
  an even byte offset into its pointed-to allocation. A byte-pointer result avoids
  inventing an object stride.
- **Input edges:** records have stride 0x24 and the previous button mask at +8;
  computes `new & ~old` and retains the new mask. `InitControllers` independently
  corroborates the record stride and global pointer. Unknown fields remain unnamed.
- **Byte readers:** little-endian 16/32-bit values with cursor advances of 2/4.
  Ghidra's UShort pseudocode presents a uint dereference, but disassembly reads
  **two individual bytes**, not four. The candidates preserve those access widths.
- **Object state:** copies the global state pointer into +0x0c, clears four words
  at +0xe4..+0xf0 and conditionally traces the old state name. All five relocation
  sites resolve to explicit original globals/format/callee destinations.
- **Random state:** 32-bit doubling with feedback polynomial 0x1d872b41 when the
  prior state is signed-nonpositive. Zero therefore receives feedback too. Unsigned
  arithmetic preserves wraparound without relying on signed-overflow behaviour.
  The bounded variant uses the low 16 bits of the bound as its loop counter and
  a signed remainder after masking the state positive. A zero bound remains an
  invalid caller input, just as in the original; no new defensive branch was added.
- **Object lists:** ten contiguous 12-byte sentinel-list headers, object type at
  +8, and two-link intrusive nodes. `LST_Remove` corroborates the link offsets.
- **Recursive position reset:** visits +0x164, then +0x160, then calls 004317b0.
  That callee subtracts parent-position fields when a parent exists. Link names
  and the full object layout remain provisional. Both self-call relocations and
  the helper-call destination match.

All parameter-taking candidates use stack arguments and caller cleanup (`__cdecl`).
Minimal observed layouts are used rather than asserting that inherited Ghidra
GXObject types are correct. Byte equality does not distinguish source-level int
versus long, prove every field's signedness, or establish an API return type. For
example, Random32 leaves the new state in EAX; the candidate exposes it as a return
value, but the inspected stream-level caller ignores it. Original API intent is
not claimed. The byte readers currently use unsigned long, which is 32-bit under
the pinned Windows compiler, not necessarily on another platform.

## Remaining mismatches

Both current readers have the correct function length and the same instruction
operations/order as the original, but ECX and EDX are interchanged for the cursor
and data pointers. The raw-byte scores penalize those register encodings. No
register renaming or byte masking was allowed to promote them to ExactMatch.

Tried and retained: explicit versus compiler-generated pointer temporaries,
separate byte temporaries, a register hint, natural little-endian OR ordering,
and unsigned-long versus unsigned-int values. These did not resolve the register
choice. The UInt separate-temporary attempt was worse; its historical evidence
remains intact. The current sources retain straightforward little-endian assembly,
not artificial control flow or untracked per-function flags.

`python3 tests/byte_readers.py` additionally passes **65,536 exhaustive 16-bit
values** and **11,048 directed/seeded 32-bit cases**, checking returned values,
cursor advancement and unchanged input buffers, including unaligned starts.
These are explicitly **host-compiler behavioural tests**, not original-byte or
Windows ABI proofs, and not universal semantic-equivalence proofs. They never
change backend match status.

## Feedback on the workflow

1. **The strict path works beyond trivial stubs.** Branches, loops, recursive calls,
   varargs, pointer addends and absolute/global relocations all verified without
   modifying the backend. About 3.5 seconds per attempt is usable interactively.
2. **Keep disassembly beside pseudocode.** The byte-reader access-width mistake
   would be easy to copy into a plausible but inaccurate candidate. Existing names
   and inferred types are clues, not authoritative source declarations.
3. **Add register-aware diagnostic diffs, not looser matching.** The two readers
   illustrate how 79–84% raw-byte scores can hide a small code-generation difference.
   Function Lab should explain register-only changes while ExactMatch remains strict.
4. **Make binding dependencies finer-grained.** Adding unrelated symbols currently
   invalidates every previous proof because the whole binding map is fingerprinted.
   Safe, but future proof records should track the bindings actually consumed.
5. **A batch summary would help.** The CLI's verbose per-attempt JSON contains the
   evidence but obscures current status, best historical score, first differing
   instruction and artifact paths. Also, `scripts/build-baseline` intentionally
   still checks only the initial two functions; it is not an all-source test gate.
6. **Do not conclude original-compiler identity yet.** Eight new exact functions
   strengthen the recovered CL 10.00.5270 / historical-flags hypothesis, but small
   selected routines do not distinguish every compatible compiler/flag combination.

## Reproduction and retained evidence

Sources: `src/functions/<address>.cpp`. Toolchain and bindings: `project.json`.
The configured compiler and all seven component fingerprints were unchanged.
The installed GOG executable still hashes to
`e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`.
Ghidra remained `GEX.exe` / `/EditedGex`; no analysis writes, patch repairs, or
reimports were performed. WndProc, WinMain and the patched graphics routine were
not selected. Neither Nexus nor its coding agent was restarted.

Local, ignored evidence:

- `.work/ten-functions/report.json`: current source hashes, result/attempt IDs,
  byte counts, scores, relocation counts and attempt counts for all ten.
- `.work/ten-functions/*-v*.json`: all 21 durable queue responses.
- `.work/ten-functions/baseline-refresh.log` and `final-status.json`: refreshed
  original baseline and final aggregate counts.
- `.work/ten-functions/live-rpc.json`: Nexus production transport successfully
  reads all ten exact function details; three schema-valid Atlas pages report
  10 exact functions / 381 bytes. This is transport validation, not GUI automation.
- `.work/attempts/<attempt>/`: immutable source, compiler logs, COFF, exact-original
  and resolved-candidate bytes, hashes, compiler configuration and proof dimensions.
- `.work/byte-reader-tests/report.json`: separate host behavioural checks.

Current durable IDs are `ten-<address>-v1`, except `0042cc20` uses `v2` and both
readers use `v6`. For example:

```sh
./scripts/verify 00429c60 ten-00429c60-v1
./scripts/verify 00417f40 ten-00417f40-v6
python3 tests/byte_readers.py
```

Repeating those IDs queries, never resubmits. Expected verifier exit codes here
are 0 for exact and 2 for the readers. After another intentional source change,
use a new stable ID only after resolving any previous uncertain command.

Current attempts:

| Address | Attempt |
|---|---|
| 0040b390 | attempt-1889aec3d67d42e0bf5b7681265900ba |
| 0040f5e0 | attempt-320fe914cb214d56a24e403d94074963 |
| 00417f00 | attempt-7e1c64f1b3164ee99b91a730a5966d19 |
| 00417f40 | attempt-6d892a396a4a4af1bc1e7f06de176233 |
| 00420bc0 | attempt-d9b5f2672f674e78b25c46ded17779a1 |
| 00428c60 | attempt-6e52606241524edd9671b595df87229e |
| 00428c80 | attempt-be82bd8724e34350b398dc518d4c9214 |
| 00429c60 | attempt-7a9361ccd15441deb81f2a4f045cdd3a |
| 0042cc20 | attempt-1d5b1cf807234f8186b802e18c7834c2 |
| 004317e0 | attempt-c11402efcf854f1899ad7f01416d3f88 |
