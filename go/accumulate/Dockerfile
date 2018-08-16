FROM addword/go-build AS build

FROM scratch
LABEL e4d.handicraft.go.accumulate.version="0.0.1"
WORKDIR /usr/app
COPY --from=build /usr/app .
EXPOSE 80
ENTRYPOINT [ "./bin/accumulate" ]
