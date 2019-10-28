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
          commandRover()
        }
        reportRover()
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

  void commandRover() {
    plan[2].each { cmd ->
      if (cmd == 'L') {
        spinRoverLeft()
      }
      if (cmd == 'R') {
        spinRoverRight()
      }
      if (cmd == 'M') {
        roverY++
      }
    }
  }

  void spinRoverLeft() {
    roverDir = 'W'
  }

  void spinRoverRight() {
    roverDir = 'E'
  }

  void reportRover() {
    result << [roverX, roverY, roverDir].join(' ')
  }
}
