package command

import (
  "testing"
  "strings"
)

func Test_prints_text(test *testing.T) {
  // Arrange
  builder := strings.Builder {}
  cmd := Print { Writer: &builder }
  cmd.Text = &[]string { "one", "two" }
  // Act
  cmd.Execute(NullContext())
  // Assert
  if builder.String() == "one\ntwo\n" { return }
  test.Error(builder.String())
}
