package dilemma

type Investigation struct {
  Prisoners []*Prisoner
  Round int
}

func NewInvestigation(prisoners ...*Prisoner) *Investigation {
  return &Investigation { Prisoners: prisoners }
}

func (investigation *Investigation) MakeRound() {
  prisoners := investigation.Prisoners
  prisoners[0].Respond(Interrogation {
    Witness: prisoners[0],
    Accomplice: prisoners[1],
  })
  prisoners[1].Respond(Interrogation {
    Witness: prisoners[1],
    Accomplice: prisoners[0],
  })
  investigation.Round ++
}
