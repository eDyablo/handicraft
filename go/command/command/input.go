package command

import (
  "bufio"
  "fmt"
  "io"
  "strings"
)

// Input implements command that reads user input
type Input struct {
  Reader  io.Reader
  Writer  io.Writer
  Text    *[]string
}

// Execute runs the command
func (command *Input) Execute(context Context) {
  verb, options := command.readInput()
  switch verb {
  case "a":
    context.Enqueue(&Append { Reader: command.Reader, Text: command.Text })
  case "h":
    fmt.Print("a\tappend\n",
      "d\tdelete\n",
      "p\tprint\n",
      "q\tquit\n",
      "r\tread\n",
      "u\tundo\n",
    )
  case "d":
    context.Enqueue(&Delete {
      Text: command.Text,
      From: len(*command.Text) - 1,
      Number: 1,
    })
  case "p":
    context.Enqueue(&Print { Writer: command.Writer, Text: command.Text })
  case "q":
    context.Enqueue(&Quit { Code: 0 })
  case "r":
    context.Enqueue(&Read {
      File: strings.SplitN(options, " ", 2)[0],
      FileSystem: context.(FileSystem),
      Text: command.Text,
    })
  case "u":
    context.Undo()
  default:
    fmt.Println("?")
  }
  context.Enqueue(command)
}

func (command *Input) readInput() (verb string, options string) {
  line, _ := bufio.NewReader(command.Reader).ReadString('\n')
  line = strings.Trim(line, "\n")
  parts := strings.SplitN(line, " ", 2)
  verb = parts[0]
  if len(parts) > 1 {
    options = parts[1]
  }
  return
}
