abstract class CheckoutStep extends PipelineStep {
  void doStep() {
    impl.echo('checkout')
  }
  
  void undoStep() {
    impl.echo('undo checkout')
  }
}
