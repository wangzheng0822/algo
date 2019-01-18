package ch08_stack

class Node[T](var data: T, var next: Option[Node[T]])

class StackDemo[T] {


  var headOpt: Option[Node[T]] = None
  var size = 0

  def clear(): Unit = {
    headOpt = None
    size = 0
  }

  def push(data: T) = {
    val newHead = new Node(data, headOpt)
    headOpt = Some(newHead)
    size += 1
  }

  def pop(): Option[Node[T]] = {
    headOpt match {
      case None => None
      case Some(head) =>
        headOpt = head.next
        size -= 1
        Some(head)

    }
  }
}
