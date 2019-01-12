package ch28_heap

import org.scalatest.{FlatSpec, Matchers}

class HeapTest extends FlatSpec with Matchers {

  behavior of "HeapTest"

  it should "insert and removeMax" in {
    val nums = Array(33, 27, 21, 16, 13, 15, 19, 5, 6, 7, 8, 1, 2, 12)
    val heap = new Heap(nums.length + 1)
    nums.foreach(heap.insert)

    heap.removeMax() should equal(33)
    heap.removeMax() should equal(27)
  }

  it should "build heap from array - bottom up" in {
    val nums = Array(33, 27, 21, 16, 13, 15, 19, 5, 6, 7, 8, 1, 2, 12)
    val heap = new Heap(nums, true)

    heap.removeMax() should equal(33)
    heap.removeMax() should equal(27)
  }

  it should "build heap from array - top down" in {
    val nums = Array(33, 27, 21, 16, 13, 15, 19, 5, 6, 7, 8, 1, 2, 12)
    val heap = new Heap(nums, false)

    heap.removeMax() should equal(33)
    heap.removeMax() should equal(27)
  }

  it should "sort array" in {
    val nums = Array(33, 27, 21, 16, 13, 15, 19, 5, 6, 7, 8, 1, 2, 12)
    val result = Heap.heapSort(nums)

    result.mkString("") should equal(nums.sorted.mkString(""))
  }

}
