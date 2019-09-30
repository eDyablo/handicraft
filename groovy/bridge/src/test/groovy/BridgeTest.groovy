import org.junit.*
import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.*

class BridgeTest {
  @Test void successfull() {
    assertThat(1, equalTo(1))
  }
}
