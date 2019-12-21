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
}
