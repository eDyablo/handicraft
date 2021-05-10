package cntsm

type memo map[int]uint

func count_sum(target int, numbers []int) uint {
	table := make([]uint, uint(target)+1)
	table[0] = 1
	for _, number := range numbers {
		for amount := int(1); amount <= target; amount++ {
			if number <= amount {
				table[amount] += table[amount-number]
			}
		}
	}
	return table[target]
}
