package fbnc

func fibo(n uint) int {
	table := make([]int, n+2)
	table[1] = 1
	for i := uint(0); i < n; i++ {
		table[i+1] += table[i]
		table[i+2] += table[i]
	}
	return table[n]
}
