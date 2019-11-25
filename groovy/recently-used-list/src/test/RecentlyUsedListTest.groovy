import org.junit.*
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

class RecentlyUsedListTest {
  final list = new RecentlyUsedList()

  @Test void it_is_initally_empty() {
    assertThat(list.size, is(equalTo(0)))
  }

  @Test void adding_first_item_to_emty_list_places_it_to_first_position() {
    list.add('first')
    assertThat(list[0], is(equalTo('first')))
  }

  @Test void adding_two_different_items_places_them_in_reversed_order() {
    list.add('first')
    list.add('second')
    assertThat(list[1], is(equalTo('first')))
  }

  @Test void adding_the_same_item_twice_to_an_empty_list_resuls_in_one_item_added() {
    list.add('the same')
    list.add('the same')
    assertThat(list.size, is(equalTo(1)))
    assertThat(list[0], is(equalTo('the same')))
  }
}
