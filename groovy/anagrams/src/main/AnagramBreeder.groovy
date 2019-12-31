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
    def anagrams = origin.split('').findAll()
    (1..<origin.size()).each {
      def breeds = anagrams.inject([]) { breeds, forebear ->
        origin.each { letter ->
          if (!forebear.contains(letter)) {
            breeds.add(forebear + letter)
          }
        }
        breeds
      }
      if (breeds.size()) {
        anagrams = breeds
      }
    }
    return anagrams
  }
}
