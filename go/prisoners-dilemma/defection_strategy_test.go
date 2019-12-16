package dilemma

import "testing"

func Test_defection_strategy_testifies_againts_the_accomplice_when_the_witness_is_not_the_suspect(t *testing.T) {
  witness := &Prisoner {}
  accomplice := &Prisoner {}
  strategy := DefectionStrategy {}
  testimony := strategy.Respond(Interrogation { Witness: witness, Accomplice: accomplice })
  if (testimony.Suspect != accomplice) {
    t.Error(testimony)
  }
}

func Test_defection_strategy_testifies_againts_the_accomplice_when_the_witness_is_the_suspect(t *testing.T) {
  witness := &Prisoner {}
  accomplice := &Prisoner {}
  strategy := DefectionStrategy {}
  testimony := strategy.Respond(Interrogation { Witness: witness, Accomplice: accomplice, Suspect: witness })
  if (testimony.Suspect != accomplice) {
    t.Error(testimony)
  }
}
