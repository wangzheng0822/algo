package ch16_bsearch

object BSearch {

  //find the first index of given value
  //-1 if not found
  def findFirstValue(items: Array[Int], target: Int): Int = {
    require(items.length > 0, "given array is empty")
    var low = 0
    var high = items.length - 1
    while (low <= high) {
      val mid = low + (high - low) / 2
      if (items(mid) > target) {
        high = mid - 1
      } else if (items(mid) < target) {
        low = mid + 1
      } else {
        //find the value in the array
        if (mid == 0 || items(mid - 1) != target) {
          return mid
        } else {
          high = mid - 1
        }
      }
    }
    -1
  }

  def findLastValue(items: Array[Int], target: Int): Int = {
    var low = 0
    var high = items.length - 1
    while (low <= high) {
      val mid = low + (high - low) / 2
      if (items(mid) > target) {
        high = mid - 1
      } else if (items(mid) < target) {
        low = mid + 1
      } else {
        //find the target value
        if (mid == items.length - 1 || items(mid + 1) != target) {
          return mid
        } else {
          low = mid + 1
        }
      }
    }
    -1
  }

  def findFirstGreaterThan(items: Array[Int], target: Int): Int = {
    var low = 0
    var high = items.length
    while (low <= high) {
      val mid = low + (high - low) / 2
      if (items(mid) >= target) {
        //find the range
        if (mid == 0 || items(mid - 1) < target) {
          return mid
        } else {
          high = mid - 1
        }
      } else {
        low = mid + 1
      }
    }
    -1
  }

  def findLastSmallerThan(items: Array[Int], target: Int): Int = {
    var low = 0
    var high = items.length - 1
    while (low <= high) {
      var mid = low + (high - low) / 2
      if (items(mid) <= target) {
        //find the range
        if (mid == items.length - 1 || items(mid + 1) > target) {
          return mid
        } else {
          low = mid + 1
        }
      } else {
        high = mid - 1
      }
    }
    -1
  }
}
