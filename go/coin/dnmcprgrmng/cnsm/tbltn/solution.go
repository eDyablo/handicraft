package cnsm

func canSum(target int, numbers []int) bool {
	table := make([]bool, target+1)
	table[0] = true
	for subTarget := int(0); subTarget <= target; subTarget++ {
		if table[subTarget] {
			for _, number := range numbers {
				sum := subTarget + number
				if sum <= target {
					table[sum] = true
				}
			}
		}
	}
	return table[target]
}
