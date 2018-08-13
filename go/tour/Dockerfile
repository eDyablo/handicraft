FROM addword/go-build AS build

FROM scratch
LABEL e4d.handicraft.go.tour.version="0.0.1"
WORKDIR /usr/app
COPY --from=build /usr/app .
ENTRYPOINT [ "./bin/tour" ]
