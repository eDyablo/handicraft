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

// TestContext inplement Context that holds only one command
type TestContext struct {
  command     Command
  undoCommand Command
}

// Enqueue stores the command
func (context *TestContext) Enqueue(command Command) {
  context.command = command
}

// EnqueueUndo stores command for undo
func (context *TestContext) EnqueueUndo(command Command) {
  context.undoCommand = command
}

// Undo executes stored undo command
func (context *TestContext) Undo() {
  context.undoCommand.Execute(NullContext())
}
