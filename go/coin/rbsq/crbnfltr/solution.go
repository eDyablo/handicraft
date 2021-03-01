package crbnfltr

func chooseFilter(filter rune) rune {
	if filter == 'a' {
		return 'b'
	} else if filter == 'b' {
		return 'a'
	}
	return filter
}

// Solution returns corrected plan
func Solution(plan string) string {
	answer := []rune(plan)
	size := len(answer)
	if size == 1 {
		if answer[0] == '?' {
			answer[0] = 'a'
		}
	} else if size == 2 {
		if answer[0] == '?' {
			answer[0] = 'a'
		}
		if answer[1] == '?' {
			answer[1] = answer[0]
		}
	} else if size > 2 {
		if answer[0] == '?' {
			if answer[1] == '?' {
				answer[0] = 'a'
			} else {
				answer[0] = chooseFilter(answer[1])
			}
		}
		for i := 1; i < size-1; i++ {
			if answer[i] == '?' {
				if answer[i+1] == answer[i-1] || answer[i+1] == '?' {
					answer[i] = chooseFilter(answer[i-1])
				} else {
					answer[i] = answer[i-1]
				}
			}
		}
		if answer[size-1] == '?' {
			answer[size-1] = chooseFilter(answer[size-2])
		}
	}
	return string(answer)
}
