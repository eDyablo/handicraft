import static org.junit.Assert.*
import org.junit.*

class AnagramBreederTest {
  final breeder = new AnagramBreeder()

  @Test
  void breeds_no_words_for_no_word() {
    assertArrayEquals([] as String[], breeder.breed())
  }
  
  @Test
  void breeds_one_word_equal_to_origin_when_it_has_one_letter() {
    assertArrayEquals(['a'] as String[], breeder.breed('a'))
  }
  
  @Test
  void breeds_for_word_with_two_letters() {
    assert ['ab', 'ba'] == breeder.breed('ab')
  }
  
  @Test
  void breeds_for_word_with_three_letters() {
    final String[] expected = [
      'abc', 'acb',
      'bac', 'bca',
      'cab', 'cba',
    ]
    assert expected == breeder.breed('abc')
  }
  
  @Test
  void breeds_for_word_with_four_letters() {
    final String[] expected = [
      'biro', 'bior', 'brio', 'broi', 'boir', 'bori',
      'ibro', 'ibor', 'irbo', 'irob', 'iobr', 'iorb',
      'rbio', 'rboi', 'ribo', 'riob', 'robi', 'roib',
      'obir', 'obri', 'oibr', 'oirb', 'orbi', 'orib',
    ]
    assert expected == breeder.breed('biro')
  }
  
  @Test
  void breeds_for_word_with_five_letters() {
    final String[] expected = [
      'abiro', 'abior', 'abrio', 'abroi', 'aboir', 'abori',
      'aibro', 'aibor', 'airbo', 'airob', 'aiobr', 'aiorb',
      'arbio', 'arboi', 'aribo', 'ariob', 'arobi', 'aroib',
      'aobir', 'aobri', 'aoibr', 'aoirb', 'aorbi', 'aorib',
      'bairo', 'baior', 'bario', 'baroi', 'baoir', 'baori',
      'biaro', 'biaor', 'birao', 'biroa', 'bioar', 'biora',
      'braio', 'braoi', 'briao', 'brioa', 'broai', 'broia',
      'boair', 'boari', 'boiar', 'boira', 'borai', 'boria',
    ]
    assert expected == breeder.breed('abiro').take(expected.size())
  }
}
