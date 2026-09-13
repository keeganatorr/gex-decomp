#!/usr/bin/env bash
set -euo pipefail
systemctl --user start pc-decomp-gex.service
exec ./scripts/build-baseline
