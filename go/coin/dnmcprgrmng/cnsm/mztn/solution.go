package cnsm

type memo map[int]bool

func (memo *memo) canSum(target int, numbers []int) bool {
	if value, in := (*memo)[target]; in {
		return value
	}
	if target == 0 {
		return true
	}
	if target < 0 {
		return false
	}
	for _, number := range numbers {
		if memo.canSum(target-number, numbers) {
			(*memo)[target] = true
			return true
		}
	}
	(*memo)[target] = false
	return false
}

func canSum(target int, numbers []int) bool {
	memo := &memo{}
	return memo.canSum(target, numbers)
}
