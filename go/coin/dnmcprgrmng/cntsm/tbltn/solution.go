package cntsm

type memo map[int]uint

func count_sum(target int, numbers []int) uint {
	table := make([]uint, uint(target)+1)
	table[0] = 1
	for _, number := range numbers {
		for sub_target := number; sub_target <= target; sub_target++ {
			table[sub_target] += table[sub_target-number]
		}
	}
	return table[target]
}
