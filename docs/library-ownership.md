# CRT/library ownership — initial activation

Ownership is now separate from reconstruction status and proof. Library functions
remain in the backend and Ghidra, with their IDs, bytes, callers/callees, references,
source and attempt history. No function was deleted or renamed. No source was
compiled or published by this work; no provider reconstruction campaign ran.

## Results

Live scan: `library-scan-2689bf0d40f14f839ff01588a34754ed`.
Machine-readable per-function report: [library-ownership-report.json](library-ownership-report.json).

| Metric | Before | After |
|---|---:|---:|
| Backend inventory | 1,323 | 1,323 |
| Current / historical source ExactMatch | 419 / 419 | 419 / 419 |
| Known static CRT/library | 0 | 28 |
| Proven PE import thunks | 0 | 3 |
| Reconstruction-pool functions | 1,323 | 1,292 |
| Unfinished reconstruction-pool functions | 904 | 873 |
| Reviewable candidate-library functions, still eligible | 0 | 69 |

The original Ghidra inventory has 1,335 non-external entries; 12 fragment records
were conservatively merged/archived in earlier work. This change did not reduce
that inventory. The three previous `Library` statuses were not ownership proof;
they were independently checked against the pinned PE import table here.

Of the 28 CRT identifications, **19 have exact relocation-resolved object matches**
and **9 use corroborated custom-toolchain FID**. Static CRT spans total 3,112 bytes;
the three import thunks total 18 bytes. These are enclosing-span counts, not a new
claim of unique executable coverage. Exact reconstructed bytes remain 15,743.

All remaining 1,292 functions have **unknown ownership**, including the 419 source
matches. They are not called game-owned merely by subtraction. Three edited
reference functions and three diagnosed analysis/extent-blocked functions remain
visible as separate overlapping diagnostic counters. Candidate-library counts
also overlap unknown ownership. The all-inventory `unmatched=904` compatibility
counter is retained, but Nexus's reconstruction progress uses **873**, not 904.

### __fpmath / 00449a70

Both recovered archives contain the expected `fpinit.obj` and canonical `__fpmath`.
The section has the expected 23-byte instruction sequence, including `fnclex`.
Exact-object resolution remains blocked on canonical symbols `__cfltcvt_init`
and `__adjust_fdiv`; no bindings were invented from the bytes being compared.

The complete custom CRT FID database identifies `__fpmath` uniquely by name across
both archive variants, with matching full/specific hashes and score 15. Its actual
call to `00449aa0` is independently checked against the pinned listing; that
56-byte callee has a unique matching custom CRT signature and recorded library
relation. Both target bodies pass separate LLVM/Ghidra address/extent and original
memory checks. Its classification is therefore:

```json
{
  "ownership": "library",
  "libraryName": "msvc-crt-10.00.5270-candidate",
  "ownershipConfidence": "corroborated-custom-fid",
  "reconstructionEligible": false
}
```

It is **not** marked ExactMatch. Its former `Surveyed` reconstruction status and
failed proposal evidence remain intact. The archive/member/symbol variants and
unresolved exact-object checks remain in Function Lab and the scan artifact.
This recognizes a runtime dependency without injecting assembly into game source.

### Intentionally unresolved

The report lists every accepted function and every detected candidate with its
reason. Examples include `_malloc` (unresolved canonical `__newmode` destination
and insufficient independent FID callee evidence), tiny `__fpclear`-style bodies,
register-entry helpers, differing object bytes, and ambiguous/non-specific FID
matches. Another 1,223 functions had no resolved archive-name candidate or custom
FID hit; the private full report lists them explicitly. They remain unknown and
eligible. Matching archive names never automatically excludes a function.

92 archive members were rejected by the static-function reader as unsupported
or functionless metadata (including sectionless placeholders and machine-neutral
aliases). No alternate CRT version was substituted. Full details remain in the
private scan report; unsupported formats are not proof that functions are game code.

## Operator commands

`project.json` schema 3 pins `libraryOwnership` version 1, archives and the custom
FID report. Old backends reject schema 3 instead of ignoring reconstruction
exclusions. Existing compiler flags, components, bindings and source contracts
were not changed.

Offline commands take the normal project-owner lock. Stop/drain the service and
loop before running them; a running service must never be bypassed with direct DB
edits. `scripts/backend` resolves the immutable current backend.

```sh
scripts/backend library-scan
# Optional bounded probe: add --function 00449a70
scripts/backend library-apply \
  --scan library-scan-RETURNED_ID --command-id A_STABLE_UNIQUE_ID
```

Scan stages an immutable `.work/library-scans/<id>/report.json` and a compact
`libraryScans` record. It does not apply classifications. Apply verifies the
recorded artifact, scanner, catalog, index, target and current function extents,
then transactionally records metadata/events and the command receipt. Reusing a
successful command ID returns the saved outcome; changing its payload fails.
No command can promote a source proof through ownership metadata.

Archive/FID/target/catalog or imported-extent provenance drift makes ownership
unknown/eligible until rescanned; retained historical evidence is not deleted.
A partial scan changes only its detected function records. New project imports
preserve ownership evidence but make old epoch-bound claims stale.

## Backend and UI

- `ownershipRecord` retains applied identification; public fields are derived and
  fail open for reconstruction eligibility, never for ownership confidence.
- `libraryIdentification`, bounded `libraryCandidates` and evidence IDs are exposed
  in Function Lab. Full immutable reports remain private artifacts.
- Functions filters distinguish ownership and eligible/excluded; proof status is
  a separate column. Atlas keeps all entries and exposes ownership in tooltips.
- `progress.reconstruction` excludes only confirmed library/import ownership;
  `progress.ownership` explains categories. Legacy inventory counters retain their
  original meaning. Capability: `library-ownership-v1`.
- Loop selection, tick/resume, preparation and publication enforce eligibility.
  All-excluded explicit scopes are rejected. Historical/frozen project runners
  check current ownership before reconstructing; no checkpoint was rewritten.
- Explicit deterministic source verification and analysis remain available.

## Validation and deployment

Backend release build, selftests (including synthetic fpinit-shaped COFF), synthetic
integration and 12 FID driver tests pass. Nexus's five CTest suites pass. Integration
covers metadata-only application/deduplication, filtering, progress, excluded-only
scope rejection, stale-policy eligibility and source/proof/history preservation.

A complete isolated trial preceded application. Before/after metadata digests over
all existing function IDs, statuses, match records, attempt histories and source
revisions are identical: `4f1a9fb7b859d7506a3bad2d7f9a2bd05870b88a148d00873948f1e8fe9c7a4d`.
This was a metadata preservation check, **not a bulk source/byte proof audit**.

Live immutable backend: `.work/backend/ownership-bounds-660e2ebf47835c31`.
The scan was produced/applied by retained `.work/backend/ownership-5d5920e92b993765`;
the follow-up only bounds public ownership evidence and exclusion previews and
keeps Atlas's SQL projection free of full FID relationship graphs. Classification
records and source proofs were not reapplied or changed by that follow-up.
Deployment/rollback materials, pre-change DB/config/unit and receipts:
`.work/ownership-activation-20260915-200641/activation.json`.
Previous backend: `.work/backend/loop-evidence-dfec7d0c48bebaff`.
Rollback to it also requires deliberate restoration of the saved schema-2 config;
otherwise it correctly refuses the project. This would undo ownership enforcement,
not erase retained source proofs. Do not restore a DB backup after newer work.

Nexus extension reloaded successfully through its rendered-frame check without
restarting Nexus. The connected live window was captured; backend RPC confirms
__fpmath excluded and all 419 source proofs current. Campaign remains LimitReached
with no job; activation did not launch any models. Ghidra `/EditedGex`, the pinned
executable and all reconstructed source files were left unchanged.
