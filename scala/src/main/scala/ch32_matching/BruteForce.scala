package ch32_matching

import scala.util.control.Breaks._

object BruteForce {

  def firstIndexOf(main: Array[Char], sub: Array[Char]): Int = {

    require(main != null, "main array required")
    require(sub != null, "sub array required")
    require(main.length >= sub.length, "sub array should be small than main array")
    var result = -1
    breakable {
      for (i <- 0 until (main.length - sub.length)) {
        if (main.slice(i, i + sub.length) sameElements sub) {
          result = i
          break
        }
      }
    }
    result
  }

}
