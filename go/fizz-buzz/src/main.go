package main

import (
  "fmt"
  "./fizzbuzz"
)

func main() {
  for i := 1; i < 1000; i++ {
    fmt.Println(fizzbuzz.AnswerFor(i))
  }
}
