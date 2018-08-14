FROM golang

ONBUILD WORKDIR /usr/app
ONBUILD COPY . .
ONBUILD ENV GOPATH=/usr/app
ONBUILD RUN \
  if [ -f packages ]; then cat packages | tr '\n' ' ' | xargs go get -d ; fi \
  && go test ./... \
  #&& CGO_ENABLED=0 GOOS=linux go build -a -ldflags '-extldflags "-static"' ./... \
  && go install ./...
