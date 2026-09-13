#!/usr/bin/env bash
set -euo pipefail
systemctl --user start pc-decomp-gex.service
./scripts/backend status
