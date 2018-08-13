package errors

import (
	"math"
	"fmt"
)

// ErrNegativeSqrt represents error
type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
  return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

// Sqrt returns square root of the number
func Sqrt(x float64) (float64, error) {
  if x < 0 {
    return 0, ErrNegativeSqrt(x)
  }
  return math.Sqrt(x), nil
}

// Exercise does the exercise
func Exercise() {
  fmt.Println(Sqrt(2))
  fmt.Println(Sqrt(-2))
}