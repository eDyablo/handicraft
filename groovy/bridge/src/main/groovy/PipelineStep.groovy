abstract class PipelineStep extends Pipeline {
  abstract void do()
  
  abstract void undo()
}
