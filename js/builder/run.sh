#!/usr/bin/env bash

set -o errexit
set -o pipefail

. test.sh
echo
node src/represent-markdown
echo
node src/compose-mail
