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
    plan[2].each { commandRover(it) }
  }

  void commandRover(String command) {
    if (command == 'L') {
      spinRoverLeft()
    }
    if (command == 'R') {
      spinRoverRight()
    }
    if (command == 'M') {
      moveRover()
    }
  }

  void spinRoverLeft() {
    if (roverDir == 'N') {
      roverDir = 'W'
    } else if (roverDir == 'W') {
      roverDir = 'S'
    } else if (roverDir == 'S') {
      roverDir = 'E'
    } else if (roverDir == 'E') {
      roverDir = 'N'
    }
  }

  void spinRoverRight() {
    if (roverDir == 'N') {
      roverDir = 'E'
    } else if (roverDir == 'E') {
      roverDir = 'S'
    } else if (roverDir == 'S') {
      roverDir = 'W'
    } else if (roverDir == 'W') {
      roverDir = 'N'
    }
  }

  void moveRover() {
    if (roverDir == 'N') {
      roverY++
    } else if (roverDir == 'S') {
      roverY--
    } else if (roverDir == 'E') {
      roverX++
    } else if (roverDir == 'W') {
      roverX--
    }
  }

  void reportRover() {
    result << [roverX, roverY, roverDir].join(' ')
  }
}
