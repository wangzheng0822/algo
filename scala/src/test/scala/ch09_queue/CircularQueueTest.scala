package ch09_queue

class CircularQueueTest extends DemoQueueTest {

  override def getInstance(): DemoQueue[Int] = new CircularQueue[Int](15)
}
