# Fresh small-function search test

Subsequent user-approved [search improvements and results](search-hypotheses.md)
are recorded separately; the following is the original 24-variant test.

User requested one very small, not-yet-reconstructed function after the two-target
compiler-search benchmark. Selected **FUN_0044C690, 0044c690**, 20 bytes:
`fn-1e76a83eaed606dd9cbc6a2c`.

Before this test it had zero retained compiler attempts, no source file, empty
attempt history and Unanalysed status. Ownership was unknown, reconstruction
eligible, not a confirmed dependency. Its calls resemble runtime cleanup, but no
library classification was inferred from that resemblance. The complete original
body and current Ghidra bytes passed the existing independent preflight. Another
29-byte candidate was inspected during selection, not compiled or modified.

## Scope and result

- One function, at most 24 variants / 60 seconds; warm dedicated compiler cache.
- Fixed CL 10.00.5270, C++, `/O2 /G5 /Oy /GR-`; no configuration/binding changes.
- No proposal-provider calls, executable/Ghidra writes, padding or byte injection.
- Reviewed family: call the first helper, then read the byte flag, conditionally
  call cleanup, with provisional void return. Variants change conditional syntax,
  byte signedness and local temporaries, not memory access width or call order.
- Host C++98 behavior tests passed **18,432 checks** across all 24 variants: every
  flag byte, three initial flag values, and a first helper that changes the flag.
  Tests check call order/branch timing and ignore cleanup's return. These are not
  exact-byte proofs and do not establish the original return type.
- **24 probes + one fresh full finalist verification; 2.536 seconds total**,
  including 227 ms cache setup and 340 ms final verification. Median probe
  compilation: **46 ms**.
- **One distinct output, no exact match.** Both bodies are 20 bytes, with 13 equal
  positions. This positional count is not semantic confidence or a proof.

The decisive difference after the first call:

```
Original:  cmpb $0, [00461138]
Candidate: movb [00461138], AL
           testb AL, AL
```

The conditional branch, tail transfer and return follow the same arrangement.
All destinations resolved without new bindings:
`_FUN_0044e7e0 → 0044e7e0`, `_DAT_00461138 → 00461138`,
`_FUN_0044e920 → 0044e920`.

The original compare leaves EAX intact whereas the candidate overwrites AL. A
possible **untested** next hypothesis is a return-value-preserving interface,
rather than more void-return cosmetic variants. Ghidra's void pseudocode is not
proof of that interface. The announced 24-variant budget ended here; no additional
candidate, compiler-contract change or replacement target was tried.

## Evidence and final state

- Search: `search-334d53906b869d784108e0e8`.
- Stable command: `fresh-small-source-search-v1-0044c690`.
- Full verification: `attempt-574b26204d79412bac34cb7a638e4a01`, **not exact**.
- `.work/fresh-small-search/` retains initial details, generator, host behavior
  test/results, manifest, command, stopped-state backup, result/log and final detail.
- Per-probe artifacts: `.work/searches/search-334d53906b869d784108e0e8/`.
- Used the previously tested immutable offline CLI
  `.work/backend/source-search-71798fd69a6e50ae/PcDecomp.dll`; all its file hashes
  checked against the retained implementation manifest before launch.
- Original live service restored; campaign still Stopped. No source published.
  Function remains Unanalysed with one retained full verification attempt.
- **424 exact / 15,882 matched bytes unchanged.** No existing matching function was
  recompiled or subjected to a whole-project byte audit.
