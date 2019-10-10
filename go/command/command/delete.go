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
  from := command.From
  number :=  command.Number
  if len(*command.Text) > 0 {
    *command.Text = append((*text)[0:from], (*text)[from + number:]...)
    context.EnqueueUndo(&AppendText {
      Text: text,
      Lines: (*text)[from:from+number],
    })
  }
}
