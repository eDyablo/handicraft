FROM gcc AS build

RUN apt-get update \
&& apt-get install --yes --no-install-recommends cmake

WORKDIR /usr/src/calc

COPY . .

RUN cmake . \
&& make

FROM scratch

WORKDIR /usr/bin/calc

COPY --from=build /usr/bin/calc .
