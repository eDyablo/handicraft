package command

// Read implements Command that reads text from file
type Read struct {
  File string
  Text *[]string
}

// Execute runs the command
func (command *Read) Execute(context Context) {
}
