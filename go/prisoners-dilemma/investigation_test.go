package dilemma

import "testing"

type testStrategy struct {
  interrogations []Interrogation
}

func (strategy *testStrategy) Respond(interrogaton Interrogation) Testimony {
  strategy.interrogations = append(strategy.interrogations, interrogaton)
  return Testimony {}
}

func Test_increases_round_number(t *testing.T) {
  investigation := Investigation {
    Dave: &Prisoner { Strategy: &testStrategy {} },
    Henry: &Prisoner { Strategy: &testStrategy {} },
  }
  investigation.MakeRound()
  if investigation.Round != 1 {
    t.Error(investigation)
  }
}

func Test_interrogates_Dave_as_a_witness_and_Henry_as_an_accomplice(t *testing.T) {
  strategy := testStrategy {}
  investigation := Investigation {
    Dave: &Prisoner { Name: "Dave", Strategy: &strategy },
    Henry: &Prisoner { Name: "Henry", Strategy: &strategy },
  }
  investigation.MakeRound()
  if len(strategy.interrogations) == 0 ||
    strategy.interrogations[0].Witness != investigation.Dave  ||
    strategy.interrogations[0].Accomplice != investigation.Henry {
    t.Error("interrogated:", strategy.interrogations)
  }
}

func Test_interrogates_Henry_as_a_witness_and_Dave_as_an_accomplice(t *testing.T) {
  strategy := testStrategy {}
  investigation := Investigation {
    Dave: &Prisoner { Name: "Dave", Strategy: &strategy },
    Henry: &Prisoner { Name: "Henry", Strategy: &strategy },
  }
  investigation.MakeRound()
  if len(strategy.interrogations) < 2 ||
    strategy.interrogations[1].Witness != investigation.Henry  ||
    strategy.interrogations[1].Accomplice != investigation.Dave {
    t.Error("interrogated:", strategy.interrogations)
  }
}

