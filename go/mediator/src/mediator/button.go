package mediator

type Button struct {
  dashboard *Dashboard
  pushed    bool
}

func NewButton(dashboard *Dashboard) *Button {
  button := &Button{dashboard: dashboard}
  return button
}

func (button *Button) Hit() {
  button.pushed = !button.pushed
  button.dashboard.Hit(button)
}

func (button *Button) IsPushed() bool {
  return button.pushed
}
