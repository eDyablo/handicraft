package command

import (
  "testing"
)

func Test_delete_does_not_delete_line_when_from_and_number_are_not_specified(test *testing.T) {
  text := []string {"line"}
  cmd := Delete { Text: &text }

  cmd.Execute(nil)

  if len(text) == 1 && text[0] == "line" { return }
  test.Error(text)
}


func Test_delete_deletes_numer_of_first_lines_when_from_is_not_specified(test *testing.T) {
  text := []string {"one", "two", "three", "four"}
  cmd := Delete { Text: &text, Number: 2 }

  cmd.Execute(nil)

  if len(text) == 2 && text[0] == "three" && text[1] == "four" { return }
  test.Error(text)
}

func Test_delete_specified_number_of_lines_starting_from_line_specified_by_from(test *testing.T) {
  text := []string {"one", "two", "three", "four"}
  cmd := Delete { Text: &text, From: 1, Number: 2 }

  cmd.Execute(nil)

  if len(text) == 2 && text[0] == "one" && text[1] == "four" { return }
  test.Error(text)
}

func Test_delete_does_not_fail_when_tries_to_delete_one_line_from_empty_text(test *testing.T) {
  text := []string{}
  cmd := Delete { Text: &text, Number: 1 }

  cmd.Execute(nil)
}
