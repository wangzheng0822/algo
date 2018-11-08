package _4_sorts

import "testing"

func TestCountingSort(t *testing.T) {
	arr := []int{5, 4}
	CountingSort(arr, len(arr))
	t.Log(arr)

	arr = []int{5, 4, 3, 2, 1}
	CountingSort(arr, len(arr))
	t.Log(arr)
}
