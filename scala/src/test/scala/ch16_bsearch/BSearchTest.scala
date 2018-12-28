package ch16_bsearch

import org.scalatest.{FlatSpec, Matchers}

class BSearchTest extends FlatSpec with Matchers {

  behavior of "BSearchTest"

  it should "findFirstValue" in {
    val items = Array(1, 3, 4, 5, 6, 8, 8, 8, 11, 18)
    BSearch.findFirstValue(items, 8) should equal(5)
  }

  it should "findLastValue" in {
    val items = Array(1, 3, 4, 5, 6, 8, 8, 8, 11, 18)
    BSearch.findLastValue(items, 8) should equal(7)
  }

  it should "findFirstGreaterThan" in {
    val items = Array(1, 3, 4, 5, 6, 8, 8, 8, 11, 18)
    BSearch.findFirstGreaterThan(items, 2) should equal(1)
    BSearch.findFirstGreaterThan(items, 8) should equal(5)
  }

  it should "findLastSmallerThan" in {
    val items = Array(1, 3, 4, 5, 6, 8, 8, 8, 11, 18)
    BSearch.findLastSmallerThan(items, 2) should equal(0)
    BSearch.findLastSmallerThan(items, 8) should equal(7)
  }

}
