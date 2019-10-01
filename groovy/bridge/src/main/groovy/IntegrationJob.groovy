class IntegrationJob extends PipelineJob {
  void run() {
    echo('integrate')
    final CheckoutStep step = new CheckoutStep(impl: impl)
    step.doStep()
  }
}
