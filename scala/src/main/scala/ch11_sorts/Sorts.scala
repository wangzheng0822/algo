package ch11_sorts

import scala.util.control.Breaks.{break, breakable}

/**
  * 冒泡排序、插入排序、选择排序
  *
  * Author: yangchuz
  */
object Sorts {

  def bubbleSort(items: Array[Int]): Array[Int] = {
    val length = items.length
    breakable {
      for (i <- Range(0, length)) {
        var exit = true
        for (j <- Range(0, length - i - 1)) {
          if (items(j + 1) < items(j)) {
            val temp = items(j + 1)
            items(j + 1) = items(j)
            items(j) = temp
            exit = false
          }
        }
        if (exit) {
          break
        }
      }
    }
    items
  }

  def insertSort(items: Array[Int]): Array[Int] = {
    val length = items.length
    for (i <- Range(1, length)) {
      val value = items(i)
      var j = i - 1
      breakable {
        while (j >= 0) {
          if (items(j) > value) {
            items(j + 1) = items(j)
          } else {
            break
          }
          j -= 1
        }
      }
      items(j + 1) = value
    }
    items
  }

  def selectionSort(items: Array[Int]): Array[Int] = {
    val length = items.length
    for (i <- Range(0, length)) {
      var minIndex = i
      for (j <- Range(i + 1, length)) {
        if (items(j) < items(minIndex)) {
          minIndex = j
        }
      }

      //put the min value to the front
      val temp = items(i)
      items(i) = items(minIndex)
      items(minIndex) = temp
    }
    items
  }
}
