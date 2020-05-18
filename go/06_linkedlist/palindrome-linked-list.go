package _6_linkedlist

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     value interface{}
 *     next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	var slow *ListNode = head.next
	var fast *ListNode = head.next
	var prev *ListNode = nil
	var temp *ListNode = nil

	if head == nil || head.next == nil {
		return true
	}

	for fast != nil && fast.next != nil {
		fast = fast.next.next
		temp = slow.next
		slow.next = prev
		prev = slow
		slow = temp
	} // 快的先跑完,同时反转了一半链表,剪短

	if fast != nil {
		slow = slow.next // 处理余数,跨过中位数
	}

	var l1 *ListNode = prev
	var l2 *ListNode = slow

	for l1 != nil && l2 != nil && l1.value == l2.value {
		l1 = l1.next
		l2 = l2.next
	}

	result := (l1 == nil && l2 == nil)

	//恢复链表
	var pp *ListNode = nil

	for prev != nil {
		pp = prev.next
		prev.next = temp
		temp = prev
		prev = pp
	}

	return result
}
