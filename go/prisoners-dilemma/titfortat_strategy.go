package dilemma

type TitForTatStrategy struct {
}

func (strategy *TitForTatStrategy) Respond(interrogation Interrogation) Testimony {
  if interrogation.Witness == interrogation.Suspect {
    return Testimony { Suspect: interrogation.Accomplice }
  }
  return Testimony {}
}
