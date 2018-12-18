package ch09_queue

import scala.reflect.ClassTag

class ArrayQueue[T: ClassTag](capacity: Int) extends DemoQueue[T] {

  var items: Array[T] = new Array[T](capacity)
  var head = 0
  var tail = 0

  override def enqueue(data: T): Unit = {
    require(tail < capacity, "queue is full")
    items(tail) = data
    tail += 1
    size += 1
  }

  override def dequeue(): Option[T] = {
    if (head < tail) {
      val result = Some(items(head))
      head += 1
      size -= 1
      result
    } else {
      None
    }
  }
}
