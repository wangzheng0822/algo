package ch28_heap

import scala.util.control.Breaks._

class Heap(val capacity: Int, var elementCount: Int = 0) {

  def this(arrayParam: Array[Int], bottomUp: Boolean) = {
    this(arrayParam.length + 1)
    if (bottomUp) {
      arrayParam.foreach(this.insert)
    } else {
      //copy data into array of heap
      for (i <- arrayParam.indices) {
        array(i + 1) = arrayParam(i)
        elementCount = arrayParam.length
      }
      for (i <- elementCount / 2 + 1 to 1 by -1) {
        heapifyTopDown(i, elementCount - 1)
      }
    }
  }

  require(capacity > 0, "capacity should be > 0")
  val array: Array[Int] = new Array[Int](capacity)

  def insert(data: Int): Unit = {
    if (elementCount == capacity - 1) {
      throw new IllegalStateException("heap full")
    }

    elementCount += 1
    array(elementCount) = data

    //heapify bottom up
    //compare the element with it's parent node i/2 until parent node > child node
    //this will make sure the root element of the tree is the biggest value
    var i = elementCount
    while (i / 2 > 0 && array(i) > array(i / 2)) {
      val temp = array(i)
      array(i) = array(i / 2)
      array(i / 2) = temp
      i = i / 2
    }

  }

  def removeMax(): Int = {
    require(elementCount > 0, "heap is empty")
    val result = array(1)
    array(1) = array(elementCount)
    elementCount -= 1
    heapifyTopDown(1, elementCount)
    result
  }

  //heapify from top to bottom
  //start from the top to compare with it's child nodes
  //swap if child node > parent node
  //stop at child node <= parent node
  private[this] def heapifyTopDown(startIndex: Int, stopIndex: Int) = {
    var pointer = startIndex
    breakable {
      while (true) {
        var maxPos = pointer
        if (pointer * 2 <= stopIndex && array(pointer * 2) > array(maxPos)) {
          maxPos = pointer * 2
        }
        if (pointer * 2 <= stopIndex && array(pointer * 2 + 1) > array(maxPos)) {
          maxPos = pointer * 2 + 1
        }
        if (maxPos == pointer) {
          break
        }
        //swap the parent and child
        val temp = array(pointer)
        array(pointer) = array(maxPos)
        array(maxPos) = temp
        //start a new round
        pointer = maxPos
      }
    }
  }

}

object Heap {
  def heapSort(array: Array[Int]): Array[Int] = {
    val result = new Array[Int](array.length)
    val heap = new Heap(array, true)
    for (i <- result.length - 1 to 0 by -1) {
      result(i) = heap.removeMax()
    }
    result
  }
}