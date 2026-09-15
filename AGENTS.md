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
The service runs as pc-decomp-gex.service with one verifier. Its optional bounded
proposal loop uses Nexus-owned agents and requires explicit models, limits and
Play. Activation alone never starts a campaign.

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

## Library ownership (schema 3)

Before reconstructing, check backend `ownership` and `reconstructionEligible`.
Confirmed CRT/library and pinned-PE import thunks stay visible but are excluded
from proposals. Never infer ownership from the legacy Library status or a name.
Unknown/candidate-library functions remain eligible. Ownership does not change
source-match status or erase proofs. `docs/library-ownership.md` and its JSON
report document 28 CRT functions + 3 import thunks, leaving 873 unfinished
reconstruction targets; all 419 source proofs remain current. __fpmath is excluded
by corroborated custom-toolchain FID, NOT an exact archive-byte claim.

`library-scan`/`library-apply` run through scripts/backend under the owner lock;
stop/drain the service first. No direct DB edits. Schema 3 pins the recovered
c1032 archives and custom FID report so old backends cannot ignore exclusions.
FID scratch tooling and provenance: `docs/crt-fid.md`. No Ghidra reference writes,
assembly injection, fabricated bindings, relocation masking or bulk recompilation.
The active immutable backend is `.work/backend/ownership-bounds-660e2ebf47835c31`;
activation/rollback: `.work/ownership-activation-20260915-200641/activation.json`.
Earlier deployment notes below are historical.

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
- Proof currency uses the recorded per-used binding subset; unrelated binding
  changes and ownership metadata do not retire source proofs. Old whole-map proofs
  retain legacy semantics until metadata migration. Never restore status by hand.
- Import bindings name IAT pointer storage, not the local jump thunk or code in
  a DLL. `docs/iat-binding-review.md` records three pinned-PE slot identities,
  SDK-corroborated stdcall import names and the activated 179-entry PE import map.
  DirectDraw cdecl candidate uses a different COFF name and is 25 bytes versus
  the original 6 even after diagnostic relocation resolution: removing an
  unresolved-symbol error is not evidence of a match. The corrected stdcall
  revision (`.work/retained-candidate-fixes/00409876-stdcall-v1/`) still emits a
  24-byte forwarding call under baseline CL flags, not the 6-byte jump; its
  decorated target/import names are verified, but it is not a current proof.
  An opaque-entry revision *does* emit the exact 6-byte jump under the unchanged
  baseline (`docs/isolated-import-thunk-match.md`), verified twice in a separate
  project and independently audited. It retains the canonical stdcall import
  declaration but uses a C-style function-pointer cast for the private entry;
  this is a compiler-specific byte-matching surrogate, not a portable type-safe
  API wrapper. CL 10 rejects the analogous reinterpret_cast with C2152. Never
  silently turn that machine-level proof into a source-level semantics claim.
  The live binding map now includes the complete pinned-PE import map. All 409
  prior proofs were reverified under its new binding hash; no proof was restored
  manually. Former NearMatch entries remain unmatched until separately reviewed.
- CoffCode resolves unique symbols in the target section relative to the target
  entry point and COFF absolute symbols locally. Other-section symbols still
  require explicit bindings, so object-local labels are not fabricated project
  bindings. `tools/import_bindings.py` validates the pinned PE hash and SDK
  import-library spelling, then emits a read-only provenance map.
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
- Live binding metadata uses a hash plus usedBindings; immutable attempt.json
  retains its original evidence. Only changed used destinations retire migrated
  proofs; exact history remains historical.

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
  The 2026-09-14 smallest follow-up confirmed that the first three unattempted
  non-thunk entries are only 11-byte NOP-terminated prefixes; preserve these
  boundary diagnostics and do not trim or retry them until complete extents and
  missing bindings are established (`docs/smallest-followup-trial.md`).
  Its report stays in .work; tests/proof_audit.py uses synthetic binaries.
- Project schema 2 enables functionOverrides (flags, c/cpp language, targetSymbol).
  Flags replace the whole global list. Source files keep the .cpp suffix even for
  C; the trusted /Tc selector and proof language field are authoritative. Old
  proofs without language mean C++. An unrelated override does not retire proof,
  but a selected override change does; migrated proofs use per-used bindings.
  Old backends must reject schema 2 rather than silently ignore overrides.
- docs/iterative-editedgex.md records the next nine matches and preserved failures.
  SCRIPT_KillPlayer forwards a second argument hidden by the callee's decompiled
  signature; inspect stack accesses, not only pseudocode. LST_InsertBefore models
  the predecessor left in EAX without claiming its historical API return type.
  SCRIPT_ShiftRight's unmasked expression is target-specific: C++ requires a count
  below 32, while the verified x86 instruction masks CL for every byte value.

The immutable backend currently runs from .work/backend/bindings-bba8b3e1a75c1d1f
(scoped compiler contracts, bounded loop, pinned reasoning and pass ceiling, plus
fail-closed local COFF resolution and the activated PE import map).
Release and rollback record: .work/reasoning-trial-20260914-204750/activation.json. The Nexus work
bridge is authorized; model order/limits and Play remain explicit user choices.
The .work/backend-current symlink is what scripts/backend resolves. The Luna
three-function trial is documented in docs/luna-three-trial.md: it ended at the
one-pass ceiling with zero gains; `_flsall` lacked a binding, VSIT retained an
18-byte NearMatch, and `__ismbblead` timed out with unknown usage. Do not repeat
those model calls without new evidence or a changed scope. Rebuild its repo
separately, test it, stage a new immutable copy and deliberately restart the user
service to deploy. Never overwrite an active DLL. Never restart Nexus to deploy it.
