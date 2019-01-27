package ch39_back_tracking

import scala.util.control.Breaks._

class Sudoku {

  def resolve(grid: Array[Array[Int]]): Unit = {
    printGrid(grid)
    println("")
    if (resolve(grid, 0, 0)) {
      printGrid(grid)
    } else {
      println("no result")
      printGrid(grid)
    }
  }

  private[this] def resolve(grid: Array[Array[Int]], row: Int, column: Int): Boolean = {
    if (row == 8 && column == 9) {
      //find the result
      return true
    }

    if (column == 9) {
      //move to next line
      return resolve(grid, row + 1, 0)
    }

    if (grid(row)(column) != 0) {
      //given number, resolve next one
      return resolve(grid, row, column + 1)
    }

    //start the real resolve
    for (num <- 1 to 9) {
      if (isOk(grid, row, column, num)) {
        grid(row)(column) = num
        if (resolve(grid, row, column + 1)) {
          return true
        }
      }
    }

    //do not find anything, reset given row and column
    grid(row)(column) = 0
    false
  }

  def isOk(grid: Array[Array[Int]], row: Int, column: Int, num: Int): Boolean = {
    isRowOk(grid, row, num) && isColumnOk(grid, column, num) && isSmallBoxOk(grid, row, column, num)
  }

  def isRowOk(grid: Array[Array[Int]], row: Int, num: Int): Boolean = {
    var isOk = true
    breakable {
      for (column <- Range(0, 9)) {
        if (grid(row)(column) == num) {
          isOk = false
          break
        }
      }
    }
    isOk
  }

  def isColumnOk(grid: Array[Array[Int]], column: Int, num: Int): Boolean = {
    var isOk = true
    breakable {
      for (row <- Range(0, 9)) {
        if (grid(row)(column) == num) {
          isOk = false
          break
        }
      }
    }
    isOk
  }

  def isSmallBoxOk(grid: Array[Array[Int]], row: Int, column: Int, num: Int): Boolean = {
    val rowOffSet = (row / 3) * 3
    val columnOffSet = (column / 3) * 3
    var isOk = true
    breakable {
      for (i <- Range(0, 3)) {
        for (j <- Range(0, 3)) {
          if (grid(i + rowOffSet)(j + columnOffSet) == num) {
            isOk = false
            break
          }
        }
      }
    }
    isOk
  }

  def printGrid(grid: Array[Array[Int]]): Unit = {
    for (i <- Range(0, 9)) {
      if (i % 3 == 0) {
        println("-------------------------")
      }
      for (j <- Range(0, 9)) {
        if (j % 3 == 0) {
          print("| ")
        }
        print(grid(i)(j) + " ")
      }
      println("| ")

    }
    println("-------------------------")
  }

}
