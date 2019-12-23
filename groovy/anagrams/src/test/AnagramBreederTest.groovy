import static org.junit.Assert.*
import org.junit.*

class AnagramBreederTest {
  final breeder = new AnagramBreeder()

  @Test
  void breeds_no_words_for_no_word() {
    assert [] == breeder.breed()
    assert [] == breeder.breed2()
  }
  
  @Test
  void breeds_one_word_equal_to_origin_when_it_has_one_letter() {
    assert ['a'] == breeder.breed('a')
    assert ['a'] == breeder.breed2('a')
  }
  
  @Test
  void breeds_for_word_with_two_letters() {
    assert ['ab', 'ba'] == breeder.breed('ab')
    assert ['ab', 'ba'] == breeder.breed2('ab')
  }
  
  @Test
  void breeds_for_word_with_three_letters() {
    final String[] expected = [
      'abc', 'acb',
      'bac', 'bca',
      'cab', 'cba',
    ]
    assert expected == breeder.breed('abc')
    assert expected == breeder.breed2('abc')
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
    assert expected == breeder.breed2('biro')
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
    assert expected == breeder.breed2('abiro').take(expected.size())
  }

  @Test void breeds_for_n_letters_word() {
    assert 'hamcrest' in breeder.breed2('matchers')
  }
}
