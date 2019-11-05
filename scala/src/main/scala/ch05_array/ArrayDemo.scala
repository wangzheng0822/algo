package ch05_array

class ArrayDemo(capacity: Int) {

  var data: Array[Char] = new Array[Char](capacity)
  var length: Int = 0

  def find(index: Int): Char = {
    if (index < 0 || index > length) {
      return 0.toChar
    }
    data(index)
  }

  def insert(index: Int, value: Char): Boolean = {
    if (length == capacity) {
      return false
    }

    if (index < 0 || index >= capacity) {
      return false
    }

    for (i <- length until index by -1) {
      data(i) = data(i - 1)
    }
    data(index) = value
    length += 1

    true
  }

  def delete(index: Int): Char = {
    if (length == 0) {
      throw new IllegalStateException("array is empty")
    }
    if (index >= length) {
      throw new IllegalStateException("index out of range, current data length is " + length)
    }
    val result = data(index)
    for (i <- index until length-1) {
      data(i) = data(i + 1)
    }

    length -= 1
    result
  }

  def print: String = {
    data.subSequence(0, length).toString
  }

}
