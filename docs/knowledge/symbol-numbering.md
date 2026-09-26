# Symbol numbering decides operand order, registers and schedule

Recipes: `symbol-numbering-padding`, `symbol-numbering-declaration-order`,
`front-end-language-switch` in [recipes.json](recipes.json). Found by hand
decompilation on 2026-09-25/26; 17 functions went from near miss to current
exact proof with it (the whole hand session: 752 → 773 exact, 63,353 → 66,802
bytes, including four body fixes in [natural-field-access.md](natural-field-access.md)).

## The observation

`0042dcf0` had 21 attempts, a 96-candidate compiler-guided search and several
model campaigns behind it, all stuck at 63%:

```
target                              best candidate
mov ecx, [esp+4]                    mov eax, [gPlayerObject]
mov eax, [gPlayerObject]            mov ecx, [esp+4]
cmp ecx, eax                        cmp eax, ecx
```

Every semantic rewrite — `a == b` vs `b == a`, locals, `register`, early
return, ternary, types — produced the same canonical order. The fix was
outside the function body: declare the callee `FUN_0042CC70` before the global
`DAT_004A27FC`. Controlled experiments on that function (all compiled with the
pinned CL 10.00.5270, `/O2 /G5 /Oy /GR-`):

| Declarations before the function (D = global, F = callee, x/y/z = unused data) | Result |
|---|---|
| D F | wrong order |
| F D | **exact** |
| x D F | wrong order |
| x y D F, x y z D F | **exact** |
| D x F, D x y F, D x y z F, D F x | wrong order |
| x F D, F x D | **exact** |

Renaming any identifier (parameter, global, callee, padding) changes nothing;
an unused `int` and an unused `char *` behave the same; an unused function
*prototype* counts differently from a data declaration. The choice is not
"source order": it behaves like a comparison of internal symbol numbers or
symbol-table addresses, which every earlier declaration shifts.

## Why this matters

The original translation units included large headers. Their declarations
fixed this numbering; a reconstructed, self-contained TU does not have them, so
equivalent encodings — which operand of a commutative compare/add is loaded
first, SIB base vs index, which scratch register, the relative order of two
independent loads — come out as a coin flip per decision. Models and semantic
search families cannot reach it because they only edit the body.

## The levers, cheapest first

`tools/perturb.py ADDRESS SOURCE --moves` does all of them, stopping at the
first exact probe (typically < 3 s; 0.1 s per compile with a warm Wine server):

1. **Orders** of the existing top-level declarations: every order up to five
   declarations, otherwise single moves and swaps. Preferred when it works
   (0042dcf0, 0043b9e0, 004196e0, 004237c0): no padding in the source.
   `004237c0` sums four globals in a loop; the loads follow the *reverse* of
   their declaration order and only that one of 24 orders matches.
2. **Padding**: insert 1–16 `extern int decl_pad_N;` at each declaration slot
   (00429b40 needed 10, 00433590 needed 14).
   They emit no code and no relocations. The tool writes a comment block saying
   they are compiler-state padding, not recovered source; keep it.
3. **Front end** (`--languages cpp,c`). `/Tc` numbers symbols differently. A C
   result is a per-function contract change (`functionOverrides`, service
   restart). 004195d0 and 004404b0 first matched only as C, then also as C++
   with 1–2 padding declarations — prefer the C++ form.

Measured on the near-miss backlog: ordering alone fixed 3 of 55 functions at
≥ 75%; padding up to 8 then fixed 11 of the 77 remaining functions at ≥ 50%
that have a source; padding up to 16 and full orders added 3 more of 20.
What remains is mostly a register choice or a single moved instruction that
none of the levers reach (00420210, 00431900, 0041f860, 0042de50): possibly
the compiler-version gap in [toolchain-limits.md](toolchain-limits.md).
Functions it did not fix usually have a second, semantic difference; fix that
first and rerun, since the perturbation only helps once the body is right.

## Proof status and honesty

Published through the normal durable queue (`scripts/verify`), attempts under
`.work/claude-hand-decomp-20260925/`. An exact proof with padding says the
pinned compiler emits the original bytes from this TU. It does not say the
original had these declarations, in this order, or that its compiler was CL
10.00 (see [toolchain-limits.md](toolchain-limits.md)). Padding is a
byte-matching surrogate in the same sense as the opaque-entry import thunk.

## Automating it

This is deterministic, provider-free and cheap, so it belongs in the backend,
not in a model's turn budget: whenever a compiled candidate's mismatch shape is
`operand-order`, `register-rename` or a same-length `general` difference, run
the perturbation family before spending the next model turn. `--manifest`
emits the same family as a pc-decomp SourceSearch manifest.
