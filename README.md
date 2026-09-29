# Gex / GOG — matching decompilation baseline

A fresh project at `/home/keegan/Repos/gex-decomp`, separate from all previous
Gex injection, SDL, pemod and recompilation work. The current source set is a
**per-function C/C++ reconstruction and verification baseline**. The active
goal is a [source-built replacement executable](docs/replacement-build.md)
whose gameplay matches the original as closely as practical.

## Working now

- Original EXE pinned by SHA256, without changing the GOG installation.
- Existing Ghidra analysis imported: **1,335 non-external functions** and **1,116
  existing type inventory entries** (including SDK/CRT types, not 1,116 newly
  recovered structures). Ghidra reports 1,515 functions including 180 externals.
- Recovered compiler runs: **Microsoft C/C++ 10.00.5270**, with the old project's
  `/O2 /G5 /Oy /GR-` flags. It is **not MSVC 2010**.
- The [previous documented checkpoint](docs/claude-hand-decomp.md) reported
  1,101 exact functions / 180,028 bytes; one further 122-byte proof brought
  the pre-rename record to **1,102 functions / 180,150 bytes**. The source tree
  currently has 1,206 isolated function files. Renaming changed their hashes,
  so those exact records are historical until a compatible verifier rechecks
  the renamed sources. They do not yet form a linked game. The completed
  [smallest-first pass](docs/smallest-pass.md), [backup recovery](docs/backup-import.md)
  and [ten-function results](docs/ten-functions.md) remain documented.
- A persistent backend serves real data to Nexus over a private named Unix socket.
- Explicit verification requests are journalled, queued and processed one at a time.
  The backend launches no model calls or autonomous workers.

## Nexus

In **Decomp**, select **Data source → real**, service identity `pc-decomp`.
Leave project ID blank (service default), or enter `gex-gog-e1fd63ec`.
It connects automatically; **Connect / reconnect** retries if needed.

**Atlas now renders a native hierarchical treemap**: module/function byte areas,
state colours, exact totals, hover details and click-to-Function-Lab. Wheel zooms,
right-drag pans, and the module selector drills down. It retains the enclosing-span
coverage warning rather than pretending those sizes are unique code coverage.

Use Functions, Function Lab, Atlas, Queue, Types, Knowledge, Ghidra, Toolchains
and History against the real backend. Empty campaigns/reviews/agents are honestly
empty, not synthetic filler. The implemented bulk action is **Verification**;
other agent-driven actions are explicitly unavailable in this baseline.

For a coding agent working on Gex, open a Nexus session **in this directory** so
it reads this project's AGENTS.md and writes here, not into the Nexus repository.
Nexus's own agents and actual session viewers remain the place for discussion.

## Build / verify

The first source-only link milestone builds and runs three reconstructed
functions as a Windows executable without reading `GEX.exe`:

```sh
./scripts/build-source-link-smoke
./scripts/build-resource-link-smoke
./tools/link_inventory.py
```

The current whole-source build assessment also needs no original executable:

```sh
./scripts/assess-replacement-link
```

It compiles all current sources and attempts a full link with source-built
Windows resources. The current expected result is exit 2 with 36 unresolved
externals in the real Windows startup link and no duplicate definitions.
The replacement executable does not link yet. Its scope and
the remaining work are in [replacement-build.md](docs/replacement-build.md).

```sh
# Start the already-installed user service; waits for its actual identity handshake.
systemctl --user start pc-decomp-gex.service

# Verify the original two-function baseline through the real queue.
./scripts/build-baseline

# One intentional verification operation; choose a stable ID for it.
./scripts/verify 00420d30 bubbles-source-v2-verification

# Repeating that same command queries its outcome. It does not run the compiler again.
./scripts/verify 00420d30 bubbles-source-v2-verification

# Read current inventory / progress through the backend CLI.
./scripts/backend status

# Read-only audit of every current exact artifact, including independent COFF relocation.
./scripts/audit-current
```

`build-baseline` keys operations by source, configuration and import epoch. An
unchanged successful baseline is queried rather than compiled repeatedly. If an
operation failed for a transient reason, inspect its result before choosing a new
explicit verification ID.

Nexus build scripts are in `.nexus/`: **Build** validates the original two translation
units (not every file in src/functions), **Run** starts the backend, **Build and run** starts it then verifies the
baseline. They do **not** launch or relink GEX.exe.

Exit codes: 0 = current exact source proof, 2 = no current exact proof, 1 = failure
or rejection, 3 = uncertain online outcome. Inspect the JSON and retained artifacts.

## Service and files

```sh
systemctl --user status pc-decomp-gex.service
journalctl --user -u pc-decomp-gex.service
systemctl --user stop pc-decomp-gex.service
```

Installed and running, but **not enabled automatically at login**. Run the start
command or the Nexus Run button after logging in. Closing Nexus does not destroy
backend-owned verification history. The socket is owner-only at
`/run/user/1000/pc-decomp/gex.sock`; only the Decomp extension is granted this
service identity in Nexus's `extension-services.json`.

| File | Owner / purpose |
|---|---|
| `project.json` | Target identity, compiler fingerprints, bindings, policy and knowledge |
| `src/functions/*.cpp` | Current source candidates |
| `scripts/`, `.nexus/` | Reproducible operator commands |
| `.work/original.exe` | Read-only original copy — ignored, never publish |
| `.work/decomp.db` | Backend SQLite — never edit from the UI/agent |
| `.work/attempts/` | Immutable source/object/log/byte-comparison evidence |
| `.work/requests/` | Online command checkpoints and receipts |
| `imports/` | Timestamped Ghidra inventory snapshots — ignored |
| `.work/backend/3545257/` | Immutable tested backend; scoped compiler contracts and compact proofs |

The backend's source is `/home/keegan/Repos/pc-decomp`. To import again, stop the
service, run `./scripts/backend import`, then restart. Existing attempts survive;
current proof is retired until reverified against the new analysis epoch. To fetch
uncached detail offline, stop the service and use `./scripts/backend detail
--function ADDRESS`. Nexus fetches details online without requiring a stop.

**Configuration changes require a service restart.** Source edits do not; they
retire current proof automatically. Header dependency capture is not implemented,
so candidate translation units must currently be self-contained. Project schema 2
adds per-function `functionOverrides` for allowlisted flags, C/C++ language and COFF
symbol. C sources retain the `.cpp` filename but compile with `/Tc`; effective
contracts are recorded in proofs. See the [checkpoint](docs/iterative-editedgex.md).

## Preserve the existing Ghidra work

The active program is `/EditedGex`, originally imported from the same binary,
but five bytes in its current `.text` are edited. Three functions are blocked:
`WndProc`, `WinMain`, and `GFX_OpenGraphics`. We did not overwrite those edits.
Only an explicit plan for original-byte analysis should change that situation.

See [baseline evidence and compiler findings](docs/baseline.md) and [TODO](TODO.md).
Nothing here proves the original compiler globally or that the whole game has
been reconstructed. Neither repository publishes the game or proprietary tools.
