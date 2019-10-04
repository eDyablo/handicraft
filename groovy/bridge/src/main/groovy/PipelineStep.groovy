abstract class PipelineStep extends Pipeline {
  abstract void doStep()
  
  abstract void undoStep()
}
