package command

import (
	"strings"
	"testing"
)

type Test struct {
  testing.T
}

func Test_append_adds_one_empty_line_when_input_is_empty(test *testing.T) {
  // Arrange
	reader := strings.NewReader("")
	text := []string {}
	cntx := TestContext {}
	cmd := Append { Reader: reader, Text: &text }
  // Act
	cmd.Execute(&cntx)
	cntx.command.Execute(&cntx)
  // Assert
	if len(text) == 1 { return }
	test.Error(text)
}

func Test_append_does_not_add_text_when_input_is_dot(test *testing.T) {
  // Arrange
	reader := strings.NewReader(".")
	text := []string {}
	cntx := TestContext {}
	cmd := Append { Reader: reader, Text: &text }
  // Act
	cmd.Execute(&cntx)
	cntx.command.Execute(&cntx)
  // Assert
	if len(text) == 0 { return }
	test.Error(text)
}

func Test_append_text_adds_lines_to_the_end_of_the_text(test *testing.T) {
  // Arrange
	cntx := TestContext {}
	text := []string { "one", "two" }
	addition := []string { "three", "four" }
	cmd := AppendText { Lines: addition, Text: &text }
  // Act
	cmd.Execute(&cntx)
  // Assert
	if len(text) == 4 &&
		text[0] == "one" &&
		text[3] == "four" { return }
	test.Error(text)
}

func Test_append_text_enqueue_undo_command(test *testing.T) {
	// Arrange
	cntx := TestContext {}
	text := []string { "one", "two" }
	addition := []string { "three", "four" }
	cmd := AppendText { Lines: addition, Text: &text }
	// Act
	cmd.Execute(&cntx)
	cntx.undoCommand.Execute(NullContext())
	// Assert
	if len(text) == 2 &&
		text[0] == "one" &&
		text[1] == "two" { return }
	test.Error(text)
}
