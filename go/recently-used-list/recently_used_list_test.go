package rul

import "testing"

func Test_an_item_added_to_empty_list_is_first(test *testing.T) {
  // Arrange
  list := RecentlyUsedList{}
  // Act
  list.Add("item")
  // Assert
  if list.Get(0) == "item" {
    return
  }
  test.Error(list)
}

func Test_two_different_items_added_to_empty_list_can_be_get_in_reverse_order(test *testing.T) {
  // Arrange
  list := RecentlyUsedList{}
  // Act
  list.Add("first")
  list.Add("second")
  // Assert
  if list.Get(0) == "second" &&
    list.Get(1) == "first" {
    return
  }
  test.Error(list)
}

func Test_does_not_add_the_same_item_twice_to_empty_list(test *testing.T) {
  // Arrange
  list := RecentlyUsedList{}
  // Act
  list.Add("the same")
  list.Add("the same")
  // Assert
  if list.Size() == 1 {
    return
  }
  test.Error(list)
}

func Test_does_not_add_the_same_item_twice_to_no_empty_list(test *testing.T) {
  // Arrange
  list := RecentlyUsedList{}
  list.Add("first")
  // Act
  list.Add("second")
  list.Add("second")
  // Assert
  if list.Size() == 2 {
    return
  }
  test.Error(list)
}

func Test_does_not_allow_to_add_empty_string(test *testing.T) {
  // Arrange
  list := RecentlyUsedList {}
  // Act
  list.Add("")
  // Assert
  if list.Size() == 0 { return }
  test.Error(list)
}
