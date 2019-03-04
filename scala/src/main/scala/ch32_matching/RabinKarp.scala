package ch32_matching

import scala.util.control.Breaks.{break, breakable}

object RabinKarp {

  def firstIndexOf(main: Array[Char], sub: Array[Char]): Int = {
    require(main != null, "main array required")
    require(sub != null, "sub array required")
    require(main.length >= sub.length, "sub array should be small than main array")
    val baseNums: Array[Long] = new Array[Long](sub.length)
    for (i <- sub.indices) {
      baseNums(i) = scala.math.pow(128, i).longValue()
    }

    val subHash = hash(sub, baseNums)
    var result = -1
    breakable {
      for (i <- 0 until (main.length - sub.length)) {
        if (hash(main.slice(i, i + sub.length), baseNums).equals(subHash)
            && main.slice(i, i + sub.length).sameElements(sub)) {
          result = i
          break
        }
      }
    }
    result

  }

  def hash(array: Array[Char], baseNums: Array[Long]): Long = {
    var hash = 0L
    for (i <- array.indices) {
      hash += array(i).toInt * baseNums(array.length - 1 - i)
    }
    hash
  }

}
