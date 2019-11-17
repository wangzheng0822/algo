package _8_stack

import "fmt"

/*
基于链表实现的栈
*/
type node struct {
	next *node
	val  interface{}
}

type LinkedListStack struct {
	//栈顶节点
	topNode *node
}

func NewLinkedListStack() *LinkedListStack {
	return &LinkedListStack{nil}
}

func (this *LinkedListStack) IsEmpty() bool {
	return this.topNode == nil
}

func (this *LinkedListStack) Push(v interface{}) {
	this.topNode = &node{next: this.topNode, val: v}
}

func (this *LinkedListStack) Pop() interface{} {
	if this.IsEmpty() {
		return nil
	}
	v := this.topNode.val
	this.topNode = this.topNode.next
	return v
}

func (this *LinkedListStack) Top() interface{} {
	if this.IsEmpty() {
		return nil
	}
	return this.topNode.val
}

func (this *LinkedListStack) Flush() {
	this.topNode = nil
}

func (this *LinkedListStack) Print() {
	if this.IsEmpty() {
		fmt.Println("empty stack")
	} else {
		cur := this.topNode
		for nil != cur {
			fmt.Println(cur.val)
			cur = cur.next
		}
	}
}
