package src

func balanced(text string) bool {
  if text == "(" {
    return false
  }
  if text == ")" {
    return false
  }
  return true
}
