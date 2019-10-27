package marsrover

import (
  "strings"
  "strconv"
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
}

// Explore does exploration
func (mission *Mission) Explore() {
  if mission.hasPlan() {
    mission.readRange()
    if len(mission.Plan) > 1 {
      mission.landRover()
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
  mission.Result = append(mission.Result, mission.Plan[1])
}
