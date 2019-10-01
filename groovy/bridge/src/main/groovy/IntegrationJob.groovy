class IntegrationJob extends PipelineJob {
  void run() {
    echo('integrate')
    checkout()
  }

  void checkout() {
    final CheckoutStep step = new CheckoutStep(impl: impl)
    step.doStep()
  }
}
