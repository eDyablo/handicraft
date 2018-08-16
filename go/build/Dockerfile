FROM golang

ONBUILD WORKDIR /usr/app
ONBUILD COPY . .
ONBUILD ENV GOPATH=/usr/app
ONBUILD RUN \
if [ -f packages ]; then cat packages | tr '\n' ' ' | xargs go get -d ; fi \
&& go test ./... \
&& CGO_ENABLED=0 GOOS=linux go install -a -tags netgo -ldflags '-extldflags "-static"' ./...
