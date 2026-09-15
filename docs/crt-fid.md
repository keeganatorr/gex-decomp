# Isolated c1032 CRT Function ID workflow

`tools/crt_fid.py` builds and queries a **custom-only** Ghidra FID database. It does
not access the backend, edited reference project, MCP, reconstructed sources or
providers. All Ghidra projects, preferences, temporary files, copied objects and
results live under a new `.work/fid/<run-id>/` directory. Existing runs are never
overwritten/resumed. Archive member names are retained as metadata, never used as
filesystem extraction paths; object filenames are content hashes.

Approved inputs are the two hash-pinned archives in `project.json`:
`c1032/lib/libc.lib` and `libcmt.lib`. This is recovered toolchain provenance,
not proof of the original game's compiler or single-/multithreaded CRT variant.
No other CRT version is silently substituted. The local `libcx32.lib` was rejected
by LLVM as malformed and `libcrt.lib` was too short to be an archive; neither is
part of this corpus.

## Reproduce

From the project root, with installed Ghidra and Java 21:

```sh
python3 tools/crt_fid.py \
  --archive /home/keegan/Downloads/NTSource/base/mvdm/tools/c1032/lib/libc.lib \
  --archive /home/keegan/Downloads/NTSource/base/mvdm/tools/c1032/lib/libcmt.lib \
  --all-members --max-members 1400 --timeout 2400 \
  --extents .work/fid/extents-validation.json \
  --run-id c1032-full-NEXT
```

`--extents` is optional: a list of `{entry,size,extentVerified}`; only verified
entries are defined with supplied boundaries in the scratch target. Duplicate or
overlapping verified entries fail. Unverified entries do not assert boundaries.
The backend independently rechecks Ghidra instruction addresses, LLVM byte extents
and current reference bytes before accepting ownership, whether or not the scratch
FID manifest claimed an extent was verified.

`--member fpinit.obj` instead of `--all-members` is useful for investigation, but
**partial-corpus reports cannot automatically exclude functions**. An all-member
run records sectionless placeholders and machine-neutral alias members without
pretending they are executable i386 functions. Only canonical, typed external
COFF function symbols enter the generated library. Untyped routines remain a
coverage limitation, not silently classified code.

The initial successful all-member run is `.work/fid/c1032-full-02/report.json`:
1,168 unique function-bearing objects imported; 2,191 FID records across both
archives; 63 target functions returned candidate matches. Failed scratch runs were
retained rather than overwritten. The driver batches imports into one headless
JVM; earlier per-object process startup was corrected during validation.

## Evidence and acceptance

The generator always emits `classification: candidate`, never ownership or source
proof. Its report includes:

- target, archive and original member hashes/offsets;
- canonical symbol names, library variants and object provenance;
- Ghidra/Java/Python/script identities and invocation;
- FID database hash and the exact active database list;
- full/specific hashes, code-unit counts, scores and competing names;
- parent/callee relations and explicit ambiguity information;
- normalized extent manifest and immutable JSON/log artifact hashes.

All installed/built-in FID databases are disabled in isolated preferences, checked
again before queries. `FidService` queries are read-only; modification counters
and database hashes are checked. FID analyzer renames/bookmarks are disabled.
The target is a separate copy of the pinned executable, never `/EditedGex`.

The backend consumes only an explicitly hash-pinned report. It checks artifact and
database integrity, archive membership against the actual archives and catalog
completeness. Automatic FID ownership requires unique full-hash naming, matching
specific hashes, a nontrivial independently complete target, and an actual direct
call to an independently complete nontrivial uniquely identified custom-FID
callee with a recorded library relation. An aggregate score, generic built-in
match or name alone is insufficient. Tiny/trivial bodies stay candidates.

`__fpmath` has a small FID hash (the hasher omits some instructions); this is not
confused with a one-instruction function. Its full 23-byte/six-instruction body
and independently matching 56-byte callee provide the additional evidence. This
is **corroborated-custom-fid**, not an exact relocation-resolved object claim.

Synthetic parser/isolation tests:

```sh
python3 tests/crt_fid.py
```

Twelve tests cover bounds, symbol handling, archive paths/duplicate names, invalid
extents, isolated headless invocation, timeouts and rejected inputs. Real archives
are demonstration material only; no CRT objects or Microsoft source are test
fixtures or committed artifacts.
