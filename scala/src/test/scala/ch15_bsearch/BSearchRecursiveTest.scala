package ch15_bsearch

import ch12_sorts.QuickSort
import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class BSearchRecursiveTest extends FlatSpec with Matchers {

  behavior of "BSearchRecursiveTest"

  it should "search with exist value" in {
    val length = 50000
    val array = new Array[Int](length)
    val rnd = new Random()
    for (i <- Range(0, length)) {
      array(i) = rnd.nextInt()
    }

    val target = array(2698)

    BSearchRecursive.search(QuickSort.quickSort(array), target) should be > -1
  }

}
