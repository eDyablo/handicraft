package fbnc.tbltn

import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.is
import static org.hamcrest.Matchers.equalTo

import org.junit.Test

class SolutionTest {

  private final solution = new Solution()

  @Test void correctness() {
    assertThat(solution.fibo(0), is(equalTo(0L)))
    assertThat(solution.fibo(1), is(equalTo(1L)))
    assertThat(solution.fibo(2), is(equalTo(1L)))
    assertThat(solution.fibo(3), is(equalTo(2L)))
    assertThat(solution.fibo(4), is(equalTo(3L)))
    assertThat(solution.fibo(5), is(equalTo(5L)))
    assertThat(solution.fibo(6), is(equalTo(8L)))
    assertThat(solution.fibo(7), is(equalTo(13L)))
    assertThat(solution.fibo(8), is(equalTo(21L)))
    assertThat(solution.fibo(9), is(equalTo(34L)))
  }

  @Test void performance() {
    assertThat(solution.fibo(50), is(equalTo(12586269025L)))
  }

}
