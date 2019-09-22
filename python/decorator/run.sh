#!/usr/bin/env bash

set -o errexit
set -o pipefail

venv_dir=".venv"

run_test() {
  . "${venv_dir}/bin/activate"
  result=$(pytest) || ( echo "${result}"; return 1 )
}

run_program() {
  . "${venv_dir}/bin/activate"
  result=$(run_test) && python "src/program.py" || echo "${result}"
}


boot_strap() {
  virtualenv .venv
  . "${venv_dir}/bin/activate"
  pip install -r "requirements"
}

[ -d "${venv_dir}" ] && run_program || ( boot_strap && run_program )
