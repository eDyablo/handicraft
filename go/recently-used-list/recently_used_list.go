package rul

// RecentlyUsedList holds strings uniquely
// in Last-In-First-Out order
type RecentlyUsedList struct {
  items []string
}

// Size returns number of items in the list
func (list *RecentlyUsedList) Size() uint {
  return uint(len(list.items))
}

// Add adds an item to the list
func (list *RecentlyUsedList) Add(item string) {
  foundAt := len(list.items)
  for index, listItem := range list.items {
    if item == listItem {
      foundAt = index
      break
    }
  }
  list.items = append([]string {item}, list.items[0:foundAt]...)
}

// Get returns an item by its index in the list
func (list *RecentlyUsedList) Get(index uint) string {
  return list.items[index]
}
