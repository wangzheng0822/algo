package _2_sorts

import "testing"

func TestMergeSort(t *testing.T) {
	arr := []int{5, 4}
	MergeSort(arr)
	t.Log(arr)

	arr = []int{5, 4, 3, 2, 1}
	MergeSort(arr)
	t.Log(arr)
}
