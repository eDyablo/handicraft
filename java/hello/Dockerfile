FROM openjdk:8-jdk AS build
WORKDIR /usr/src/e4d/handicraft/hello
COPY . .
RUN mkdir --parents /usr/bin/e4d/handicraft/hello \
  && javac Main.java -d /usr/bin/e4d/handicraft/hello

FROM openjdk:8-jre-slim
WORKDIR /usr/bin/e4d/handicraft/hello
COPY --from=build /usr/bin/e4d/handicraft/hello .
ENTRYPOINT [ "java", "Main" ]
