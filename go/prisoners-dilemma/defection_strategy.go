package dilemma

type DefectionStrategy struct {
}

func (strategy *DefectionStrategy) Respond(interrogation Interrogation) Testimony {
  return interrogation.Witness.Testify(interrogation.Accomplice)
}
