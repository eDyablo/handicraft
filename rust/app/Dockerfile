FROM addword/rust-build-cargo AS build

FROM scratch
WORKDIR /usr/app
COPY --from=build /usr/app/target/x86_64-unknown-linux-musl/debug .
ENTRYPOINT [ "./app" ]
