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
most valuable open experiment.

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

## noreturn-tail: one extent bug, two real limits

`00436c90` (SCRIPT_ExitScriptError) is recorded as ending at `call _exit`, but
the original bytes continue `add esp, 4; ret`: Ghidra treated `_exit` as
noreturn and cut the extent, and the verifier then refuses the body as
incomplete. A plain C wrapper compiles to exactly the 29 original bytes (given a binding
for `__exit`, which the index finds ambiguous); the
fix is an extent repair in the backend, not a source trick. `00402ec0`
(MUS_SetMusicPlaying) calls `_exit` mid-function and carries on too, so the
original compiler did not treat `_exit` as noreturn.
`004064d0` (WND_CleanUp) and `00449bd0` (CRT entry) really do end at
`call _exit` with no epilogue; CL 10.00 has no noreturn knowledge and rejects
`__declspec(noreturn)`, so those two stay toolchain-limited.

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

## Unplaced out-of-line blocks (1)

004130a0 PlayerSideSpin places the outer `else` call before the inner one;
no nesting, early-return or fall-through form reproduced that order.

## Using this

A near miss whose only remaining difference is one of these shapes is not a
reason to spend another model turn. Record it, move on, and come back when a
second toolchain is pinned. `idiom_scan.py ADDRESS` answers "is this one of
them?" in a second.
