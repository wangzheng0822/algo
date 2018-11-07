package _7_linkedlist

import "testing"

var l *LinkedList

func init() {
	n5 := &ListNode{value: 5}
	n4 := &ListNode{value: 4, next: n5}
	n3 := &ListNode{value: 3, next: n4}
	n2 := &ListNode{value: 2, next: n3}
	n1 := &ListNode{value: 1, next: n2}
	l = &LinkedList{head: &ListNode{next: n1}}
}

func TestReverse(t *testing.T) {
	l.Print()
	l.Reverse()
	l.Print()
}

func TestHasCycle(t *testing.T) {
	t.Log(l.HasCycle())
	l.head.next.next.next.next.next.next = l.head.next.next.next
	t.Log(l.HasCycle())
}

func TestMergeSortedList(t *testing.T) {
	n5 := &ListNode{value: 9}
	n4 := &ListNode{value: 7, next: n5}
	n3 := &ListNode{value: 5, next: n4}
	n2 := &ListNode{value: 3, next: n3}
	n1 := &ListNode{value: 1, next: n2}
	l1 := &LinkedList{head: &ListNode{next: n1}}

	n10 := &ListNode{value: 10}
	n9 := &ListNode{value: 8, next: n10}
	n8 := &ListNode{value: 6, next: n9}
	n7 := &ListNode{value: 4, next: n8}
	n6 := &ListNode{value: 2, next: n7}
	l2 := &LinkedList{head: &ListNode{next: n6}}

	MergeSortedList(l1, l2).Print()
}

func TestDeleteBottomN(t *testing.T) {
	l.Print()
	l.DeleteBottomN(3)
	l.Print()
}

func TestFindMiddleNode(t *testing.T) {
	l.DeleteBottomN(1)
	l.DeleteBottomN(1)
	l.DeleteBottomN(1)
	l.DeleteBottomN(1)
	l.Print()
	t.Log(l.FindMiddleNode())
}
