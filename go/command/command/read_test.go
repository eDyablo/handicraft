package command

import (
	"testing"
)

type TestFileSystem struct {
	Content []string
}

func (fs *TestFileSystem) Read(string) []string {
	return fs.Content
}

func (fs *TestFileSystem) Write(string, []string) {
}

func Test_read_does_nothing_when_no_file_specified(test *testing.T) {
	// Arrange
	fs := TestFileSystem { Content: []string { "content" } }
	cmd := Read { File: "", Text: &[]string{}, FileSystem: &fs }
	// Act
	cmd.Execute(nil)
	// Assert
	if len(*cmd.Text) == 0 {
		return
	}
	test.Error(*cmd.Text)
}

func Test_read_adds_content_of_the_file_at_the_end_of_the_text(test *testing.T) {
	// Arrange
	fs := TestFileSystem { Content: []string { "first", "second" } }
	cmd := Read { File: "file", Text: &[]string{}, FileSystem: &fs }
	// Act
	cmd.Execute(&TestContext{})
	// Assert
	if len(*cmd.Text) == 2 &&
    (*cmd.Text)[0] == "first" &&
    (*cmd.Text)[1] == "second" { return }
	test.Error(*cmd.Text)
}

func Test_read_enqueue_undo_command_that_deletes_added_text(test *testing.T) {
  // Arrange
  cntx := TestContext {}
	fs := TestFileSystem { Content: []string { "first", "second" } }
	cmd := Read { File: "file", Text: &[]string { "initial" }, FileSystem: &fs }
	// Act
  cmd.Execute(&cntx)
  cntx.Undo()
  // Assert
  if len(*cmd.Text) == 1 &&
    (*cmd.Text)[0] == "initial" { return }
  test.Error(*cmd.Text)
}
