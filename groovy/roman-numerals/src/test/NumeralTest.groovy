package numeral

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class NumeralTest {
  @Test void converts_arabic_numeral_to_roman_numeral() {
    final def tests = [
      [   1, "I"],
      [   2, "II"],
      [   3, "III"],
      [   4, "IV"],
      [   5, "V"],
      [   9, "IX"],
      [  10, "X"],
      [  40, "XL"],
      [  50, "L"],
      [  90, "XC"],
      [ 100, "C"],
      [ 400, "CD"],
      [ 500, "D"],
      [ 900, "CM"],
      [1000, "M"],
      [1990, "MCMXC"],
      [2008, "MMVIII"],
      [  99, "XCIX"],
      [  47, "XLVII"],
    ]
    tests.each { arabic, roman ->
      assertThat("\n     For: ${ arabic }",
        Numeral.toRoman(arabic), is(equalTo(roman)))
    }
  }
}
