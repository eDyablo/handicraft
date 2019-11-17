import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class RecentlyUsedListTest {
  @Test void it_is_initally_empty() {
    final list = new RecentlyUsedList()
    assertThat(list.size, is(equalTo(0)))
  }

  @Test void adding_first_item_to_emty_list_places_it_to_first_position() {
    final list = new RecentlyUsedList()
    list.add('first')
    assertThat(list.getAt(0), is(equalTo('first')))
  }
}
