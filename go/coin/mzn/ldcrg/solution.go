package ldcrg

import (
	"container/heap"
	"math"
)

type MaxIntHeap []int

func (h MaxIntHeap) Len() int                        { return len(h) }
func (h MaxIntHeap) Less(first int, second int) bool { return h[first] > h[second] }
func (h MaxIntHeap) Swap(first int, second int)      { h[first], h[second] = h[second], h[first] }
func (h *MaxIntHeap) Push(element interface{})       { *h = append(*h, element.(int)) }
func (h *MaxIntHeap) Pop() interface{} {
	origin := *h
	size := len(origin)
	top := origin[size-1]
	*h = origin[0 : size-1]
	return top
}

func min(first int, second int) int {
	return int(math.Min(float64(first), float64(second)))
}

func Solution(containers []int, items []int, cargoSize int) int {
	count := min(len(containers), len(items))
	pile := &MaxIntHeap{}
	heap.Init(pile)
	for i := 0; i < count; i++ {
		for container := 0; container < containers[i]; container++ {
			heap.Push(pile, items[i])
		}
	}
	var amount int = 0
	cargoSize = min(cargoSize, len(*pile))
	for i := 0; i < cargoSize; i++ {
		amount += heap.Pop(pile).(int)
	}
	return amount
}
