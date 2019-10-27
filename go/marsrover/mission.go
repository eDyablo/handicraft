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
}

// Rover represents rover placement
type Rover struct {
  X         int
  Y         int
  Direction string
}

func (rover *Rover) String() string {
  return fmt.Sprint(rover.X, rover.Y, " ", rover.Direction)
}

// Explore does exploration
func (mission *Mission) Explore() {
  if mission.hasPlan() {
    mission.readRange()
    if len(mission.Plan) > 1 {
      mission.landRover()
      if len(mission.Plan) > 2 {
        for _, cmd := range mission.Plan[2] {
          if cmd == 'L' { mission.spinRoverLeft() }
          if cmd == 'R' { mission.spinRoverRight() }
        }
      }
      mission.reportRover()
    }
  }
}

func (mission *Mission) hasPlan() bool {
  return len(mission.Plan) > 0
}

func (mission *Mission) readRange() {
  items := strings.SplitN(mission.Plan[0], " ", 2)
  x,_ := strconv.Atoi(items[0])
  y,_ := strconv.Atoi(items[1])
  mission.Range = Range { X: x, Y: y }
}

func (mission *Mission) landRover() {
  items := strings.SplitN(mission.Plan[1], " ", 3)
  x,_ := strconv.Atoi(items[0])
  y,_ := strconv.Atoi(items[1])
  mission.rover = Rover { X: x, Y: y, Direction: items[2] }
}

func (mission *Mission) spinRoverLeft() {
  switch mission.rover.Direction {
  case "N": { mission.rover.Direction = "W" }
  case "W": { mission.rover.Direction = "S" }
  case "S": { mission.rover.Direction = "E" }
  case "E": { mission.rover.Direction = "N" }
  }
}

func (mission *Mission) spinRoverRight() {
  switch mission.rover.Direction {
  case "N": { mission.rover.Direction = "E" }
  case "E": { mission.rover.Direction = "S" }
  case "S": { mission.rover.Direction = "W" }
  case "W": { mission.rover.Direction = "N" }
  }
}

func (mission *Mission) reportRover() {
  mission.Result = append(mission.Result, mission.rover.String())
}
