package fbnc

type memo struct {
	Record map[uint]int
}

func (memo *memo) fibo(n uint) int {
	if value, in := memo.Record[n]; in {
		return value
	}
	value := int(1)
	if n > 2 {
		value = memo.fibo(n-1) + memo.fibo(n-2)
	}
	memo.Record[n] = value
	return value
}

func fibo(n uint) int {
	memo := &memo{make(map[uint]int)}
	return memo.fibo(n)
}
