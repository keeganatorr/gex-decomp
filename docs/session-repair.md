# Schema-6 same-session repair activation

Activated immutable backend/UI `session-repair-e3b19e240e398dd4` with the project's
explicit schema-6 opt-in. The already-restarted Nexus host/runtime at
`stable-30eea9c66bb1` matched all staged host-module and native-runtime hashes.
No Nexus restart or model call was needed during activation.

Only `project.json.schemaVersion` changed, from 5 to 6. Service and
`.work/backend-current` now use:

`$HOME/.local/state/pc-decomp/staged/session-repair-e3b19e240e398dd4/backend`

The release UI loaded successfully through the native rendered-frame check.
Backend reports `persistentRepairEnabled:true` and `persistentRepairSupported:true`.

## Preservation

Before/after API receipts confirm identical **641 exact proofs / 35,146 bytes**,
proof histories, all source-file hashes and progress counts. Compiler settings,
bindings, ownership and every other project setting are unchanged. Campaign
`loop-77482146e96fa7384514b060` remained **Stopped**, with zero active/queued work;
its existing policy was not changed. No campaign was started or resumed.

Receipts and stopped-owner backups:
`.work/session-repair-activation-e3b19e240e398dd4/`

Manifest SHA256:
`9c00070e7ce17f33f9db1457c19950ab42495835ecaa7d5f4d1c539c15d3c151`

## Using it

For a separately confirmed new run, select **Keep the same conversation for
compiler-guided repair**, choose exactly one available model, and set the shared
function budget (default **600 seconds**) plus the overall limit. Schema opt-in
does not silently convert legacy policies or start work. Function time includes
replies, analysis, compilation and paused wall time; it does not reset on Resume.

See `../../pc-decomp/docs/session-repair.md` for evidence-receipt safeguards,
unknown-usage behavior, cancellation, capabilities and testing. Stop/drain with
the compatible backend before any rollback; never restore a historical DB over
newly journalled work.
