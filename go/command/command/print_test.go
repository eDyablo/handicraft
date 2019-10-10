package command

import (
  "testing"
  "strings"
)

func Test_prints_text(test *testing.T) {
  builder := strings.Builder {}
  cmd := Print { Writer: &builder }
  cmd.Text = &[]string {"one", "two"}

  cmd.Execute(nil)

  if builder.String() == "one\ntwo\n" { return }
  test.Error(builder.String())
}
