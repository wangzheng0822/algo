/**
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第n个结点
 * 5) 求链表的中间结点
 *
 * Author: Zackratos
 */

object LinkedListAlgo {

    // 单链表反转
    fun reverse(list: Node): Node? {
        var curr: Node? = list
        var pre: Node? = null
        while (curr != null) {
            val next = curr.next
            curr.next = pre
            pre = curr
            curr = next
        }
        return pre
    }

    // 检测环
    fun checkCircle(list: Node): Boolean {
        var fast = list.next
        var slow: Node? = list
        while (fast != null && slow != null) {
            fast = fast.next?.next
            slow = slow.next
            if (fast === slow)
                return true
        }

        return false
    }

    // 有序链表合并
    fun mergeSortedLists(la: Node, lb: Node): Node? {
        var p: Node? = la
        var q: Node? = lb
        val head: Node?
        if (p?.data ?: 0 < q?.data ?: 0) {
            head = p
            p = p?.next
        } else {
            head = q
            q = q?.next
        }
        var r = head
        while (p != null && q != null) {
            if (p.data < q.data) {
                r?.next = p
                p = p.next
            } else {
                r?.next = q
                q = q.next
            }
            r = r?.next
        }
        if (p != null) {
            r?.next = p
        } else {
            r?.next = q
        }
        return head
    }

    // 删除倒数第 k 个结点
    fun deleteLastKth(list: Node, k: Int): Node? {
        var fast: Node? = list
        var i = 1
        while (fast != null && i < k) {
            fast = fast.next
            i++
        }
        if (fast == null) {
            return when (i) {
                k -> list.next
                else -> list
            }
        }
        var slow: Node? = list
        var pre: Node? = null
        while (fast != null) {
            fast = fast.next
            pre = slow
            slow = slow?.next
        }
        pre?.next = pre?.next?.next
        return list
    }

    // 求中间结点
    fun findMiddleNode(list: Node): Node? {
        var fast: Node? = list
        var slow: Node? = list
        while (fast?.next != null && fast.next?.next != null) {
            fast = fast.next?.next
            slow = slow?.next
        }
        return slow
    }

    class Node(var data: Int, var next: Node?)
}