package _9_queue

import "testing"

func TestArrayQueue_EnQueue(t *testing.T) {
	q := NewArrayQueue(5)
	q.EnQueue(1)
	q.EnQueue(2)
	q.EnQueue(3)
	q.EnQueue(4)
	q.EnQueue(5)
	q.EnQueue(6)
	t.Log(q)
}

func TestArrayQueue_DeQueue(t *testing.T) {
	q := NewArrayQueue(5)
	q.EnQueue(1)
	q.EnQueue(2)
	q.EnQueue(3)
	q.EnQueue(4)
	q.EnQueue(5)
	q.EnQueue(6)
	t.Log(q)
	q.DeQueue()
	t.Log(q)
	q.DeQueue()
	t.Log(q)
	q.DeQueue()
	t.Log(q)
	q.DeQueue()
	t.Log(q)
	q.DeQueue()
	t.Log(q)
}
