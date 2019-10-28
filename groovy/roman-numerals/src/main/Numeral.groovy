package numeral

class Numeral {
  static String toRoman(int arabic) {
    final def roman = new StringBuilder()
    while (arabic >= 1) {
      roman << 'I'
      arabic -= 1
    }
    return roman
  }
}
