abstract class PipelineImpl {
  abstract void echo(String text)

  abstract String read(String path)

  abstract void write(String path, String text)
}