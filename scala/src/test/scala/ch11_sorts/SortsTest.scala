package ch11_sorts

import org.scalatest.{FlatSpec, Matchers}

class SortsTest extends FlatSpec with Matchers {

  behavior of "SortsTest"

  it should "bubbleSort int arrays" in {
    var array = Array(4,5,6,3,2,1)
    array = Sorts.bubbleSort(array)
    array.mkString("") should equal ("123456")

    array = Array(4)
    array = Sorts.bubbleSort(array)
    array.mkString("") should equal ("4")
  }

}
