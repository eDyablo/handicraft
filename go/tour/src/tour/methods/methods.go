package methods

import (
	"math"
	"fmt"
)

// Vertex represents 2d vertex
type Vertex struct {
  X, Y float64
}

// Abs return absolute value of the vertex
func (v Vertex) Abs() float64 {
  return math.Sqrt(v.X * v.X + v.Y * v.Y)
}

// Exercise does the exercise
func Exercise() {
  v := Vertex {3, 4}
  fmt.Println(v.Abs())
}