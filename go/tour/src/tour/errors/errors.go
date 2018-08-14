package errors

import (
  "fmt"
  "time"
)

// Error type
type Error struct {
  When time.Time
  What string
}

func (e *Error) Error() string {
  return fmt.Sprintf("at %v, %s", e.When, e.What)
}

func run() error {
  return &Error { time.Now(), "it didn't work" }
}

// Exercise does the exercise
func Exercise() {
  if err := run(); err != nil {
    fmt.Println(err)
  }
}