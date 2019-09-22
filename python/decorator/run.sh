#!/usr/bin/env bash

set -o errexit
set -o pipefail

venv_dir=".venv"

run_test() {
  . "${venv_dir}/bin/activate"
  test_result=$(pytest) && python "src/program.py" || echo "${test_result}"
}

boot_strap() {
  virtualenv .venv
  . "${venv_dir}/bin/activate"
  pip install -r "requirements"
}

[ -d "${venv_dir}" ] && run_test || ( boot_strap && run_test )
