package marsrover

class Mission {
  def plan
  int rangeX
  int rangeY
  int roverX
  int roverY
  String roverDir
  final List<String> result = new ArrayList<String>()

  void explore() {
    if (plan) {
      readRange()
      if (plan[1]) {
        landRover()
        if (plan[2]) {
          roverDir = 'W'
        }
        result << [roverX, roverY, roverDir].join(' ')
      }
    }
  }

  void readRange() {
    def (x, y) = plan.first().split(' ')
    rangeX = Integer.parseInt(x)
    rangeY = Integer.parseInt(y)
  }

  void landRover() {
    def (x, y, dir) = plan[1].split(' ')
    roverX = Integer.parseInt(x)
    roverY = Integer.parseInt(y)
    roverDir = dir
  }
}
