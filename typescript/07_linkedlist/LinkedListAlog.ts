/**
 * 单链表的常见操作包括
 * 链表反转
 * 链表中环的检测
 * 有序链表的合并
 * 删除链表倒数第n个节点
 * 链表中间节点
 */
class LinkedListAlog {
  /**
   * 反转链表,依次将节点插入到头部
   * @param list
   */
  public static reverse<T>(list: SingleNode<T>): SingleNode<T> | null {
    let currentNode: SingleNode<T> | null = list
    let prevNode = null
    while (currentNode) {
      const nextNode: SingleNode<T> | null = currentNode.next
      currentNode.next = prevNode
      prevNode = currentNode
      currentNode = nextNode
    }
    return prevNode
  }

  /**
   * 通过快慢指针来检测是否为一个环
   * @param list
   */
  public static checkCircle<T>(list: SingleNode<T>): boolean {
    if (!list) return false
    let fast: SingleNode<T> | null = list.next
    let slow: SingleNode<T> | null = list
    while (fast && fast.next) {
      fast = fast.next.next
      slow = slow!.next
      if (fast === slow) return true
    }
    return false
  }

  /**
   * 倒序删除节点
   * @param list
   * @param index
   */
  public static removeFromEnd<T>(list: SingleNode<T>, index: number): SingleNode<T> | null {
    // 如果是个环，就没必要找了
    if (this.checkCircle(list)) return list
    let newNode = this.reverse(list)
    let preNode = null
    let pos = 0
    while (newNode && pos !== index) {
      newNode = newNode.next
      pos++
      preNode = newNode
    }
    if (!newNode) return null
    if (preNode) {
      preNode.next = newNode.next
    }
    return this.reverse(newNode)
  }

  public static findMidNode<T>(list: SingleNode<T>): SingleNode<T> | null {
    if (!list) return null
    let fast = list.next
    let slow = list
    while (fast && fast.next) {
      fast = fast.next.next
      slow = slow.next!
    }
    return slow
  }

  /**
   * 有序链表的合并，根据不同的值进行插入
   * @param a
   * @param b
   */
  public static mergeSortedLists<T>(a: SingleNode<T>, b: SingleNode<T>): SingleNode<T> | null {
    if (!a || !b) return a ? a : b
    let p: SingleNode<T> | null = a
    let q: SingleNode<T> | null = b
    // 新链表的头部指针
    let newList: SingleNode<T> | null = null
    if (p.value < q.value) {
      newList = p
      p = p.next
    } else {
      newList = q
      q = q.next
    }
    let currNode = newList
    while (p && q) {
      if (p.value < q.value) {
        currNode.next = p
        p = p.next
      } else {
        currNode.next = q
        q = q.next
      }
      currNode = currNode.next
    }
    if (p) {
      currNode.next = p
    } else {
      currNode.next = q
    }
    return newList
  }
}

class SingleNode<T> {
  public value: T
  public next: SingleNode<T> | null

  constructor(value: T, next: SingleNode<T> | null = null) {
    this.value = value
    this.next = next
  }
}

const node1 = new SingleNode(1)
node1.next = new SingleNode(3)
node1.next.next = new SingleNode(5)

const node2 = new SingleNode(2)
node2.next = new SingleNode(7)
node2.next.next = new SingleNode(8)
node2.next.next.next = new SingleNode(10)

console.log(LinkedListAlog.findMidNode(node1))
