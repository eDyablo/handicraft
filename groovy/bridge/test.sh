#!/usr/bin/env bash

set -o errexit
set -o pipefail

test -d gradle/wrapper || gradle wrapper

. gradlew test "${@:-"--info"}"
