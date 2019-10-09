package command

// Command declares an interface for all commands,
// providing a simple execute() method which asks the Receiver
// of the command to carry out an operation.
type Command interface {
  Execute(context Context)
}
