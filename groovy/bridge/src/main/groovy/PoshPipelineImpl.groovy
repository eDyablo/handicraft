class PoshPipelineImpl extends PipelineImpl {
  void echo(String text) {
    println "PowerShell: ${ text }"
  }

  String read(String path) {
    println "PowerShell: reads ${ path }"
    path
  }

  void write(String path, String text) {
  }
}
