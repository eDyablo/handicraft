package mediator

import (
  "testing"
)

func Test_lights_the_bulb_when_hit_the_button(test *testing.T) {
  dashboard :=  NewDashboard()
  bulb := NewBulb(dashboard)
  button := NewButton(dashboard)
  dashboard.Bind(button, bulb)

  button.Hit()

  if (bulb.IsLit() == false) {
    test.Errorf("The bulb is not lit")
  }
}

func Test_turns_off_the_bulb_when_hit_the_buttob(test *testing.T) {
  dashboard := NewDashboard()
  bulb := NewBulb(dashboard)
  bulb.LightOn()
  button := NewButton(dashboard)
  button.Hit()
  dashboard.Bind(button, bulb)

  button.Hit()

  if (bulb.IsLit() == true) {
    test.Errorf("The bulb is not turned off")
  }
}

func Test_lights_all_bulbs_when_hit_the_button(test *testing.T) {
  dashboard := NewDashboard()
  bulbs := []*Bulb {
    NewBulb(dashboard),
    NewBulb(dashboard),
  }
  button := NewButton(dashboard)
  for _, bulb := range bulbs {
    dashboard.Bind(button, bulb)
  }

  button.Hit()
  
  for _, bulb := range bulbs {
    if bulb.IsLit() == false {
      test.Errorf("Not all bulbs are lit")
    }
  }
}
