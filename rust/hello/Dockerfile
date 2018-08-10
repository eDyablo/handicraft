FROM rust AS build
WORKDIR /use/src/e4d/handicraft/rust/hello
COPY . .
RUN mkdir --parents /usr/bin/e4d/handicraft/rust/hello \
  && rustc -o /usr/bin/e4d/handicraft/rust/hello/hello main.rs

FROM rust:slim
LABEL e4d.handicraft.rust.hello.version="0.0.1"
WORKDIR /usr/bin/e4d/handicraft/rust/hello
COPY --from=build /usr/bin/e4d/handicraft/rust/hello .
ENTRYPOINT [ "./hello" ]
