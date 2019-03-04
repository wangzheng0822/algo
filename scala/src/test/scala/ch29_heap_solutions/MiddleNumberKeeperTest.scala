package ch29_heap_solutions

import org.scalatest.{FlatSpec, Matchers}

class MiddleNumberKeeperTest extends FlatSpec with Matchers {

  behavior of "MiddleNumberKeeperTest"

  it should "get middle of the array" in {
    val numKeeper = new MiddleNumberKeeper()
    for (i <- Range(0, 10)) {
      numKeeper.put(i)
    }

    numKeeper.get().get should equal(4)
  }

  it should "get 90% position of the array" in {
    val numKeeper = new MiddleNumberKeeper(0.9)
    for (i <- Range(0, 9)) {
      numKeeper.put(i)
    }
    numKeeper.put(9)

    numKeeper.get().get should equal(8)
  }

}
