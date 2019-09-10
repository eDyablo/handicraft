package mediator

type Binding struct {
  button *Button
  bulb   *Bulb
}

type Dashboard struct {
  bindings []Binding
}

func NewDashboard() *Dashboard {
  return &Dashboard{}
}

func (panel *Dashboard) Bind(button *Button, bulb *Bulb) {
  binding := Binding{button: button, bulb: bulb}
  panel.bindings = append(panel.bindings, binding)
}

func (panel *Dashboard) Hit(button *Button) {
  for _, binding := range panel.bindings {
    if binding.button == button {
      sync(binding)
    }
  }
}

func sync(binding Binding) {
  button := binding.button
  bulb := binding.bulb
  if button.IsPushed() {
    bulb.LightOn()
  } else {
    bulb.TurnOff()
  }
}
