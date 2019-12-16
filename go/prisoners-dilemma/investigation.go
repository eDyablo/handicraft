package dilemma

type Investigation struct {
  Dave *Prisoner
  Henry *Prisoner
  Round int
}

func (investigation *Investigation) MakeRound() {
  investigation.Dave.Respond(Interrogation { Witness: investigation.Dave, Accomplice: investigation.Henry })
  investigation.Henry.Respond(Interrogation { Witness: investigation.Henry, Accomplice: investigation.Dave })
  investigation.Round ++
}
