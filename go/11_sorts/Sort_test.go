package _1_sorts

import (
	"testing"
)

func TestBubbleSort(t *testing.T) {
	a := []int{5, 4, 3, 2, 1}
	BubbleSort(a)
	t.Log(a)
}

func TestSelectionSort(t *testing.T) {
	a := []int{5, 4, 3, 2, 1}
	SelectionSort(a)
	t.Log(a)
}
func TestInsertSort(t *testing.T) {
	a := []int{5, 4, 3, 2, 1}
	InsertSort(a)
	t.Log(a)
}

func BenchmarkBubbleSort(b *testing.B) {
	a := []int{5, 4, 3, 2, 1}
	for i := 0; i < b.N; i++ {
		BubbleSort(a)
	}
}

func BenchmarkSelectionSort(b *testing.B) {
	a := []int{5, 4, 3, 2, 1}
	for i := 0; i < b.N; i++ {
		SelectionSort(a)
	}
}

func BenchmarkInsertSort(b *testing.B) {
	a := []int{5, 4, 3, 2, 1}
	for i := 0; i < b.N; i++ {
		InsertSort(a)
	}
}
