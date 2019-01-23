package ch10_recursive

import org.scalatest.{FlatSpec, Matchers}

class RecursiveDemoTest extends FlatSpec with Matchers {

  behavior of "RecursiveDemoTest"

  it should "calculateStepWays" in {
    RecursiveDemo.calculateStepWays(1) should equal(1)
    RecursiveDemo.calculateStepWays(2) should equal(2)
    RecursiveDemo.calculateStepWays(3) should equal(3)
    RecursiveDemo.calculateStepWays(4) should equal(5)
    RecursiveDemo.calculateStepWays(5) should equal(8)
  }

}
