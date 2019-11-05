package ch32_matching

import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class BruteForceTest extends FlatSpec with Matchers {

  behavior of "BruteForceTest"

  it should "find firstIndexOf a sub string" in {
    val random = Random.alphanumeric
    val main = random.take(1000).toArray
    val index = Random.nextInt(950)
    val sub = random.take(1000).toArray.slice(index, index + 50)

    BruteForce.firstIndexOf(main, sub) should equal(index)
  }

}
