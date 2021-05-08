package fbnc

func Fibo(n uint) int {
	memo := make(map[uint]int)
	return fibo(n, memo)
}

func fibo(n uint, memo map[uint]int) int {
	if n < 3 {
		return 1
	}
	if value, in := memo[n]; in {
		return value
	}
	memo[n] = fibo(n-1, memo) + fibo(n-2, memo)
	return memo[n]
}
