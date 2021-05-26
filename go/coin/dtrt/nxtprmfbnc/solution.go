package nxtprmfbnc

import "math"

func isPrime(number int64) bool {
	bound := int64(math.Ceil(math.Sqrt(float64(number))))
	for i := int64(2); i < bound; i++ {
		if number%i == 0 {
			return false
		}
	}
	return true
}

func fibonacci(number int32) int64 {
	current := int64(1)
	next := int64(1)
	for i := int32(1); i < number; i++ {
		current, next = next, current+next
	}
	return current
}

func nextPrimeFibonacci(number int64) int64 {
	for i := int32(1); ; i++ {
		fib := fibonacci(i)
		if fib > number && isPrime(fib) {
			return fib
		}
	}
}
