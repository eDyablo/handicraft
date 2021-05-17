package fbnc.brtfrc;

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
    assertThat(solution.fibo(0), is(equalTo(0)));
    assertThat(solution.fibo(1), is(equalTo(1)));
    assertThat(solution.fibo(2), is(equalTo(1)));
    assertThat(solution.fibo(3), is(equalTo(2)));
    assertThat(solution.fibo(4), is(equalTo(3)));
    assertThat(solution.fibo(5), is(equalTo(5)));
    assertThat(solution.fibo(6), is(equalTo(8)));
    assertThat(solution.fibo(7), is(equalTo(13)));
    assertThat(solution.fibo(8), is(equalTo(21)));
    assertThat(solution.fibo(9), is(equalTo(34)));
  }
}
