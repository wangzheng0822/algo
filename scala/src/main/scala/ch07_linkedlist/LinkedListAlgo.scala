package ch07_linkedlist

import ch06_linkedlist.Node

object LinkedListAlgo {

  //reverse a linked list
  def reverse(head: Node): Node = {
    if (head.next.isEmpty) {
      //single node of linked list
      return head
    }
    var prev: Option[Node] = None
    var current: Option[Node] = Some(head)
    var next: Option[Node] = None

    while (current.get.next.isDefined) {
      next = current.get.next
      current.get.next = prev

      prev = current
      current = next
    }
    //for the tail of the node, make it point to previous node to complete the reverse
    current.get.next = prev

    current.get
  }

  def checkCircle(head: Node): Boolean = {
    var fast = head
    var slow = head

    while (fast.next.isDefined && fast.next.get.next.isDefined) {
      fast = fast.next.get.next.get
      slow = slow.next.get

      if (fast.equals(slow)) {
        return true
      }
    }
    false
  }

  //form all the chain value as string
  def mkStringForChain(node: Node): String = {
    val result = new StringBuilder

    var p = node

    while (p.next.isDefined) {
      result.append(p.data)
      p = p.next.get
    }
    result.append(p.data)
    result.mkString
  }
}
