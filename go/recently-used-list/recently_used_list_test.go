package rul

import "testing"

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

func Test_does_not_add_the_same_item_twice_to_empty_list(test *testing.T) {
  // Arrange
  list := RecentlyUsedList {}
  // Act
  list.Add("the same")
  list.Add("the same")
  // Assert
  if list.Size() == 1 { return }
  test.Error(list)
}
