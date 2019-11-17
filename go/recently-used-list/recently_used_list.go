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
  if item == "" { return }
  size := uint(len(list.items))
  foundAt := list.find(item)
  restAt := foundAt + 1
  if restAt > size { restAt = size }
  list.items = append([]string {item},
    append(list.items[0:foundAt], list.items[restAt:]...)...)
}

// Get returns an item by its index in the list
func (list *RecentlyUsedList) Get(index uint) string {
  return list.items[index]
}

func (list *RecentlyUsedList) find(item string) uint {
  foundAt := len(list.items)
  for index, listItem := range list.items {
    if item == listItem {
      foundAt = index
      break
    }
  }
  return uint(foundAt)
}
