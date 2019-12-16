package dilemma

type CooperationStrategy struct {
}

func (strategy *CooperationStrategy) Respond(interrogation Interrogation) Testimony {
  return interrogation.Witness.RemainSilent(interrogation.Accomplice)
}
