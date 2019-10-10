package command

// Macro implements Command that combines
// several commands into one
type Macro struct {
  Commands []Command
}

// Execute executes all commands in order
func (macro *Macro) Execute(context Context) {
  for _, command := range macro.Commands {
    command.Execute(context)
  }
}
