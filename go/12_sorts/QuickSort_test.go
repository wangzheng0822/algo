package _2_sorts

import (
	"math/rand"
	"testing"
)

func createRandomArr(length int) []int {
	arr := make([]int, length, length)
	for i := 0; i < length; i++ {
		arr[i] = rand.Intn(100)
	}
	return arr
}

func TestQuickSort(t *testing.T) {
	arr := []int{5, 4}
	QuickSort(arr)
	t.Log(arr)

	arr = createRandomArr(100)
	QuickSort(arr)
	t.Log(arr)
}
