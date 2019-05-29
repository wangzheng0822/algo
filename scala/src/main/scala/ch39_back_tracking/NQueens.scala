package ch39_back_tracking

import scala.util.control.Breaks.{break, breakable}

class NQueens(numberOfQueens:Int) {
  //use array index to identify the row,the value of the row to identify the column
  val result = new Array[Int](numberOfQueens)
  var count = 0

  def calcNQueues(row: Int): Unit = {
    if (row == numberOfQueens) {
      //everything is done
      printNQueens()
      return
    }

    for (column <- Range(0, numberOfQueens)) {
      if (isOkOnColumn(row, column)) {
        result(row) = column //place the column value into the array
        calcNQueues(row + 1) //calculate next row
      }
    }

  }

  def isOkOnColumn(row: Int, column: Int): Boolean = {
    var ok = true
    var leftUp = column - 1
    var rightUp = column + 1

    breakable {
      //will compare all the rows above current row
      for (i <- row - 1 to 0 by -1) {
        //check current column
        if (result(i) == column) {
          ok = false
          break
        }
        //check left up
        if (leftUp >= 0) {
          if (result(i) == leftUp) {
            ok = false
            break
          }
        }
        //check right up
        if (rightUp < numberOfQueens) {
          if (result(i) == rightUp) {
            ok = false
            break
          }
        }
        //move leftUp and rightUp
        leftUp -= 1
        rightUp += 1
      }
    }

    ok
  }

  def printNQueens(): Unit = {
    count +=1
    for (row <- Range(0, numberOfQueens)) {
      for (column <- Range(0, numberOfQueens)) {
        if (result(row) == column) {
          print("Q ")
        } else {
          print("* ")
        }
      }
      //new line for next row
      println("")
    }
    println(count+"==============")
  }
}
