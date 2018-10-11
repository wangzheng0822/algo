package _9_queue

import "fmt"

type CircularQueue struct {
	q        []interface{}
	capacity int
	head     int
	tail     int
}

func NewCircularQueue(n int) *CircularQueue {
	if n == 0 {
		return nil
	}
	return &CircularQueue{make([]interface{}, n), n, 0, 0}
}

/*
栈空条件：head==tail为true
*/
func (this *CircularQueue) IsEmpty() bool {
	if this.head == this.tail {
		return true
	}
	return false
}

/*
栈满条件：(tail+1)%capacity==head为true
*/
func (this *CircularQueue) IsFull() bool {
	if this.head == (this.tail+1)%this.capacity {
		return true
	}
	return false
}

func (this *CircularQueue) EnQueue(v interface{}) bool {
	if this.IsFull() {
		return false
	}
	this.q[this.tail] = v
	this.tail = (this.tail + 1) % this.capacity
	return true
}

func (this *CircularQueue) DeQueue() interface{} {
	if this.IsEmpty() {
		return nil
	}
	v := this.q[this.head]
	this.head = (this.head + 1) % this.capacity
	return v
}

func (this *CircularQueue) String() string {
	if this.IsEmpty() {
		return "empty queue"
	}
	result := "head"
	var i = this.head
	for true {
		result += fmt.Sprintf("<-%+v", this.q[i])
		i = (i + 1) % this.capacity
		if i == this.tail {
			break
		}
	}
	result += "<-tail"
	return result
}
