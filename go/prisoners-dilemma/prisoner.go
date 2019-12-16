package dilemma

type Prisoner struct {
  Name string
  Strategy PrisonerStrategy
}

func (prisoner *Prisoner) RemainSilent(accomplice *Prisoner) Testimony {
  return Testimony {}
}

func (prisoner *Prisoner) Testify(accomplice *Prisoner) Testimony {
  return Testimony { Suspect: accomplice }
}

func (prisoner *Prisoner) Respond(interrogation Interrogation) Testimony {
  return prisoner.Strategy.Respond(interrogation)
}

func (prisoner Prisoner) String() string {
  return prisoner.Name
}
