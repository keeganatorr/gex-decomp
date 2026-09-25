# Project memory inputs

`historical-lessons.json` is a curated import manifest
(`pc-decomp-historical-lessons-v1`) for pc-decomp's schema-7 project memory. It
restates the reusable lessons from `docs/iterative-editedgex.md` (blob
`ac4e18bf218dec3a4c974f90c755a650ce451afc`) with their caveats, trigger feature
terms and the functions they cite. It is an input, not an authority: importing it
creates `historical-documented` recipes, and each cited function is linked only to
what its retained proof artifacts establish at import time. Nothing is recompiled
and no provider is called. See `../pc-decomp/docs/project-memory.md`.

Generated human-readable views belong in `docs/decomp-knowledge/` (written by
`pc-decomp memory-export`); do not hand-edit them expecting the database to change.
Edits come back only through `pc-decomp memory-import-docs` as proposals.

## Read-only dry run (2026-09-25)

The bootstrap was exercised against a snapshot copy of this project's store
(SQLite backup API; retained attempts and sources read through symlinks; a
copied `project.json` with `schemaVersion: 7`). The live project, its database,
`project.json`, sources and running backend were not modified.

- 1,323 functions scanned; 752 exact proofs reconciled with their retained
  artifacts (0 report-only); 10 per-function contract observations; 115 saturated
  output families; 1,201 dossiers; 6 historical lessons imported.
- Second run: 0 new records; the attempts directory stayed at 5,838 entries (no compile).
- Linked history is honest about the present: `00417f00`/`00417f40` have no
  current exact proof, while `0041fba0` (cited in a negative lesson) is now exact.
- A cutoff-now benchmark plan over the 60 smallest unsolved functions reported
  zero leakage; 37 received related solved examples (e.g. `ObjCallUnk` siblings),
  6 received approval-needed per-function contract observations, none matched a
  historical recipe's triggers, and 23 received nothing, which is a valid outcome.

This project stays on schemaVersion 6 until the operator explicitly activates
the schema-7 backend and restarted Nexus host. No campaign was started.
