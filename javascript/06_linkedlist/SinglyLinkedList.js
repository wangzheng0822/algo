/**
 * 1）单链表的插入、删除、查找操作；
 * 2）链表中存储的是int类型的数据；
 */
class Node {
  constructor (element) {
    this.element = element
    this.next = null
  }
}

class LinkedList {
  constructor () {
    this.head = new Node('head')
  }
  // 根据value查找节点
  findByValue (item) {
    let currentNode = this.head
    while (currentNode !== null && currentNode.element !== item) {
      currentNode = currentNode.next
    }
    console.log(currentNode)
    return currentNode === null ? -1 : currentNode
  } 
  
  // 根据index查找节点
  findByIndex (index) {
    let currentNode = this.head
    let pos = 0
    while (currentNode !== null && pos !== index) {
      currentNode = currentNode.next
      pos++
    }
    console.log(currentNode)
    return currentNode === null ? -1 : currentNode
  } 
  
  // 指定元素向后插入
  insert (newElement, element) {
    const currentNode = this.findByValue(element)
    if (currentNode === -1) {
      console.log('未找到插入位置')
      return
    }
    const newNode = new Node(newElement)
    newNode.next = currentNode.next
    currentNode.next = newNode
  } 
  
  // 查找前一个
  findPrev (item) {
    let currentNode = this.head
    while (currentNode.next !== null && currentNode.next.element !== item) {
      currentNode = currentNode.next
    }
    if (currentNode.next === null) {
      return -1
    }
    return currentNode
  } 
  
  // 根据值删除
  remove (item) {
    const desNode = this.findByValue(item)
    if (desNode === -1) {
      console.log('未找到元素')
      return
    }
    const prevNode = this.findPrev(item)
    prevNode.next = desNode.next
  } 
  
  // 遍历显示所有节点
  display () {
    let currentNode = this.head
    while (currentNode !== null) {
      console.log(currentNode.element)
      currentNode = currentNode.next
    }
  }
}
// Test
const LList = new LinkedList()
LList.insert('chen', 'head')
LList.insert('curry', 'chen')
LList.insert('sang', 'head')
LList.insert('zhao', 'head')
console.log('-------------remove item------------')
LList.remove('curry', 'chen')
LList.display()
console.log('-------------find by item------------')
LList.findByValue('chen')
console.log('-------------find by index------------')
LList.findByIndex(2)
