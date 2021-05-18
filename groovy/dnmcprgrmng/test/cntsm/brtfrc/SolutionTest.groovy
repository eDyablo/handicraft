package cntsm.brtfrc

import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.is
import static org.hamcrest.Matchers.equalTo

import org.junit.Test

class SolutionTest {

  private final Solution solution = new Solution()

  @Test void correctness() {
    assertThat(solution.countSum(0, [1, 2, 3]), is(equalTo(1)))
    assertThat(solution.countSum(1, [1]), is(equalTo(1)))
    assertThat(solution.countSum(1, [2]), is(equalTo(0)))
    assertThat(solution.countSum(2, [1, 2]), is(equalTo(2)))
    assertThat(solution.countSum(3, [ 1, 2, 3 ]), is(equalTo(3)))
    assertThat(solution.countSum(10, [ 1, 5, 10, 25 ]), is(equalTo(4)))
    assertThat(solution.countSum(25, [ 1, 5, 10, 25 ]), is(equalTo(13)))
    assertThat(solution.countSum(7, [ 7, 4, 3, 2 ]), is(equalTo(3)))
  }

}
