package _17_skiplist

import (
	"testing"
)

func TestSkipList(t *testing.T) {
	list := NewSkipList()
	list.Insert(1)
	list.Insert(2)
	list.Insert(3)

	if list.Find(1) == nil || list.Find(1).data != 1 {
		t.Logf("list find %d from list error, value: %v", 1, list.Find(1))
		t.FailNow()
	}

	if list.Find(2) == nil || list.Find(2).data != 2 {
		t.Logf("list find %d from list error, value: %v", 2, list.Find(2))
		t.FailNow()
	}

	if list.Find(3) == nil || list.Find(3).data != 3 {
		t.Logf("list find %d from list error, value: %v", 3, list.Find(3))
		t.FailNow()
	}

	list.Delete(3)
	if list.Find(1) == nil || list.Find(1).data != 1 {
		t.Logf("list find %d from list error, value: %v", 1, list.Find(1))
		t.FailNow()
	}

	if list.Find(2) == nil || list.Find(2).data != 2 {
		t.Logf("list find %d from list error, value: %v", 2, list.Find(2))
		t.FailNow()
	}

	if list.Find(3) != nil {
		t.Logf("list find %d from list error, expect nil, but got non-nil", 3)
		t.FailNow()
	}

}
