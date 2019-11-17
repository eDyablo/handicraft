package rul

// RecentlyUsedList holds strings uniquely
// in Last-In-First-Out order
type RecentlyUsedList struct {
  item []string
}

// Size returns number of items in the list
func (list *RecentlyUsedList) Size() uint {
  return uint(len(list.item))
}

// Add adds an item to the list
func (list *RecentlyUsedList) Add(item string) {
  found := len(list.item)
  for i, ci := range list.item {
    if ci == item {
      found = i
      break
    }
  }
  list.item = append([]string {item}, list.item[0:found]...)
}

// Get returns an item by its index in the list
func (list *RecentlyUsedList) Get(index uint) string {
  return list.item[index]
}
