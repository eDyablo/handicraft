package command

// Read implements Command that reads text from file
type Read struct {
  FileSystem
  File string
  Text *[]string
}

// Execute runs the command
func (command *Read) Execute(context Context) {
  if command.File == "" { return }
  size := len(*command.Text)
  lines := command.Read(command.File)
  *command.Text = append(*command.Text, lines...)
  context.EnqueueUndo(&Delete {
    Text: command.Text,
    From: size,
    Number: len(lines),
  })
}

func (command *Read) Read(file string) []string {
  return command.FileSystem.Read(command.File)
}
