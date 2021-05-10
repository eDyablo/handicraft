package fbnc

type memo map[uint]int

func (memo memo) fibo(n uint) int {
	if value, in := memo[n]; in {
		return value
	}
	value := int(1)
	if n > 2 {
		value = memo.fibo(n-1) + memo.fibo(n-2)
	}
	memo[n] = value
	return value
}

func fibo(n uint) int {
	memo := &memo{}
	return memo.fibo(n)
}
