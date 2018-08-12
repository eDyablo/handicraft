FROM addword/cpp-build-cmake AS build

FROM scratch
WORKDIR /usr/bin/app
COPY --from=build /usr/bin/app .
ENTRYPOINT [ "./app" ]