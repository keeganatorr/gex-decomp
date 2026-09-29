# Where the pinned toolchain stops

Recipes `narrow-mask-shift` and `noreturn-tail` in [recipes.json](recipes.json).
`tools/idiom_scan.py` lists every eligible function containing either idiom.

## The compiler is probably not the original one

The pinned compiler is CL **10.00.5270** (Visual C++ 4.0). The executable's PE
header says linker **4.20** and a build time of **1996-09-12 00:33 UTC**;
Visual C++ 4.2 shipped in mid-1996 with CL 10.20. Nothing on this machine is a
10.20 compiler (`c932` is CL 9.00, `c1032` is 10.00, the other copies are 12.x
and 13.x). Exact proofs show that 10.00 reproduces most of the game. The
narrow-mask family once listed here as the strongest evidence of a different
compiler turned out to be a source shape (below), which weakens the case; the
remaining entries are small. Obtaining VC++ 4.2 and pinning
it as a second toolchain (per-function contract, never a silent swap) is the
most valuable open experiment. Check flags first, though: 00401f20 looked
like an allocator difference and was `/Oa` (below).

## narrow-mask-shift: not a toolchain limit (solved 2026-09-26)

Target: `and edi, 0x80000000` … `shr edi, 0x1c` (bit 31 moved to bit 3).
Every *shift* spelling — `(x >> 31) << 3`, `(x & 0x80000000) >> 28`,
`/ 0x10000000`, split statements, an unsigned bitfield — widens the mask to
`0x8fffffff`, which is why this section used to call the family
toolchain-limited. The original source was a **ternary**:
`(flags & 0x80000000 ? 8 : 0) | angle >> 21`. CL 10.00 lowers a select between
a power of two and zero to mask + shift and keeps the narrow mask. The 1/0
variant `and r, 0x80000000; shr r, 0x1f` is `(x & 0x80000000) != 0`
(004207e0 already had it, which is how the ternary was found). 20 proofs in
the `InitPlayerSide*` family followed within the hour; see recipe
`narrow-mask-shift` and [source-shapes.md](source-shapes.md).

Lesson for the method: a "reviewed negative search" over *arithmetic*
spellings says nothing about *control-flow* spellings of the same value. Before
calling a family toolchain-limited, grep the exact corpus for the idiom; one
exact function containing it proves the compiler can emit it.

## noreturn-tail and switch-tail extents: fixed in the backend (2026-09-28)

Ghidra treats `_exit` as noreturn and ends 00436c90 (SCRIPT_ExitScriptError)
and 004064d0 (WND_CleanUp) at `call _exit`, but the original continues with
the caller's epilogue (`add esp, 4; [pops]; ret`), and the verifier refused the
bodies as incomplete. pc-decomp's `extend-noreturn-tails` now extends such an
extent over a pure epilogue (no branch, no data, nothing another function
claims); both functions then verified exact with plain C (`exit_00449780`
resolves through its embedded address, no binding needed). 0040c340
(MainMenuButtonDraw) was refused for the opposite reason: its body ends on a
jump back into itself (out-of-line blocks after the `ret`), followed by
alignment filler, its switch table and padding. `confirm-switch-tails` accepts
exactly that shape, and `Detail` re-checks it on every verify. `00449bd0` (CRT
entry) is the one function that really ends at `call _exit`; CL 10.00 has no
noreturn knowledge and rejects `__declspec(noreturn)`. `00402ec0`
(MUS_SetMusicPlaying) calls `_exit` mid-function and carries on too, so the
original compiler did not treat `_exit` as noreturn.

## high-byte bit test: not a toolchain limit (solved 2026-09-27)

`mov ah, byte ptr [esi + 0xe1]; test ah, 8` for bit 11 of `flags2`. A mask
(`flags2 & 0x800`), a bitfield, a `(char *)` byte access or a `short` view
all load the whole dword or put the byte in `al`. The source casts the
*shifted* value: `(unsigned char)(gob->flags2 >> 8) & 8`. CL 10.00 then loads
only byte 1, and into `ah`. The three `event_*` handlers (00438e40, 00438ea0,
00438f00) became exact from it. Same lesson as the narrow mask: an
arithmetic spelling that fails says nothing about a cast spelling.

## shift-pair fold: partly a source shape

`(x & m) >> k` followed by a scale (`* 8` as an index, `<< n`) folds into one
shift for every unsigned spelling. Casting the shifted value to `int` stops the
fold: `T[(int)((c & 0xffff00) >> 8)]` keeps `shr 8` and the `*8` index
(0040d470, exact). Two cases remain open. 0040f610 (ReadAnalogValue) also has
a signed 1-bit term, `(int)(bits << 31) >> 31`, which still folds with the
index scale into `sar 0x1d`. 0043e2c0 (colour tint) keeps its shifts with the
cast, but CL 10.00 reassociates the three-term sum and folds the last term's
shift into an `lea` scale. Both also need bindings (`0x457c64`, `0x460048`).

## A load hoisted above a conditional branch (2, candidate)

In 00406fe0 (InitWindowVars) and 00440a30 the original loads a global that
only the fall-through block uses *before* the `cmp`/`test` and `jcc` that
guard that block (`mov ecx, [prev]; mov eax, [sel]; cmp eax, 1; jne`). CL
10.00 loads it inside the block, and no statement order, local copy or
condition spelling tried so far moves it. 00406fe0 differs in exactly these
three loads; 00440a30 has other open differences too. Not yet proved a
toolchain limit — the last two "limits" were source shapes — but a candidate
for the CL 10.20 experiment.

## A distributive fold the original did not make (1, candidate)

0043d630 (ob218DoIt) computes `(amp * t << 8) - (amp << 15)` as two products
and a `sub`. CL 10.00 always factors it to `(t - 0x80) * amp << 8`: ten
spellings (separate statements, `*256` / `*0x8000`, a ternary operand, a
compound `-=`) all fold. Everything else in the function matches, including
the sine macro. Candidate for the CL 10.20 experiment.

## `/Oa` (assume no aliasing): a per-function flag, not a shape (solved 2026-09-28)

00401f20 (SFX_Open) is **exact** with its natural source under
`/O2 /G5 /Oy /GR- /Oa` (source: `.work/claude-hand-decomp-20260925/w/00401f20.exact.cpp`)
and cannot be matched under the project flags: its loop loads `*size` before
the store through `sound`, which only a compiler that assumes the two pointers
do not alias may do, and the hoisted temporary then takes a fresh ebx (the
prologue's `push ebx`). Under `/Oa` both follow with no spelling tricks.

The flag is per function (or per file), not global: SND_PlaySound (00401b50),
the hunt code (004397f0, 00439390), ProcessPaused (0041bfc0) and ob229Init
(0042ff10) all get worse under `/Oa`, because their originals reload globals
after stores through pointers. `tools/probe.py` trials it without touching
project.json: `PROBE_OVERRIDE='{"flags": ["/O2","/G5","/Oy","/GR-","/Oa"]}'`
(every tool built on the probe honours it).

pc-decomp's verifier allowlist had no `/Oa`; it now accepts `/Oa` and `/Ow`
(code-generation switches that read no extra input, which is what the
allowlist exists to prevent). With that backend staged and the per-function
override in project.json (config batch 11), 00401f20 verified exact on
2026-09-28.

What to look for: a load through one pointer scheduled above a store through
another, or a loop temporary in a fresh callee-saved register while a dead
variable's register sits free. Try `/Oa` before searching spellings.

## Register choices no declaration order moves (4, candidates)

Large functions that otherwise match byte for byte, where the last lines are a
register choice that `tools/declpos.py` (every placement of the variables
involved) and `tools/altsearch.py` (spellings, block scopes, retypes, extern
order) cannot move. Each was checked for being a source shape first; the
spellings tried are in the parked notes of `.work/claude-hand-decomp-20260925/`.

- 004397f0 (HuntDiveInner, 2412 B, 12 lines): the original computes
  `r = DAT_004646f8 >> 16` once into **eax** and multiplies both sine results
  by it before the first store. An `r` variable lands in edi here; writing the
  shift twice keeps the other registers right but loses the common
  subexpression (the store through a pointer in between may alias the global).
  A file `static` does not save it either: CL 10.00 reloads a static after a
  pointer store just the same (checked), and `/Oa` changes the whole function.
- 0041bfc0 (ProcessPaused, 2599 B, 6 lines): a value computed into edi is
  copied to ebp before its only use (`mov ebp, edi`) and a flag reload goes to
  esi; CL 10.00 coalesces the copy for every spelling (local, forwarded
  global, a copy inside the block, a block-scoped copy, one variable for both
  ring indices).
- 00439390 (200 B, 10 lines): the index loop's induction pointer gets eax and
  the loaded `y` ebx in the original, the other way round here.
- 0041cb80 (227 B, 12 lines): the original spills `x` only around the loop
  that needs its register (a live-range split, with a dead `xor ebp, ebp` at
  the loop entry); CL 10.00 spills it at its definition.

- 00401f20 (SFX_Open, 102 B): with the source order right (the size load
  before the pointer store, see source-shapes.md), the loop temporary shares
  esi with a variable that died before the loop; the original gives it a
  fresh ebx and saves ebx in the prologue for it. The 0041bfc0 copy is the
  same preference seen from the other side: the original moves a value into
  a register of its own instead of keeping or reusing one.

None is proved: a declaration order is a search, and the search space is not
closed. But five functions of 5.5 KB between them stopping on allocation, not
on shape, is the strongest remaining argument for the CL 10.20 experiment.

## Unplaced out-of-line blocks (1)

004130a0 PlayerSideSpin places the outer `else` call before the inner one;
no nesting, early-return or fall-through form reproduced that order.

## Using this

A near miss whose only remaining difference is one of these shapes is not a
reason to spend another model turn. Record it, move on, and come back when a
second toolchain is pinned. `idiom_scan.py ADDRESS` answers "is this one of
them?" in a second.
