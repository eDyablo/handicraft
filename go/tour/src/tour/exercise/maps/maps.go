package maps

import (
	"fmt"
	"strings"
)

func wordCount(text string) map[string]int {
	counters := make(map[string]int)
	for _, word := range strings.Fields(text) {
		counters[word]++
	}
	return counters
}

// Exercise does the exercise
func Exercise() {
	fmt.Println(wordCount("I am learning Go!"))
	fmt.Println(wordCount("The quick brown fox jumped over the lazy dog"))
	fmt.Println(wordCount("I ate a donut. Then I ate another donut"))
	fmt.Println(wordCount("A man a plan a canal panama"))
}
