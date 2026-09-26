# Source shapes that decide the bytes

Recipes in [recipes.json](recipes.json) whose doc is this file. Each has an
executable pair under [examples/](examples/): the exact source and a
semantically equivalent source that differs, both checked by
`tests/knowledge_checks.py` against the pinned CL 10.00.

These came from the second hand-decompilation pass (2026-09-26, 833 → 899
exact). Almost every near miss in that pass was one of two things: symbol
numbering (see [symbol-numbering.md](symbol-numbering.md), solved by
`tools/perturb.py`) or a *source shape* that compiles to the same semantics
with different code. Read the asm for the shapes below before searching.

## Control flow is laid out in source order

CL 10.00 does not reorder blocks. The block after a `jcc` is the `then` body;
the jump target is the `else` body or the code after the `if`.

| In the target | Write |
|---|---|
| an error path at the end of the function, reached by `jne` | `if (ok) { … } else error();` — not an early `return` (`if-else-source-order`, 004026d0) |
| a far `jne` to a body placed after a later test | that body is the `else` branch: `if (!a) { if (c) … } else { … }` (004249e0) |
| a store with an immediate in one branch while neighbouring stores reuse a register | the store is common code *after* the if/else, tail-duplicated after register allocation (`common-tail-after-if-else`, 00429940) |
| error paths returning `mov eax, esi` (a variable known to be 0) | they jump to one `return frame;` at the end (`goto done;` or fall-through); `return frame;` in each path constant-folds to `xor eax, eax` (`join-point-return`, 0041a500) |
| two identical out-of-line `call`s, the outer `else` first | not reproduced yet (004130a0 at 91%) |

## Switches

- A jump table longer than the highest case with code: list the empty cases
  explicitly (`case 3: case 5: case 7: … case 10: break;`). A lone empty
  `case 10: break;` is dropped (`explicit-empty-case-labels`, 00435ab0).
- Two table slots pointing at one block placed after higher cases: two case
  labels with **separate identical bodies**; the compiler merges them into
  the later block. `case 0xc: case 0x70:` puts the block at 0xc's position
  (`duplicate-case-bodies`, 0040c940).
- Per-case calls with a constant argument (`push imm; jmp common_call`) are
  separate calls in the source, tail-merged; a ternary argument compiles to
  `sbb/and/add` instead (00435ab0).
- A compare chain rather than a table: `switch` on a byte with sparse values
  or an if/else chain — both compile the same; take the if chain.

## Expressions

| In the target | Write |
|---|---|
| `mov eax, x; jns L; mov eax, x; neg eax` | `if (x < 0) d = -x; else d = x;` (`abs-branch-vs-ternary`, 0042c1a0) |
| `cdq; xor eax, edx; sub eax, edx` | `d = x < 0 ? -x : x;` |
| `mov reg, 0` (not `xor`) before a test | `v = cond ? a : 0;` (`ternary-mov-zero`, 00411230) |
| `cmp x, 1; sbb eax, eax; and eax, k; add eax, c` | `v = x ? c + k : c;` style ternaries on a global |
| a trip count `(n + 7) >> 3` feeding a down-counter | `for (n = 0; n < bits; n += 8)` (`loop-trip-count`, 00429850) |
| `inc esi; inc esi; mov al, [esi-2]; mov cl, [esi-1]` | `a = *p++; b = *p++;` (`script-post-increment`, 00418180) |
| a byte loaded, xored, then widened with `xor edx, edx; mov dl, bl` | the result assigned to an `int` through a `(unsigned char)` cast |
| `xor reg, reg` then four register stores | `memset(p, 0, sizeof *p)` on a small struct (`memset-register-zero-fill`, 00409350) |
| `and r, 0x80000000; shr r, 0x1c` | `(flags & 0x80000000 ? 8 : 0)` — every shift or divide spelling widens the mask (`narrow-mask-shift`, 004125b0 and 19 more) |
| `and r, 0x80000000; shr r, 0x1f` | `(flags & 0x80000000) != 0` |
| `cmp eax, 1; jl` rather than `test; jle` | the source constant is literal: `x >= 1`, not `x > 0` (004143b0) |
| `cmp eax, K; jl; mov eax, K` with one callee-saved register fewer | `v = v < K ? v : K;` (a ternary clamp) rather than `if (v >= K) v = K;` (004264c0); `tools/shapes.py` tries both |
| a spilled `h`, `mov [h], 0; mov byte [h], al` | a byte widened into a spilled `int` local; it is not a union |
| `lea` + `shl 3` then `[reg + table]` (not `[reg*8 + table]`) | explicit byte arithmetic: `*(int *)((char *)T + ((i & 0xf) << 3))` (00412630) |

## Memory and aliasing

- `lea ebx, [esi + 0xc]` reused for a field: that is the compiler's own CSE.
  Ghidra's `int *p = &obj->field;` local changes the schedule; write
  `obj->field` (`ghidra-field-pointer-local`, 004094f0).
- A global pointer assigned `&X`, then an absolute `and [X], m` and a reload
  of an unrelated `char` global: the source writes **through the pointer**
  just stored (`*ptr &= m`), which the compiler forwards but still treats as
  aliasing (`store-through-global-pointer`, 0043daf0).
- A value reloaded after a store to an unrelated object: something between
  them is written through a pointer the compiler cannot disambiguate. Keep
  that store between the two reads.
- `mov esi, A; jmp` / `mov esi, B; jmp` / `mov esi, C` feeding one
  `rep movsd`: three separate struct assignments, cross-jumped. Choosing a
  pointer and copying once becomes a speculative assignment
  (`separate-struct-copies`, 0042f860).

## Interfaces and headers

- DirectX COM calls are C style: `obj->lpVtbl->Method(obj, …)`. A C++
  interface with virtual `__stdcall` methods schedules the `this` push
  differently (`com-c-style-vtable`, 00401720).
- mmsystem structs are packed (`WAVEFORMAT` is 14 bytes). Without a pragma,
  flatten them (`PCMWAVEFORMAT` as six fields = 16 bytes).
- The verifier rejects **any** `#` in a source, comments included.
  `tools/probe.py` now reports `REJECTED` instead of `EXACT` for such a
  source, mirroring `Verifier.CheckInputs`.
- A string literal cannot be used for a global string: the candidate would
  relocate to its own data. Declare the global (`extern char s_…[];`) and,
  for a two-byte `"0"`, copy it as `*(unsigned short *)dst = DAT_…;`.

## Macros

No `#` is allowed, so a macro in the original has to be written out. Signs:

- An argument expression recomputed in several branches (a repeated `idiv`,
  or `-x` compiled as `(a - c) << 7 / (b - a)`): the argument was substituted
  textually. 004391d0 is a sine macro over the quarter table at 0x45a5c8;
  generate the nested ternaries with a script and it matches on the first
  compile. 14 more functions use the same macro (their operands include
  0x45a3c8, 0x45a7c8 and 0x45a9c8).
- Three stores to one field in a row (after `+=`, after a min, after a max):
  `s += d; s = s < 255 ? s : 255; s = s > 0 ? s : 0;` (00428fa0).

## Control flow that Ghidra reshapes

- `if (A && B) X; else if (A && C) Y;` compiles to a test of A, then B, then
  A again; Ghidra shows the repeated test as a nested if (00439640).
- A fall-through default placed inline between two case bodies comes from
  `if (w == A) {…} else if (w != B) {default} else {B}` (00431470).
- A condition repeated verbatim (`end <= l && br > l || end <= l && br > l`)
  is a copy-paste bug in the original; reproduce it (0041e9d0).

## Not source problems

- `nop` inside a prologue or loop is CL 10.00's /G5 pairing filler; the
  pinned compiler emits it too.
- Stores repeated in several branches (`mov [x], ecx` three times) are the
  compiler's; write the natural code (00405120).
- `(x & 0x7f80) >> 7 << 8` and `((b & 2) >> 1) * 4`: CL 10.00 folds the shift
  pair into the mask/scale; the original keeps both shifts. Same family as
  `narrow-mask-shift` ([toolchain-limits.md](toolchain-limits.md)).

## Search order that worked

1. Write natural code from the asm (field names from Ghidra's layouts,
   globals by their indexed names). About a third matched on the first
   compile.
2. Read the diff for the shapes above.
3. `tools/solve.sh ADDR FILE`: perturbation (both front ends), local
   declaration orders (and a C++ twin of any C-only match), joint
   statement × declaration orders for save/restore runs (`jointperm.py`),
   expression shapes (`shapes.py`: ternary vs if clamps, `abs()`, compare
   spelling, operand order, commutative operands with calls), adjacent swaps,
   any-move hill climb, and every order of each 2–6 statement run, then
   perturbation again.
4. `tools/sweep_attempts.py` after any verifier or binding change: two old
   attempts became exact after the switch-table fix without a new compile.
