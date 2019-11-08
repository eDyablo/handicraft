package composite

import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class CompositeTest {
  @Test void explode_returns_list_of_added_shapes() {
    final def line = new Line()
    final def triangle = new Triangle()
    final def compex = new Complex()
    compex.add(line)
    compex.add(triangle)
    assertThat(compex.explode(), contains(line, triangle))
  }
}
