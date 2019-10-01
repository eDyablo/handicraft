class BuildStep extends PipelineStep {
  void doStep() {
    impl.echo('build')
  }
  
  void undoStep() {
    impl.echo('undo build')
  }
}
