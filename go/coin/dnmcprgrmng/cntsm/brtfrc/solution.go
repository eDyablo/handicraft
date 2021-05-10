package cntsm

func count_sum(target int, numbers []int, selected uint) uint {
	if target == 0 {
		return 1
	}
	if target < 0 {
		return 0
	}
	if selected >= uint(len(numbers)) {
		return 0
	}
	return count_sum(target-numbers[selected], numbers, selected) +
		count_sum(target, numbers, selected+1)
}
