package ch29_heap_solutions

import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class TopKItemsKeeperTest extends FlatSpec with Matchers {

  behavior of "TopKItemsKeeperTest"

  it should "put and get top K from the keeper" in {
    val length = 50
    val k = 5
    val topKItemsKeeper = new TopKItemsKeeper(k)
    val nums = new Array[Int](length)
    for (i <- Range(0, length)) {
      nums(i) = Random.nextInt
    }

    nums.foreach(topKItemsKeeper.put)
    val ordering = scala.math.Ordering.Int.reverse
    topKItemsKeeper.get().toArray.sorted(ordering) should equal(nums.sorted(ordering).slice(0, k))
  }

}
