/**
 * 1）单链表的插入、删除、查找操作；
 * 2）链表中存储的是int类型的数据；
 *
 * Author：Zackratos
 */

class SinglyLinkedList {

    private var head: Node? = null

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            val link = SinglyLinkedList()
            println("hello")
            val data = intArrayOf(1, 2, 5, 3, 1)

            for (i in data.indices) {
                //link.insertToHead(data[i]);
                link.insertTail(data[i])
            }

            println("打印原始:")
            link.printAll()
            if (link.palindrome()) {
                println("回文")
            } else {
                println("不是回文")
            }
        }
    }

    fun findByValue(value: Int): Node? {
        var p = head
        while (p != null && p.data != value) {
            p = p.next
        }

        return p
    }

    fun findByIndex(index: Int): Node? {
        var p = head
        var pos = 0
        while (p != null && pos != index) {
            p = p.next
            ++pos
        }

        return p
    }

    //无头结点
    //表头部插入
    //这种操作将于输入的顺序相反，逆序
    fun insertToHead(value: Int) {
        val newNode = Node(value, null)
        insertToHead(newNode)
    }

    fun insertToHead(newNode: Node) {
        if (head == null) {
            head = newNode
        } else {
            newNode.next = head
            head = newNode
        }
    }

    //顺序插入
    //链表尾部插入
    fun insertTail(value: Int) {

        val newNode = Node(value, null)
        //空链表，可以插入新节点作为head，也可以不操作
        if (head == null) {
            head = newNode

        } else {
            var q = head
            while (q?.next != null) {
                q = q.next
            }
            newNode.next = q?.next
            q?.next = newNode
        }
    }

    fun insertAfter(p: Node?, value: Int) {
        val newNode = Node(value, null)
        insertAfter(p, newNode)
    }

    fun insertAfter(p: Node?, newNode: Node) {
        if (p == null) return

        newNode.next = p.next
        p.next = newNode
    }

    fun insertBefore(p: Node?, value: Int) {
        val newNode = Node(value, null)
        insertBefore(p, newNode)
    }

    fun insertBefore(p: Node?, newNode: Node) {
        if (p == null) return
        if (head === p) {
            insertToHead(newNode)
            return
        }

        var q = head
        while (q != null && q.next !== p) {
            q = q.next
        }

        if (q == null) {
            return
        }

        newNode.next = p
        q.next = newNode

    }

    fun deleteByNode(p: Node?) {
        if (p == null || head == null) return

        if (p === head) {
            head = head?.next
            return
        }

        var q = head
        while (q != null && q.next !== p) {
            q = q.next
        }

        if (q == null) {
            return
        }

        q.next = q.next?.next
    }

    fun deleteByValue(value: Int) {
        if (head == null) return

        var p = head
        var q: Node? = null
        while (p != null && p.data != value) {
            q = p
            p = p.next
        }

        if (p == null) return

        if (q == null) {
            head = head?.next
        } else {
            q.next = q.next?.next
        }
    }

    fun printAll() {
        var p = head
        while (p != null) {
            print("${p.data} ")
            p = p.next
        }
        println()
    }

    //判断true or false
    fun TFResult(left: Node?, right: Node?): Boolean {
        var l: Node? = left
        var r: Node? = right

        println("left_:${l?.data}")
        println("right_:${r?.data}")
        while (l != null && r != null) {
            if (l.data == r.data) {
                l = l.next
                r = r.next
                continue
            } else {
                break
            }

        }

        println("什么结果")
        return l == null && r == null
    }

    //　判断是否为回文
    fun palindrome(): Boolean {
        if (head == null) {
            return false
        } else {
            println("开始执行找到中间节点")
            var p = head
            var q = head
            if (p?.next == null) {
                println("只有一个元素")
                return true
            }
            while (q?.next != null && q.next?.next != null) {
                p = p?.next
                q = q.next?.next
            }

            println("中间节点${p?.data}")
            println("开始执行奇数节点的回文判断")
            val leftLink: Node?
            val rightLink: Node?
            if (q?.next == null) {
                //　p 一定为整个链表的中点，且节点数目为奇数
                rightLink = p?.next
                leftLink = inverseLinkList(p)?.next
                println("左边第一个节点${leftLink?.data}")
                println("右边第一个节点${rightLink?.data}")

            } else {
                //p q　均为中点
                rightLink = p?.next
                leftLink = inverseLinkList(p)
            }
            return TFResult(leftLink, rightLink)

        }
    }

    //带结点的链表翻转
    fun inverseLinkList_head(p: Node): Node {
        //　Head　为新建的一个头结点
        val Head = Node(9999, null)
        // p　为原来整个链表的头结点,现在Head指向　整个链表
        Head.next = p
        /*
        带头结点的链表翻转等价于
        从第二个元素开始重新头插法建立链表
        */
        var Cur = p.next
        p.next = null
        var next: Node?

        while (Cur != null) {
            next = Cur.next
            Cur.next = Head.next
            Head.next = Cur
            println("first " + Head.data)

            Cur = next
        }

        //　返回左半部分的中点之前的那个节点
        //　从此处开始同步像两边比较
        return Head

    }

    //无头结点的链表翻转
    fun inverseLinkList(p: Node?): Node? {

        var pre: Node? = null
        var r = head
        println("z---${r?.data}")
        var next: Node?
        while (r !== p) {
            next = r?.next

            r?.next = pre
            pre = r
            r = next
        }

        r?.next = pre
        //　返回左半部分的中点之前的那个节点
        //　从此处开始同步像两边比较
        return r

    }

    fun createNode(value: Int): Node = Node(value, null)



    class Node(var data: Int, var next: Node?)
}