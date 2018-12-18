package ch09_queue

class Node[T](var data: T, var next: Option[Node[T]])

class LinkListQueue[T]() extends DemoQueue[T] {

  var headOpt: Option[Node[T]] = None
  var tailOpt: Option[Node[T]] = None

  override
  def enqueue(data: T): Unit = {
    val node = new Node(data, None)
    size += 1
    headOpt match {
      case None => headOpt = Some(node)
      case Some(_) =>
    }
    tailOpt match {
      case None => tailOpt = Some(node)
      case Some(tail) =>
        tail.next = Some(node)
        tailOpt = Some(node)
    }
  }

  override
  def dequeue(): Option[T] = {
    headOpt.map(head => {
      size -= 1
      headOpt = head.next
      if (headOpt.isEmpty) {
        //head is empty reach the end of the queue
        tailOpt = None
      }
      head.data
    })
  }

}
