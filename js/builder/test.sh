#!/usr/bin/env bash

set -o errexit
set -o pipefail

node node_modules/jasmine/bin/jasmine JASMINE_CONFIG_PATH=./jasmine.json
