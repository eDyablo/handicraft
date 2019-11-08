package composite

import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class LineTest {
  @Test void has_zero_points_when_created_with_no_parameters() {
    final def line = new Line()
    float[] zero = [0.0, 0.0]
    assertThat(line, allOf(
      hasProperty('start', equalTo(zero)),
      hasProperty('end', equalTo(zero)),
    ))
  }

  @Test void explode_returns_list_contains_the_line() {
    final def line = new Line()
    assertThat(line.explode(), contains(sameInstance(line)))
  }
}
