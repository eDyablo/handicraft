class PoshPipelineImpl extends PipelineImpl {
  void echo(String text) {
    println "PowerShell: ${ text }"
  }

  String read(String path) {
    path
  }

  void write(String path, String text) {
  }
}