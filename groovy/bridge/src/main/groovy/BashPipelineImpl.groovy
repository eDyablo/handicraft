class BashPipelineImpl extends PipelineImpl {
  void echo(String text) {
    println "bash\$ ${ text }"
  }

  String read(String path) {
    println "bash\$ reads ${ path }"
    path
  }

  void write(String path, String text) {
  }
}
