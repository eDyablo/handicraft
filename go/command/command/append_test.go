package command

import (
  "strings"
  "testing"
)

func Test_append_adds_one_empty_line_when_input_is_empty(test *testing.T) {
  reader := strings.NewReader("")
  text := []string{}
  context := TestContext {}
  cmd := Append { Reader: reader, Text: &text }

  cmd.Execute(&context)
  context.command.Execute(&context)

  if len(text) == 1 { return }
  test.Error(text)
}

func Test_append_does_not_add_text_when_input_is_dot(test *testing.T) {
  reader := strings.NewReader(".")
  text := []string{}
  context := TestContext {}
  cmd := Append { Reader: reader, Text: &text }

  cmd.Execute(&context)
  context.command.Execute(&context)

  if len(text) == 0 { return }
  test.Error(text)
}

func Test_append_text_adds_lines_to_the_end_of_the_text(test *testing.T) {
  context := TestContext {}
  text := []string {"one", "two"}
  addition := []string {"three", "four"}
  cmd := AppendText { Lines: addition, Text: &text }

  cmd.Execute(&context)

  if len(text) == 4 &&
    text[0] == "one" &&
    text[3] == "four" { return }
  test.Error(text)
}

func Test_append_text_enqueue_undo_command(test *testing.T) {
  // Arrange
  context := TestContext {}
  text := []string {"one", "two"}
  addition := []string {"three", "four"}
  cmd := AppendText { Lines: addition, Text: &text }
  // Act
  cmd.Execute(&context)
  context.undoCommand.Execute(&context)
  // Assert
  if len(text) == 2 &&
    text[0] == "one" &&
    text[1] == "two" { return }
  test.Error(text)
}
