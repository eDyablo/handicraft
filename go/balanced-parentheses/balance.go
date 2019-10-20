package balance

// IsOpening determines if the symbol is opening bracket
func IsOpening(symbol rune) bool {
  return symbol == '(' || symbol == '['
}

// IsClosing determines if the symbol is closing bracket
func IsClosing(symbol rune) bool {
  return symbol == ')' || symbol == ']'
}

// IsPair determines if the closing and opening brackets
// are complementar to each other
func IsPair(closing rune, opening rune) bool {
  if closing == ']' && opening == '[' {
    return true
  }
  if closing == ')' && opening == '(' {
    return true
  }
  return false
}

// IsBalanced determines if the text has balanced
// parantheses, brackets and braces
func IsBalanced(text string) bool {
  counter := 0
  openings := make([]rune, len(text))
  for _, c := range text {
    if IsOpening(c) {
      openings[counter] = c
      counter++
    }
    if IsClosing(c) {
      counter--
      if counter < 0 {
        return false
      }
      if IsPair(c, openings[counter]) == false {
        return false
      }
    }
  }
  return counter == 0
}
