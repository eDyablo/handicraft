package smlstlmnt

// SmallestElement returns integer
func SmallestElement(Array []int) int {
	var result int = Array[0]
	for i := 1; i < len(Array); i++ {
		if result > Array[i] {
			result = Array[i]
		}
	}
	return result
}
