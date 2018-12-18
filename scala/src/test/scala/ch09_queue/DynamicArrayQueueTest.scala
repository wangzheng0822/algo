package ch09_queue

class DynamicArrayQueueTest extends DemoQueueTest {

  override def getInstance(): DemoQueue[Int] = new DynamicArrayQueue[Int](15)

  it should "copy data when tail reach the end of the queue" in {
    val queue = getInstance()
    for (i <- Range(0, 15)) {
      queue.enqueue(i)
    }
    queue.size should equal(15)
    queue.dequeue().get should equal(0)

    //enqueue another one
    queue.enqueue(30)
    queue.size should equal(15)

  }
}
