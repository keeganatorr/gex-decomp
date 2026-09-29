# What Yodecomp did differently (and what Gex should borrow)

Yodecomp (`~/Repos/Yodecomp`, github.com/shinyquagsire23/Yodecomp) decompiled
LucasArts' Yoda Stories demo engine (MSVC 4.2, MFC, 534 app functions) with
Claude doing essentially all of the work. Read 2026-09-29 from its README,
CLAUDE.md, PLAN_COMPLETED.md and docs/compiler-hunt.md, docs/compile-units.md.
This is a comparison, not a plan of record; decisions belong in TODO/the
config batches.

## Where they ended up

- **Every function transcribed** into idiomatic C++ in 13 real `.cpp`
  translation units, the image links (`tools/link_exe.sh`, 0 unresolved),
  the game runs, and it has since been ported to SDL, WASM and Android.
- **Byte-exact: 211 → 215 of 534** (~40%). The rest are either
  `// EFFECTIVE` (behaviourally faithful, an annotated allocator/scheduling
  residual; ~40 of them) or still-unfaithful source (~134). "Coverage 99.17%"
  is transcription coverage, not byte-exact coverage.
- So their definition of done was: **complete, linkable, runnable source;
  byte-exact where the toolchain allows; residuals annotated, not ground.**

Gex today: 1076/1181 game functions byte-exact (91%, 64% of bytes) — far
more exact than Yodecomp — but no whole-image link and ~105 functions with no
committed source at all. The gap between the projects is the opposite one:
Gex is ahead on exactness and behind on completeness.

## Lessons that map directly onto open Gex residuals

Their numbered codegen lessons (PLAN_COMPLETED.md "KEY codegen lessons") are
for MSVC 4.2 but agree with everything measured here under 10.00.5270:

| Yodecomp lesson | Gex evidence |
|---|---|
| #7/#8 + v96: **register allocation depends on TU context**; the driver is the *file-scope symbol count* (enum = tag + fields, macros free, identifier length irrelevant) | our `decl_pad` padding is exactly this dial, measured per function instead of per TU |
| v96: **"the dial is an instrument, not a knob"** — a gain with zero regressions means a real missing declaration; a trade means padding. They never commit placeholder padding. | Gex *does* commit `decl_pad_N`/`decl_fn_N` (with a comment saying so). Honest, but it encodes a number, not a fact |
| #13: repeating an expression vs a local decides slot vs register residency | 0x421560 (target spilled), 0x434190/0x434260 (path in eax), 0x423b80 |
| #19: **aliasing dictates locals** — per-statement reloads mean the source had no caching local, or stores went through a pointer lvalue | the "load never hoisted above a stack store" cases: 0x41d310, 0x434b10, 0x4344d0 (volatile only approximated it) |
| #15: block layout is trace-driven and mostly not source-steerable → annotate and park | 0x4130a0 family (order of two out-of-line jump blocks) |
| #6: cmp operand order is often not forceable by the expression | many of ours moved only via declaration position |
| #10: `x <<= s; x &= m;` as separate statements never combine | 0x4054c0's two-statement `left` assignment |
| workflow rule: `align==0 && reg_pen>0` ⇒ allocator tie-break ⇒ **stop after ~30 min, annotate, move on** | we routinely spent hours per near miss |

## Things they did that Gex has not

1. **Identified the compiler by fingerprinting the static libraries**
   (docs/compiler-hunt.md v52): 20-byte relocation-tolerant windows of the
   exe's CRT/MFC region against LIBCMT/NAFXCW from VC 4.0/4.1/4.2 — 1404
   windows unique to 4.2, zero to the others. Decisive where compiler A/B
   tests were not.
   **Done for Gex 2026-09-29 with what is on disk** (16-byte windows,
   relocation bytes excluded, over 0x449000–end of .text, `tools/libfingerprint.py`):
   NTSource c1032 libc/libcmt match **7647 / 26096** windows (29%), c932
   **1581**; 6136 unique to c1032, 70 unique to c932. So Gex's CRT is of
   c1032's generation but is **not** those libraries — the retail VC 4.x
   LIBC is untested. Their conclusion also warns that libraries and the
   app compiler are separable axes.
2. **Compile units reconstructed from data layout** (docs/compile-units.md,
   `tools/segment_cus.py`): MSVC emits a TU's `.rdata/.data` contiguously in
   `.text` order, so a function's lowest own-data reference steps up at each
   `.obj` boundary. They then compile whole TUs, which is what makes the
   symbol-count dial a real fact rather than a per-function pad.
3. **Residual classification** (`tools/idiomscan.py`): split non-exact
   functions into pure-regalloc / scheduled / source-or-idiom by aligned
   structure and mnemonic multisets. It found only 41 of 175 were
   allocator/scheduling residuals; the other 134 were unfinished source.
   Gex's parked notes are qualitative only.
4. **Whole-image oracles**: full link, field/slot scan, vtable and
   message-map checks — completeness proven by the image, not by a count.
5. **Hand-written assembly kept as `__asm`** (Canvas.cpp blitters, CPUID in
   Deskcpp.cpp, MMX opcodes as `_emit`), with a portable C path under
   `#ifdef YODA_PORTABLE`. Gex's policy forbids inline asm, which leaves
   ~22 functions (~35 KB: tile drawers, span loops, int3/ebp helpers)
   permanently unmatched.
6. **Session protocol**: CLAUDE.md carries only the current "next session
   pickup"; history is appended to PLAN_COMPLETED.md; lessons are numbered and
   cited by number. Same idea as this repo's knowledge/ docs and parked.txt,
   but with one canonical pickup block per session.

## Suggested adoption, in order of payoff

1. Decide whether provably hand-written functions may use `__asm` (with the
   evidence in a header comment and a C reference beside it). Biggest single
   lever: ~35 KB.
2. Obtain retail VC 4.0/4.1/4.2 `LIBC.LIB` (Yodecomp keeps
   `toolchain/vc40`, `vc41`, `vc42` locally, gitignored) and repeat the
   fingerprint; if the CRT matches a later 4.x, A/B its `cl` on the parked
   near misses.
3. Adopt an `EFFECTIVE` state: a verified-equivalent source with an
   allocator/scheduling autopsy counts as transcribed, with a time box per
   function. Keep ExactMatch as the proof tier.
4. Segment Gex into compile units from `.rdata/.data` order, then try
   compiling neighbours together; replace `decl_pad` counts with real shared
   declarations as they are found.
5. Classify every open function like `idiomscan.py` so effort goes to the
   ~source-unfaithful class first.
