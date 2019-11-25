class RecentlyUsedList {
  def items = []

  int getSize() {
    items.size()
  }

  void add(String item) {
    items = [item] + items.findAll { it != item }
  }

  String getAt(int index) {
    items[index]
  }
}
