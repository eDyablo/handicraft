package numeral

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class NumeralTest {
  @Test void converts_arabic_numeral_to_roman_numeral() {
    final def tests = [
      [1, 'I'],
      [2, 'II'],
      [3, 'III'],
    ]
    tests.each { arabic, roman ->
      assertThat("\n     For: ${ arabic }",
        Numeral.toRoman(arabic), is(equalTo(roman)))
    }
  }
}
