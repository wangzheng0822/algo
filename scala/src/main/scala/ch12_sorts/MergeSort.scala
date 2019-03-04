package ch12_sorts

object MergeSort {

  def mergeSort(items: Array[Int]): Array[Int] = {
    _mergeSort(items, 0, items.length - 1)
    items
  }


  private[this] def _mergeSort(items: Array[Int], p: Int, r: Int): Unit = {
    if (p >= r) {
      return
    }

    val q = p + (r - p) / 2
    _mergeSort(items, p, q)
    _mergeSort(items, q + 1, r)
    _merge(items, p, q, r)

  }

  private[this] def _merge(items: Array[Int], p: Int, q: Int, r: Int): Unit = {
    //start of first half
    var i = p
    //start of second half
    var j = q + 1
    var k = 0
    //temp array to hold the data
    val tempArray = new Array[Int](r - p + 1)
    while (i <= q && j <= r) {
      if (items(i) <= items(j)) {
        tempArray(k) = items(i)
        i += 1
      } else {
        tempArray(k) = items(j)
        j += 1
      }
      k += 1
    }

    var start = i
    var end = q

    if (j <= r) {
      start = j
      end = r
    }

    for (n <- start to end) {
      tempArray(k) = items(n)
      k += 1
    }

    //copy tempArray back to items
    for (n <- 0 to r - p) {
      items(p + n) = tempArray(n)
    }
  }
}
