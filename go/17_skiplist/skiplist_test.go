package _7_skiplist

import "testing"

func TestSkipList(t *testing.T) {
	sl := NewSkipList()

	sl.Insert("leo", 95)
	t.Log(sl.head.forwards[0])
	t.Log(sl.head.forwards[0].forwards[0])
	t.Log(sl)
	t.Log("-----------------------------")

	sl.Insert("jack", 88)
	t.Log(sl.head.forwards[0])
	t.Log(sl.head.forwards[0].forwards[0])
	t.Log(sl.head.forwards[0].forwards[0].forwards[0])
	t.Log(sl)
	t.Log("-----------------------------")

	sl.Insert("lily", 100)
	t.Log(sl.head.forwards[0])
	t.Log(sl.head.forwards[0].forwards[0])
	t.Log(sl.head.forwards[0].forwards[0].forwards[0])
	t.Log(sl.head.forwards[0].forwards[0].forwards[0].forwards[0])
	t.Log(sl)
	t.Log("-----------------------------")

	t.Log(sl.Find("jack", 88))
	t.Log("-----------------------------")

	sl.Delete("leo", 95)
	t.Log(sl.head.forwards[0])
	t.Log(sl.head.forwards[0].forwards[0])
	t.Log(sl.head.forwards[0].forwards[0].forwards[0])
	t.Log(sl)
	t.Log("-----------------------------")
}
