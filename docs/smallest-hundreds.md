# Smallest-first hundreds pass

The user requested hundreds of functions, starting with the smallest. This pass
used only functions that were still reconstruction-eligible, unresolved and had
zero retained attempts at selection time. Confirmed libraries/import thunks were
excluded. Searches were local-only: no proposal providers, no campaign Resume,
unchanged CL 10.00.5270 C++ `/O2 /G5 /Oy /GR-`, max 24 candidates and 60 seconds
per function, one serial verifier.

## Coverage

The refreshed inventory contained **302** never-attempted eligible functions,
ordered by size. Of those:

- **254** received bounded searches in 11 checkpointed batches (25 each, final 4);
- **48** were fail-closed before compilation: 34 declaration/decompilation
  blockers and 14 extent/ABI proof blockers;
- one prepared 7,306-byte target (`00441150`) was recorded as skipped by the
  backend's 4 KiB local-search bound, with no compiler call.

The pass performed **5,798 probe compilations** and retained 501.323 seconds of
summed search timers. Search artifacts, manifests, details and batch receipts are
under `.work/smallest-hundreds/`. Existing sources were not overwritten by search.

## Exact results

Four new exact functions were published through the normal durable verification
queue:

| Entry | Size | Current proof |
|---|---:|---|
| `00449e10` `_rand` | 42 | `attempt-551e8465172840839b5148c6f6d19d1f` |
| `004397c0` `FUN_004397c0_HuntDiveInner` | 43 | `attempt-8ba7a880178249ce8a4f644ef4f1224e` |
| `004187f0` `SCRIPT_DisplayBehindParent` | 49 | `attempt-c8d46abab5894dfdab609a32efe9d9bf` |
| `0041fbd0` `FUN_0041FBD0` | 75 | `attempt-7180126eadd34b18adebf5b616c5ecb3` |

The earlier same-session smallest targets `0044e7e0`, `0044ab50` and
`00405350` were also published after focused assembly-derived searches. Current
project state after follow-up dependency work is **445 exact / 16,730 bytes**, with
878 unmatched records (847 in the reconstruction projection).

The remaining 250 searched targets produced 239 exhausted/no-output or 10
full-verified non-exact results. These are historical diagnostics, not current
source/proof publication. Family duplicate output is scheduling evidence only;
uncompiled candidates are not disproved.

## Reverse-engineering observations

The first two tiny CRT wrappers (`_flsall` and `__ismbblead`) required explicit
callee declarations whose addresses were confirmed by the pinned function index.
The successful game targets similarly came from direct Ghidra/assembly call and
register/field observations. Their exact bytes do not prove original source types,
CRT provenance, or compiler identity beyond the configured matching contract.
The follow-up dependency pass published two more exact functions. `0040fce0`
`OBI_CheckRemoveObject` now has proof `attempt-0e96c3cf3d304ae8afd8a61a050576ca`;
its 23 callers and observed object offsets `0x6c`, `0x78`, `0x7c`, `0xd0`, camera
bounds and the `00419840` removal call are recorded under
`.work/full-source-coverage/obi-ordered/`. `00419840` `GOB_RemoveMapObject` now
has proof `attempt-e7382597628d41eca963b6b1d2a2cff7`; its old near miss was
replaced only through normal durable verification. A new raw-offset hypothesis for
`0041cb80` was tested and retained as a non-exact near miss, not published. The
next dependency cluster is the 34-caller `00444590` display routine: recover its
sprite/draw-node/image contracts before attempting compiler variants. `0042d2c0`
follows after the shared angle-edge and tile callback contracts are established.
`0041be80` remains unresolved because `_obs_0__gdat_points` lacks an authorized
symbol resolution; no binding was fabricated. `00441150` remains a large graphics
function requiring a separate contract/layout effort.

## Safety and state

The service is active, the campaign remains Stopped and queued/running work is
zero. The pinned executable SHA and project configuration were unchanged. Earlier
exact proof metadata remains historical/current through the normal backend paths;
no database status was edited directly. New work should now shift from generic
smallest-first variants to genuinely new ABI, CRT provenance, graphics layout and
call-graph hypotheses rather than blindly repeating saturated families.
