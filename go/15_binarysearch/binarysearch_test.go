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

func TestBinarySearchFirst(t *testing.T) {
	var a []int

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirst(a, 2) != 1 {
		t.Fatal(BinarySearchFirst(a, 2))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirst(a, 3) != 4 {
		t.Fatal(BinarySearchFirst(a, 3))
	}
}

func TestBinarySearchLast(t *testing.T) {
	var a []int

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLast(a, 2) != 3 {
		t.Fatal(BinarySearchLast(a, 2))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLast(a, 3) != 4 {
		t.Fatal(BinarySearchLast(a, 3))
	}
}

func TestBinarySearchFirstGT(t *testing.T) {
	var a []int

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirstGT(a, 2) != 4 {
		t.Fatal(BinarySearchFirstGT(a, 2))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirstGT(a, 1) != 1 {
		t.Fatal(BinarySearchFirstGT(a, 1))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirstGT(a, 3) != 5 {
		t.Fatal(BinarySearchFirstGT(a, 3))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchFirstGT(a, 4) != -1 {
		t.Fatal(BinarySearchFirstGT(a, 4))
	}
}

func TestBinarySearchLastLT(t *testing.T) {
	var a []int

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLastLT(a, 2) != 0 {
		t.Fatal(BinarySearchLastLT(a, 2))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLastLT(a, 1) != -1 {
		t.Fatal(BinarySearchLastLT(a, 1))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLastLT(a, 3) != 3 {
		t.Fatal(BinarySearchLastLT(a, 3))
	}

	a = []int{1, 2, 2, 2, 3, 4}
	if BinarySearchLastLT(a, 4) != 4 {
		t.Fatal(BinarySearchLastLT(a, 4))
	}
}
