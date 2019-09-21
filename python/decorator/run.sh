#!/usr/bin/env bash

set -o errexit
set -o pipefail

pytest

python src/program.py
