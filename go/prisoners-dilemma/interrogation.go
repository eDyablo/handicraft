package dilemma

import (
	"fmt"
)

// Interrogation represents an interrogation
type Interrogation struct {
  Witness *Prisoner
  Accomplice *Prisoner
  Suspect *Prisoner
}

func (interrogation Interrogation) String() string {
  return fmt.Sprintf("[%s is witness, %s is accomplice]",
    interrogation.Witness, interrogation.Accomplice)
}
