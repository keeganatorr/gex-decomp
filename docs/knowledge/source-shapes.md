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
| `mov eax, [g]; mov [m], 1; test eax, eax; jne; mov [m], 0` (the load above the first store) | `if (g) m = 1; else m = 0;` — CL stores the `then` constant before the test. `m = 1; if (!g) m = 0;` puts the load after the store (0040c4d0, 0042b180) |
| `test; je zero; jmp one` in each arm of an if/else-if chain, with one shared `m = 1` and one `m = 0` | each arm is its own `if (g) m = 1; else m = 0;`; CL cross-jumps the identical stores. Early `break`/`goto` spellings give `jne one; jmp zero` (0040c210) |
| which `case` bodies of a switch share a tail (`jmp` into another case's last two instructions) | the statement order inside each case: `x = a; y = b;` and `y = b; x = a;` merge differently. Enumerate the 2^n orders with `tools/rankvariants.py` (0040fe80) |
| a second `cmp reg, K` on a register that already holds the value tested just before | the source tests a local twice: `i = state; if (i == 3) { … if (i == 3) { …; i = idx; } else i = 0; }` — CL does not remove the redundant test (0042b180) |

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
- A range test `cmp 3; jl A; cmp 5; jle B; A: … jmp; B: …` with the outside
  body first: `switch (s) { case 3: case 4: case 5: B; break; default: A; }`.
  Every `if (s < 3 || s > 5)` / `if (s >= 3 && s <= 5)` spelling and the
  ternary lay the in-range body out first (00415e80).
- A big switch (an interpreter, 00435d90 GOB_RunScript, 61 cases) is one
  register allocation: the variables used in one case move `eax`/`ecx`
  choices and even the `esi`/`edi` assignment of the parameters in every
  other case. Score it per case with `tools/casediff.py` (and `--swap
  esi:edi` to see case bodies through a global swap), keep a list of
  alternative bodies per case, and search alternatives, local and `extern`
  declaration order and local types jointly on the per-case total. Reordering
  the case bodies in the source changes nothing; CL lays them out by value.
- A sparse switch compiles to a byte map plus a dword table of distinct
  targets. Several map values with their own dword entries that all point at
  one block are separate case labels with identical bodies (`case 4: s =
  0x73; break; case 5: s = 0x73; break;`); grouped labels share one entry.
  An entry that points at the end of the switch, when the default does too,
  is a case whose body was optimised away after the table was built: `case
  3: sound = 0; break;` with `sound` dead keeps the entry and the `cmp eax,
  0xb0` bound, while `case 3: break;` is dropped (00416320).
- Each case of such a switch may use its own byte temporary. Zero-extension
  shows which: `mov dl, [esi]` kept in `dl` then `xor eax, eax; mov al, dl`
  is an `unsigned char` local; `xor eax, eax; mov al, [esi-1]` straight into
  an index is an `int`. The number of `unsigned char` locals decided the
  `esi`/`edi` assignment of RunScript's parameters.

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
| `mov ah, byte ptr [reg + off + 1]; test ah, k` | `(unsigned char)(x >> 8) & k` — a mask, bitfield or `char *` access loads the dword or uses `al` (00438e40) |
| `test byte ptr [idx*8 + table], k` | an `unsigned short` field `& k` (`LevelEntry.info`); an `int` field gives `mov`+`test cl`, a `char` gives `mov cl` (0040a660) |
| `mov edx, ecx; and edx, ecx` storing to a global just written with `ecx` | PSX `setlen(p, 0)`: a `{addr:24; len:8}` bitfield cleared through the list pointer just assigned; a direct `&=` folds (0043fb40) |
| `inc edi; inc edi` after reading two bytes | `dx = *p++; dy = *p++;` or `p++; p++;`; `p += 2` gives `add edi, 2` (00434260) |
| `cmp dl, 0x81` on a value loaded with `movsx` | `(signed char)dx == (signed char)0x81`; `dx == -127` compares the dword (00434260) |
| `mov ecx, eax; shr ecx, 0x10; test cx, cx` | `(unsigned short)(wParam >> 16)` (HIWORD); `!(wParam >> 16)` tests the dword (00407330) |
| `lea ecx, [esi]; add esi, 0xc` then a struct copy `[ecx]` to `[esi]` | `p++; *p = p[-1];` (double-buffered PSX prim); `p[1] = p[0]` gives `lea ecx, [esi + 0xc]` (0043f7f0) |
| `mov eax, [g]; mov ecx, eax; test eax, eax` feeding a call | a ternary argument `f(g ? g : alt)` (00423dc0) |
| `sub r, x; jns L; add r, 0x10000; L: sar r, 0x11` | hand rounding `if (d < 0) d += 0x10000; d >>= 17;` (0043f7f0) |
| `sar ebp, 0x11` and `and ecx, 0xfffe0001; sar ecx, 1` on the same value | the expression `(d >> 17) << 16` written out twice, as in a macro; a variable would be shifted once (00430f20) |
| a `\|` chain of calls evaluated last to first | separate `hits \|= f() ? k : 0;` statements keep source order (00420960) |
| a frame one slot smaller than the candidate | the original reused a spilled local for a second value across calls (`hy = p->cc; ...; p->cc = hy;`) (00417500, 00437790) |
| every `return` is `mov eax, esi` from a register holding 0 or 1 | all cases `break` to one `return result;`; `return result;` in each case constant-folds to `xor eax, eax` (0041ecd0) |
| a compare chain on a global loaded once | a `switch` with a `default`, not an if/else-if chain that reloads it (0041ecd0) |
| per-loop register roles that swap between identical loops | each loop has its own block-scoped `int i; int x;` (a macro), with its own declaration and init order (0041b770) |
| a parameter slot reused for a later value | assign the parameter itself (`y = par->y % par->height;`) rather than a new local; a new local adds a frame slot (0041fef0) |
| a store and a load between which a global is reloaded | the global is `volatile` in the original (a thread-shared flag, 00402c00; a scan index, 00410dc0) |
| `mov ebp, eax; mov [ecx], eax` after a call | `*p = f(); a = *p;` — `a = f(); *p = a;` stores first (0040eb70, 0041f2d0) |
| `inc` scheduled after the parameter loads | write the index as `g + 1` in the stores and `g++` after them; `g++` first schedules the `inc` early (0041f860) |
| `xor ebx, ebx` hoisted before a call, then `mov bl, [byte]` | an `int` local assigned from an `unsigned char` field (0040c540) |
| `and r, ~(mask & ~v); or r, v` | a constant stored into a bitfield: CL clears only the bits that are 0 in the value (`state:4 = 4` gives `and ~0xb; or 4`) |
| a dead `lea eax, [eax*2 + 1]` | an index local that is computed and folded into both addressing modes: `i = n * 2 + 1; x = p[i]; y = p[i + 1];` (00419c00) |
| struct locals in an unexpected frame order | aggregate slots follow use weight, not declaration order or name: the most used struct gets the lowest address. One fewer read of a struct (a call using the global just stored from it) reorders them (004044b0) |
| a param load inside each branch instead of above the test | the first statement differs between the branches; permute the branch-local stores (00434670) |
| `cmp a, b` orientation or `test r1, r2` order that no spelling changes | symbol numbering: a separate local for one of the operands (`solid2`, `ex2`) plus a declaration-order search fixed it (00423350, 0040f910) |
| `and r, 0xff3fffff; sar r, 0x16` as an index into a dword table | `T[(int)x >> 24]`: CL folds the top-byte shift and the `*4` scale into one shift. `x += 0x1000000; if (x >> 24 >= 2)` gives `add 0x1000000` and `and 0xff000000; cmp 0x2000000` (0042b180, 00440430) |
| `and r, 0xffffff03; or r, 3` storing a small state | an 8-bit bitfield (`state : 8`) assigned 3 and read as `state & 0xf`; two 4-bit fields assigned separately give two `and`s (0042b180) |
| `and eax, 0x7fff` (32-bit) before a word store of a ternary | the ternary goes through an `int` temporary: `*p++ = v = c ? 0 : 0x7fff;`; storing the ternary directly gives `and ax, 0x7fff` (00436cf0) |
| `testb $k, [x*8 + table + 1]` on a table entry | the entry's first field is an `unsigned short` tested with `k << 8`; reuse the struct an exact sibling already declares for that global (`LevelEntry`, 004099b0) |
| one field load copied into two registers that are masked and shifted differently | one local: `off = p->offset; ox = off & 0xffff0000; oy = off << 16;` (00440cb0) |
| an unfolded `add ecx, 0x68` before `[ecx + edx*4]` | a pointer to a member array chosen per branch and indexed at the join: `if (a) f = a->fields; else if (b) f = b->fields; … f[i]` (00418040) |
| `and eax, 0xfff0; cmp eax, 0x1900; jl` on a word that is also updated with `lea/xor/and 0xfff0/xor` | a 12-bit counter kept in an `int` and read through a mask: `(w & 0xfff0) >= 0x1900`. An `unsigned` bitfield read gives `jb`, a signed one adds `shl/sar`. `w = w & 0xffff000f \| w + 0x10 & 0xfff0` is byte-identical to the bitfield increment (0042b7f0) |
| `or ecx, eax` after a call, with the parameter loaded after the first argument push | the call result goes through a local: `level = f(gob, 0); w = level \| w & 0xffff0000;`. `w = f(gob, 0) \| w & mask` gives `or eax, ecx` and hoists the parameter load (0042b7f0) |
| one register swapped in an otherwise exact block, with a temporary used elsewhere in the function | remove a register-candidate local: a rotation `t = a8; …; a8 = -1; a4 = t;` written as `a4 = a8; a8 = -1;` freed a register and fixed an unrelated `mov ecx`/`mov eax` choice 60 lines away (00415e80) |
| `mov cl, [b]; mov edi, 1; test cl, cl` — a constant assigned between a load and the test that uses it | the assignment is written in both arms: `if (b) { moved = 1; … } else moved = 1;`. CL hoists the common store to the end of the block before the branch; one `moved = 1;` ahead of the `if` is scheduled before the load (00426690) |
| two globals compared (`mov eax, [a]; mov ecx, [b]; cmp ecx, eax`) loaded in the wrong order | the extern declaration order decides which loads first, not the spelling of `==`: swap the two `extern` lines (0040a010) |
| a `cmp` orientation or register choice that neither spelling nor `perturb.py` fixes | shuffle the order of *all* local declarations (150 random samples through `rankvariants.py`, both front ends); single moves miss it (00420300, /Tc) |
| a dead `mov eax, [flags]; and eax, 0x40000000` right after a call, overwritten immediately | an unused macro expansion: `flip = f & 0x40000000; top = flip ? -fr->bottom : fr->top; bottom = flip ? -fr->top : fr->bottom;` in a path that never reads `top`/`bottom`. CL drops the selects and keeps the `and`; omitting the dead code is 7 bytes short (00438470) |
| `cmp ecx, eax` with `eax` a call result and `ecx` computed after the call | the call result goes into a local first: `c = f(…); if (y < c)`. A call written inside the comparison always compiles `cmp eax, ecx`, whichever side it is on (00438470) |
| stack slots in the wrong order, or a branch's values in registers instead of slots | later branches reuse the earlier branches' variables (`upLeft` in one branch is `blockRight` in another); enumerate the name assignments per branch with `rankvariants.py` (00438470, 840 combinations) |
| the same block of 15-20 instructions twice before two epilogues | the source repeats it in both arms (`if (b) { if (f()) return; T } else { T }`, a macro); CL only duplicates a few instructions itself. Missing it shows as a candidate ~100 bytes short (00437f40) |
| a loop pointer over a global array held in a scratch register (`ecx`) while the parameters sit in `esi`/`edi` | an index loop `for (i = 0; i < 10; i++) … T[i].head`, which CL strength-reduces to that pointer; a pointer loop variable `for (p = T; p < T + 10; p++)` is given a callee-saved register (0040c110) |
| `inc esi; xor eax, eax; mov al, [esi-1]` for a script byte | `p++; v = p[-1];`. `v = *p++` gives `xor eax, eax; inc esi` — and changes register choices in unrelated cases of the same function (00435d90) |
| `test r, r` scheduled before two zero stores of other flags | the `ZF = r == 0; SF = r < 0;` assignments come first in source, `OF = 0; CF = 0;` after (00435d90) |
| `lea ecx, [edi + 0x194]; mov eax, 0xc; L: mov [ecx], ebx; add ecx, 8; dec eax; jne L` | `for (i = 0; i < 12; i++) gob->events[i].number = 0;` with an `int` index; an `unsigned char` index keeps the index and compares it (00435d90) |
| `[eax + esi - 4]` (base = offset, index = pointer) and a different register choice elsewhere | integer address arithmetic: `*(int *)((int)p + off - 4)`; `*(int *)(p + off - 4)` compiles the same instruction with base and index swapped and cost 24 lines across the function (00435d90) |
| `cmp`/`xor` operand order between a global and a local that no spelling of the comparison changes | conversions decide it: an operand wrapped in a conversion (explicit cast or the implicit one from mixing `int` and `unsigned`) goes second. `(unsigned)R < uv` compiles `cmp uv, R`; with `int` locals and both sides cast, `cmp R, v`. Carry/overflow emulation in RunScript mixes both kinds, so the locals' signedness is per case (00435d90) |
| a global reloaded as a memory operand (`xor edx, [g]`) where an earlier load of it is still in a register | the second use has a different conversion than the first: `old > (unsigned)g` in the compare, `old ^ g` with `int old` in the overflow test; CL's CSE matches the converted value, not the load (00435d90) |
| every callee-saved register role in a big function rotated (x in `edi` instead of `ebx`, the step in `eax` instead of `ecx`) with every case body otherwise right | the order of the initialisations before the switch: `moved = 0; speed = …; idle = 0; x = …; y = …;` against `x = …; moved = 0; …` moved 163 lines in 00427d30 PlayerSideCrawl. Search statement runs jointly with declaration order |
| two `lea` argument temporaries with swapped registers in one case of several identical ones | that case computes its arguments into locals first: `nx = x - 0x180000; ny = y + 0x180000; f(level, nx, ny)` (00427d30) |
| `mov eax, ecx; shl eax, 0x10; mov ax, cx; mov ecx, 7; rep stosd; stosw` | a plain fill loop, `for (i = 1; i < 16; i++) p[i] = c;` with `unsigned short` elements: CL recognises it (00416320) |
| loop tests `cmp esi, 0x3fc; jne` on a strength-reduced counter | the loop condition is `!=`: `for (b = 0; b != 4; b++)`; `<` gives `jl` (004066d0) |
| a clamp `test eax, eax; jl zero; cmp eax, ecx; jl keep; mov eax, ecx` with the divisor constant reused as the bound | `if (v >= 0) { if (v >= 31) v = 31; r = v; } else r = 0;` with `v` shared between the three channel computations; `v > 30` compares with an immediate (004066d0) |
| a parameter loaded into its register before an early-return test that does not use it | the function copies it into a local first: `gob = object;` as the first statement (00435d90) |
| a global loaded once before an unrotated loop and reloaded only after a call inside it | not reproduced yet: `for (i = 0; T[i].track != g; i++)` hoists the load but rotates the loop; `while (1) { if (T[i].track == g) break; … }` keeps the top test but reloads each pass (00402ec0) |

## Memory and aliasing

- A global store emitted straight after the call that produced the value,
  before `add esp`: `p = f(); g = p;`. `p = (g = f());` copies first
  (004194c0).
- A load that lands in `ecx` rather than `eax` when stored to a global, with
  nothing else live: the global is `volatile` (a queue slot polled
  elsewhere, 00401ad0). `perturb.py --volatile` finds it.
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

## Stack frames

- Slot order follows reference count, for scalars and aggregates alike: the
  most referenced local gets the lowest address. Declaration order does not
  move it. Removing one use of a local is enough to move it past its
  neighbours, which makes a quick experiment for "why is this slot here".
- A small struct whose slot sits in the wrong place is often the head of a
  bigger aggregate. In 0041e190 an 8-byte callback message sat below two
  0x28-byte edge blocks; all three were one `HitRecord self {unk0, type, a,
  b}`: `ComputeAngleEdges(gob, &self.a)`, `ComputeAngleEdges(other,
  &self.b)`, and the gob's callback receives `&self`. Separate locals put
  the message at the lowest address; the record put everything in place and
  took the function from 96.9% to exact.
- Two aggregates of one type in adjacent slots, in declaration-independent
  order, may be one array (`CLDEdges e[2]`) — try it before permuting.
- A block-scoped aggregate shares its slot with compiler temporaries from a
  sibling block (0041e190's hoisted `a.x + ar` lives in the first word of the
  callback record's slot). A frame four bytes too large often means a local
  that should be block-scoped.
- CL does not share a slot between two function-scope aggregates, however
  disjoint their lifetimes: four `GXObject` copies declared at function scope
  gave a 0x88c frame for 00416320 against the original's 0x250. Declared
  inside the blocks that use them, sibling blocks overlap, and scalars saved
  in a later block land inside a dead copy's storage (the original's saved
  `y` sits in the first word of the object copy). Scalars at function scope
  are packed by lifetime among themselves, but not into aggregates.
- A flag loaded on one path from another variable's stack slot (`mov edx,
  [esp+0x18]` where the slot holds the player's x) is a local the source
  leaves uninitialised on that path: `if (r == 6) { a = 0; b = 1; } if (r
  == 10) { a = 1; b = 0; }` and nothing else. CL gives it the dead slot's
  home, so writing an initial value is what breaks the match (00410280,
  00416320's `shake`/`cycle` in a `switch` without `default`).
- A pointer spilled once and reloaded at the top of an outer loop is a
  common subexpression written again at the loop top
  (`hb = e.b.frame->boxes;` both before the null check and first in the loop
  body), not a separate variable; a separate variable adds a slot.

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

- Sine: `tools/sinmacro.py` writes the nested ternaries over `gTrigTable_0045a5c8`; cosine is `S(x + 64)`. Five functions matched from it on the first or second compile.
- A fixed-point multiply `FixMul(a, b)` (abs of both, split 16.16 product, sign from `(a > 0) != (b > 0)`) computes the magnitude once and negates conditionally, so it was an inline function or a statement macro, not a ternary macro (00442e50, parked at 70%).

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
- `cmp x, 1; je B; cmp x, 3; je END; A; jmp END; B:` is a `switch` whose
  `default:` body is written first (0040a660).
- A block reached only by a branch and laid out after everything else is the
  `else` of an enclosing `if`: `if (!left && !right) {...} else { Walk();
  return; }` (00423dc0). Failure paths that all jump to one `return 0` at the
  end are nested conditions, not early returns (0040b460, 00403030).
- CL puts a label reached only by `goto` at the site of the *last* goto
  before it, whatever its source position (004256e0, unresolved).

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
4. `PROBE_METRIC=aligned` makes every search score by instruction text with
   branch targets normalised (`probe.aligned_percent`). The default positional
   percentage collapses after the first inserted byte, so a fix that shifts the
   rest of the function looks like a regression. Ranking statement-order and
   spelling variants by instruction-text difference is what found 0042a690,
   00423350 and 0041ecd0.
5. `tools/sweep_attempts.py` after any verifier or binding change: two old
   attempts became exact after the switch-table fix without a new compile.
6. Re-run the newer searches over attempts that predate them. A sweep of old
   near misses with `tools/storeperm.py` (every order of each run of up to
   seven straight-line assignments, both front ends) found 004248e0, 004263b0
   and 00442de0 in minutes; the older hill climb had stopped at a local
   optimum on each. Stores after a call are the usual case: where the shared
   zero (`xor r, r`) and the next call's pushes land depends on the whole
   store order.
7. Before inventing a struct for a global, grep `src/functions` for its
   address. An exact sibling's layout is evidence; 004099b0 matched on the
   first compile once it used `LevelEntry` from 0040a660.
8. A register swap that `perturb.py` misses at its default padding can still
   be symbol numbering: 0040f170 needed 25 pad declarations. Try
   `--pad 48` before calling a swap a toolchain limit.
9. `tools/declshuffle.py ADDRESS FILE` after `perturb.py`: it shuffles whole
   declaration groups (locals, extern data, prototypes) instead of moving one
   line. It found 00437f40 (SIB order, sample 62) and 00420300 (`cmp`
   orientation) where single moves had not.
10. When a candidate is shorter than the target, look for code the original
    kept that looks dead or duplicated: an unused macro expansion
    (00438470, 7 bytes) or a tail written out twice (00437f40, 100 bytes).
11. Functions over ~1 KB, and every jump-table function: score with
    `tools/casediff.py ADDRESS FILE` (per case, `--swap esi:edi` to look
    through a global register swap) instead of the positional percentage,
    which stays flat while the function converges. Mark the uncertain
    spellings in the candidate with `/*ALT*/ … /*OR*/ … /*END*/` and run
    `tools/altsearch.py ADDRESS FILE --runs 8`: it searches the alternatives
    jointly with declaration order, local types and extern order. 00427d30
    (3.8 KB) went from 166 mismatched lines to exact with one prologue order
    and one pair of argument temporaries; 00435d90 (3.6 KB) from 231 to 2.
12. `tools/shapes.py` now also swaps `(x & 2^n) >> n` with `(x & 2^n) != 0`:
    the same `and`/`shr` either way, but a different tree for the compare
    that follows (00421740).
