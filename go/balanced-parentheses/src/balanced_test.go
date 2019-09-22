package src

import "testing"

func Test_empty_text_is_balanced(test *testing.T) {
  if balanced("") { return }
  test.Error()
}