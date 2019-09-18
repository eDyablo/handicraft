#!/usr/bin/env bash

set -o errexit
set -o pipefail

. test.sh
echo
node program.js
