package dilemma

type PrisonerStrategy interface {
  Respond(interrogation Interrogation) Testimony
}
