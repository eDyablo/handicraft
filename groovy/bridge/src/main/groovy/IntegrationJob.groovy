class IntegrationJob extends PipelineJob {
  void run() {
    echo('integrate')
    checkout()
    build()
  }

  void checkout() {
    final CheckoutStep step = new CheckoutStep(impl: impl)
    step.doStep()
  }

  void build() {
    final BuildStep step = new BuildStep(impl: impl)
    step.doStep()
  }
}
