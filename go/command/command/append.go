package command

import (
	"strings"
  "io"
  "bufio"
)

// Append implements Command that appends input to the text
type Append struct {
  Reader  io.Reader
  Text    *[]string
}

// AppendText implements Command that appends lines to the text
type AppendText struct {
  Lines []string
  Text  *[]string
}

// Execute runs the command
func (command *Append) Execute(context Context) {
  context.Enqueue(&AppendText {
    Lines: command.readText(),
    Text: command.Text,
  })
}

// Execute runs the command
func (command *AppendText) Execute(context Context) {
  size := len(*command.Text)
  *command.Text = append(*command.Text, command.Lines...)
  context.EnqueueUndo(&Delete {
    Text: command.Text,
    From: size,
    Number: len(command.Lines),
  })
}

func (command *Append) readText() []string {
  lines := make([]string, 0)
  for {
    line, err := bufio.NewReader(command.Reader).ReadString('\n')
    line = strings.Trim(line, "\n")
    if line == "." {
      break
    }
    lines = append(lines, strings.Split(line, "\n")...)
    if err != nil {
      break
    }
  }
  return lines
}
