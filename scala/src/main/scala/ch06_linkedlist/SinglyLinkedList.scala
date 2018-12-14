package ch06_linkedlist

// the model class for the linked list
class Node(var data: Int, var next: Option[Node])

class SinglyLinkedList(var headOpt: Option[Node]) {

  //define constructor without param
  def this() = this(None)


  def findByValue(value: Int): Option[Node] = {
    headOpt.flatMap(head => {
      var node = head
      while (!node.data.equals(value) && node.next.nonEmpty) {
        node = node.next.get
      }

      if (node.data.equals(value)) {
        return Some(node)
      } else {
        //arrive the end of the chain
        return None
      }
    })
  }

  def insertToHead(value: Int): Unit = {
    val newNode = new Node(value, None)
    insertToHead(newNode)
  }

  def insertToHead(newNode: Node): Unit = {
    headOpt match {
      case None =>
        //it's an empty linked list, make new node as head
        headOpt = Some(newNode)
      case Some(head) =>
        newNode.next = Some(head)
        headOpt = Some(newNode)
    }
  }

  def insertTail(value: Int): Unit = {
    val newNode = new Node(value, None)
    insertTail(newNode)
  }

  def insertTail(newNode: Node): Unit = {
    headOpt match {
      case None =>
        //it's an empty linked list, make new node as head
        headOpt = Some(newNode)
      case Some(head) =>
        //need to start to find from head to current tail
        var node = head
        while (node.next.nonEmpty) {
          node = node.next.get
        }
        //now node is the tail as node.next is None
        //add new tail
        node.next = Some(newNode)
    }
  }

  def insertAfter(existNode: Node, value: Int): Unit = {
    val newNode = new Node(value, None)
    insertAfter(existNode, newNode)
  }

  def insertAfter(existNode: Node, newNode: Node): Unit = {
    existNode.next match {
      case None =>
        //exist node is tail
        newNode.next = None
        existNode.next = Some(newNode)
      case Some(next) =>
        newNode.next = Some(next)
        existNode.next = Some(newNode)
    }
  }

  def insertBefore(existNode: Node, value: Int): Unit = {
    val newNode = new Node(value, None)
    insertBefore(existNode, newNode)
  }

  def insertBefore(existNode: Node, newNode: Node): Unit = {
    headOpt match {
      case None =>
        throw new IllegalStateException("head node should not be None")
      case Some(head) =>
        if (existNode.equals(head)) {
          insertToHead(newNode)
        }
        var node = head
        while (node.next.nonEmpty && !node.next.get.equals(existNode)) {
          node = node.next.get
        }

        if (node.next.isEmpty) {
          throw new IllegalArgumentException("existNode " + existNode + " does not exist in this chain")
        }

        newNode.next = node.next
        node.next = Some(newNode)
    }
  }

  def deleteByNode(node: Node): Unit = {
    headOpt.map(head => {
      if (head.equals(node)) {
        //deleting head
        headOpt = node.next
      } else {
        var p: Node = head
        while (p.next.isDefined && !p.next.get.equals(node)) {
          p = p.next.get
        }

        if (p.next.isEmpty) {
          throw new IllegalArgumentException("could not find given node")
        }
        p.next = node.next
      }

    })
  }

  def mkString(): String = {
    headOpt.map(head => {
      var node = head
      val result = new StringBuilder

      while (node.next.nonEmpty) {
        result.append(node.data)
        node = node.next.get
      }
      result.append(node.data)

      result.mkString
    }).getOrElse("")
  }

}
