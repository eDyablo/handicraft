package dilemma

// DefectionStrategy is a prisoner strategy
type DefectionStrategy struct {
}

// Respond testifies the accomplice regardless of interrogation state
func (strategy *DefectionStrategy) Respond(interrogation Interrogation) Testimony {
	return interrogation.Witness.Testify(interrogation.Accomplice)
}
