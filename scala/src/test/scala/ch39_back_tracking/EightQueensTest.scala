package ch39_back_tracking

import org.scalatest.FlatSpec

class EightQueensTest extends FlatSpec {

  behavior of "EightQueensTest"

  it should "calc8Queues" in {
    val eightQueens = new EightQueens()
    eightQueens.calc8Queues(0)
  }

}
