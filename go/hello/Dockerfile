FROM addword/go-build AS build

FROM scratch
LABEL e4d.handicraft.go.hello.version="0.0.1"
WORKDIR /usr/bin/app
COPY --from=build /usr/app/bin .
ENTRYPOINT [ "./hello" ]
