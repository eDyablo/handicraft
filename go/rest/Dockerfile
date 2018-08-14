FROM addword/go-build AS build

FROM google/golang-runtime
LABEL e4d.handicraft.go.rest.version="0.0.1"
WORKDIR /usr/app
COPY --from=build /usr/app .
EXPOSE 8000
ENTRYPOINT [ "./bin/rest" ]
