package command

import (
  "io"
)

// Print implements command that prints out the text
type Print struct {
  Writer  io.Writer
  Text    *[]string
}

// Execute runs the command
func (command *Print) Execute(context Context) {
  for _, line := range *command.Text {
    command.Writer.Write([]byte(line))
    command.Writer.Write([]byte("\n"))
  }
}
