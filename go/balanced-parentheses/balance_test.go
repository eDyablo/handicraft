package balance
 
import ("testing")
 
func Test_empty_text_is_balanced(t *testing.T) {
  if IsBalanced("") == true { return }
  t.Error()
}
 
func Test_single_opening_parenthesis_is_not_balanced(t *testing.T) {
  if IsBalanced("(") == false { return }
  t.Error()
}
 
func Test_single_closing_parenthesis_is_not_balanced(t *testing.T) {
  if IsBalanced(")") == false { return }
  t.Error()
}
 
func Test_two_opening_parentheses_are_not_balanced(t *testing.T) {
  if IsBalanced("((") == false { return }
  t.Error()
}

func Test_three_opening_parentheses_are_not_balanced(t *testing.T) {
  if IsBalanced("(((") == false { return }
  t.Error()
}
 
func Test_three_closing_parentheses_are_not_balanced(t *testing.T) {
  if IsBalanced(")))") == false { return }
  t.Error()
}

func Test_opening_and_closing_parentheses_reversed_not_balanced(t *testing.T) {
  if IsBalanced(")(") == false { return }
  t.Error()
}

func Test_occo_are_not_balanced(t *testing.T) {
  if IsBalanced("())(") == false { return }
  t.Error()
}


func Test_single_opening_bracket_is_not_balanced(t *testing.T) {
  if IsBalanced("[") == false { return }
  t.Error()
}   

func Test_single_closing_bracket_is_not_balanced(t *testing.T) {
  if IsBalanced("]") == false { return }
  t.Error()
}

func Test_opening_parenthesis_and_closing_bracket_are_not_balanced(t *testing.T) {
  if IsBalanced("(]") == false { return }
  t.Error()
}
 
func Test_opening_bracket_and_closing_parenthesis_are_not_balanced(t *testing.T) {
  if IsBalanced("[)") == false { return }
  t.Error()
}
 
func Test_balanced_brackets_inside_balnced_parentheses_are_balanced(t *testing.T) {
  if IsBalanced("([])") == true { return }
  t.Error()
}
