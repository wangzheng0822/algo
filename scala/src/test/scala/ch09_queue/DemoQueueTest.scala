package ch09_queue

import org.scalatest.{FlatSpec, Matchers}

abstract class DemoQueueTest extends FlatSpec with Matchers {

  def getInstance(): DemoQueue[Int]

  behavior of "test"

  it should "dequeue nothing for empty queue" in {
    val queue = getInstance()
    assert(queue.dequeue().isEmpty)
  }

  it should "enqueue/dequeue should be FIFO" in {
    val queue = getInstance()
    for (i <- Range(0, 10)) {
      queue.enqueue(i)
    }

    queue.size should equal(10)

    for (i <- Range(0, 10)) {
      queue.dequeue().get should equal(i)
    }
  }
}
