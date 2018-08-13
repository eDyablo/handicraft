FROM golang

ONBUILD WORKDIR /usr/app
ONBUILD COPY . .
ONBUILD ENV GOPATH=/usr/app
ONBUILD RUN go test ./...\
    && go install ./...
