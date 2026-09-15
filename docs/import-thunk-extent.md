# Import-thunk extent and the "noncontiguous analysis" blocker

2026-09-15. Three import thunks were blocking the decomp loop with
`Unsupported/edited/noncontiguous analysis; original-byte analysis required`:

- `00409870 DirectSoundCreate_00409870`
- `00409876 DirectDrawCreate_00409876`
- `0044f5ea RtlUnwind_0044f5ea`

All three are a single instruction, an absolute indirect tail jump through an IAT
slot:

```
  409876: ff 25 cc 53 4a 00   jmpl  *0x4a53cc
```

Their ordinals and bytes already matched the pinned original
(`ghidraBytesEqualOriginal` true). The blocker was purely the terminator rule:
`Verifier.HasCompleteReturn` accepted `ret`/`iret` and a **direct** `jmp addr`,
but not an absolute-indirect `jmp *mem`. With no accepted terminator the extent
was recorded unverified, and `DecompLoop.Prepare` refused the function.

## Fix

`HasCompleteReturn` now also accepts an absolute indirect tail transfer
(`jmpl *0x...` or `jmp dword ptr [0x...]`). This is the same external-transfer
case already allowed for a direct jump: the instruction leaves the retained
range, so it is not evidence of a truncated/estimated body. Register-indirect
(`jmp *%eax`) and index-indirect (`jmp *table(,%eax,4)`) forms are still
rejected, because their targets are not statically known.

`DecompLoop.Prepare` also persists the refreshed analysis fields it evaluated,
re-reading the row and copying only analysis keys so it never clobbers
attempts/source owned by the verification worker. The UI and later proof checks
therefore see the same extent the loop used.

No verifier relaxation: relocation-byte masking, extent byte comparison and the
edited-body refusal are unchanged. The three genuinely patched bodies
(`WndProc_00403960`, `WinMain_00405bf0`, `FUN_00444d10_GFX_OpenGraphics`) remain
blocked.

## Activation and retest

Backend `thunk-extent-b125c7caa11ecf09` (sha256
`b125c7ca…33ed`) replaced `thunks-6dc57286abfeab4e`. Before/after unit,
project and rollback steps are in
`.work/thunk-extent-activation-20260915-181202/activation.json`.

While the owner lock was free, the offline `detail` command persisted
`extentVerified=true` and `ghidraBytesEqualOriginal=true` for all three thunks.

Run `loop-5118084f5439aeb798322d59` (DeepSeek V4.1 Flash/high,
`.work/thunk-extent-retest-20260915-180533/`) processed all three with
**blockedCount 0** — no noncontiguous message. None became exact: DirectSound
and RtlUnwind produced no usable proposal (model deadline and an upstream
provider error), and DirectDraw returned an argument-forwarding wrapper rather
than the six-byte compiler-specific cast thunk already proven in isolation in
`docs/isolated-import-thunk-match.md`. Exact proofs stayed 417.

The remaining work for these thunks is source matching, not extent or bindings.
