FROM golang AS build
WORKDIR /usr/src/e4d/handicraft/go/hello
COPY . .
RUN go build -o /usr/bin/e4d/handicraft/go/hello/hello

FROM scratch
LABEL e4d.handicraft.go.hello.version="0.0.1"
WORKDIR /usr/bin/e4d/handicraft/go/hello
COPY --from=build /usr/bin/e4d/handicraft/go/hello .
ENTRYPOINT [ "/usr/bin/e4d/handicraft/go/hello/hello" ]
