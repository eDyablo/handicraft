package numeral

import ("testing")

type testData struct {
  arabic  int
  roman   string
}

func Test_arabic_to_roman(t *testing.T) {
  tests := []testData {
    {    1, "I" },
    {    2, "II" },
    {    3, "III" },
    {    4, "IV" },
    {    5, "V" },
    {    9, "IX" },
    {   10, "X" },
    {   40, "XL" },
    {   50, "L" },
    {   90, "XC" },
    {  100, "C" },
    {  400, "CD" },
    {  500, "D" },
    {  900, "CM" },
    { 1000, "M" },
    { 1990, "MCMXC" },
    { 2008, "MMVIII" },
    {   99, "XCIX" },
    {   47, "XLVII" },
  }
  for _, test := range tests {
    roman := ArabicToRoman(test.arabic)
    if roman != test.roman {
      t.Error(
        "for:", test.arabic,
        "expect:", test.roman,
        "but was:", roman)
    }
  }
}
