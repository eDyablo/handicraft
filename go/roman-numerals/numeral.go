package numeral

type digit struct {
  arabic  int
  roman   string
}

var digits []digit = []digit {
  { arabic: 1000, roman: "M" },
  { arabic: 900,  roman: "CM" },
  { arabic: 500,  roman: "D" },
  { arabic: 400,  roman: "CD" },
  { arabic: 100,  roman: "C" },
  { arabic: 90,   roman: "XC" },
  { arabic: 50,   roman: "L" },
  { arabic: 40,   roman: "XL" },
  { arabic: 10,   roman: "X" },
  { arabic: 9,    roman: "IX" },
  { arabic: 5,    roman: "V" },
  { arabic: 4,    roman: "IV" },
  { arabic: 1,    roman: "I" },
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
