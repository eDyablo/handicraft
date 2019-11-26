package marsrover

import "testing"

func Test_exploration_without_plan_has_no_results(test *testing.T) {
  mission := Mission {}
  mission.Explore()
  if (len(mission.Result) == 0) { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_sets_mission_range(test *testing.T) {
  mission := Mission {
    Plan: []string { "1 2" },
  }
  mission.Explore()
  if (mission.Range.X == 1 && mission.Range.Y == 2) { return }
  test.Error("Range is", mission.Range)
}

func Test_exploration_plan_for_one_rover_lands_the_rover_to_coordinates_with_direction_from_the_plan(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "1 2 N",
    },
  }
  mission.Explore()
  if mission.Result[0] == "1 2 N" { return }
  test.Error("Result is", mission.Result)
}

func Test_exloration_plan_with_one_L_command_spins_north_oriented_rover_to_west(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "L",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 W") { return }
  test.Error("Result is", mission.Result)
}

func Test_exloration_plan_with_one_R_command_spins_north_oriented_rover_to_east(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "R",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 E") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_two_L_commands_rotates_rover_to_south(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "LL",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 S") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_four_L_commands_does_full_rover_rotation(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "LLLL",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 N") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_four_R_commands_does_full_rover_rotation(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "RRRR",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 N") { return }
  test.Error("Result is", mission.Result)
}

func Test_exloration_plan_with_one_M_command_moves_north_oriented_rover_one_step_towards_north(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "M",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 1 N") { return }
  test.Error("Result is", mission.Result)
}

func Test_exloration_plan_with_one_M_command_moves_south_oriented_rover_one_step_towards_south(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 1 S",
      "M",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 S") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_one_M_command_moves_east_orientes_rover_one_step_towards_east(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 E",
      "M",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "1 0 E") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_one_M_command_moves_west_orientes_rover_one_step_towards_west(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "1 0 W",
      "M",
    },
  }
  mission.Explore()
  if (mission.Result[0] == "0 0 W") { return }
  test.Error("Result is", mission.Result)
}

func Test_exploration_plan_with_M_commands_for_two_rovers_moves_the_rovers(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "1 1",
      "0 0 N",
      "M",
      "1 1 S",
      "M",
    },
  }
  mission.Explore()
  if (len(mission.Result) == 2 &&
    mission.Result[0] == "0 1 N" &&
    mission.Result[1] == "1 0 S") { return }
  test.Error(mission.Result)
}

func Test_exploration_with_plan_from_the_kata_gives_correct_results(test *testing.T) {
  mission := Mission {
    Plan: []string {
      "5 5",
      "1 2 N",
      "LMLMLMLMM",
      "3 3 E",
      "MMRMMRMRRM",
    },
  }
  mission.Explore()
  if (len(mission.Result) == 2 &&
    mission.Result[0] == "1 3 N" &&
    mission.Result[1] == "5 1 E") { return }
  test.Error(mission.Result)
}
