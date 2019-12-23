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
    def anagrams = origin.split('') as ArrayList<String>
    def (int begin, int end) = [0, anagrams.size()]
    (1..<origin.size()).each {
      anagrams[begin..<end].each { s ->
        origin.findAll { c ->
          !s.contains(c)
        }.each { c ->
          anagrams << (s + c)
        }
      }
      (begin, end) = [end, anagrams.size()]
    }
    return anagrams[begin..<end]
  }
}
