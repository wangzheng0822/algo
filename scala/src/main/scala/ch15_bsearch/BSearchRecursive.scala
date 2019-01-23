package ch15_bsearch

object BSearchRecursive {

  def search(items: Array[Int], target: Int): Int = {
    _search(items, target, 0, items.length - 1)
  }

  private[this] def _search(items: Array[Int], target: Int, low: Int, high: Int): Int = {
    if (low > high) {
      return -1
    }

    val mid = low + (high - low) / 2
    if (items(mid) == target) {
      mid
    } else if (items(mid) > target) {
      _search(items, target, low, mid - 1)
    } else {
      _search(items, target, mid + 1, high)
    }
  }
}
