package fbnc.brtfrc

import static org.hamcrest.MatcherAssert.assertThat
import static org.hamcrest.Matchers.is
import static org.hamcrest.Matchers.equalTo

import org.junit.Test
import groovy.transform.CompileStatic

/**
 * Tests
 */
@CompileStatic
class SolutionTest {

  private final Solution solution = new Solution()

  @Test void correctness() {
    assertThat(solution.fibo(0), is(equalTo(0)))
    assertThat(solution.fibo(1), is(equalTo(1)))
    assertThat(solution.fibo(2), is(equalTo(1)))
    assertThat(solution.fibo(3), is(equalTo(2)))
    assertThat(solution.fibo(4), is(equalTo(3)))
    assertThat(solution.fibo(5), is(equalTo(5)))
    assertThat(solution.fibo(6), is(equalTo(8)))
    assertThat(solution.fibo(7), is(equalTo(13)))
    assertThat(solution.fibo(8), is(equalTo(21)))
    assertThat(solution.fibo(9), is(equalTo(34)))
  }

}
