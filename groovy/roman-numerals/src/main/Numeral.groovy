package numeral

class Numeral {
  static String toRoman(int arabic) {
    final def roman = new StringBuilder()
    while (arabic >= 10) {
      roman << 'X'
      arabic -= 10
    }
    while (arabic >= 1) {
      roman << 'I'
      arabic -= 1
    }
    return roman
  }
}
