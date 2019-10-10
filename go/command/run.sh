#!/usr/bin/env bash

set -o errexit
set -o pipefail

run_test() {
  packages=("command")
  go "test" "${packages/#/./}" 
}

run_program() {
  go run ed.go
}

run_test && run_program
