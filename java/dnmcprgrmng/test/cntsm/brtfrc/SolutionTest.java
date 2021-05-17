package cntsm.brtfrc;

import org.junit.*;

import static org.hamcrest.MatcherAssert.*;
import static org.hamcrest.Matchers.*;

public class SolutionTest {
  Solution solution;

  @Before
  public void BeforeEach() {
    solution = new Solution();
  }

  @Test
  public void correctness() {
    assertThat(solution.CountSum(0, new int[] { 1, 2, 3 }), is(equalTo(1)));
    assertThat(solution.CountSum(1, new int[] { 2 }), is(equalTo(0)));
    assertThat(solution.CountSum(1, new int[] { 1 }), is(equalTo(1)));
    assertThat(solution.CountSum(2, new int[] { 1, 2 }), is(equalTo(2)));
    assertThat(solution.CountSum(3, new int[] { 1, 2, 3 }), is(equalTo(3)));
    assertThat(solution.CountSum(10, new int[] { 1, 5, 10, 25 }), is(equalTo(4)));
    assertThat(solution.CountSum(25, new int[] { 1, 5, 10, 25 }), is(equalTo(13)));
    assertThat(solution.CountSum(7, new int[] { 7, 4, 3, 2 }), is(equalTo(3)));
  }
}
