class PoshPipeline extends PipelineImpl {
  void echo(String text) {
    println "PowerShell: ${ text }"
  }

  String read(String path) {
    ''
  }

  void write(String path, String text) {
  }
}