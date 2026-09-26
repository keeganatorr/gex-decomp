# Code-generation notes from hand decompilation

Recipes `switch-table-extent`, `volatile-thread-flags`,
`statement-and-declaration-order`, `mask-test-not-shift`, `inline-int3` in
[recipes.json](recipes.json). Each has executable checks.

## Switch tables

A `switch` compiles to code followed, in the same COFF section, by its jump
(and sometimes index) table. Ghidra's extent ends at the last instruction, so
until the switch-tables backend (pc-decomp `Verifier.TrailingData`) no switch
could ever verify: 55 unmatched functions, zero exact. The verifier now widens
the comparison to the candidate's length when the code references that tail
through a relocation and no other function starts inside it; every widened
byte must still equal the original. Seven retained sources turned out to be
byte-exact already (0040b0a0, 0042ca40, 0043a240, 00420fa0, 0041b3e0,
0042c0a0, 0041beb0); 00409f00 and 0041a920 followed.

## Thread-polled flags were volatile

Gex runs its game loop in a thread (`GameThread`) and polls flags in
`Sleep(0)` loops. The originals declared those flags `volatile`: CL then keeps
the constant 0 in a callee-saved register (`xor edi, edi` / `push edi`) and
reloads the flag each iteration. Without it, CL pushes an immediate. Which
flags matters (0040b320 needed exactly two of five); `tools/perturb.py
--volatile` tries every subset.

## Order is a search dimension, not a semantic question

Independent statements (stores, even a call and a store) and the order of names
in `int a, b;` change scheduling and register choice. Because an exact match
proves the compiled code identical, any reordering that matches is equivalent
by construction; search freely (the session's `stperm.py` hill-climb and
exhaustive permutations of short runs found six). Stack slots for local
aggregates did *not* follow declaration order (004044b0 unchanged over 1,500
orders).

## Other one-liners

- `(x & 0x80000000) != 0` keeps `and; shr 31`; `x >> 31` drops the mask.
- Interleaved loads before two tests mean both values were computed into locals
  before a nested `if` (00431640).
- A table indexed off a global pointer is loaded once when the source copies
  the pointer into a local first (Ghidra's `KeyInput = gInputRecords` hint).
- The SCRIPT_* commands read operands through an `int *fields = gob->fields`
  pointer; the surviving dead `add ecx, 0x68` is the tell (00418990).
- Byte readers (SCRIPT_GetUInt, EVENT_ExtractUShort) needed 19 padding
  declarations: functions from one original file tend to share a padding count.
- `int 3` after `OutputDebugStringA` (CDIO_FileClose, FreeMemory) is inline
  assembly; policy refuses it and VC4 has no `__debugbreak`.
