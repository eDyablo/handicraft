#! /usr/bin/env bash

set -o errexit

iid_file="build/idd"

mkdir -p "build"

docker build --iidfile="${iid_file}" .
