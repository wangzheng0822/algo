package ch09_queue

class ArrayQueueTest extends DemoQueueTest {

  override def getInstance() = new ArrayQueue[Int](15)
}
