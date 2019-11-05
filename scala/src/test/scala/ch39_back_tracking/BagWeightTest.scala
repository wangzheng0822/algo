package ch39_back_tracking

import org.scalatest.FlatSpec

class BagWeightTest extends FlatSpec {

  behavior of "BagWeightTest"

  it should "calculateMaxWeight" in {
    val bagWeight = new BagWeight(5,9)
    val maxWeight = bagWeight.calculateMaxWeight(Array(1,2,3,5,6))
    println(maxWeight)
  }

}
