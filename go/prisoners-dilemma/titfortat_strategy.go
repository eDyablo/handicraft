package dilemma

type TitForTatStrategy struct {
}

func (strategy *TitForTatStrategy) Respond(interrogation Interrogation) Testimony {
  if interrogation.Witness == interrogation.Suspect {
    return interrogation.Witness.Testify(interrogation.Accomplice)
  }
  return interrogation.Witness.RemainSilent(interrogation.Accomplice)
}
