package dilemma

type Prisoner struct {
  strategy PrisonerStrategy
}

func (prisoner *Prisoner) RemainSilent(accomplice *Prisoner) Testimony {
  return Testimony {}
}

func (prisoner *Prisoner) Testify(accomplice *Prisoner) Testimony {
  return Testimony { Suspect: accomplice }
}

func (prisoner *Prisoner) Respond(interrogation Interrogation) Testimony {
  return prisoner.strategy.Respond(interrogation)
}
