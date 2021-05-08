package fbnc

func fibo(n uint) int {
	if n < 3 {
		return 1
	}
	return fibo(n-1) + fibo(n-2)
}
