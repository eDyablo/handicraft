package dilemma

// Investigation represents an investigation
type Investigation struct {
  Prisoners []*Prisoner
  Round int
}

// NewInvestigation creates an investigation against the prisoners
func NewInvestigation(prisoners ...*Prisoner) *Investigation {
  return &Investigation { Prisoners: prisoners }
}

// MakeRound does one round of the investigation
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
