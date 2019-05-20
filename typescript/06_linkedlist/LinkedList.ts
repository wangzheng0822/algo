/**
 * 双向链表，更加常用设计也更加复杂一些
 * 需要更多的存储空间和操作复杂度
 */
import List from './List'

class LinkedList<T> implements List<T> {
  size: number = 0
  private head: LinkedListNode<T> | null = null
  private last: LinkedListNode<T> | null = null

  findByIndex(index: number): LinkedListNode<T> | null {
    let p = this.head
    let pos = 0
    while (p && pos !== index) {
      p = p.next
      pos++
    }
    return p
  }

  findByValue(value: T): LinkedListNode<T> | null {
    let p = this.head
    while (p && p.item !== value) {
      p = p.next
    }
    return p
  }

  insertToHead(value: T): void {
    let p = this.head
    const newNode = new LinkedListNode(value)
    // 没有元素的时候需要初始化头节点和尾节点
    if (!p) {
      this.last = this.head = newNode
    } else {
      p.prev = newNode
      newNode.next = p
      this.head = newNode
    }
    this.size++
  }

  /**
   * 在指定的index后面插入节点
   * @param value 节点的值
   * @param index 指定的位置
   */
  insertToIndex(value: T, index: number): void {
    let p = this.head
    let pos = 0
    const newNode = new LinkedListNode(value)
    while (p !== null && pos !== index) {
      p = p.next
      pos++
    }
    if (p === null) return
    newNode.next = p.next
    p.next = newNode
    newNode.prev = p
    this.size++
  }

  insertToTail(value: T): void {
    let p = this.last
    const newNode = new LinkedListNode(value)
    if (p === null) {
      this.head = this.last = newNode
    } else {
      p.next = newNode
      newNode.prev = p
      this.last = newNode
    }

    this.size++
  }

  remove(value: T): boolean {
    let p = this.head
    while (p && p.item !== value) {
      p = p.next
    }
    if (!p) return false
    if (p.prev) {
      p.prev.next = p.next
    } else {
      this.head = p.next
    }
    if (p.next) {
      p.next.prev = p.prev
    } else {
      this.last = p.prev
    }
    this.size--
    return true
  }

  toString(): string {
    let ret: string = ''
    let p = this.head
    while (p) {
      ret = `${ret} ${p.item} `
      p = p.next
    }
    return ret
  }
}

class LinkedListNode<T> {
  item: T
  next: LinkedListNode<T> | null
  prev: LinkedListNode<T> | null

  constructor(
    item: T,
    next: LinkedListNode<T> | null = null,
    prev: LinkedListNode<T> | null = null
  ) {
    this.item = item
    this.next = next
    this.prev = prev
  }
}

const linkedList = new LinkedList()
linkedList.insertToHead('12')
linkedList.insertToHead('haha')
linkedList.insertToHead('www')
linkedList.insertToTail('zxc')
linkedList.insertToIndex('12ooo', 0)
linkedList.remove('12oooo')
console.log(linkedList.toString())
