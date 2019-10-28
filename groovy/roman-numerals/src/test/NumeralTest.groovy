package numeral

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class NumeralTest {
  @Test void failure() {
    assertThat(1, is(equalTo(0)))
  }
}
