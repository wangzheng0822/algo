package _5_binarysearch

import "testing"

func TestBinarySearch(t *testing.T) {
	var a []int

	a = []int{1, 3, 5, 6, 8}
	if BinarySearch(a, 8) != 4 {
		t.Fatal(BinarySearch(a, 3))
	}
	if BinarySearch(a, 4) != -1 {
		t.Fatal(BinarySearch(a, 4))
	}
}

func TestBinarySearchRecursive(t *testing.T) {
	var a []int

	a = []int{1, 3, 5, 6, 8}
	if BinarySearchRecursive(a, 8) != 4 {
		t.Fatal(BinarySearch(a, 3))
	}
	if BinarySearchRecursive(a, 4) != -1 {
		t.Fatal(BinarySearch(a, 4))
	}
}
