package pqueue

// Node 队列节点
type Node struct {
	value    int
	priority int
}

// PQueue priority queue
type PQueue struct {
	heap []Node

	capacity int
	used     int
}

// NewPriorityQueue new
func NewPriorityQueue(capacity int) PQueue {
	return PQueue{
		heap:     make([]Node, capacity+1, capacity+1),
		capacity: capacity,
		used:     0,
	}
}

// Push 入队
func (q *PQueue) Push(node Node) {

	if q.used > q.capacity {
		// 队列已满
		return
	}
	q.used++
	q.heap[q.used] = node
	// 堆化可以放在 Pop 中
	// adjustHeap(q.heap, 1, q.used)
}

// Pop 出队列
func (q *PQueue) Pop() Node {
	if q.used == 0 {
		return Node{-1, -1}
	}
	// 先堆化, 再取堆顶元素
	adjustHeap(q.heap, 1, q.used)
	node := q.heap[1]

	q.heap[1] = q.heap[q.used]
	q.used--

	return node
}

// Top 获取队列顶部元素
func (q *PQueue) Top() Node {
	if q.used == 0 {
		return Node{-1, -1}
	}

	adjustHeap(q.heap, 1, q.used)
	return q.heap[1]
}
