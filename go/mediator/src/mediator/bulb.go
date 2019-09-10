package mediator

type Bulb struct {
  dashboard *Dashboard
  lit       bool
}

func NewBulb(dashboard *Dashboard) *Bulb {
  return &Bulb{dashboard: dashboard}
}

func (bulb *Bulb) IsLit() bool {
  return bulb.lit
}

func (bulb *Bulb) LightOn() {
  bulb.lit = true
}

func (bulb *Bulb) TurnOff() {
  bulb.lit = false
}
