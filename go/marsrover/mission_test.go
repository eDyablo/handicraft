package marsrover

import "testing"

func Test_exploration_without_plan_has_no_results(test *testing.T) {
  mission := Mission {}
  if (len(mission.Result) == 0) { return }
  test.Error(mission.Result)
}
