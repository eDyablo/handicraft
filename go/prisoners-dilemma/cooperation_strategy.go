package dilemma

// CooperationStrategy is a prisoner strategy
type CooperationStrategy struct {
}

// Respond remains silent regardless of interrogation state
func (strategy *CooperationStrategy) Respond(interrogation Interrogation) Testimony {
  return interrogation.Witness.RemainSilent(interrogation.Accomplice)
}
