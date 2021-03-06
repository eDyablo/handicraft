package fizzbuzz

import (
  "testing"
)



type testCase struct {
  number int
  answer string
}

var cases = []testCase {
  {1, "1"},
  {2, "2"},
  {3, "Fizz"},
  {4, "4"},
  {5, "Buzz"},
  {6, "Fizz"},
  {7, "7"},
  {8, "8"},
  {9, "Fizz"},
  {10, "Buzz"},
  {11, "11"},
  {12, "Fizz"},
  {13, "13"},
  {14, "14"},
  {15, "FizzBuzz"},
}

func Test_answers(test *testing.T) {
  for _, tc := range cases {
    if answer := AnswerFor(tc.number); answer != tc.answer {
      test.Errorf("AnswerFor(%d) = '%s', want '%s'", tc.number, answer, tc.answer)
    }
  }
}
