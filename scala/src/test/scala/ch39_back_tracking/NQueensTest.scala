package ch39_back_tracking

import org.scalatest.FlatSpec

class NQueensTest extends FlatSpec {

  behavior of "NQueensTest"

  it should "calc8Queues" in {
    val eightQueens = new NQueens(8)
    eightQueens.calcNQueues(0)

  }

  it should "calc4Queues" in {
    val eightQueens = new NQueens(4)
    eightQueens.calcNQueues(0)

  }

}
