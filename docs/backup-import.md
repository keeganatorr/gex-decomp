# Recovering a source archive

Source archive: private local archive (name and path omitted). The archive, installed GOG
executable and existing Ghidra analysis were kept unchanged. This is a source
recovery/verification pass, not a revival of the old injection/mod runtime.

## Final results

Compared **882 additional function addresses**, retaining **816 source candidates**:

| Result | Functions |
|---|---:|
| ExactMatch | **344** |
| NearMatch (90% or higher, still not exact) | 32 |
| Compiles, below 90% | 440 |
| Deferred after comparison failure or mismatching placeholder | 66 |

The exact imports add **13,163 verified bytes**. Including the protected original
work, the project now has **354 / 1,335 exact functions, 13,544 exact bytes**, plus
32 near matches. Of the 344 new exact bodies, 82 are at most eight bytes; the other
262 include substantive gameplay/support routines. The runner retained **1,005
attempt records**, including restored-best/configuration refresh comparisons.

Examples of larger exact imports: FUN_0040ca70 (241 bytes), SCRIPT_ClearController
(186), FUN_00410d10_CollisionInner (175), PlayerStopFalling (172),
FUN_00421780_pStateUnk_Fall (153), PlayerStartTailSlashImpl (127), CheckIdle (122),
SCRIPT_AdjustPlut (119) and BLOC_LoadBlocks (115).

The final production Nexus transport probe read all ten resource pages, 32 exact
function details and the complete Atlas inventory. Final source/artifact/config
checks passed, all 2,461 audited archive source hashes remained unchanged, and
there were no running or queued verification tasks. Failed historical tasks remain
visible; they were not erased to make the queue history look successful.

The machine-readable [provenance index](backup-import-index.json) records each
selected source's archive path/hash, current source hash, current attempt and
command IDs, exactness, positional score and byte extent. Nonmatching candidates
are **not** recovered exact code. An eight-byte-or-smaller body is counted honestly
but separately, so returning from a genuine empty callback does not look like
recovering a large gameplay routine. Byte totals remain sums of verified/imported
function spans, not a claimed unique executable-byte union.

## What was in the archive

- `src/functions`: **2,461 C++ files**, 2,303 with addresses in their names,
  representing **1,209 distinct addresses**. Many addresses have upper/lower-case
  variants with substantially different implementations.
- 140 main-tree files contain assembly/naked/raw-emission constructs. Some are
  duplicates, existing protected candidates or outside current function entries;
  the mutually exclusive audit categories consequently show a smaller assembly
  count after those earlier checks.
- `GEX_mod/functions`: **977 files, all assembly/raw-byte wrappers**. They remain
  useful reference material but are not imported as C++ recovery.
- `gexsdl` and `stormmod` contain other port artifacts, but no C++ function files
  in their `functions` directories.
- **1,745 JSON objdiff reports**, of which 605 report a 100% code-section score.
  These are historical clues, not current compiler/destination proofs. For example,
  the backup's uppercase SCRIPT_GetUInt counterpart is a naked assembly rewrite.
  Its old 100% result does not resolve the current C++ register-allocation mismatch.
- Most main sources refer to missing `../../include/game_types.h`. The header in
  the separate mod tree contains only fixed-width aliases and a cdecl macro; it
  is not a recovered complete game type system.

There was no standalone compare script in the backup. Comparisons ran through
this project's `scripts/verify`, using the existing pc-decomp compiler/COFF/original
byte pipeline, not old object files or the legacy objdiff score.

## Conservative adaptation

`scripts/scan-backup` performs a read-only inventory and stages candidates under
`.work/backup-import/candidates`. It:

1. Resolves a filename address against the current imported function inventory.
   The three patched Ghidra bodies and all 12 pre-existing project sources are
   protected. Interior labels and unknown addresses are not guessed into functions.
2. Excludes assembly/raw emission, other preprocessor dependencies, unsupported
   calling conventions, unresolved types/declarations, unaddressed externals,
   initialized globals and multiple-definition translation units.
3. Removes only the known missing include, materializes the fixed-width aliases
   actually used, expands PDA_CDECL to __cdecl, and exposes the one implementation
   as GEX_Target with C linkage. No shared-header dependency bypass is introduced.
4. Makes uninitialized, address-named data declarations explicit `extern` imports.
   This candidate does not own or initialize original game data. This also handles
   single-declaration `extern "C"` forms whose Clang AST omits storageClass.
5. Uses Clang only for syntax/declaration inspection; no object from that check is
   ever used for comparison. Final compilation is always the pinned CL 10.00.5270
   under its dedicated Wine prefix with `/O2 /G5 /Oy /GR-`.
6. Rejects obvious empty/constant placeholders for nontrivial original bodies.
   Small placeholder-shaped candidates are retained only if their complete bytes
   really match; a mismatching empty stub is not useful recovered source.

The resulting audit contains **1,014 staged variants at 882 additional function
addresses**. The full audit lists why every other file was deferred. These are
per-file categories: a rejected lowercase variant can have a tested uppercase
counterpart. They must not be added together as counts of missing functions.

Bindings are explicit original-address aliases from the source declarations;
unknown named imports are not assigned fabricated addresses. Every actual COFF
relocation is still independently resolved and compared to the pinned target.
The source compiler, seven compiler component hashes, target hash and flags were
not changed to obtain matches. No original bytes, padding or relocations were
masked, trimmed or emitted as source.

## Comparison and selection

`scripts/verify-backup` is a deterministic queue client, not an AI campaign:

- One runner lock, one project owner and one verification worker.
- Each source/config/import-epoch combination gets a stable intent ID. Every
  comparison passes through the durable backend command journal.
- Source-install intent and current installed hash are checkpointed. External
  source edits are refused, not overwritten.
- An uncertain response stops the runner. A resume queries that same ID rather
  than issuing a different intent. This path is tested with a synthetic peer.
- The original 12 source files are never replaced. For each additional address,
  the best successfully compared variant is selected; exact ends further trials.
  A best variant restored after a worse trial is reverified as the current source.
- Failed candidates and worse historical attempts remain in the archive and
  immutable attempt evidence. All-failed and mismatching-placeholder sources are
  removed from the active source directory, not misrepresented as implementations.
- A configuration change revalidates selected proofs. The initial 12 candidates
  were reverified after adding the binding catalog, preserving their original
  ten exact results and two nonmatching byte-reader results.

The first pass used a narrower declaration classifier; it was expanded to handle
explicit data imports. Its completed comparisons remain in the history. One
import client was stopped while its backend job finished; the pending receipt
was queried before configuration changes. Later deployment pauses were between
functions. Nexus and its coding agent were never restarted.

## Backend scaling fix — unchanged validity rules

The expanded catalog has **1,945 explicit binding names**. Previously the whole
map was repeated in every live proof, function history entry and queue result.
That would overwhelm bounded UI responses during this import.

Backend `544312b` keeps complete maps in immutable `attempt.json` evidence but
publishes a canonical SHA256 binding-map identity in live records. Older database
rows/receipts are compacted only in detached RPC responses; they are not rewritten.
Current-proof checks accept both shapes. **The hash still covers every binding**:
changing even an unused symbol still invalidates proof. This is not relaxed
matching or the deferred per-used-binding dependency feature.

Selftests cover legacy/compact identity, unused-binding drift, contradictory
map/hash refusal, missing identity, 2,000 bindings and nested old receipts.
Synthetic PE/COFF/socket/SQLite integration verifies both compact live results and
complete immutable artifacts. The immutable service build was deployed while the
queue was idle; frontend, Nexus host/agent and Ghidra stayed running.

## Remaining work and feedback

- High-scoring nonmatches deserve targeted source/code-generation work; scores
  alone do not justify promotion. The two original byte readers remain unchanged.
- Missing real struct definitions and calling-convention support prevent direct
  reuse of many other files. Do not invent layouts or silently turn stdcall into
  cdecl merely to make them compile.
- Some candidates reach current COFF limitations: local jump-table/label targets,
  compiler runtime helpers, embedded strings/data and non-contiguous extents.
  Their blocked evidence is retained; do not bind unresolved labels to convenient
  bytes or change analysis boundaries to force a match.
- The metadata compaction makes this corpus usable without weakening validity,
  but indexed compact database projections and artifact paging remain valuable.
- Legacy "100%" reports need provenance. An assembly wrapper and genuine matching
  C++ can have the same old score while representing very different progress.
- Full-game linking, correct data initialization, semantic type recovery and run
  testing remain separate work. This import does not claim a rebuilt executable.

## Reproduction

```sh
# Original inventory snapshot must exist at .work/ten-functions/live-rpc.json.
# Read-only archive inspection + isolated syntax checking:
./scripts/scan-backup

# After reviewing .work/backup-import/audit.json and configuring its explicit
# bindings with the service stopped, restart the service, then:
./scripts/verify-backup

# Current-source/artifact consistency checks + compact public provenance index:
./scripts/report-backup

# Entirely synthetic runner/scanner regression test:
python3 tests/backup_tools.py
```

The scanner's backup root can be overridden with `PC_DECOMP_BACKUP_ROOT`.
Do not rerun the scanner while a comparison batch uses its staged files. The
runner resumes `.work/backup-import/run.json`; completed unchanged work is not
compiled again. Create `.work/backup-import/pause` to stop between functions,
remove it to resume. Resolve any uncertain command before changing configuration.
`scripts/build-baseline` intentionally remains the original two-function smoke
test; it is not an all-source gate or a substitute for this batch report.

Local evidence stays ignored: `audit.json`, `audit-phase1.json`, `run.json`,
`responses/`, selected/worse candidates and `.work/attempts/`. Only adapted source
and compact provenance/documentation are committed; no game binaries, proprietary
compiler files, Ghidra exports or copied raw-byte wrappers are published.
