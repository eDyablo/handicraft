package fizzbuzz

import (
	"fmt"
)

// AnswerFor gives proper answer
func AnswerFor(numer int) string {
  var answer string
  if numer % 3 == 0 {
    answer += "Fizz"
  }
  if numer % 5 == 0 {
    answer += "Buzz"
  }
  if answer == "" {
    answer = fmt.Sprint(numer)
  }
  return answer
}
