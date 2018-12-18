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

  /**
    *
    * @param head
    * @return Some(Node) a node in a circle or None
    */
  def checkCircle(head: Node): Option[Node] = {
    var fast = head
    var slow = head

    while (fast.next.isDefined && fast.next.get.next.isDefined) {
      fast = fast.next.get.next.get
      slow = slow.next.get

      if (fast.equals(slow)) {
        return Some(slow)
      }
    }
    None
  }

  /**
    * calculate the length of the circle
    *
    * @param node - some node in the circle
    * @return circle length
    */
  def calculateCircleLength(node: Node): Int = {
    var length = 1
    var cursor = node.next.get

    while (cursor != node) {
      length += 1
      cursor = cursor.next.get
    }

    length
  }

  def findCircleEntrance(head: Node): Option[Node] = {
    checkCircle(head).map(node => {
      val length = calculateCircleLength(node)
      var fast = head
      var slow = head
      //fast move length steps
      for (i <- 0 until length) {
        fast = fast.next.get
      }

      while (slow != fast) {
        fast = fast.next.get
        slow = slow.next.get
      }

      slow
    })
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

  def deleteLastKthNode(headOpt: Option[Node], k: Int): Option[Node] = {
    require(k > 0, "k must greater than 0")
    headOpt match {
      case None => None
      case Some(head) =>
        var index = 0
        var slow = headOpt
        var fast = headOpt
        while (fast.get.next.isDefined && index < k) {
          //move fast cursor to k
          fast = fast.get.next
          index += 1
        }

        if (fast.get.next.isEmpty && index + 1 == k) {
          //deleting the head element
          return head.next
        }

        require(index.equals(k), "given linked list should contains at least k elements ")
        while (fast.get.next.isDefined) {
          fast = fast.get.next
          slow = slow.get.next
        }

        //fast cursor is in the end of the chain
        //slow is the previous pos of k element
        //do the operation
        slow.get.next = slow.get.next.get.next
    }

    headOpt
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
