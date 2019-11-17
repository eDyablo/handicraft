import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class RecentlyUsedListTest {
  @Test void it_is_initally_empty() {
    final list = new RecentlyUsedList()
    assertThat(list.size, is(equalTo(0)))
  }
}
