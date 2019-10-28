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
      '1 2'
    ]
    mission.explore()
    assertThat(mission, allOf(
      hasProperty('rangeX', is(equalTo(1))),
      hasProperty('rangeY', is(equalTo(2))),
    ))
  }
}
