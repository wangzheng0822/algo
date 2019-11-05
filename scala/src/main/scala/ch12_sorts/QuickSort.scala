package ch12_sorts

object QuickSort {

  //find the K th smallest element int the array
  def findKthElement(items: Array[Int], k: Int): Int = {
    _findKthElement(items, k, 0, items.length - 1)
  }

  private[this] def _findKthElement(items: Array[Int], k: Int, p: Int, r: Int): Int = {
    val q = _partition(items, p, r)

    if (k == q + 1) {
      items(q)
    } else if (k < q + 1) {
      _findKthElement(items, k, p, q - 1)
    } else {
      _findKthElement(items, k, q + 1, r)
    }
  }

  def quickSort(items: Array[Int]): Array[Int] = {
    _quickSort(items, 0, items.length - 1)
    items
  }

  private[this] def _quickSort(items: Array[Int], p: Int, r: Int): Unit = {
    if (p >= r) {
      return
    }
    val q = _partition(items, p, r)
    _quickSort(items, p, q - 1)
    _quickSort(items, q + 1, r)
  }

  private[this] def _partition(items: Array[Int], p: Int, r: Int): Int = {
    val pivot = items(r)
    var i = p
    for (j <- Range(p, r)) {
      if (items(j) < pivot) {
        val temp = items(i)
        items(i) = items(j)
        items(j) = temp
        i += 1
      }
    }

    val temp = items(i)
    items(i) = items(r)
    items(r) = temp

    i
  }
}
