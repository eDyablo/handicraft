FROM golang AS build
WORKDIR /usr/src/e4d/handicraft/go/hello
COPY . .
RUN go build -o /usr/bin/e4d/handicraft/go/hello/hello

FROM scratch
WORKDIR /usr/bin/e4d/handicraft/go/hello
COPY --from=build /usr/bin/e4d/handicraft/go/hello .
ENTRYPOINT [ "/usr/bin/e4d/handicraft/go/hello/hello" ]
