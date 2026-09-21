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
