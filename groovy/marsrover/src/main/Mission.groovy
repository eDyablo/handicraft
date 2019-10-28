package marsrover

class Mission {
  def plan
  int rangeX
  int rangeY
  final List<String> result = new ArrayList<String>()

  void explore() {
    if (plan) {
      readRange()
      landRover()
    }
  }

  void readRange() {
    final def range = plan.first().split(' ')
    rangeX = Integer.parseInt(range[0])
    rangeY = Integer.parseInt(range[1])
  }

  void landRover() {
    result << plan[1]
  }
}
