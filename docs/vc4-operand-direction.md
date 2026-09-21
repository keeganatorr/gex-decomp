# VC4 operand direction and register selection for two-memory comparisons

Measured against the pinned `vc40-cl-10.00.5270` under the dedicated `wine-vc4`
prefix with the project contract flags `/O2 /G5 /Oy /GR-`. Established while
resolving `0041fba0`, where 46 attempts across 8 source revisions plateaued at
17/18 bytes.

## The plateau

`0041fba0 VSIT_ForcedVoiceSituationReady_0041fba0` is 18 bytes:

```
33 c0              xor  eax, eax
8b 0d dc 39 46 00  mov  ecx, [0x4639DC]
3b 0d d0 02 4a 00  cmp  ecx, [0x4A02D0]
0f 94 c0           sete al
c3                 ret
```

Every candidate reproduced all of it except byte 8:

```
original : 33 c0 8b 0d dc 39 46 00 3b 0d d0 02 4a 00 0f 94 c0 c3
plateau  : 33 c0 8b 0d dc 39 46 00 39 0d d0 02 4a 00 0f 94 c0 c3
                                    ^^
```

`3B /r` is `CMP r32, r/m32` (register is the destination, memory the source).
`39 /r` is `CMP r/m32, r32` (memory is the destination). Same ModRM, same
disp32, semantically identical for `ZF`. Only the direction bit differs.

## The two levers

For `a == b` where both operands are memory, this compiler decides two things
independently, and both must be steered:

1. **Which operand is loaded into a register — declaration order.** The operand
   whose `extern` declaration comes *second* is the one loaded. This is the lever
   no proposal ever varied; models varied qualifiers, expression order, locals
   and subtraction identities instead, all of which leave it untouched.
2. **The CMP direction and the register — `volatile` placement.** The `volatile`
   operand becomes the CMP's memory operand and the other is loaded. A volatile
   memory operand is the *destination*, giving `39`; a plain one is the *source*,
   giving `3B`. Any `volatile` in the function also moves register allocation
   from EDX (ModRM `15`) to ECX (ModRM `0d`).

Both are required. Either alone stalls:

| declarations | volatile on | result |
|---|---|---|
| `4639DC`, `4A02D0` | `4A02D0` | 94.4% — right load, wrong direction (`39`) |
| `4639DC`, `4A02D0` | none | 55.6% — wrong load, EDX |
| `4A02D0`, `4639DC` | none | 88.9% — right load and `3B`, but EDX |
| `4A02D0`, `4639DC` | `4A02D0` | **exact 18/18** |

## The proven source

```cpp
extern "C" {
extern volatile unsigned int DAT_004A02D0;
extern unsigned int DAT_004639DC;
unsigned int __cdecl GEX_Target(void)
{
    return DAT_004A02D0 == DAT_004639DC;
}
}
```

Differs from the long-standing 94.4% candidate *only* in the order of the two
`extern` declarations.

## Method note

Opcode/ModRM shape is not sufficient to judge a candidate: one probe matched the
target's shape byte-for-byte while its relocations pointed at the opposite
symbols, making it the existing 66.7% family. Always resolve relocations against
the pinned bindings and compare resolved bytes. Offline probes are diagnosis
only — the strict relocation/byte verifier remains the sole source of a proof.

## Declaration order also decides register-to-register CMP encoding

`0041fba0` showed declaration order selecting which *memory* operand is loaded.
The SetVolume cluster shows the same lever deciding the ModRM encoding of a
**register-to-register** compare, where no memory operand is involved at all.

All three functions share the shape `mov edx,[global]; lea ecx,[eax+eax*4]; cmp`:

| function | original | candidate produced | declarations |
|---|---|---|---|
| `00401e20` | `3b ca` `cmp ecx,edx` | `3b d1` | global, then function |
| `00401ed0` | `3b ca` `cmp ecx,edx` | `3b d1` | global, then function |
| `00401e70` | `3b d1` `cmp edx,ecx` | `3b ca` | function, then global |

Moving the callee's declaration ahead of the global flips the encoding, and the
flip runs in *both* directions — `00401e20`/`00401ed0` needed the function first,
`00401e70` needed the global first. All three verify exact with no other change.

Two things this rules out, both measured:

- **Swapping the comparison's operands does nothing.** `00401e20` writes
  `DAT_0049FB20 != newVol` and `00401ed0` writes `newVol != DAT_0048a030` —
  opposite source order, identical wrong output. VC canonicalises `==`/`!=` on a
  register pair, so reordering the expression is not a lever. Neither is
  restructuring into a `&&` comma expression, nor an intervening global store.
- The same canonicalisation is why an operand swap failed on `0041f8c0`, whose
  remaining single byte is also a reg-to-reg ModRM.

Practical rule: when a candidate is byte-perfect except for one ModRM byte in a
`3b` compare, permute the order of the `extern` declarations before touching the
expression. The expression is usually already correct.

## Where the declaration lever stops working

Three functions resisted it entirely: `0042e8b0`, `0043a7c0` and `00419520`.
Each is one ModRM byte from exact (`00419520` is four copies of the same byte),
each compare is followed by `je`/`jne` so the operands are commutative, and each
was searched exhaustively:

| function | search | result |
|---|---|---|
| `0042e8b0` | all 24 declaration orders x volatile (96), expression swap | no exact |
| `0043a7c0` | all 24 orders x volatile (120), expression swap | no exact |
| `00419520` | 4000 of ~5040 order x volatile variants, casts removed, expression swap | no exact |

`00419520` shows why. Its original contains **six identical `3b c6` compares**.
The candidate reproduces the first two exactly and gets the last four wrong,
even after every comparison is written in the identical uncast pointer form:

```
  43 matches   3b c6   cmpl %esi, %eax
  58 matches   3b c6   cmpl %esi, %eax
  73 MISMATCH  3b c6   cmpl %esi, %eax     (and 88, 103, 118)
```

So the encoding this compiler chooses depends on the comparison's **position in
the statement sequence**, not on how that comparison is written. No per-site
source form can make all six agree, and no declaration order reaches it either.

This is the same wall as the register-rename class in `0042de50` and `00417f40`:
a whole-function code-generation decision that the source cannot address. Note
`project.json` records `"originalCompilerProven": false` — the pinned
`vc40-cl-10.00.5270` is a recovered candidate. A build that emitted all six
compares uniformly would explain every one of these at once.

The expression swap being inert here is also the first direct test of the
canonicalisation claim rather than an inference from it: swapping operands on
all three functions changed nothing.

## Local declaration order is a second, independent lever

`004308d0 ob229Draw` was one of the "register rename" near misses: four bytes
off, two field loads landing in exchanged registers and the matching stores
likewise. Extern declaration order does nothing for it. What works is the order
of the **local variable declarations**, and it is independent of the order of
the statements that assign them:

| local decls | load order | store order | result |
|---|---|---|---|
| `ypos, xpos` | ypos first | xpos first | 4 off (baseline) |
| `xpos, ypos` | ypos first | xpos first | stores fixed, loads worse |
| `ypos, xpos` | xpos first | xpos first | loads fixed, stores still off |
| **`xpos, ypos`** | **xpos first** | **xpos first** | **exact** |

Separating declarations from assignments is what makes this searchable: while
the locals are declared with initialisers the two orders are the same edit, and
neither alone reaches the target.

This does **not** generalise. `00417f40` has three locals and all six
declaration orders produce identical output; only the assignment order moves it,
and none of the twelve combinations is exact. Treat local declaration order as a
knob to try, not a rule.

## Constant selection is also outside source control

`00412750 InitPlayerSideUTurn` and its siblings `00411d70` and `00411b90` are
four bytes off in a single immediate. The original masks `0x80000000`; every
candidate emits `0x8fffffff`:

```
original : 81 e7 00 00 00 80    andl $0x80000000, %edi
candidate: 81 e7 ff ff ff 8f    andl $0x8fffffff, %edi
```

The two are equivalent in context — the result is immediately `shr edi, 0x1c`,
which discards bits 30..28, so both masks leave bit 31 in bit 3. The source was
never wrong.

Eight source forms were tried: a separate local for the masked value, a `U`
suffix, full parenthesisation, splitting into two statements, reversing the `|`
operands, a volatile local, and `((x >> 0x1f) << 3)` — a structurally different
expression computing the same value. **All eight produced byte-identical output
with `0x8fffffff`.** The compiler normalises them to one internal form and picks
its own constant encoding, so no source form reaches the original's choice.

This is the third independent line of evidence for the same conclusion, after
the register-rename class and `00419520`'s position-dependent compare encoding:
the pinned `vc40-cl-10.00.5270` makes code-generation choices the original
compiler did not, and `project.json` already records
`"originalCompilerProven": false`.
