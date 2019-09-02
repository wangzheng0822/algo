/**
 * 1)单链表的插入、删除、查找操作；
 * 2)链表支持任意类型数据
 */
import List from './List'

class SingleLinkedList<T> implements List<T> {
  // 哨兵头节点
  private readonly head: SingleNode<T>

  constructor() {
    this.head = new SingleNode<any>(null)
  }

  public findByValue(value: T): SingleNode<T> | null {
    let p = this.head
    while (p.next != null) {
      if (p.next.value === value) return p.next
      p = p.next
    }
    return p.next
  }

  public findByIndex(index: number): SingleNode<T> | null {
    let p = this.head
    let pos = 0
    while (p.next != null && pos !== index) {
      p = p.next
      pos++
    }
    return p.next
  }

  /**
   * 向指定的位置插入节点
   * @param value
   * @param index
   */
  public insertToIndex(value: T, index: number): void {
    const newNode = new SingleNode(value)
    let p = this.head
    let pos = 0
    while (p.next != null && pos !== index) {
      p = p.next
      pos++
    }
    if (p.next == null) return
    newNode.next = p.next.next
    p.next.next = newNode
  }

  /**
   * 根据值去删除节点
   * @param value 1 表示删除成功，0 表示删除失败
   */
  public remove(value: T): boolean {
    let p = this.head
    while (p.next != null) {
      if (p.next.value === value) break
      p = p.next
    }
    if (p.next === null) return false
    p.next = p.next.next
    return true
  }

  public insertToHead(value: T): void {
    const newNode = new SingleNode(value, null)
    this.insertNodeToHead(newNode)
  }

  public insertToTail(value: T): void {
    const newNode = new SingleNode(value, null)
    this.insertNodeToTail(newNode)
  }

  private insertNodeToHead(node: SingleNode<T>): void {
    node.next = this.head.next
    this.head.next = node
  }

  public toString(): string {
    let ret: string = ''
    let p = this.head
    while (p.next != null) {
      ret = `${ret} ${p.next.value} `
      p = p.next
    }
    return ret
  }

  /**
   * 单链表的尾插入比较费时
   * @param newNode 插入的新节点
   */
  private insertNodeToTail(newNode: SingleNode<T>): void {
    let p = this.head
    while (p.next != null) {
      p = p.next
    }
    p.next = newNode
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

const singleLinkedList = new SingleLinkedList<string>()
singleLinkedList.insertToTail('god')
singleLinkedList.insertToTail('my')
// console.log(singleLinkedList.printLinkedList())
singleLinkedList.insertToIndex('haha', 1)
singleLinkedList.remove('ha1')
singleLinkedList.toString()
