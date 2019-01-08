package ch12_sorts

import org.scalatest.{FlatSpec, Matchers}

class QuickSortTest extends FlatSpec with Matchers {

  behavior of "QuickSortTest"

  it should "quickSort" in {
    var array = Array(4, 5, 6, 3, 2, 1)
    array = QuickSort.quickSort(array)
    array.mkString("") should equal("123456")

    array = Array(4)
    array = QuickSort.quickSort(array)
    array.mkString("") should equal("4")

    array = Array(4, 2)
    array = QuickSort.quickSort(array)
    array.mkString("") should equal("24")
  }

  it should "find the Kth element in the array" in {
    val array = Array(4, 2, 5, 12, 3)

    QuickSort.findKthElement(array, 3) should equal(4)
    QuickSort.findKthElement(array, 5) should equal(12)
    QuickSort.findKthElement(array, 1) should equal(2)
  }

}
