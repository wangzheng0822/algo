package ch09_queue

import scala.reflect.ClassTag

class CircularQueue[T: ClassTag](capacity: Int) extends DemoQueue[T] {

  var items: Array[T] = new Array[T](capacity)
  var head = 0
  var tail = 0


  override def enqueue(data: T): Unit = {
    require((tail + 1) % capacity != head, "queue is full")
    items(tail) = data
    tail = (tail + 1) % capacity
    size += 1
  }

  override def dequeue(): Option[T] = {
    if (head == tail) {
      None
    } else {
      size -= 1
      val result = Some(items(head))
      head = (head + 1) % capacity
      result
    }
  }
}
