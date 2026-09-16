# Parallel Luna → Terra → Sol trial — stopped, two exact gains

## Approved policy

The user approved implementation/testing followed by one paid trial:

- Up to **10 concurrent function proposal lanes**, with **one serial compiler /
  verifier / publication worker**.
- Each function: **2 Luna → 2 Terra → 2 Sol** attempts, all literal **max** thinking.
  Provider/model IDs are `openai-codex/gpt-5.6-{luna,terra,sol}`. All three catalog
  entries advertise max; native workers must still verify actual/supported effort
  before prompting. No fallback to another provider/model/effort.
- Same original ten-function selection, skipping functions already exact; no
  replacement targets. **Eight remained unresolved at Start.**
- **5,400 seconds overall**, one pass, 300 seconds per attempt; no automatic
  Resume, repeat pass, new budget or replay of an uncertain start. Token cap is
  disabled; no dollar/quota guarantee is claimed for subscription usage.

| Entry | Final trial disposition |
|---|---|
| 00411fd0 InitPlayerSideInside90Trans | Already exact; skip |
| 00418bb0 SCRIPT_LinkObject2 | Eligible, unresolved |
| 0042dcf0 Object_unk | Eligible, unresolved |
| 004010e0 DDRAW_Destroy | Exact, Luna/max |
| 0040bc50 PrintStringInner | Unresolved in this trial; subsequently exact via local source search |
| 00417f40 EVENT_ExtractUShort | Eligible, unresolved |
| 0041f840 VFX_Reset | Already exact; skip |
| 0042cc70 Object_unk | Eligible, unresolved |
| 00439110 | Exact, Sol/max |
| 00441130 VideoTiles | Eligible, unresolved |

The earlier iterative run `loop-07e254aa78dacd5cf0345aef` is **Stopped**, no job
in flight, five attempts, one exact gain. Together with VFX from the preceding
one-shot run, the pre-trial total was **421 exact functions / 15,798 bytes**.
Pre-activation implementation/testing did not compile Gex sources or start paid work.

## Staged release

- Release **`c0311f3a351aa137`**.
- Manifest and approval:
  `.work/decomp-loop-staging/c0311f3a351aa137/{manifest,approved-trial}.json`.
- Immutable backend: `.work/backend/parallel-738d0f450e51f142/PcDecomp.dll`.
- Release extension: `.work/decomp-loop-staging/c0311f3a351aa137/libnexus-decomp.so`.
- Runtime, exact host modules, tests and an explicit trial runner are retained
  beside the manifest. Source repositories remain uncommitted; the manifest pins
  file hashes, not merely base commits.
- **Activated after the user relaunched Nexus.** Frozen host
  `stable-59ce651b073d` and runtime hashes matched the manifest. The idle service
  and CLI link now use `parallel-738d0f450e51f142`; the release extension passed
  its rendered-frame check. `activation.json` and `activation-backup/` retain
  checks and stopped-state backups. Activation preserved all 421 current proofs /
  15,798 bytes, configuration, pinned executable, EditedGex and source files.

The host bridge is a stable Nexus module. **Finish the coding task, close every
Nexus window, then relaunch.** A frontend/plugin reload cannot load this change.
After relaunch, compare the actual frozen host/runtime hashes with the manifest;
then switch the idle backend and release extension deliberately. Backend-only
updates never require restarting Nexus; this release also changes its host.

Activation must verify `loop-parallel-v1`, `parallelSupported`,
`reasoningSupported`, all three actual catalog entries, unchanged target/config
identity, and idle prior work. Record `activation.json` with the release and
`verified:true` only after those checks. The approval runner defaults to a dry
notice and requires an explicit flag:

```sh
python3 .work/decomp-loop-staging/c0311f3a351aa137/run-approved-trial.py \
  --release .work/decomp-loop-staging/c0311f3a351aa137 --start-approved-trial
```

Do not run that before activation. It rechecks only the original bounded scope,
records the command before sending, reconciles its fixed ID, and never automatically
resubmits an uncertain start. Activation itself sends no campaign command.

**Rollback:** use the new backend to Stop/drain and terminalize any parallel run
before downgrading, including a recovered Paused run. Old backends cannot safely
Resume policy fields/lane cursors they do not understand. Preserve newer sources,
proofs and attempts; never restore an old database over them.

## Safety implementation

pc-decomp owns bounded durable lanes, independent function/tier counters and
feedback, shared budgets and serial verification. Pause drains all leased
attempts; Stop/auth errors halt new dispatch; host/service loss interrupts every
lease and requires manual Resume. Exact functions and confirmed library/import
ownership are rechecked before dispatch/publication. Source/config/compiler and
lease/budget checks still gate exact publication. Compiler feedback commits
separately so a refused publication cannot erase the next tier's diagnostics.

Nexus owns ten isolated, tool-free native workers at most per bridge. One offer
and one result per exchange preserve the 1 MiB frame ceiling. Active identities,
pending completions and recent per-lane result projections are bounded at ten.
Every deadline is checked while RPCs await replies; failed teardown blocks new
admissions, and closing during an awaited RPC cannot spawn a worker afterward.

## Verification evidence

All tests use synthetic assets/fake providers:

- pc-decomp Release build: zero warnings/errors; selftests pass.
- Full RPC/SQLite/PE/COFF/fake compiler/Ghidra integration:
  `/tmp/pc-decomp-test-rkiupsvz`, retained log in the release's `tests/` directory.
  Ten unique function leases; 2/2/2 max ladder; 55 attempts (one exact function
  stops after its first attempt, nine others exhaust six); per-function feedback;
  compiler overlap guard; source conflict; exact publication; all-lane auth/
  Pause/Stop drain; service restart/manual Resume; late/deduplicated results;
  capability loss; shared token budget; compiler draining past time limit without
  publication; legacy end-of-pass migration; unrelated proof preservation.
- Nexus selftest: ALL PASS, no live prompt. Harness suite: **42/42**, including a
  real host with **ten simultaneously active native workers**, ten fake Pi peers
  and unique session identities; frontend detach does not duplicate prompts.
- Release extension CTest: **5/5**. Isolated rendered acceptance:
  `/tmp/nd-OPXhaY`, two windows, saved parallelism=10, module reload/rollback,
  frontend replacement, service reconnect; screenshot inspected. This is not a
  mouse-driven expanded-lane transcript/button matrix.
- Live metadata check: prior run still Stopped; **421 / 15,798** unchanged.
  No whole-project compilation or byte-audit sweep was performed.

## Trial results

**Stopped:** `loop-0fbc8c03e1a344ff2a48fede`, zero active jobs, 40 attempts,
21 minutes 15.7 seconds recorded elapsed time. It was already stopped when the
user approved the subsequent local-search benchmark; no duplicate Stop or new
paid start was issued.

- **2 ExactPublished, +56 bytes:** `004010e0 DDRAW_Destroy` (Luna/max,
  `attempt-2b2cc3855a7d4f3eb1eb165eaaa364b9`) and `00439110` (Sol/max,
  `attempt-d85d8d2c7edc4fab97338f4c90a23062`). Total after this trial:
  **423 exact / 15,854 bytes**.
- 13 compiling mismatches; 5 duplicate candidates retained without recompiling.
- 11 deadline/lease failures; 2 WebSocket failures; 3 owner cancellations.
- 4 model-reported MissingEvidence responses, not provider/authentication errors.
  The `00439110` lane later succeeded on Sol; the earlier missing-table prose is
  not a permanent independently verified blocker.

Only 15 of 40 attempts reached compilation. Parallelism improved throughput but
did not make equivalent source compile identically or cure provider failures.
Session/lease counts are not provider-internal concurrency metrics.

Final scoped evidence is under `trial-evidence/` beside the immutable manifest:
`final.json`, `after.json`, `functions-final.json` and 40 `work-*.json` records.
Observer log: `/tmp/parallel-gex-trial-c0311f3a351aa137.log`. Do not resume/repeat or
request a new budget automatically. The subsequent [two-target local search](compiler-guided-search.md)
used no new proposal-provider calls and added one further exact function.
