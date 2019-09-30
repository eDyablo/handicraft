class BashPipeline extends PipelineImpl {
  void echo(String text) {
    println "bash\$ ${ text }"
  }

  String read(String path) {
    ''
  }

  void write(String path, String text) {
  }
}