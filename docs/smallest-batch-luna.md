# Approved smallest-first batch: transport failure, no source changes

## Approval and fixes

The operator approved two preflight fixes followed by one bounded batch using the
current Luna/max settings:

- First 100 unresolved eligible functions, smallest byte size/address first.
- `openai-codex/gpt-5.6-luna`, reasoning `max`, one proposal lane.
- 300 seconds/request, 3600 seconds/run, 200,000 reported tokens (possible one-request
  overshoot), one model attempt per reconstruction ladder, bounded batch repair and
  one changed-dependency revisit. No shared-contract acceptance or budget expansion.

Backend `smallest-bd58b165f8a55359` preserves smallest-first order in batch mode;
legacy review-first SCC ordering is unchanged. Ownership policy now remains valid
across supported schemas >=3 rather than only schema 3. This restores 31 confirmed
library/import exclusions and the pre-run inventory of **847 unresolved eligible**
functions. The selected 100 functions span **8–61 bytes**.

Release build, selftests and full synthetic integration passed, including new
schema-4/5 ownership-exclusion and initial-dispatch ordering regressions. Existing
445 proof/history records, all source hashes and project configuration were
preserved during immutable activation. The whole-cell tint extension is unchanged.

## Outcome

Run: `loop-2a359fd951223a7126881ceb`.
Command: `smallest-100-luna-max-bd58-start`.
First function: `00406fd0 FUN_00406fd0_timeSetEventInner`, 8 bytes.
Job: `work-092fe5a4fd5d4ca5ba3c6556aa4e2d9a`.

The only provider request failed after approximately **165 seconds** with
**`WebSocket error`**, before the configured 300-second deadline. Response text was
empty, no source proposal was produced, and no compiler attempt/publication followed.
Usage was **unknown**: reported zero tokens/cost is not evidence of zero consumption.
The token-budget guard ended the run `LimitReached`; no retry/Resume was attempted.
99 of the selected functions received no model request.

Results: **0 new exact matches, 0 partial improvements, 0 changed source files**.
All **445 prior exact proofs / 16,730 bytes**, their history, and project configuration
remain unchanged. No active lane or job; the provider worker and monitor exited.
The transcript exists and independently records an assistant error with
`stopReason:error` and `errorMessage:WebSocket error`.

A separate efficiency issue was identified: this 8-byte function's prompt contained
74,457 characters, including roughly 65 KB of project-wide symbol bindings (JSON
measurement includes whitespace). These should be narrowed to relevant bindings
without weakening backend relocation resolution. There is **no evidence establishing
that prompt size caused the transport failure**. Investigate transport and prompt
construction before seeking approval for another provider run; do not automatically
switch models, remove the token cap, retry or enlarge the budget.

## Retained evidence

Project-relative `.work/smallest-batch-bd58b165f8a55359/` contains the approved
policy and selection, preflight/before/after snapshots, durable Start command and
receipt, `monitor.jsonl`, `run.log`, function details, batch task state, and
**`summary.json`**. Immutable backend:
`/home/keegan/.local/state/pc-decomp/staged/smallest-bd58b165f8a55359/`.

Request/response: `.work/loop/work-092fe5a4fd5d4ca5ba3c6556aa4e2d9a/`.
Session: `f26cd8e5-ee3c-4298-9c7a-d7791511755d`.
Reported transcript:
`/home/keegan/.pi/agent/sessions/--home-keegan-.local-state-nexus-harness-proposal-workspace--/2026-09-16T14-43-20-555Z_01a0aaac-196b-75f8-8f6a-bd8cf0dc21b4.jsonl`.
