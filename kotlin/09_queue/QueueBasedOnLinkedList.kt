
/**
 *
 * Desc:基于链表实现的队列
 * <p>
 * Date: 2019-12-05
 * Author: pengyushan
 */
class QueueBasedOnLinkedList {
    // 队列的队首和队尾
    private var head: Node? = null
    private var tail: Node? = null
    // 入队
    fun enqueue(value: String) {
        if (tail == null) {
            val newNode =
                Node(value, null)
            head = newNode
            tail = newNode
        } else {
            tail!!.next = Node(value, null)
            tail = tail!!.next
        }
    }

    // 出队
    fun dequeue(): String? {
        if (head == null) return null
        val value = head!!.data
        head = head!!.next
        if (head == null) {
            tail = null
        }
        return value
    }

    fun printAll() {
        var p = head
        while (p != null) {
            print("${p.data} ")
            p = p.next
        }
        println()
    }

    private class Node(
        val data: String,
        var next: Node?
    )
}