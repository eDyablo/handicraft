class PosixBashPipelineImpl extends PipelineImpl {
  void echo(String text) {
    println "posix bash\$ ${ text }"
  }

  String read(String path) {
    println "posix bash\$ reads ${ path }"
    path
  }

  void write(String path, String text) {
    println "posix bash\$ writes ${ path }"
  }
}
