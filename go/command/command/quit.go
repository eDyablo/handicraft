package command

import "os"

// Quit implements command that quits the application
type Quit struct {
  Code int
}

// Execute runs the command
func (command *Quit) Execute(context Context) {
  os.Exit(command.Code)
}
