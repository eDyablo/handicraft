package crbnfltr

import (
	"strings"
	"testing"
)

func Test_solution(t *testing.T) {
	plans := []string{
		"",
		"?", "a", "b",
		"??", "a?", "b?", "?a", "?b",
		"???", "a??", "b??", "aa?", "bb?", "?aa", "?bb", "a?a", "b?b", "a?b", "b?a", "?a?", "?b?",
		"????", "a???", "b???", "aa??", "bb??", "aab?", "bba?",
		"??a??", "??b??", "a??a", "b??b", "a??b", "b??a",
		"a?bb", "??abb", "a?b?aa", "aa??aa",
		"b?aa", "??baa", "b?a?bb", "bb??bb",
		"?????", "a?a?a", "b?b?b", "?a?a?", "?b?b?", "a?b?a", "b?a?b", "?a?b?", "?b?a?",
		"??????", "aa??bb", "bb??aa", "??aa??", "??bb??", "ab??ab", "ba??ba", "ab??ba", "ba??ab", "??ab??", "??ba??",
	}
	for _, plan := range plans {
		answer := Solution(plan)
		if len(answer) != len(plan) {
			t.Error("for", plan, "expected the same length but got", len(answer))
		}
		if strings.ContainsRune(answer, '?') {
			t.Error("for", plan, "no ? expected to be found in plan but got", answer)
		}
		if strings.Contains(answer, "aaa") || strings.Contains(answer, "bbb") {
			t.Error("for", plan, "expected no three consequent letters but got", answer)
		}
	}
}
