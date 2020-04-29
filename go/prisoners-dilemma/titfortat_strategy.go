package dilemma


// TitForTatStrategy is a prisoner strategy
type TitForTatStrategy struct {
}

// Respond remains silent or testifies depending on interrogation state
func (strategy *TitForTatStrategy) Respond(interrogation Interrogation) Testimony {
  if interrogation.Witness == interrogation.Suspect {
    return interrogation.Witness.Testify(interrogation.Accomplice)
  }
  return interrogation.Witness.RemainSilent(interrogation.Accomplice)
}
