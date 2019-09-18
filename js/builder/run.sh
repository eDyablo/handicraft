#!/usr/bin/env bash

set -o errexit
set -o pipefail

. test.sh
echo
node program
echo
node compose-mail
