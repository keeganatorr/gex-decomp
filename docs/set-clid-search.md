# SCRIPT_SetCLIDCheckRoutine — exact on the first candidate

User requested reconstruction of another function. Selected **004188e0**, 29
bytes, `fn-d091dbe6e2708962a263b615`, after checking the service was idle and the
paid campaign Stopped. It had no retained source or compiler attempts and was
reconstruction-eligible. Its complete original extent and current Ghidra bytes
passed the existing preflight. No Ghidra or executable modification was made.

## Assembly-derived contract

- Read one unsigned script byte and advance the script pointer by one.
- Load a 32-bit entry from the pinned table at **00458cc0**, indexed by that byte.
- Store the word at destination offset **0x16c** (word index **0x5b**).
- Return the advanced pointer; preserve EBX as the original does.

The source uses a 32-bit word view, not a claimed recovered GXObject layout or
function-pointer signature. Preconditions are a readable script byte/table entry
and an aligned writable destination word. Byte equality does not establish the
original source types, original compiler identity or the real table length.

## Bounded test

Prepared up to **24 variants / 60 seconds**, varying byte-extension expressions,
register parameter declarations and equivalent destination-address expressions.
Register-allocation hypotheses were separate families, so a cosmetic duplicate
could not prematurely exclude another register assignment. Only the first
candidate was compiled: simple unsigned-byte postincrement, two register
parameters and a word-indexed store. No byte-representation variant was needed.

Host C++98 tests passed **12,288 checks** over all prepared variants: all 256 byte
indices, both separate-script and script/destination-alias cases, returned pointer,
full 32-bit entry copy, and preservation of all other destination words. These
are behavior tests, not exact-byte proofs; their 256-entry fixture does not claim
that the original table has 256 entries.

**Result: ExactMatch on candidate v000, all 29 bytes.**

- Probe compilation: **47 ms**.
- Entire search, including preflight/cache setup and fresh full verification:
  **1.068 seconds**.
- Full finalist verification portion: **295 ms**.
- One probe + one full candidate verification; stopped immediately on equality.
- No proposal-provider calls; no compiler, language, flag or binding changes.
- Fixed CL **10.00.5270**, C++, `/O2 /G5 /Oy /GR-`.

All bytes, including the DIR32 relocation to
`_PTR_CLD_CheckCollisionNormal_00458cc0 → 00458cc0`, matched. The symbol resolved
from existing pinned evidence; no address was fabricated or added to config.

## Publication

After checking the source was still absent and config unchanged, retained a
publication intent and wrote the **identical verified source bytes** to
`src/functions/004188e0.cpp`. One normal durable queue job recompiled and verified
the current source; this was not publication from a heuristic probe score.

- Search: `search-15d4982df3e984837f1a3ac5`.
- Candidate proof: `attempt-33ea1e441e344a56a50a53e73c2c5c57`.
- Publication command: `set-clid-publish-v1-004188e0`.
- Current-source proof: **`attempt-08cd0872bd2e41a88233eb42fc3973da`**.
- Source SHA256:
  `4aa0c6ded34f427daa5e998f9c36680c475ce7e4d70e17f52f8b52c5192f0157`.
- **424 → 425 exact functions; 15,882 → 15,911 matched bytes.**

Evidence: `.work/set-clid-search/` (initial detail, generator/host test, manifest,
backend identity, command, stopped-state backup, result, publication intent/
receipts and final detail). Individual artifacts remain under `.work/searches/`
and `.work/attempts/`.

Used the already tested immutable offline CLI
`.work/backend/source-search-c4ed997dd21733a0/PcDecomp.dll`, checking its entire file
hash manifest before launch. Original live daemon/link restored unchanged. No
existing matching source was recompiled or subjected to a whole-project byte
audit, and the paid campaign was not resumed.
