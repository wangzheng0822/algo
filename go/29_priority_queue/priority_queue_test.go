package pqueue

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_Push(t *testing.T) {
	queue := NewPriorityQueue(100)

	queue.Push(Node{0, 1})
	assert.Equal(t, 0, queue.Top().value)

	queue.Push(Node{3, 1})
	assert.Equal(t, 0, queue.Top().value)

	queue.Push(Node{3, 2})
	assert.Equal(t, 3, queue.Top().value)

	queue.Push(Node{6, 6})
	assert.Equal(t, 6, queue.Top().value)

	queue.Push(Node{12, 5})
	assert.Equal(t, 6, queue.Top().value)

	queue.Push(Node{13, 8})
	assert.Equal(t, 13, queue.Top().value)
}

func Test_PushPop(t *testing.T) {
	queue := NewPriorityQueue(100)

	queue.Push(Node{0, 1})
	queue.Push(Node{3, 1})
	queue.Push(Node{3, 2})
	queue.Push(Node{6, 6})
	queue.Push(Node{12, 5})
	queue.Push(Node{13, 8})
	assert.Equal(t, 13, queue.Top().value)

	assert.Equal(t, 13, queue.Pop().value)
	assert.Equal(t, 6, queue.Pop().value)
	assert.Equal(t, 12, queue.Top().value)
	assert.Equal(t, 12, queue.Pop().value)

	queue.Push(Node{24, 8})
	assert.Equal(t, 24, queue.Top().value)
}

// 无法保证入队顺序和出队顺序的一致性
// func Test_PushPop_Equal(t *testing.T) {
// 	queue := NewPriorityQueue(9)

// 	queue.Push(Node{0, 1})  // 8
// 	queue.Push(Node{3, 1})  // 9
// 	queue.Push(Node{3, 2})  // 3
// 	queue.Push(Node{6, 2})  // 4
// 	queue.Push(Node{11, 3}) // 2
// 	queue.Push(Node{12, 2}) // 5
// 	queue.Push(Node{13, 2}) // 6
// 	queue.Push(Node{19, 5}) // 1
// 	queue.Push(Node{17, 2}) // 7

// 	assert.Equal(t, 19, queue.Pop().value)
// 	assert.Equal(t, 11, queue.Pop().value)
// 	assert.Equal(t, 3, queue.Pop().value)
// 	assert.Equal(t, 6, queue.Pop().value)
// 	assert.Equal(t, 12, queue.Pop().value)
// 	assert.Equal(t, 13, queue.Pop().value)
// 	assert.Equal(t, 17, queue.Pop().value)
// 	assert.Equal(t, 0, queue.Pop().value)
// 	assert.Equal(t, 3, queue.Pop().value)
// }
