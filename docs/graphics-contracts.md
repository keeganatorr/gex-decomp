# Graphics/object contract recovery

## `GOB_DisplayObject_00444590`

This is the next high-fanout dependency: 615 bytes and 34 callers. The pinned
body is complete and byte-equal to the original import. It should not receive a
placeholder `GXObject`/sprite layout.

Observed contracts from the assembly:

- Input is one object pointer. Object word offsets used directly are `0x18`,
  `0x1b`, `0x1e`, `0x1f`, `0x2f`, `0x30`, `0x38`, `0x7d`, `0x7e`, `0x7f`,
  `0xbc`, `0xc0`, `0xe0`, `0x1f4`, `0x1f8` and `0x1fc` (word offsets are the
  displayed byte offsets divided by four where applicable).
- The current-frame helper returns an opaque sprite pointer. Its word at `+0x18`
  is the head of a draw-record chain. Each iteration advances the record cursor
  by four bytes and reads the next record from the cursor's word zero.
- A draw record has observed words at `+0`, `+4`, `+8`, `+0xc` and `+0x10`.
  `+0x4` carries horizontal/vertical flip bits `0x80000000` and
  `0x40000000`; `+0x8` is an image pointer; `+0xc` and `+0x10` are fallback
  position values. The loop terminates on a null next record.
- The image object has observed fields at `+0`, `+4`, `+8`, `+0xc` and
  `+0x14`. The first four are width/height/offset values used in fixed-point
  clipping; `+0x14` gates drawing.
- Camera globals are `004a2974`, `004a2988`, `004a2a94`, `004a2a96`. Object
  position/flag values are clipped against `0x1400000` horizontally and
  `0xf00000` vertically, with sign-aware flip arithmetic.
- `FUN_0043dc70` is called cdecl with eight 32-bit arguments. The call consumes
  `0x20` bytes. Its call-site argument order is visible at `004447c5` through
  `004447d1`; its own 1,610-byte body is still unresolved.

Ghidra's read-only type inventory supplies corroborating layouts: `GXObject`
size `0x200` with `gob_flags` at `0x6c`, position at `0x78/0x7c`, animation
pointer at `0x0c`, parent at `0x15c`, and animation/group fields at `0x50/0x54`;
`DrawStructUnk` is 20 bytes with next/flags/image at `0/4/8` and position words at
`0xc/0x10`; `SpriteStruct` is 28 bytes with its draw head at `0x18`;
`ImageStruct` is 36 bytes with the draw gate at `0x14`; and `astruct_22` is 22
bytes with integer fields at `0x4/0x8/0xc`. These definitions were read only;
no Ghidra types or bodies were changed. They are useful corroboration, but a
reviewed source candidate must still use independently justified declarations or
opaque byte-offset accessors. Do not add padding-only structs merely to make the
provisional pseudocode compile.

## Dependency order

A typed-contract probe for `0041a500` used those recovered animation layouts and
removed the provisional null checks. It improved the retained score but still
emitted a different register allocation and was not published. The mismatch is
recorded under `.work/full-source-coverage/current-frame-typed/`; it is not proof
of a different layout.

1. Recover `0041a500` current-frame return/chain contract and its callers.
2. Resolve the draw-record/image contracts above and the exact eight-argument ABI
   of `0043dc70`.
3. Form compiler hypotheses for `00444590`; only then revisit the larger
   `00441150` scale/rotate path.
4. Separately recover `0041cb80`/`0042d2c0` angle-edge and tile callback
   contracts. The first raw-offset `0041cb80` experiment was retained as a
   non-exact near miss and is not evidence for a source layout.
