#! /usr/bin/env bash

set -o errexit

script_dir="$(cd "$(dirname "${0}")"; pwd)"

mkdir -p "build"

iid_file="build/idd"

docker build --iidfile="${iid_file}" --file="Dockerfile" .
