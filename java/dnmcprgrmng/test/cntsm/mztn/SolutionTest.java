package cntsm.mztn;

import org.junit.*;

import static org.hamcrest.MatcherAssert.*;
import static org.hamcrest.Matchers.*;

public class SolutionTest {
  Solution solution;

  @Before
  public void beforeEach() {
    solution = new Solution();
  }

  @Test
  public void correctness() {
    assertThat(solution.countSum(0, new int[] { 1, 2, 3 }), is(equalTo(1)));
    assertThat(solution.countSum(1, new int[] { 2 }), is(equalTo(0)));
    assertThat(solution.countSum(1, new int[] { 1 }), is(equalTo(1)));
    assertThat(solution.countSum(2, new int[] { 1, 2 }), is(equalTo(2)));
    assertThat(solution.countSum(3, new int[] { 1, 2, 3 }), is(equalTo(3)));
    assertThat(solution.countSum(10, new int[] { 1, 5, 10, 25 }), is(equalTo(4)));
    assertThat(solution.countSum(25, new int[] { 1, 5, 10, 25 }), is(equalTo(13)));
    assertThat(solution.countSum(7, new int[] { 7, 4, 3, 2 }), is(equalTo(3)));
  }

  @Test
  public void performance() {
    assertThat(solution.countSum(1000, new int[] { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 }), is(equalTo(0)));
  }
}
