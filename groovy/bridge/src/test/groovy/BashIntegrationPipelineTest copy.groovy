
import org.junit.*
import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.*

class BashIntegrationPipelineTest {
  @Test void run() {
    def pipeline = new IntegrationPipeline(impl: new BashPipeline())
    pipeline.run()
  }
}
