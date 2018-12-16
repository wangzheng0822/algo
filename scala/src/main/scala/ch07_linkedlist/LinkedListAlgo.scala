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

  //assuming nodeA and nodeB are all sorted list in ascending order
  def mergeSortedList(nodeA: Option[Node], nodeB: Option[Node]): Option[Node] = {
    if (nodeA.isEmpty && nodeB.isEmpty) {
      return None
    }
    if (nodeA.isEmpty && nodeB.isDefined) {
      return nodeB
    }
    if (nodeA.isDefined && nodeB.isEmpty) {
      return nodeA
    }
    //now we have both nodeA and nodeB defined
    var head: Option[Node] = None
    var leftCursor = nodeA
    var rightCursor = nodeB

    //calculate head and we are sure both leftCursor and rightCursor has data
    if (leftCursor.get.data < rightCursor.get.data) {
      head = leftCursor
      leftCursor = leftCursor.get.next
    } else {
      head = rightCursor
      rightCursor = rightCursor.get.next
    }

    var mergedCursor: Option[Node] = head
    while (leftCursor.isDefined && rightCursor.isDefined) {
      if (leftCursor.get.data < rightCursor.get.data) {
        mergedCursor.get.next = leftCursor
        leftCursor = leftCursor.get.next
      } else {
        mergedCursor.get.next = rightCursor
        rightCursor = rightCursor.get.next
      }
      mergedCursor = mergedCursor.get.next
    }
    //we have loop over at least one chain
    //we just put the other chain in to the merged chain
    if (leftCursor.isDefined) {
      mergedCursor.get.next = leftCursor
    } else {
      mergedCursor.get.next = rightCursor
    }

    head
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
