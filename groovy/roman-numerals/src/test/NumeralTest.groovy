package numeral

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class NumeralTest {
  @Test void converts_arabic_1_to_roman_I() {
    assertThat(Numeral.toRoman(1), is(equalTo('I')))
  }
}
