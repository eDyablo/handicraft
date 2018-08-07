FROM gcc AS build
WORKDIR /usr/src/e4d/handicraft/cpp/hello
COPY . .
RUN mkdir --parents /usr/bin/e4d/handicraft/cpp/hello
RUN g++ main.cpp -o /usr/bin/e4d/handicraft/cpp/hello/hello -static -static-libgcc -static-libstdc++

FROM scratch
WORKDIR /usr/bin/e4d/handicraft/cpp/hello
COPY --from=build /usr/bin/e4d/handicraft/cpp/hello .
ENTRYPOINT [ "./hello" ]
