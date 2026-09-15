# DirectDraw import thunk — exact isolated byte match

2026-09-14. The user requested an exact candidate **in isolation**, keeping the
active project configuration unchanged. The retained DirectDraw candidate is now
represented by a compiler-specific opaque thunk that passes the unchanged
backend's strict verification in a separate project. It has **not** been promoted
to the live Gex project.

## Result

- Function: DirectDrawCreate thunk, `00409876`.
- Original and complete relocated candidate: **6 bytes**, `ff 25 cc 53 4a 00`.
- Instruction: indirect jump through IAT slot `004a53cc`.
- Compiler: pinned CL `10.00.5270`.
- Flags: unchanged `/O2 /G5 /Oy /GR-`.
- COFF target: `_GEX_Target`, actual function Type `0x20`.
- Relocation: DIR32 at offset 2, `__imp__DirectDrawCreate@12` → `004a53cc`.
- No inline assembly, raw-byte emission, padding trimming, masked relocations,
  guessed storage layouts or relaxed verifier rules.

Two separate official backend CLI verifications returned **ExactMatch**:

1. `attempt-58072792b8834a1cb869e8d29de48e05`
2. `attempt-3daac8449c6f4aaea0045d82ba32934b`

An independent COFF/PE audit regenerated every relocation, checked whole-section
ownership and function type, compared the entire six-byte body to independently
sliced pinned PE bytes, and checked retained source/object/component hashes and
compiler contracts for both attempts. Both passed. Backend verification also
freshly checked the Ghidra identity, instruction extent and unchanged memory.

## What changed from the failed candidates

The cdecl forwarding wrapper was 25 bytes; correcting it to a typed stdcall
wrapper produced 24 bytes. CL copies the three arguments and emits an indirect
call followed by stack-cleaning return. Merely binding the import cannot turn
that body into the original linker-style jump.

Control probes established that CL's baseline optimizer emits the six-byte tail
jump for an opaque entry with no C++ argument-forwarding expressions. The winning
source retains the **correct three-argument stdcall import declaration**, then
uses a C-style function-pointer cast for the private opaque entry. The compiler
emits only the indirect jump, leaving the incoming stack and registers untouched
for the real imported function. The cast form was compiled and checked, not
assumed: this old compiler rejects the analogous `reinterpret_cast` with C2152.
That failed attempt (`attempt-ec9a7a64d15d4214af5f372a876d9f40`) is retained too.

### Important type-level limitation

This is a **compiler-specific representation of an import thunk**, not a portable,
type-safe C++ implementation of DirectDrawCreate. Calling an API through an
incompatible function-pointer type is not a valid general C++ forwarding idiom.
The private `GEX_Target()` declaration is not the public API declaration and must
not be used as one. Its machine-code entry is intended only for the original
stdcall API calling contract, whose argument forwarding follows from the exact
whole-body jump.

The proof is explicitly machine-byte/relocation equality under the pinned build
contract, **not** source-level semantic equivalence, recovered original source,
a generally callable zero-argument API or whole-program build correctness.
Do not replace these checks with a claim that any cast-based wrapper is safe.

## Isolation and preservation

A new private project was created with its own project ID, source directory,
metadata import, owner lock and database. Ghidra metadata was read through the
backend's normal import command; no Ghidra analysis was edited or reimported into
Ghidra. Only that isolated config received the already-proven IAT binding. The
live database was neither copied nor edited, and no verifier result was manually
promoted.

The live project still has **409 exact proofs / 15,439 bytes**. All **898 active
source hashes**, live `project.json`, installed/pinned executable and the old
retained candidates are unchanged. Its last AI campaign remains LimitReached
with 12 attempts; no new AI campaign ran. Applying the candidate/binding to the
live project remains a separate operation requiring approval and re-verification
under the changed binding-map identity.

## Evidence and candidate

Corrected retained revision:
`.work/retained-candidate-fixes/00409876-opaque-thunk-v2/source.cpp`

Isolated project and evidence:
`.work/isolated-thunk-match-20260914-220237/`

- `project/project.json`, `project/src/functions/00409876.cpp`
- Fresh read-only metadata import and immutable attempts under `project/.work/`
- `verification-cast.json`, `verification-repeat.json`
- `audit.py`, `independent-audit.json`, `live-preservation-audit.json`
- `live-before.json` records the unchanged configuration/source hashes

Earlier probe matrices remain in `.work/tail-jump-probes-20260914-215453/`,
`.work/tail-jump-probes-20260914-215615/`, and
`.work/tail-jump-probes-20260914-215945/`. Diagnostic no-argument control imports
are labelled as controls, not substituted for the correctly named imported API.

See [iat-binding-review.md](iat-binding-review.md) for independently established
slot identities and the original candidate's additional ABI/body problems.
