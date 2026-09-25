# DeepSeek V4.1 Flash: twenty closest live-current functions — 2026-09-25

One authorised campaign, `loop-e4375278e4ea12f336aa5382`: `openrouter/deepseek/deepseek-v4.1-flash`
at **max** reasoning, ten lanes, up to eight iterations per function, 600 s per turn,
one pass, 1,800 s active time and a 30-minute wall guard. Settings mirror the earlier
DeepSeek run that published eight proofs (`loop-61c36711e0a1dc110341fb05`). Scope: the
twenty highest live-current, source-present eligible functions (88.7–99.2%), frozen in
`.work/deepseek-twenty-20260925-b/scope.json`.

**Result: Stopped by the wall guard, no exact gain.** 51 jobs, 1,778 s active,
2,053,972 provider-reported tokens and $0.66 provider metadata, with `unknownUsage=true`
(expired turns carry no usage). Thirteen functions were reached; seven (`004260c0`,
`0041f860`, `004237c0`, `004121b0`, `00429c10`, `00429b40`, `0040cca0`) received no turn.
Diagnostics: 17 byte mismatches, 7 immediate-only, 2 operand-order, 5 investigations,
3 model-reported missing evidence, 2 format-invalid, 2 provider/session and **13 expired
600 s turns**. No working candidate regressed: every scoped function ended at its starting
current and best percentage. All **752 exact / 63,353 bytes** were preserved. Sixteen
scoped non-exact working sources differ from the last commit and nothing outside the scope
changed: nine were rewritten during this run, and ten (overlapping) were rewritten at
dispatch in the blocked first attempt, where the backend materialised each function's
highest verified retained candidate as its working source (`retained-best-working-source`,
by design; no score changed).

Two safety pauses, both "Persistent session lost" after a turn hit its 600 s deadline:
the host retires the conversation on an expired turn, the backend then leases the next
turn in that same conversation, and the refusal pauses the whole campaign. One Resume
inside the original window and budget was sent after the first pause
(`resume-1-intent.json`); the second pause came within the last two minutes and was left
for the wall Stop. This lease mismatch, not source quality, cost most of the window and
should be fixed before another paid run (restart the conversation, not the campaign, on
an expired turn).

Operational notes: the first attempt (`loop-029c214ab0eb48d2490fab8d`) blocked all twenty
functions in Prepare because Ghidra had no program loaded (0 tokens). Before either run the
backend was restarted from the stale `astra-loop-d286452` launch declaration onto the
activated `source-baseline-1f599aca2c3698b2`; `~/.local/state/nexus/extension-services.json`
still names the old build. Evidence: `.work/deepseek-twenty-20260925-b/` (scope, baseline DB
and source hashes, intents/receipts, timeline, `result.json`).

**Follow-up (same day).** Fixed and activated in `function-time-b3b4984fd40aa68a`: a reply
the host did not keep now starts a fresh conversation instead of pausing every lane; with a
per-function time budget there is no per-reply limit, and `fullFunctionTime` keeps every
function working until it is exact or its budget is spent (Start checks the run is long
enough for every function); a Ghidra outage pauses the run instead of blocking functions;
the two "not a JSON object" replies were cut off at the provider's 131,072 output-token cap
(reasoning used nearly all of it) and are now diagnosed as `PROPOSAL_OUTPUT_INCOMPLETE`.
The service launch declaration now names the activated build.

