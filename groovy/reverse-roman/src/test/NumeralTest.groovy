package numeral

import org.junit.*
import static org.junit.Assert.*
import static org.hamcrest.Matchers.*

class NumeralTest {
  @Test void roman_to_arabic() {
    final tests = [
      [      '', 0],
      [     'I', 1],
      [    'II', 2],
      [     'V', 5],
      [     'X', 10],
      [     'L', 50],
      [    'IV', 4],
      [    'IX', 9],
      [    'XL', 40],
      [     'C', 100],
      [     'D', 500],
      [     'M', 1000],
      [ 'MCMXC', 1990],
      ['MMVIII', 2008],
      [  'XCIX', 99],
      [ 'XLVII', 47],
    ]
    tests.each { roman, arabic ->
      assertThat("\n     For: ${ roman }",
        Numeral.toArabic(roman), is(equalTo(arabic)))
    }
  }
}
