package cnsm

import "testing"

type testCase struct {
	target   int
	numbers  []int
	expected bool
}

func Test_correctness(t *testing.T) {
	tests := []testCase{
		{0, []int{1, 2, 3}, true},
		{1, []int{1}, true},
		{1, []int{2}, false},
		{3, []int{1, 2}, true},
		{7, []int{2, 3}, true},
		{7, []int{5, 3, 4, 7}, true},
		{7, []int{2, 4}, false},
		{8, []int{2, 3, 5}, true},
	}
	for _, test := range tests {
		if actual := canSum(test.target, test.numbers); actual != test.expected {
			t.Error("for", test.target, "and", test.numbers, "expected", test.expected, "but got", actual)
			t.Fail()
		}
	}
}
