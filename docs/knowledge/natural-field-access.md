# Natural field access beats Ghidra-shaped locals

Recipe `natural-field-access` in [recipes.json](recipes.json).

Ghidra types most object parameters as `GXObject **`, so its pseudocode for
`GOB_ProcessYPositionChange` (`004390d0`) reads

```c
pGVar3 = (GXObject *)((int)param_1[0x23]->gob_scripts[0].gas_stack +
                      (int)(param_1[0x25]->gob_scripts + -1) + -0xc);
```

and candidates derived from it cache every field in a local:

```c
int a = p[0x25]; int b = p[0x23]; int sum = b + a; int bound = p[0x24];
p[0x23] = sum;
if (sum > bound) p[0x23] = bound; else if (sum < -bound) p[0x23] = -bound;
```

That compiled to the right instructions with one compare mirrored (93.7%, six
attempts). The layout Ghidra already has for `GXObject` names these members
`gob_yVel`, `gob_maxyVel`, `gob_yAccl`. Written the way the programmer would
have written a velocity clamp, re-reading fields through the pointer, it is
exact with no other change:

```c
gob->gob_yVel += gob->gob_yAccl;
if (gob->gob_yVel > gob->gob_maxyVel)
    gob->gob_yVel = gob->gob_maxyVel;
else if (gob->gob_yVel < -gob->gob_maxyVel)
    gob->gob_yVel = -gob->gob_maxyVel;
MoveGuillotine(gob, gob->gob_yVel);
```

Its twin `00439090` (x axis) needed the same body plus symbol-numbering padding
([symbol-numbering.md](symbol-numbering.md)); the two levers compose.

The same happened to `004213f0` (GexMovementLeftAndRight, 213 bytes): the
retained candidate followed Ghidra's goto-shaped control flow and inverted one
conditional jump; the natural version — `gob->gob_xVel += gob->gob_xAccl`,
friction toward zero, `if (vel < -max) vel = -max; else if (vel > max) ...`,
then the wall-collision divide — matched on the first compile.

## Stack frames

`00421820` differed in `sub esp, 0x28` vs `0x18` and in every `[esp+k]`. Ghidra
had split the 40-byte record `CLD_ComputeAngleEdges` fills into `local_28[6]`
plus `local_10`/`local_c`, and the candidate read those two locals without ever
writing them. One `int edges[10]` read as `edges[6]`/`edges[7]` matched exactly.
When the frame size differs, size the aggregate from the frame and the `lea`
handed to the callee before touching anything else.

## How to get the layout into a self-contained source

```sh
tools/ghidra_struct.py GXObject --only 8c,90,94 --name GXObject
```

prints a struct with only those members and padding elsewhere. The layout is
evidence, not proof: an exact match does not establish member types, and a
member Ghidra has wrong will still compile to the same bytes if it has the
same width.

## Why models miss it

Loop prompts carry Ghidra pseudocode and target assembly but no layouts, and
the project allowed only opaque `GXObject` pointer slots, so a model has no
reason to write `gob->gob_yVel`. Supplying the relevant members of known
structs in the prompt is the cheap fix.
