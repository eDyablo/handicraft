package marsrover

class Mission {
  def plan
  int rangeX
  int rangeY
  int roverX
  int roverY
  String roverDir
  final List<String> result = new ArrayList<String>()
  int step

  void explore() {
    if (plan) {
      readRange()
      while (plan[step]) {
        landRover()
        if (plan[step]) {
          commandRover()
        }
        reportRover()
      }
    }
  }

  void readRange() {
    step = 0
    def (x, y) = plan[step].split(' ')
    rangeX = Integer.parseInt(x)
    rangeY = Integer.parseInt(y)
    step++
  }

  void landRover() {
    def (x, y, dir) = plan[step].split(' ')
    roverX = Integer.parseInt(x)
    roverY = Integer.parseInt(y)
    roverDir = dir
    step++
  }

  void commandRover() {
    plan[step].each { commandRover(it) }
    step++
  }

  void commandRover(String command) {
    if (command == 'L') {
      spinRoverLeft()
    } else if (command == 'R') {
      spinRoverRight()
    } else if (command == 'M') {
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
