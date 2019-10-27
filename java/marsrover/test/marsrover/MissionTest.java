package marsrover;

import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

public class MissionTest {
  Mission mission = new Mission();

  @Test public void exploration_with_no_plan_givest_no_result() {
    mission.explore(new String[]{});
    assertThat(mission.result, is(empty()));
  }

  @Test public void exploration_plan_sets_mission_range() {
    mission.explore(new String[] {
      "1 2",
    });
    assertThat(mission.xRange, is(equalTo(1)));
    assertThat(mission.yRange, is(equalTo(2)));
  }

  @Test public void exploration_with_one_rover_lands_the_rover_to_coordinates_and_direction_from_the_plan() {
    mission.explore(new String[]{
      "1 1",
      "1 1 N",
    });
    assertThat(mission.result, contains("1 1 N"));
  }

  @Test public void exloration_plan_with_one_L_command_spins_north_oriented_rover_to_east() {
    mission.explore(new String[] {
      "1 1",
      "1 1 N",
      "L"
    });
    assertThat(mission.result, contains("1 1 E"));
  }

  @Test public void exloration_plan_with_one_R_command_spins_north_oriented_rover_to_west() {
    mission.explore(new String[] {
      "1 1",
      "1 1 N",
      "R"
    });
    assertThat(mission.result, contains("1 1 W"));
  }

  @Test public void exloration_plan_with_one_M_command_moves_north_oriented_rover_one_step_towards_north() {
    mission.explore(new String[] {
      "1 1",
      "0 0 N",
      "M"
    });
    assertThat(mission.result, contains("0 1 N"));
  }

  @Test public void exloration_plan_with_two_M_commands_moves_north_oriented_rover_two_steps_towards_north() {
    mission.explore(new String[] {
      "2 2",
      "0 0 N",
      "MM"
    });
    assertThat(mission.result, contains("0 2 N"));
  }

  @Test public void exloration_plan_with_two_L_commands_spins_north_oriented_rover_to_south() {
    mission.explore(new String[] {
      "1 1",
      "0 0 N",
      "LL"
    });
    assertThat(mission.result, contains("0 0 S"));
  }

  @Test public void exloration_plan_with_two_R_commands_spins_north_oriented_rover_to_south() {
    mission.explore(new String[] {
      "1 1",
      "0 0 N",
      "RR"
    });
    assertThat(mission.result, contains("0 0 S"));
  }

  @Test public void exloration_plan_with_four_L_commands_do_full_rover_rotation() {
    mission.explore(new String[] {
      "1 1",
      "0 0 N",
      "LLLL"
    });
    assertThat(mission.result, contains("0 0 N"));
  }

  @Test public void exloration_plan_with_four_R_commands_do_full_rover_rotation() {
    mission.explore(new String[] {
      "1 1",
      "0 0 N",
      "RRRR"
    });
    assertThat(mission.result, contains("0 0 N"));
  }

  @Test public void exloration_plan_with_one_M_command_moves_south_oriented_rover_one_step_towards_south() {
    mission.explore(new String[] {
      "1 1",
      "0 1 S",
      "M"
    });
    assertThat(mission.result, contains("0 0 S"));
  }

  @Test public void exloration_plan_with_one_M_command_moves_west_oriented_rover_one_step_towards_west() {
    mission.explore(new String[] {
      "1 1",
      "0 0 W",
      "M"
    });
    assertThat(mission.result, contains("1 0 W"));
  }

  @Test public void exloration_plan_with_one_M_command_moves_east_oriented_rover_one_step_towards_east() {
    mission.explore(new String[] {
      "1 1",
      "1 0 E",
      "M"
    });
    assertThat(mission.result, contains("0 0 E"));
  }
}
