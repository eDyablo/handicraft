package cntsm

type memo map[int]uint

func (memo *memo) count_sum(target int, numbers []int, selected uint) uint {
	key := target*len(numbers) + int(selected)
	if value, in := (*memo)[key]; in {
		return value
	}
	if target == 0 {
		(*memo)[key] = 1
	} else if target < 0 {
		(*memo)[key] = 0
	} else if selected >= uint(len(numbers)) {
		(*memo)[key] = 0
	} else {
		(*memo)[key] = memo.count_sum(target-numbers[selected], numbers, selected) +
			memo.count_sum(target, numbers, selected+1)
	}
	return (*memo)[key]
}

func count_sum(target int, numbers []int) uint {
	memo := &memo{}
	return memo.count_sum(target, numbers, 0)
}
