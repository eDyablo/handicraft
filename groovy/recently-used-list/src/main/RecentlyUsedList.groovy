class RecentlyUsedList {
  def items = []

  int getSize() {
    items.size()
  }

  void add(String item) {
    if (item in items)
      return
    items = [item] + items
  }

  String getAt(int index) {
    items[index]
  }
}
