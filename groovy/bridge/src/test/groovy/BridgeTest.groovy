import org.junit.*
import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.*

class BridgeTest {
  @Test void run_bash_integration_pipeline() {
    final Pipeline pipeline = new IntegrationPipeline(impl: new BashPipelineImpl())
    pipeline.run()
  }

  @Test void run_posh_integration_pipeline() {
    final Pipeline pipeline = new IntegrationPipeline(impl: new PoshPipelineImpl())
    pipeline.run()
  }
}
