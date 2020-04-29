package dilemma

import "testing"

func Test_coopertion_strategy_does_not_testify_accomplice_when_the_witness_is_suspect(t *testing.T) {
  witness := &Prisoner {}
  accomplice := &Prisoner {}
  strategy := CooperationStrategy {}
  testimony := strategy.Respond(Interrogation { Witness: witness, Accomplice: accomplice, Suspect: witness })
  if (testimony.Suspect == accomplice) {
    t.Error(testimony)
  }
}

func Test_coopertion_strategy_does_not_testify_when_the_witness_is_not_suspect(t *testing.T) {
  witness := &Prisoner {}
  accomplice := &Prisoner {}
  strategy := CooperationStrategy {}
  testimony := strategy.Respond(Interrogation { Witness: witness, Accomplice: accomplice, Suspect: accomplice })
  if (testimony.Suspect == accomplice) {
    t.Error(testimony)
  }
}
