package numeral

class Numeral {
  static int toArabic(String roman) {
    final digits = [
      I: 1,
      V: 5,
      X: 10,
      L: 50,
      C: 100,
      D: 500,
      M: 1000,
    ]
    int arabic
    int delta
    roman.each { symbol ->
      final int newDelta = digits[symbol]
      arabic += newDelta
      if (newDelta > delta) {
        arabic -= 2 * delta
      }
      delta = newDelta
    }
    return arabic
  }
}
