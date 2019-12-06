package numeral

type digit struct {
  arabic  int
  roman   string
}

var digits []digit = []digit {
  { 1000, "M" },
  {  900, "CM" },
  {  500, "D" },
  {  400, "CD" },
  {  100, "C" },
  {   90, "XC" },
  {   50, "L" },
  {   40, "XL" },
  {   10, "X" },
  {    9, "IX" },
  {    5, "V" },
  {    4, "IV" },
  {    1, "I" },
}

// ArabicToRoman converts arabic numeral to roman numeral
func ArabicToRoman(arabic int) (roman string) {
  for _, digit := range digits {
    for arabic >= digit.arabic {
      roman += digit.roman
      arabic -= digit.arabic
    }
  }
  return
}
