package main

import (
  "tour/hello"
  "tour/sandbox"
  "tour/methods"
  "tour/exercise/errors"
  "tour/stringer"
  "tour/exercise_stringer"
  "tour/error"
)

func main() {
  hello.Exercise()
  sandbox.Exercise()
  methods.Exercise()
  errors.Exercise()
  stringer.Stringer()
  exercise_stringer.ExerciseStringer()
  error.Exercise()
}
