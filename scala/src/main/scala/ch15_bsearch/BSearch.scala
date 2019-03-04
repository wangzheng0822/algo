package ch15_bsearch

import scala.math.abs

object BSearch {

  def search(items: Array[Int], target: Int): Int = {
    var low = 0
    var high = items.length - 1
    while (low <= high) {
      val mid = low + (high - low) / 2
      if (items(mid) == target) {
        return mid
      } else if (items(mid) > target) {
        high = mid - 1
      } else {
        low = mid + 1
      }
    }

    -1
  }

  def sqrt(x: Double, precision: Double): Double = {

    require(precision > 0, "precision must > 0")
    require(x > 0, "input value for sqrt must > 0")
    var low = 0.0
    var high = x
    val actualPrecision = precision / 10

    if (x > 0 && x < 1) {
      low = x
      high = 1
    }
    while (high - low > actualPrecision) {
      val mid = low + (high - low) / 2
      if (abs(mid * mid - x) < actualPrecision) {
        //find it
        return mid
      } else if (mid * mid > x) {
        high = mid
      } else {
        low = mid
      }
    }
    throw new IllegalStateException("could not determine the sqrt value for " + x)

  }
}
