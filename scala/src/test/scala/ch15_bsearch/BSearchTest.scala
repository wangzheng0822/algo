package ch15_bsearch

import ch12_sorts.QuickSort
import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class BSearchTest extends FlatSpec with Matchers {

  behavior of "BSearchTest"

  it should "search with exist value" in {
    val length = 50000
    val array = new Array[Int](length)
    val rnd = new Random()
    for (i <- Range(0, length)) {
      array(i) = rnd.nextInt()
    }

    val target = array(2698)

    BSearch.search(QuickSort.quickSort(array), target) should be > -1
  }

  it should "calculate sqrt value -1 " in {
    val x = 4
    val precision = 0.000001
    BSearch.sqrt(x, precision) should equal(2.0)
  }

  it should "calculate sqrt value -2 " in {
    val x = 0.04
    val precision = 0.000001
    BSearch.sqrt(x, precision) should equal(0.2 +- precision)
  }

}
