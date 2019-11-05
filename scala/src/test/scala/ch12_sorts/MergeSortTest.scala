package ch12_sorts


import org.scalatest.{FlatSpec, Matchers}

class MergeSortTest extends FlatSpec with Matchers {
  behavior of "SortsTest in ch12"

  it should "mergeSort int arrays" in {
    var array = Array(4, 5, 6, 3, 2, 1)
    array = MergeSort.mergeSort(array)
    array.mkString("") should equal("123456")

    array = Array(4)
    array = MergeSort.mergeSort(array)
    array.mkString("") should equal("4")

    array = Array(4, 2)
    array = MergeSort.mergeSort(array)
    array.mkString("") should equal("24")
  }
}
