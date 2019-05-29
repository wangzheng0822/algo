package ch29_heap_solutions

import scala.collection.mutable

class MiddleNumberKeeper(val percent: Double) {

  def this() = this(0.5)

  val bigTop = new mutable.PriorityQueue[Int]()
  val smallTop = new mutable.PriorityQueue[Int]()(scala.math.Ordering.Int.reverse)


  def put(num: Int): Unit = {
    if (smallTop.nonEmpty && num >= smallTop.head) {
      smallTop += num
      adjustHeap()
      return
    }

    //for any other scenario, we just put the item to bitTop then adjustHeap
    bigTop += num
    adjustHeap()
  }

  def get(): Option[Int] = {
    bigTop.headOption
  }

  private[this] def adjustHeap(): Unit = {
    val totalLength = smallTop.length + bigTop.length
    //deal with bigTop
    while (bigTop.length.doubleValue() / totalLength - percent > 0.0001) {
      //move item from bigTop to smallTop
      smallTop += bigTop.dequeue()
    }

    //deal with smallTop
    while (smallTop.length.doubleValue() / totalLength - (1.0D - percent) > 0.0001) {
      bigTop += smallTop.dequeue()
    }
  }
}
