package composite

import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class TriangleTest {
  @Test void explode_returns_list_contains_three_lines() {
    final def triangle = new Triangle(points: [
      [1.0, 1.0],
      [3.0, 2.0],
      [2.0, 3.0],
    ])
    assertThat(triangle.explode(), contains(
      allOf(
        instanceOf(Line),
        hasProperty('start', equalTo([1.0, 1.0] as float[])),
        hasProperty('end', equalTo([3.0, 2.0] as float[]))
      ),
      allOf(
        instanceOf(Line),
        hasProperty('start', equalTo([1.0, 1.0] as float[])),
        hasProperty('end', equalTo([2.0, 3.0] as float[]))
      ),
      allOf(
        instanceOf(Line),
        hasProperty('start', equalTo([3.0, 2.0] as float[])),
        hasProperty('end', equalTo([2.0, 3.0] as float[]))
      ),
    ))
  }
}
