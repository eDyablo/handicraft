package mediator

type ScreenHub struct {
  screens []*Screen
}

func NewScreenHub() *ScreenHub {
  return &ScreenHub{}
}

func (hub *ScreenHub) AddScreen(screen *Screen) {
  hub.screens = append(hub.screens, screen)
}

func (hub *ScreenHub) Display(text string, originator *Screen) {
  for _, screen := range hub.screens {
    if screen != originator {
      screen.Receive(text)
    }
  }
}
