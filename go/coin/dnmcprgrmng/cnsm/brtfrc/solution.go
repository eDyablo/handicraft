package cnsm

func canSum(target int, numbers []int) bool {
	if target == 0 {
		return true
	}
  if target < 0 {
    return false
  }
	for _, number := range numbers {
		if canSum(target-number, numbers) {
			return true
		}
	}
	return false
}
