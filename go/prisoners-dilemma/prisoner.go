package dilemma

// Prisoner represents a prisoner
type Prisoner struct {
  Name string
  Strategy PrisonerStrategy
}

// RemainSilent responds silent testimony
func (prisoner *Prisoner) RemainSilent(accomplice *Prisoner) Testimony {
  return Testimony {}
}

// Testify testifies against the accomplice 
func (prisoner *Prisoner) Testify(accomplice *Prisoner) Testimony {
  return Testimony { Suspect: accomplice }
}

// Respond responds a testimony
func (prisoner *Prisoner) Respond(interrogation Interrogation) Testimony {
  return prisoner.Strategy.Respond(interrogation)
}

func (prisoner Prisoner) String() string {
  return prisoner.Name
}
