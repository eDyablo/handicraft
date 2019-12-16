package dilemma

import (
	"fmt"
)

type Interrogation struct {
  Witness *Prisoner
  Accomplice *Prisoner
  Suspect *Prisoner
}

func (interrogation Interrogation) String() string {
  return fmt.Sprintf("[%s is witness, %s is accomplice]",
    interrogation.Witness, interrogation.Accomplice)
}
