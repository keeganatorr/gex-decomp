# Import-slot binding review and activation

2026-09-14. The initial review staged only the three previously missing import
bindings. The later implementation expanded that evidence into a read-only PE
import inventory, added section-local/absolute COFF relocation resolution, and
applied the complete SDK-correlated import map through the normal project
configuration path. No executable, Ghidra analysis, or source candidate was
repaired or reimported.

The activation was recorded under
`.work/binding-activation-20260914-223323/`. It stopped the idle service, backed
up the prior configuration/database, switched to the immutable backend build
`backend/bindings-bba8b3e1a75c1d1f`, applied 179 named PE imports, and reverified
all 409 prior ExactMatch proofs in 13 durable batches. The current result is
409 ExactMatch functions / 15,439 bytes, with the 34 former NearMatch entries
returned to unmatched until explicitly reverified. The three newly resolved
slots are the identities below; no new exact project function was promoted.

## Proven slot identities

The pinned PE's import directory, lookup tables and slot indices establish these
addresses. A separate raw PE reader uses the section RVA at +12, raw size at +16
and raw file offset at +20. LLVM's import report corroborates the DLL/symbol
identities. Each original six-byte thunk is an indirect jump through the stated
slot. Image base: `00400000`.

| Import | DLL | Thunk VA | IAT slot VA | Canonical x86 COFF import symbol |
|---|---|---|---|---|
| DirectSoundCreate | DSOUND.dll | `00409870` | `004a53d4` | `__imp__DirectSoundCreate@12` |
| DirectDrawCreate | DDRAW.dll | `00409876` | `004a53cc` | `__imp__DirectDrawCreate@12` |
| RtlUnwind | KERNEL32.dll | `0044f5ea` | `004a54e4` | `__imp__RtlUnwind@16` |

These are **addresses of pointer slots in the image**, not addresses of DLL code
or of the local jump thunks. Binding an `__imp__` symbol to the thunk itself would
be wrong.

The spellings above occur in the corresponding local SDK i386 import libraries.
SDK declarations corroborate the WINAPI/NTAPI stdcall convention and three,
three and four pointer-sized arguments respectively. Library/header hashes and
paths are retained as provenance. These SDK files are supporting ABI evidence,
not a claim that they are the original game's build inputs.

The original three-entry proposal remains preserved at:

`.work/iat-binding-review-20260914-211129/proposed-bindings.json`

The complete generated inventory and provenance used for activation is preserved
at `.work/binding-activation-20260914-223323/import-bindings.json`; the live
entries are now in `project.json`. The broad invalidation rule was deliberately
honoured: every prior exact proof was recompiled and verified under the new
binding-map identity, rather than having status restored by hand.

The implementation also resolves a relocation against a unique symbol defined
in the target COFF section relative to `_GEX_Target`, and resolves COFF absolute
symbols directly. Symbols in other sections remain external and require
bindings; duplicate names, unsupported relocation types, incomplete targets,
and unresolved destinations still fail closed. `tools/import_bindings.py` is
read-only and validates the pinned executable hash before emitting its staged
JSON map.

## Retained candidate: binding repair is not enough

Only DirectDrawCreate has a retained compiler candidate from the preceding trial:
`attempt-9d2b909376384b25a682d939e3e48d12`.

Its source declares both the import and forwarding function as **cdecl**. The
actual undefined COFF symbol is consequently `__imp__DirectDrawCreate`, without
`@12`. This differs from the canonical stdcall import name above.

A read-only diagnostic assigned that exact existing undefined symbol to the
independently established `004a53cc` slot and resolved its DIR32 relocation.
That alias is **not** in the proposed canonical mapping and was never activated.
The result still fails:

- Original function: **6 bytes**, an indirect jump.
- Retained compiled function: **25 bytes**, argument loads/pushes, an indirect
  call, stack adjustment and return.
- Entire resolved bodies differ; nothing was masked or trimmed.

Thus the previous unresolved-relocation error hid an additional body mismatch.
Resolving a pointer address does not correct a calling-convention declaration or
make this compiler emit a tail jump. There are no retained compiler candidates
for the other two imports to evaluate in this review. No ExactMatch is claimed.

Any future stdcall candidate would also need its decorated target symbol reflected
in the scoped compiler contract; the current `_GEX_Target` default must not be
silently reused for a differently decorated function.

These thunks may be better handled as linker/import-library output rather than
ordinary reconstructed C++ bodies. Excluding them from a subsequent ordinary-code
trial remains an option, but no further trial is authorized by this report.

## Follow-up — corrected retained candidate, not activated

The user subsequently requested **just the retained candidate fix**, not a global
binding/configuration change. Only DirectDrawCreate had retained source to fix.
Its original immutable attempt is untouched; the corrected revision is:

`.work/retained-candidate-fixes/00409876-stdcall-v1/source.cpp`

Both import and wrapper now use `__stdcall`, with opaque GUID/IDirectDraw/IUnknown
pointer types and the Win32 HRESULT-compatible return type. An isolated compile
with the pinned CL 10.00.5270, unchanged `/O2 /G5 /Oy /GR-` and normal blank
include/library/CL environment confirms the actual emitted names:

- Target: `_GEX_Target@12`
- Import relocation: `__imp__DirectDrawCreate@12`

The ABI defect is corrected. The resulting body is **24 bytes**, not the original
6: CL emits argument loads/pushes, an indirect call and `ret 12`, not the desired
indirect jump. Diagnostic resolution against the staged slot still compares
unequal. It is **not ExactMatch**, not an active project source and not a new
backend proof. No flags, bindings or active target-symbol override were changed.

The revision directory retains the old source, exact compiler invocation,
component/source/object hashes, compiler output, disassembly, relocation inspection
and preservation audit. All 409 proofs and 898 active source hashes remain
unchanged. No new AI trial ran.

## Later follow-up — isolated exact byte match

A subsequent compiler-specific **opaque thunk** revision now passes two normal
backend ExactMatch verifications in a separate project, plus an independent
COFF/PE audit: complete six-byte equality with the canonical stdcall import
relocation resolved. The active project is still unchanged. This form uses an
incompatible function-pointer cast and is not a portable type-safe API wrapper;
see [isolated-import-thunk-match.md](isolated-import-thunk-match.md) for the exact
scope, evidence and type-level limitation. The earlier 24-byte typed wrapper and
all failures remain retained.

## Preservation and reproducibility

Evidence directory: `.work/iat-binding-review-20260914-211129/`.

- `pinned-pe-imports.json`, `probe-import-bindings.py`, `llvm-pe-imports.txt`
- `sdk-coff-symbols.json`, `sdk-header-provenance.json`
- `proposed-bindings.json`
- `retained-candidate/`, `retained-comparison.json`, `retained-disassembly.txt`
- `preservation.json`, `preservation-audit.json`

Independent audit: **409 exact proofs / 15,439 bytes**, unchanged. All **898 source
hashes** and the byte hash of `project.json` are unchanged. Both installed and
pinned executables retain SHA256
`e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86`.
The previous trial remains LimitReached with 12 attempts and no active job.
