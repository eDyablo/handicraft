FROM addword/cpp-build-simple AS build

FROM scratch
LABEL e4d.handicraft.cpp.hello.version="0.0.1"
WORKDIR /usr/bin/app
COPY --from=build /usr/bin/app .
ENTRYPOINT [ "./app" ]
