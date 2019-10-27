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
  if (mission.Result[0] == "1 2 N") { return }
  test.Error("Result is", mission.Result)
}
