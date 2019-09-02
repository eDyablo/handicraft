package mediator

import "fmt"

type Screen struct {
  hub *ScreenHub
  id  string
}

func NewScreen(hub *ScreenHub, id string) *Screen {
  screen := &Screen{hub: hub, id: id}
  hub.AddScreen(screen)
  return screen
}

func (screen *Screen) Display(text string) {
  screen.Receive(text)
  screen.hub.Display(text, screen)
}

func (screen *Screen) Receive(text string) {
  fmt.Println(screen.id, text)
}
