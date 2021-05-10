package cntsm

import "testing"

type testCase struct {
	target  int
	numbers []int
	count   uint
}

func Test_correctness(t *testing.T) {
	tests := []testCase{
		{0, []int{1, 2, 3}, 1},
		{1, []int{1}, 1},
		{1, []int{2}, 0},
		{2, []int{1, 2}, 2},
		{3, []int{1, 2, 3}, 3},
		{10, []int{1, 5, 10, 25}, 4},
		{25, []int{1, 5, 10, 25}, 13},
		{7, []int{7, 4, 3, 2}, 3},
	}
	for _, test := range tests {
		if count := count_sum(test.target, test.numbers); count != test.count {
			t.Error("expected", test.count, "way(s) to get", test.target, "by sum up", test.numbers, "but got", count)
		}
	}
}

func Test_performance(t *testing.T) {
	tests := []testCase{
		{1000, []int{3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, 0},
	}
	for _, test := range tests {
		if count := count_sum(test.target, test.numbers); count != test.count {
			t.Error("expected", test.count, "way(s) to get", test.target, "by sum up", test.numbers, "but got", count)
		}
	}
}
