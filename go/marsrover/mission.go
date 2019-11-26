package marsrover

import (
  "strings"
  "strconv"
  "fmt"
)

// Range represents exploration mission range
type Range struct {
  X int
  Y int
}

// Mission represents exploration mission
type Mission struct {
  Plan   []string
  Result []string
  Range  Range
  rover  Rover
  step   int
}

// Rover represents rover placement
type Rover struct {
  X         int
  Y         int
  Direction rune
}

func (rover *Rover) String() string {
  return fmt.Sprint(rover.X, rover.Y, " ", string(rover.Direction))
}

// Explore does exploration
func (mission *Mission) Explore() {
  if mission.hasPlan() {
    mission.start()
    mission.readRange()
    for mission.continues() {
      mission.landRover()
      if mission.continues() {
        mission.commandRover()
      }
      mission.reportRover()
    }
  }
}

func (mission *Mission) hasPlan() bool {
  return len(mission.Plan) > 0
}

func (mission *Mission) start() {
  mission.step = 0
}

func (mission *Mission) continues() bool {
  return mission.step < len(mission.Plan)
}

func (mission *Mission) readRange() {
  items := strings.SplitN(mission.Plan[0], " ", 2)
  x,_ := strconv.Atoi(items[0])
  y,_ := strconv.Atoi(items[1])
  mission.Range = Range { X: x, Y: y }
  mission.step++
}

func (mission *Mission) landRover() {
  record := mission.Plan[mission.step]
  items := strings.SplitN(record, " ", 3)
  x,_ := strconv.Atoi(items[0])
  y,_ := strconv.Atoi(items[1])
  dir := []rune(items[2])[0]
  mission.rover = Rover { X: x, Y: y, Direction: dir}
  mission.step++
}

func (mission *Mission) commandRover() {
  instructions := mission.Plan[mission.step]
  for _, cmd := range instructions {
    switch cmd {
    case 'L': { mission.spinRoverLeft() }
    case 'R': { mission.spinRoverRight() }
    case 'M': { mission.moveRover() }
    }
  }
  mission.step++
}

func (mission *Mission) spinRoverLeft() {
  switch mission.rover.Direction {
  case 'N': { mission.rover.Direction = 'W' }
  case 'W': { mission.rover.Direction = 'S' }
  case 'S': { mission.rover.Direction = 'E' }
  case 'E': { mission.rover.Direction = 'N' }
  }
}

func (mission *Mission) spinRoverRight() {
  switch mission.rover.Direction {
  case 'N': { mission.rover.Direction = 'E' }
  case 'E': { mission.rover.Direction = 'S' }
  case 'S': { mission.rover.Direction = 'W' }
  case 'W': { mission.rover.Direction = 'N' }
  }
}

func (mission *Mission) moveRover() {
  switch mission.rover.Direction {
  case 'N': { mission.rover.Y++ }
  case 'S': { mission.rover.Y-- }
  case 'E': { mission.rover.X++ }
  case 'W': { mission.rover.X-- }
  }
}

func (mission *Mission) reportRover() {
  mission.Result = append(mission.Result, mission.rover.String())
}
