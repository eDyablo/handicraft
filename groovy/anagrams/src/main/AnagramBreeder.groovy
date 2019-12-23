class AnagramBreeder {
  def breed(String origin='') {
    final size = origin.size()
    if (size == 0) {
      return [] as String[]
    }
    if (size == 1) {
      return [origin] as String[]
    }
    (0..<size).inject([]) { anagrams, i ->
      breed(origin.take(i) + origin.drop(i+1)).each { forebear ->
        anagrams << origin[i] + forebear
      }; anagrams
    } as String[]
  }

  def breed2(String origin='') {
    def anagrams = origin.split('')
    (1..<origin.size()).each {
      anagrams = anagrams.inject([]) { result, word ->
        origin.each { letter ->
          if (!word.contains(letter)) {
            result.add(word + letter)
          }
        }
        result
      }
    }
    return anagrams
  }
}
