FROM microsoft/dotnet:2.1-sdk AS build
WORKDIR /usr/src/e4d/handicraft/csharp/hello
COPY . .
RUN dotnet build --output /usr/bin/e4d/handicraft/csharp/hello

FROM microsoft/dotnet:2.1-runtime
COPY --from=build /usr/bin/e4d/handicraft/csharp/hello /usr/bin/e4d/handicraft/csharp/hello
ENTRYPOINT [ "dotnet", "/usr/bin/e4d/handicraft/csharp/hello/hello.dll" ]
