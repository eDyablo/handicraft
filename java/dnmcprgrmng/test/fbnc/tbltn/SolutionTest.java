package fbnc.tbltn;

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
    assertThat(solution.fibo(0), is(equalTo(0l)));
    assertThat(solution.fibo(1), is(equalTo(1l)));
    assertThat(solution.fibo(2), is(equalTo(1l)));
    assertThat(solution.fibo(3), is(equalTo(2l)));
    assertThat(solution.fibo(4), is(equalTo(3l)));
    assertThat(solution.fibo(5), is(equalTo(5l)));
    assertThat(solution.fibo(6), is(equalTo(8l)));
    assertThat(solution.fibo(7), is(equalTo(13l)));
    assertThat(solution.fibo(8), is(equalTo(21l)));
    assertThat(solution.fibo(9), is(equalTo(34l)));
  }

  @Test
  public void performance() {
    assertThat(solution.fibo(50), is(equalTo(12586269025l)));
  }
}
