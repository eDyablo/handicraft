#!/usr/bin/env bash

set -o errexit
set -o pipefail

test_result=$(pytest) && python src/program.py || echo "${test_result}"
