package _7_linkedlist

import "fmt"

//单链表节点
type ListNode struct {
	next  *ListNode
	value interface{}
}

//单链表
type LinkedList struct {
	head *ListNode
}

//打印链表
func (this *LinkedList) Print() {
	cur := this.head.next
	format := ""
	for nil != cur {
		format += fmt.Sprintf("%+v", cur.value)
		cur = cur.next
		if nil != cur {
			format += "->"
		}
	}
	fmt.Println(format)
}

/*
单链表反转
时间复杂度：O(N)
*/
func (this *LinkedList) Reverse() {
	if nil == this.head || nil == this.head.next || nil == this.head.next.next {
		return
	}

	var pre *ListNode = nil
	cur := this.head.next
	for nil != cur {
		tmp := cur.next
		cur.next = pre
		pre = cur
		cur = tmp
	}

	this.head.next = pre
}

/*
判断单链表是否有环
*/
func (this *LinkedList) HasCycle() bool {
	if nil != this.head {
		slow := this.head
		fast := this.head
		for nil != fast && nil != fast.next {
			slow = slow.next
			fast = fast.next.next
			if slow == fast {
				return true
			}
		}
	}
	return false
}

/*
两个有序单链表合并
*/
func MergeSortedList(l1, l2 *LinkedList) *LinkedList {
	if nil == l1 || nil == l1.head || nil == l1.head.next {
		return l2
	}
	if nil == l2 || nil == l2.head || nil == l2.head.next {
		return l1
	}

	l := &LinkedList{head: &ListNode{}}
	cur := l.head
	curl1 := l1.head.next
	curl2 := l2.head.next
	for nil != curl1 && nil != curl2 {
		if curl1.value.(int) > curl2.value.(int) {
			cur.next = curl2
			curl2 = curl2.next
		} else {
			cur.next = curl1
			curl1 = curl1.next
		}
		cur = cur.next
	}

	if nil != curl1 {
		cur.next = curl1
	} else if nil != curl2 {
		cur.next = curl2
	}

	return l
}

/*
删除倒数第N个节点
*/
func (this *LinkedList) DeleteBottomN(n int) {
	if n <= 0 || nil == this.head || nil == this.head.next {
		return
	}

	fast := this.head
	for i := 1; i <= n && fast != nil; i++ {
		fast = fast.next
	}

	if nil == fast {
		return
	}

	slow := this.head
	for nil != fast.next {
		slow = slow.next
		fast = fast.next
	}
	slow.next = slow.next.next
}

/*
获取中间节点
*/
func (this *LinkedList) FindMiddleNode() *ListNode {
	if nil == this.head || nil == this.head.next {
		return nil
	}
	if nil == this.head.next.next {
		return this.head.next
	}

	slow, fast := this.head, this.head
	for nil != fast && nil != fast.next {
		slow = slow.next
		fast = fast.next.next
	}
	return slow
}
