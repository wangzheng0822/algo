package _9_queue

import "testing"

func TestListQueue_EnQueue(t *testing.T) {
	q := NewLinkedListQueue()
	q.EnQueue(1)
	q.EnQueue(2)
	q.EnQueue(3)
	q.EnQueue(4)
	q.EnQueue(5)
	q.EnQueue(6)
	t.Log(q)
}

func TestListQueue_DeQueue(t *testing.T) {
	q := NewLinkedListQueue()
	q.EnQueue(1)
	q.EnQueue(2)
	q.EnQueue(3)
	q.EnQueue(4)
	q.EnQueue(5)
	q.EnQueue(6)
	t.Log(q)

	// 1
	q.DeQueue()
	t.Log(q)

	// 2
	q.DeQueue()
	t.Log(q)

	// 3
	q.DeQueue()
	t.Log(q)

	// 4
	q.DeQueue()
	t.Log(q)

	// 5
	q.DeQueue()
	t.Log(q)

	// 6 note: all of the nodes are dequeue
	// head = tail = nil
	q.DeQueue()
	t.Log(q)

	// enqueue
	q.EnQueue(1)
	t.Log(q)

	// head = tail = nil
	q.DeQueue()
	t.Log(q)
}
