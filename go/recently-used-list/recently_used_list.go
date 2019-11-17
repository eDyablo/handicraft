package rul

// RecentlyUsedList holds strings uniquely
// in Last-In-First-Out order
type RecentlyUsedList struct {
  item []string
}

// Size returns the count of items in the list
func (list *RecentlyUsedList) Size() uint {
  return 0
}

// Add adds an item to the list
func (list *RecentlyUsedList) Add(item string) {
  list.item = append([]string {item}, list.item...)
}

// Get returns an item by its index in the list
func (list *RecentlyUsedList) Get(index uint) string {
  return list.item[index]
}
