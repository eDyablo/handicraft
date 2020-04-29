package dilemma

import "testing"

type testStrategy struct {
  interrogations []Interrogation
}

func (strategy *testStrategy) Respond(interrogaton Interrogation) Testimony {
  strategy.interrogations = append(strategy.interrogations, interrogaton)
  return Testimony {}
}

func Test_interrogates_Dave_as_a_witness_and_Henry_as_an_accomplice(t *testing.T) {
  strategy := testStrategy {}
  Dave := Prisoner { Name: "Dave", Strategy: &strategy }
  Henry := Prisoner { Name: "Henry", Strategy: &strategy }
  investigation := NewInvestigation(&Dave, &Henry)
  investigation.MakeRound()
  if len(strategy.interrogations) < 1 ||
    strategy.interrogations[0].Witness != &Dave  ||
    strategy.interrogations[0].Accomplice != &Henry {
    t.Error("interrogated:", strategy.interrogations)
  }
}

func Test_interrogates_Henry_as_a_witness_and_Dave_as_an_accomplice(t *testing.T) {
  strategy := testStrategy {}
  Dave := Prisoner { Name: "Dave", Strategy: &strategy }
  Henry := Prisoner { Name: "Henry", Strategy: &strategy }
  investigation := NewInvestigation(&Dave, &Henry)
  investigation.MakeRound()
  if len(strategy.interrogations) < 2 ||
    strategy.interrogations[1].Witness != &Henry  ||
    strategy.interrogations[1].Accomplice != &Dave {
    t.Error("interrogated:", strategy.interrogations)
  }
}
