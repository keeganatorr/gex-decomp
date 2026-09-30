# Astra loop fixes — activated

The operator requested “Apply fixes” after the bounded campaign/audit.
Activated backend commit **d286452a76c4d23f79d946bf0be2a8640f8846ce** as immutable
release **astra-loop-d286452-cec8d7ff8e72** on 2026-09-22.

Backend:
`$HOME/.local/state/pc-decomp/staged/astra-loop-d286452-cec8d7ff8e72/backend`

The release includes `Iced.dll`; its instruction decoding is advisory only.
Strict verification, pinned compiler/flags, bindings and Ghidra are unchanged.
Closest-first applies to **new** campaigns. Historical diagnostic records and the
completed campaign's frozen order are not rewritten.

## Process / launch consistency

The previous owner was a directly launched process using the mutable repository
build, not the inactive systemd unit. After confirming terminal campaign and idle
verification, it was stopped gracefully with SIGTERM. Only then was the new
owner started through `pc-decomp-gex.service`; no overlapping owner or socket
unlink was used. The unit remains disabled for automatic login startup, as before.

All launch paths now agree on the immutable backend:

- `~/.config/systemd/user/pc-decomp-gex.service` (active owner)
- `~/.local/state/nexus/extension-services.json` (`pc-decomp.launch`)
- `.work/backend-current` (standalone CLI wrapper)

Nexus, its agents and the native extension were not restarted. The work bridge
reconnected automatically. Service generation changed from
`run-9cd918cac8054ecd9e882f7c90a8734b` to
`run-aa6946b567a1452c8c70dc69f0ce32d9`.

## Acceptance

Before activation, rebuilt outside the live output directory and passed:

- backend selftests;
- full synthetic socket/SQLite/fake-compiler/Ghidra integration, including
  diagnostic provenance, transport pause/no-retry, investigation routing,
  closest-first dispatch and publication guards.

After startup and source-currency processing, checked:

- **740 exact / 61,108 bytes** unchanged;
- all **740 exact proof metadata records and source revisions** identical;
- all **1,088 source-file hashes** identical, no added/removed sources;
- `project.json` hash unchanged;
- every deployed file matches the staged SHA-256 manifest, and the live process
  command line names that release;
- campaign `loop-934da8537fb606c616423ead` still **LimitReached**, 184 attempts;
- policy, tokens, reported cost and gains unchanged; **zero active lanes** and
  **zero queued/running verifier tasks**;
- service healthy, bridge connected. No new campaign, Resume, paid model call,
  live compiler probe or bulk re-verification was performed.

## Receipt and rollback

Local deployment receipt (not committed; contains proof/source manifests and
configuration backups):
`.work/activation-astra-loop-d286452-cec8d7ff8e72/receipt.json`.
Build/selftest/integration logs are beside it. The receipt stores previous unit,
launch configuration and CLI link, plus before/after snapshots and complete file
hashes.

A separately built, selftested immutable pre-fix backend from commit `66d2972`
is retained at:
`$HOME/.local/state/pc-decomp/staged/astra-pre-audit-66d2972-99aacf362956/backend`.
This was built from the pre-fix source because the previous owner used a mutable
build path; that path is not a reliable rollback binary.

Rollback only after confirming terminal/drained work: stop the service, point all
three launch paths to the retained rollback backend, daemon-reload and restart,
then repeat proof/source preservation checks. **Never restore an old database or
start/resume paid work as part of rollback.**
