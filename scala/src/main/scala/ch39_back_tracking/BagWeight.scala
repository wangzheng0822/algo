package ch39_back_tracking

class BagWeight(maxBagItemCount: Int, maxBagWeight: Int) {

  def calculateMaxWeight(items: Array[Int]): Int = {
    var maxWeight = 0

    def _calcMaxWeight(itemIndex: Int, currentWeight: Int): Unit = {
      if (currentWeight == maxBagWeight || itemIndex == items.length) {
        if (currentWeight > maxWeight) {
          maxWeight = currentWeight
        }
      } else {
        //check next item
        _calcMaxWeight(itemIndex + 1, currentWeight)
        if (currentWeight + items(itemIndex) <= maxBagWeight) {
          _calcMaxWeight(itemIndex + 1, currentWeight + items(itemIndex))
        }
      }
    }

    _calcMaxWeight(0, 0)
    maxWeight
  }
}
