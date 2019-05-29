package LinearSort

import "testing"

func TestBucketSort(t *testing.T) {
	a := []int{1,6,3,5,8,6,4}
	BucketSort(a)
	t.Log(a)
}

func TestBucketSortSimple(t *testing.T) {
	a := []int{1,6,3,5,8,6,4}
	BucketSortSimple(a)
	t.Log(a)
}
