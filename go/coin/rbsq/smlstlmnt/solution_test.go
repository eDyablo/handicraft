package smlstlmnt

import "testing"

type TestCase struct {
	Input    []int
	Expected int
}

func Test_smallest_element(t *testing.T) {
	tests := []TestCase{
		{[]int{-1, 1, -2, 2}, -2},
		{[]int{1}, 1},
	}
	for _, test := range tests {
		smallest := SmallestElement(test.Input)
		if smallest != test.Expected {
			t.Error("Smallest element of", test.Input, "is expected to be", test.Expected, "but got", smallest)
		}
	}
}
