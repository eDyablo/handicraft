package main

import (
	"bufio"
  "./command"
  "os"
)

type editor struct {
  main command.Queue
  undo command.Queue
}

func (ed *editor) Enqueue(cmd command.Command) {
  ed.main.Enqueue(cmd)
}

func (ed *editor) EnqueueUndo(cmd command.Command) {
  ed.undo.Push(cmd)
}

func (ed *editor) Undo() {
  if ed.undo.HasCommands() {
    ed.undo.Dequeue().Execute(command.NullContext())
  }
}

func (ed *editor) Read(path string) (content []string) {
  file, _ := os.Open(path)
  defer file.Close()
  scanner := bufio.NewScanner(file)
  for scanner.Scan() {
    content = append(content, scanner.Text())
  }
  return
}

func (ed *editor) Write(string, []string) {
}

func (ed *editor) run() {
  for ed.main.HasCommands() {
    ed.main.Dequeue().Execute(ed)
  }
}

func main() {
  text := []string{}
  ed := editor {
    main: command.NewQueue(),
    undo: command.NewQueue(),
  }
  ed.Enqueue(&command.Input {
    Reader: os.Stdin,
    Writer: os.Stdout,
    Text: &text,
  })
  ed.run()
}
