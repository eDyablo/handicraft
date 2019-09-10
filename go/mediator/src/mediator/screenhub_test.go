package mediator

import (
  "testing"
)

func Test_screen_hub(test *testing.T) {
  hub := NewScreenHub()
  screen := NewScreen(hub, "a")
  NewScreen(hub, "b")
  screen = NewScreen(hub, "c")
  screen.Display("hello")
}
