package dilemma

import "testing"

func Test_titfortat_strategy_responds_with_no_suspect_when_the_witness_is_not_the_suspect(t *testing.T) {
  witness := &Prisoner {}
  suspect := &Prisoner {}
  strategy := TitForTatStrategy {}
  testimony := strategy.Respond(Interrogation { Witness: witness, Suspect: suspect })
  if (testimony.Suspect != nil) {
    t.Error(testimony)
  }
}

func Test_titfortat_strategy_responds_with_accomplice_as_a_suspect_when_the_witness_is_the_suspect(t *testing.T) {
  witness := &Prisoner {}
  accomplice := &Prisoner {}
  strategy := TitForTatStrategy {}
  interrogation := Interrogation { Witness: witness, Suspect: witness, Accomplice: accomplice }
  testimony := strategy.Respond(interrogation)
  if (testimony.Suspect != accomplice ) {
    t.Error(testimony)
  }
}
