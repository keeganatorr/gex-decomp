# Gex matching decompilation

This is the new source-reconstruction project, not the existing SDL/pemod port.
Do not modify ../pc-decomp-agent-csharp, GexReverseProject, backups or the installed
GOG game. Do not use removed legacy C# commands or its claimed MSVC 2010 version.

Target SHA256: e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86.
Source EXE: /home/keegan/.wine/drive_c/GOG Games/Gex/GEX.exe.
The backend owns a read-only pinned copy under .work/. No binaries, database,
Ghidra exports or compiled artifacts may be committed or published.

## Authority

Nexus owns agents/sessions/MCP/UI. ../pc-decomp owns compiler jobs, SQLite and proof.
Use scripts/backend (offline read/import/verify) or scripts/verify (online queue).
Never manipulate decomp.db directly or claim a match by editing its status.
The service runs as pc-decomp-gex.service, one worker, no autonomous campaign.

## Compiler

Recovered CL 10.00.5270, VC4.0-era, with /O2 /G5 /Oy /GR- through a dedicated Wine
prefix. Tool binaries and flags are fingerprinted in project.json. Original GEX
linker version is 4.20. The old notes' 'MSVC 2010' label is wrong; per-function
exact matches do not prove the compiler/version/flags for the entire game.

## Ghidra warning

MCP project Gex, active program name GEX.exe, actual DomainFile /EditedGex.
Its original-import SHA matches, but FIVE current code bytes differ from the
original across WndProc, WinMain and GFX_OpenGraphics. Do not repair, overwrite,
reimport or rename that Ghidra analysis without explicit approval. The backend
blocks those bodies. Read docs/baseline.md before reasoning about a mismatch.

## Source loop

1. Choose an unpatched function; inspect Ghidra via Nexus MCP with program=GEX.exe
   and verify the DomainFile/hash. Existing names/types are evidence, not proof.
2. Write src/functions/<eight-digit-lowercase-address>.cpp. Emit the symbol
   GEX_Target with a justified calling convention. Keep this baseline translation
   unit self-contained: no headers/preprocessor directives, inline assembly or
   raw-byte emission. No PCH/forced includes. Dependency snapshots are future work.
3. Declare external globals/functions explicitly. Their COFF names must have
   justified original addresses in project.json's symbolBindings. Config changes
   require stopping/restarting the service; do not change another job's environment.
4. Run ./scripts/verify ADDRESS STABLE_COMMAND_ID. Reusing an ID queries its result;
   it NEVER resends. For another intentional source attempt, use a new ID only
   after resolving any earlier uncertain operation. No new ID to hide a timeout.
5. Inspect retained attempt, compiler output and resolved-byte comparison. Do not
   mask relocations, trim inconvenient bytes or use the first RET as a boundary.
6. Commit the candidate and evidence notes. An exact match means current compiled
   function bytes including destinations matched, not proven source types or a
   reconstructed whole executable. Preserve near misses and failed attempts.

## Reconstruction notes

- Read docs/ten-functions.md for the first ten-function expansion and retained
  attempt IDs. The two byte readers are Compiles, NOT ExactMatch; ECX/EDX differ.
  Positional byte scores are not semantic scores. tests/byte_readers.py is a
  host-only behavioural check and must never promote backend proof status.
- Ghidra's EVENT_ExtractUShort pseudocode suggests a wider memory load than the
  assembly actually performs. Read instruction access widths before copying types.
- Adding symbol bindings currently retires all old proofs, even for unrelated
  functions. Reverify affected current proofs; never restore status by hand.
- scripts/build-baseline and the Nexus Build button still cover only the original
  two functions. They are not an all-source verification gate.

- Backup recovery is indexed in docs/backup-import-index.json and explained in
  docs/backup-import.md. Sources retain their archive path/hash. Do not trust old
  objdiff 100% reports: many mod wrappers literally emit original bytes. Compiles
  and NearMatch sources are retained starting points, never proof of fidelity.
- scan-backup stages files; verify-backup uses the existing durable queue and
  refuses external source edits. Never rerun the scanner during a running import.
  To pause, create .work/backup-import/pause and wait for the current function.
  Delete that marker to resume. tests/backup_tools.py covers uncertainty recovery.
- Live binding metadata is now a hash, while immutable attempt.json keeps the full
  map. This does NOT narrow invalidation: changing any binding still retires proof.

- The bounded smallest-first pass is documented in docs/smallest-pass.md and its
  per-function index. A pass outcome is not a backend status: a reconstruction
  blocker can still have an older compiling source. scripts/smallest-pass resumes
  its frozen .work/smallest-pass checkpoint; it does not start a new campaign.
  Its source/config guards and stable verification IDs must not be bypassed to
  get past an uncertain result. The runner lock scopes this pass client, not every
  possible editor or other verification client.
- Imported sizes are enclosing spans, not guaranteed complete functions. Some tiny
  entries contain only prologues; 00409970 spans 218,888 bytes and its detail exceeds
  the transport budget. Do not trim bytes or repair Ghidra in place to fit a test.
  A body ending in a call may instead be a legitimate noreturn wrapper: recover
  that callee contract rather than automatically declaring its bounds corrupt.
- Fresh proposals may use an opaque GXObject declaration for four-byte pointer-slot
  accesses. That is not a recovered object layout. Missing member layouts,
  conflicting declarations and unrecovered register inputs stay diagnostics;
  syntax checks, higher positional scores and inherited type names are not proof.
- scripts/report-smallest-pass validates its historical frozen checkpoint and now
  intentionally refuses the changed configuration. scripts/audit-current is the
  current-phase read-only auditor: it independently parses retained COFF, resolves
  DIR32/REL32, slices the pinned PE and checks source/config/compiler identities.
  Its report stays in .work; tests/proof_audit.py uses synthetic binaries.
- Project schema 2 enables functionOverrides (flags, c/cpp language, targetSymbol).
  Flags replace the whole global list. Source files keep the .cpp suffix even for
  C; the trusted /Tc selector and proof language field are authoritative. Old
  proofs without language mean C++. An unrelated override does not retire proof,
  but a selected override change does; full binding-map invalidation is unchanged.
  Old backends must reject schema 2 rather than silently ignore overrides.
- docs/iterative-editedgex.md records the next nine matches and preserved failures.
  SCRIPT_KillPlayer forwards a second argument hidden by the callee's decompiled
  signature; inspect stack accesses, not only pseudocode. LST_InsertBefore models
  the predecessor left in EAX without claiming its historical API return type.
  SCRIPT_ShiftRight's unmasked expression is target-specific: C++ requires a count
  below 32, while the verified x86 instruction masks CL for every byte value.

The immutable backend currently runs from .work/backend/3545257 (scoped compiler contracts).
The .work/backend-current symlink is what scripts/backend resolves. Rebuild its repo
separately, test it, stage a new immutable copy and deliberately restart the user
service to deploy. Never overwrite an active DLL. Never restart Nexus to deploy it.
