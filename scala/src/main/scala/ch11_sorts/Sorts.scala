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

  def insertSort(arr: Array[Int], n: Int): Array[Int] = {
    for (i <- 1 until n) {
      val tmp = arr(i)
      breakable {
        for (j <- (i - 1) to(0, -1)) {
          if (tmp < arr(j)) {
            arr(j + 1) = arr(j)
          } else {
            arr(j + 1) = tmp
            break
          }
        }
      }
    }
    arr
  }

  def selectionSort(arr: Array[Int], n: Int): Array[Int] = {
    for (i <- 0 until n) {
      var min = i
      for (j <- (i + 1) until n) {
        if (arr(j) < arr(min)) {
          min = j
        }
      }

      val tmp = arr(i)
      arr(i) = arr(min)
      arr(min) = tmp
    }
    arr
  }
}
