package numeral

class Numeral {
  static def digits = [
    [100, 'C'],
    [ 10, 'X'],
    [  1, 'I'],
  ]

  static String toRoman(int arabic) {
    final def roman = new StringBuilder()
    digits.each { arabicDigit, romanDigit ->
      while (arabic >= arabicDigit) {
        roman << romanDigit
        arabic -= arabicDigit
      }
    }
    return roman
  }
}
