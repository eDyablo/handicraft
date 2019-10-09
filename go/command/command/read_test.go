package command

import "testing"

func Test_read_does_nothing_when_no_file_specified(test *testing.T) {
  // Arrange
  cmd := Read { File: "", Text: &[]string{} }
  // Act
  cmd.Execute(nil)
  // Assert
  if len(*cmd.Text) == 0 { return }
  test.Error(*cmd.Text)
}

func Test_read_adds_content_of_the_file_at_the_end_of_the_text(test *testing.T) {
  // Arrange
  cmd := Read { File: "file", Text: &[]string{} }
  // Act
  cmd.Execute(nil)
  // Assert
  if len(*cmd.Text) != 0 { return }
  test.Error(*cmd.Text)
}
