package command

// Delete implements command that deletes
// lines from the text
type Delete struct {
  Text    *[]string
  From    int
  Number  int
}

// Execute runs the command
func (command *Delete) Execute(context Context) {
  text := command.Text
  begin := command.From
  end :=  begin + command.Number
  if len(*command.Text) > 0 {
    *command.Text = append((*text)[0:begin], (*text)[end:]...)
    context.EnqueueUndo(&AppendText {
      Text: text,
      Lines: (*text)[begin:end],
    })
  }
}
