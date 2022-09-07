FROM bitnami/git AS source

WORKDIR /sample/src

RUN git clone https://github.com/gflags/gflags.git googleflags
RUN git clone https://github.com/google/glog.git googlelog

FROM gcc AS build

RUN apt-get update \
    && apt-get install --yes --no-install-recommends cmake

WORKDIR /sample/src

COPY --from=source /sample/src .

COPY src .

RUN cmake . \
    && make

FROM scratch

COPY --from=build /sample/out .

CMD [ "./sample" ]
