class PosixBashPipelineImpl extends BashPipelineImpl {
  void echo(String text) {
    println "POSIX bash\$ ${ text }"
  }
}