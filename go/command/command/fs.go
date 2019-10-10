package command

// FileSystem declares basic operations on files
type FileSystem interface {
  Read(file string) []string
}
