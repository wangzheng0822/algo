/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool  {
		var slow *ListNode = head
		var fast *ListNode = head
		var prev *ListNode = nil
		var temp *ListNode = nil
	
		if (head == nil || head.Next == nil) {
			return true
		}
	
		for (fast != nil && fast.Next !=nil){
			fast = fast.Next.Next
			temp = slow.Next
			slow.Next = prev
			prev = slow
			slow = temp
		}							// 快的先跑完,同时反转了一半链表,剪短
	
		if fast != nil {
			slow = slow.Next		// 处理余数,跨过中位数
                                    // prev 增加中 2->1->nil
		}
	
		var l1 *ListNode = prev
		var l2 *ListNode = slow
	
		for (l1 != nil && l2 !=nil && l1.Val == l2.Val){
			l1 = l1.Next
			l2 = l2.Next
		}
	
		return (l1 == nil && l2 == nil)
	
	}
