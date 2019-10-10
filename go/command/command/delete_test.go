package command

import (
  "testing"
)

func Test_delete_does_not_delete_line_when_from_and_number_are_not_specified(test *testing.T) {
  // Arrange
  text := []string {"line"}
  cmd := Delete { Text: &text }
  // Act
  cmd.Execute(&TestContext {})
  // Assert
  if len(text) == 1 && text[0] == "line" { return }
  test.Error(text)
}


func Test_delete_deletes_numer_of_first_lines_when_from_is_not_specified(test *testing.T) {
  // Arrange
  text := []string {"one", "two", "three", "four"}
  cmd := Delete { Text: &text, Number: 2 }
  // Act
  cmd.Execute(&TestContext {})
  // Assert
  if len(text) == 2 && text[0] == "three" && text[1] == "four" { return }
  test.Error(text)
}

func Test_delete_specified_number_of_lines_starting_from_line_specified_by_from(test *testing.T) {
  // Arrange
  text := []string {"one", "two", "three", "four"}
  cmd := Delete { Text: &text, From: 1, Number: 2 }
  // Act
  cmd.Execute(&TestContext {})
  // Assert
  if len(text) == 2 && text[0] == "one" && text[1] == "four" { return }
  test.Error(text)
}

func Test_delete_does_not_fail_when_tries_to_delete_one_line_from_empty_text(test *testing.T) {
  // Arrange
  text := []string{}
  cmd := Delete { Text: &text, Number: 1 }
  // Act
  cmd.Execute(&TestContext {})
}

func Test_delete_enqueue_undo_command_that_restores_deleted_lines(test *testing.T) {
  // Arrange
  text := []string { "first", "second" }
  cmd := Delete { Text: &text, From: 1, Number: 1 }
  cntx := TestContext {}
  // Act
  cmd.Execute(&cntx)
  cntx.Undo()
  // Assert
  if len(text) == 2 &&
    text[0] == "first" &&
    text[1] == "second" { return }
  test.Error(text)
}
