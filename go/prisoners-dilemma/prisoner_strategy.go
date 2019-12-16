package dilemma

// PrisonerStrategy defines a prisoner strategy
type PrisonerStrategy interface {
  Respond(interrogation Interrogation) Testimony
}
