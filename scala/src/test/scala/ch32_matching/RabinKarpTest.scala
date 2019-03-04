package ch32_matching

import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class RabinKarpTest extends FlatSpec with Matchers {

  it should "find firstIndexOf a sub string" in {
    val random = Random.alphanumeric
    val main = random.take(1000).toArray
    val index = Random.nextInt(950)
    val sub = random.take(1000).toArray.slice(index, index + 50)

    RabinKarp.firstIndexOf(main, sub) should equal(index)
  }
}
