package fbnc

import "testing"

type testCase struct {
	number   uint
	expected int
}

func Test_correctness(t *testing.T) {
	tests := []testCase{
		{1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 5}, {6, 8}, {7, 13}, {8, 21}, {9, 34},
	}
	for _, test := range tests {
		if actual := fibo(test.number); actual != test.expected {
			t.Error("expected fibo(", test.number, ") to be", test.expected, "but go", actual)
		}
	}
}

func Test_performance(t *testing.T) {
	tests := []testCase{
		{50, 12586269025},
	}
	for _, test := range tests {
		if actual := fibo(test.number); actual != test.expected {
			t.Error("expected fibo(", test.number, ") to be", test.expected, "but go", actual)
		}
	}
}
