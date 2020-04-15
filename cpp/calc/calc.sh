#! /usr/bin/env bash

set -o errexit

iid_file="build/idd"

if [ ! -f "${iid_file}" ]; then
  . build.sh
fi

image_id="$(cat "${iid_file}")"

if [ -z "$(docker image inspect --format='{{ .Id }}' "${image_id}")" ]; then
  . build.sh
  image_id="$(cat "${iid_file}")"
fi

docker run --rm --interactive --tty "${image_id}" ./calc "${@}"
