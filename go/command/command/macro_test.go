package command

import "testing"

type MacroTestCommand struct {
  Log *string
  Text string
}

func (cmd *MacroTestCommand) Execute(Context) {
  *cmd.Log += cmd.Text
}

func Test_macro_executes_all_its_commands_in_order(test *testing.T) {
  // Arrange
  log := ""
  commands := []Command {
    &MacroTestCommand { Log: &log, Text: "first" },
    &MacroTestCommand { Log: &log, Text: "second" },
  }
  macro := Macro { Commands: commands }
  // Act
  macro.Execute(NullContext())
  // Assert
  if log == "firstsecond" { return }
  test.Error(log)
}
