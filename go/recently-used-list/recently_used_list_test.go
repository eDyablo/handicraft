package rul

import "testing"

func Test_the_list_is_initially_empty(test *testing.T) {
  list := RecentlyUsedList {}
  if list.Size() == 0 { return }
  test.Error(list)
}

func Test_an_item_added_to_empty_list_is_first(test *testing.T) {
  list := RecentlyUsedList {}
  list.Add("item")
  if list.Get(0) == "item" { return }
  test.Error(list)
}

func Test_two_different_items_added_to_empty_list_can_be_get_in_reverse_order(test *testing.T) {
  list := RecentlyUsedList {}
  list.Add("first")
  list.Add("second")
  if list.Get(0) == "second" &&
    list.Get(1) == "first" { return }
  test.Error(list)
} 
