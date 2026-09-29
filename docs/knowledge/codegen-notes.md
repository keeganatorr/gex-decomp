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

The same declaration pins a *store's* position among other global stores:
0042ff10 (ob229Init) stores a dozen globals, and CL moved `DAT_0045b098 = -1`
two stores later until exactly `DAT_0045b098` and `DAT_004a2948` were
volatile (94.6% to exact; 3000 statement perturbations had not moved it).
With more than six globals `--volatile` tries subsets of up to three among
the ones the function stores to; before that it silently tried nothing.

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

## Register order follows use weight (measured 2026-09-29)

With four locals live across calls, CL 10.00 gives the most-used one `esi`,
then `edi`, `ebx`, `ebp` (four variables used 8, 6, 4 and 2 times got exactly
that order). Declaration order, `register` and top-level declaration moves
did not change it in 00410280, where the original has `ty` in `ebx` and
`speedx` in `ebp` and the reconstruction swaps them. When two register
variables are swapped and nothing else is, count their references: the
source has one more use of one, or one fewer of the other (an extra
temporary, a compound assignment, a chained `a = b = c`). Adding a local
also re-ranks everything below it.

## One store per statement, and when there is not

- A chain of statements into a **spilled local** (`v = a - D; v >>= 8; v *=
  s; v -= CAMX; ...`) keeps a store to the local's slot after every
  statement; the same chain into a register local is one expression. In
  0042f910 three of seven screen coordinates are spilled and show the
  stores, the other four do not. Write every coordinate the same stepwise
  way; the allocator decides which ones show it.
- The same chain into a **global** is merged by CL 10.00 into one
  expression and one store. 0042eaf0 keeps `store; reload; shl; store; add;
  store; sub; store` for its parallax offsets; the only spelling that
  reproduced it is a `volatile` global with nested assignments,
  `g = d >> 8; g = (g = (g = g << 15) + c) - x;`. Compound assignments on a
  volatile reload before every step instead.

## Memory operations kept in source order (measured 2026-09-29)

CL 10.00's /G5 scheduler freely interleaves independent stores through one
pointer, and hoists a load above stores it can prove do not alias it. When
the original keeps every store and load through an object in exact source
order (constant stores not regrouped, a trailing `a->x = a->y` load after the
last store), a `volatile` object pointer or `volatile` fields reproduce it:
004344d0 went from ten diff lines to one register pick. Array indexing
(`gob_fields[n]`) and `char *` offset arithmetic do not; CL disambiguates
both. The same symptom against *stack* stores (0041d310: loads through
`gob`/`other` never rise above stores to one spilled local) is not fixed by
volatile on either side, so it has a different cause that is still open.

## Initialised declarations are not the same as assignments (measured 2026-09-29)

`int bhi = b >> 16, blo = b & 0xffff;` and the same values assigned after
plain declarations compile differently: the initialisers fix one evaluation
order. 00437e50 (FixMul) sat at 85.5% with initialisers in every
declaration order; plain declarations followed by four assignments, ordered
by `tools/stmtperm.py`, were exact on the first run.

## A struct copy's esi can be live in the original (00434b10, open)

00434b10 keeps a result flag in esi across `cur = *hit` (rep movsd), then
tests esi on paths where the copy left `hit + 0x58` there, so they take the
"nonzero" exit. CL 10.00.5270 here never allocates a variable to esi across
a struct copy, so that shape cannot be reproduced by declaration order or
scoping. Treat such a function as a possible compiler-version difference
before searching further.

## A global spelled as an array element is not hoisted (00406fe0)

`if (gSel == 1 && gIDL[3] != 1)` never loads the second operand early; the
same global declared as a plain `extern int` is loaded next to the first one,
above the `cmp/jne`, as the original does three times in a row. Declared as a
scalar, the pair's eax/ecx order then followed the new extern's position among
the declarations (one position out of forty was exact).
