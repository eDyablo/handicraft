package command

// Context implements command execution context
type Context interface {
  Enqueue(command Command)

  EnqueueUndo(command Command)

  Undo()
}

// NullContext implements Context that does nothing
func NullContext() Context {
  return &nullContext {}
}

type nullContext struct {}

func (*nullContext) Enqueue(Command) { }
func (*nullContext) EnqueueUndo(Command) { }
func (*nullContext) Undo() { }
