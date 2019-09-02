package ch29_heap_solutions

import scala.collection.mutable

/**
  * keep the top k items in the the class
  */
class TopKItemsKeeper(val itemsToKeepCount: Int) {


  //have a smallest value top heap
  val queue = new mutable.PriorityQueue[Int]()(scala.math.Ordering.Int.reverse)

  def put(item: Int): Unit = {
    if (queue.length < itemsToKeepCount) {
      queue += item
      return
    }

    //queue already have the k items
    if (item.compareTo(queue.head) > 0) {
      queue.dequeue()
      queue += item
    }
  }

  def get(): List[Int] = {
    queue.clone().dequeueAll
  }
}
