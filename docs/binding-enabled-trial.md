# Binding-enabled reconstruction trial

2026-09-15. The reconstruction workflow added the evidence-backed binding
`_gSFXTable_0049fb54 -> 0049fb54` from the pinned analysis (`audit_global`
reports `gSFXTable_0049fb54`, `undefined4`, four cross-references). No separate
whole-project proof audit was run.

A fresh one-function bounded trial then retried `SND_Destroy_00401f90` using the
approved Luna/Terra/Sol/Astra lane, one pass and a 300-second ceiling. It
completed after one Luna attempt: **ExactMatch, 27 bytes**, 32,348 tokens,
reported cost `$0.0092286`, and authoritative usage.

Adding a global binding intentionally invalidated prior proof statuses under the
current strict binding-hash policy. They remained in immutable attempt history
while reconstruction continued. A subsequent durable re-verification submitted
all 412 historical/new exact candidates in 32-function batches; every batch
completed successfully under the serialized compiler worker. That first binding cycle restored **412 ExactMatch functions / 15,511 bytes**.
A later reconstruction pass found the separate missing callee binding
`_FUN_0040FE80 -> 0040fe80`; loading it intentionally retired the current proof
statuses again. The live status is now 0 current proofs, while the historical
counter remains 412 functions / 15,511 bytes. No source, executable or Ghidra
analysis was modified.

Run evidence is in `.work/smallest-followup-20260915-014251/`; binding evidence
and the configuration backup are in `.work/auto-binding-20260915-004555/`; the
batched re-verification receipts are in
`.work/reverify-all-current-20260915-015330/`.
