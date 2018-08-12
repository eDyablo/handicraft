FROM gcc

RUN apt-get update \
  && apt-get install --yes --no-install-recommends cmake

ONBUILD WORKDIR /usr/src/app
ONBUILD COPY . .
ONBUILD RUN cmake . \
  && make
