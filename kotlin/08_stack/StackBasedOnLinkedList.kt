/**
 * 基于链表实现的栈。
 *
 * Author: Zackratos
 */

class StackBasedOnLinkedList {
    
    private var top: Node? = null

    fun push(value: Int) {
        val newNode = Node(value, null)
        // 不管 top 是不是 null，都可以这么写
        newNode.next = top
        top = newNode
    }

    fun pop(): Int {
        if (top == null) return -1
        val node = top
        top = top!!.next
        return node!!.data
    }

    fun printAll() {
        var p = top
        while (p != null) {
            print("${p.data} ")
            p = p.next
        }
        println()
    }

    class Node(var data: Int, var next: Node?)

}