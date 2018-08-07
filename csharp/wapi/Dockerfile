FROM microsoft/dotnet:2.1-sdk AS build
WORKDIR /usr/src/e4d/handicraft/cs/wapi
COPY . .
RUN dotnet build --output /usr/bin/e4d/handicraft/csharp/wapi

FROM microsoft/dotnet:2.1-aspnetcore-runtime
COPY --from=build /usr/bin/e4d/handicraft/csharp/wapi /usr/bin/e4d/handicraft/csharp/wapi
EXPOSE 80/tcp
ENTRYPOINT [ "dotnet", "/usr/bin/e4d/handicraft/csharp/wapi/wapi.dll" ]
