package ldcrg

import "testing"

type TestCase struct {
	containers []int
	items      []int
	cargoSize  int
	shipped    int
}

func Test_correctness(t *testing.T) {
	tests := []TestCase{
		{[]int{3, 1, 2}, []int{1, 2, 3}, 4, 9},
		{[]int{1, 2, 3}, []int{3, 2, 1}, 3, 7},
		{[]int{1, 2, 3}, []int{3, 2, 1}, 10, 10},
	}
	for _, test := range tests {
		shipped := Solution(test.containers, test.items, test.cargoSize)
		if shipped != test.shipped {
			t.Error("expected to ship", shipped, "but got", test.shipped)
		}
	}
}
