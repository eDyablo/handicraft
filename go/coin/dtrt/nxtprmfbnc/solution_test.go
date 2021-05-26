package nxtprmfbnc

import "testing"

type testCase struct {
	number   int64
	expected int64
}

func Test_correctness(t *testing.T) {
	tests := []testCase{{0, 1}, {1, 2}, {2, 3}, {3, 5}, {4, 5},
		{5, 13}, {13, 89}, {20, 89}, {89, 233}}
	for _, test := range tests {
		if actual := nextPrimeFibonacci(test.number); actual != test.expected {
			t.Log("for", test.number, "expected", test.expected, "but got", actual)
			t.Fail()
		}
	}
}

func Test_performance(t *testing.T) {
	tests := []testCase{{1000000, 0}, {10000000, 0}, {100000000, 0}, {1000000000, 0}, {2000000000, 0}}
	for _, test := range tests {
		nextPrimeFibonacci(test.number)
	}
}
