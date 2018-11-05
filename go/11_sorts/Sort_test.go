package _1_sorts

import (
	"fmt"
	"testing"
)

func TestBubbleSort(t *testing.T) {
	arr := []int{1,5,9,6,3,7,5,10}
	fmt.Println("排序前：",arr)
	BubbleSort(arr,len(arr))
	fmt.Println("排序后：",arr)
}

func TestInsertionSort(t *testing.T) {
	arr := []int{1,5,9,6,3,7,5,10}
	fmt.Println("排序前：",arr)
	InsertionSort(arr,len(arr))
	fmt.Println("排序后：",arr)
}

func TestSelectionSort(t *testing.T) {
	arr := []int{1,5,9,6,3,7,5,10}
	fmt.Println("排序前：",arr)
	SelectionSort(arr,len(arr))
	fmt.Println("排序后：",arr)
}
