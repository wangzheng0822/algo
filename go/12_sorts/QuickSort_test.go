package _2_sorts

import "testing"

func TestQuickSort(t *testing.T) {
	arr := []int{5, 4}
	QuickSort(arr)
	t.Log(arr)

	arr = []int{5, 4, 3, 2, 1}
	QuickSort(arr)
	t.Log(arr)
}
