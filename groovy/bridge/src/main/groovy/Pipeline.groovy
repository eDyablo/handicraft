abstract class Pipeline {
  def impl

  void echo(String text) {
    impl.echo(text)
  }

  String read(String path) {
    impl.read(path)
  }

  void write(String path, String text) {
    impl.write(path, text)
  }

  abstract void run()
}