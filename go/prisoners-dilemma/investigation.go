package dilemma

// Investigation represents an investigation
type Investigation struct {
  Prisoners []*Prisoner
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
}

// Hold holds the investigation by conducting the number of interrogations
func (investigation *Investigation) Hold(number int) {
  for round := 0; round < number; round++ {
    investigation.MakeRound()
  }
}
