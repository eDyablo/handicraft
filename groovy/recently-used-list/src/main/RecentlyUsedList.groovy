class RecentlyUsedList {
  def items = []

  int getSize() {
    0
  }

  void add(String item) {
    items = [item] + items
    println items
  }

  String getAt(int index) {
    items[index]
  }
}
