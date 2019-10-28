package marsrover

import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class MissionTest {
  final def mission = new Mission()

  @Test void exploration_without_plan_gives_no_result() {
    mission.explore()
    assertThat(mission.result, is(empty()))
  }

  @Test void mission_gets_its_ranges_from_the_plan() {
    mission.plan = [
      '1 2',
    ]
    mission.explore()
    assertThat(mission, allOf(
      hasProperty('rangeX', is(equalTo(1))),
      hasProperty('rangeY', is(equalTo(2))),
    ))
  }

  @Test void lands_rover_when_there_is_one_in_the_plan() {
    mission.plan = [
      '1 1',
      '1 2 N',
    ]
    mission.explore()
    assertThat(mission.result, contains('1 2 N'))
  }

  @Test void one_L_command_in_the_plan_spins_north_oriented_rover_to_west() {
    mission.plan = [
      '1 1',
      '0 0 N',
      'L',
    ]
    mission.explore()
    assertThat(mission.result, contains('0 0 W'))
  }

  @Test void one_R_command_in_the_plan_spins_north_oriented_rover_to_east() {
    mission.plan = [
      '1 1',
      '0 0 N',
      'R',
    ]
    mission.explore()
    assertThat(mission.result, contains('0 0 E'))
  }

  @Test void one_M_command_in_the_plan_moves_north_oriented_rover_one_step_towards_north() {
    mission.plan = [
      '1 1',
      '0 0 N',
      'M',
    ]
    mission.explore()
    assertThat(mission.result, contains('0 1 N'))
  }

  @Test void two_M_commands_in_the_plan_moves_north_oriented_rover_two_steps_towards_north() {
    mission.plan = [
      '1 1',
      '0 0 N',
      'MM',
    ]
    mission.explore()
    assertThat(mission.result, contains('0 2 N'))
  }
}
