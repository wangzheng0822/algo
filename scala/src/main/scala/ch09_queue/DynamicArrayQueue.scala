package ch09_queue

import scala.reflect.ClassTag

class DynamicArrayQueue[T: ClassTag](val capacity: Int) extends ArrayQueue[T](capacity) {

  override def enqueue(data: T): Unit = {
    if (tail == capacity) {
      //tail is the end of
      require(head > 0, "queue is full")
      for (i <- Range(head, tail)) {
        items(i - head) = items(head)
      }
      tail = tail - head
      head = 0
    }
    super.enqueue(data)
  }
}
