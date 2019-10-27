package marsrover;

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

public class MissionTest {
  Mission mission = new Mission();

  @Test public void exploration_with_no_plan_givest_no_result() {
    String[] result = mission.explore(new String[]{});
    assertThat(result, is(emptyArray()));
  }

  @Test public void exploration_plan_sets_mission_range() {
    mission.explore(new String[] {
      "1 2",
    });
    assertThat(mission.xRange, is(equalTo(1)));
    assertThat(mission.yRange, is(equalTo(2)));
  }

  @Test public void exploration_with_one_rover_lands_the_rover_to_coordinates_and_direction_from_the_plan() {
    String[] result = mission.explore(new String[]{
      "1 1",
      "1 1 N",
    });
    assertThat(result, is(array(equalTo("1 1 N"))));
  }
}
