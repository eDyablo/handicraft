package src

import "testing"

func Test_empty_text_is_balanced(test *testing.T) {
  if balanced("") == true { return }
  test.Error()
}

func Test_signle_opening_parenthesis_is_non_balanced(test *testing.T) {
  if balanced("(") == false { return }
  test.Error()
}
