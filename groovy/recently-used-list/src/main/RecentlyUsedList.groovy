class RecentlyUsedList {
  def items = []

  int getSize() {
    items.size()
  }

  void add(String item) {
    items = items.inject([item]) { result, current ->
      if (current != item) {
        result << current
      }
      result
    }
  }

  String getAt(int index) {
    items[index]
  }
}
