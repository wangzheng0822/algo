package ch39_back_tracking

import org.scalatest.FlatSpec

class SudokuTest extends FlatSpec {

  behavior of "SudokuTest"

  it should "resolve - 1" in {
    val grid = Array(
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0)
    )
    val sudoku = new Sudoku()
    sudoku.resolve(grid)
  }

  it should "resolve - 2" in {
    val grid = Array(
      Array(0, 0, 7, 2, 5, 6, 4, 0 ,0),
      Array(4, 0, 0, 0, 0, 0, 0, 0, 5),
      Array(0, 1, 0, 0, 3, 9, 0, 6, 0),
      Array(0, 0, 0, 5, 0, 8, 0, 0, 0),
      Array(0, 0, 8, 0, 6, 0, 2, 0, 0),
      Array(0, 9, 0, 1, 0, 7, 0, 0, 0),
      Array(0, 3, 0, 0, 7, 0, 0, 9, 0),
      Array(2, 0, 0, 0, 0, 0, 0, 0, 4),
      Array(0, 0, 6, 3, 1, 2, 7, 0, 8)
    )
    val sudoku = new Sudoku()
    sudoku.resolve(grid)
  }

  it should "resolve - 3" in {
    val grid = Array(
      Array(3, 8, 0, 0, 0, 0, 0, 0, 1),
      Array(0, 0, 6, 4, 0, 0, 7, 8, 5),
      Array(0, 0, 9, 0, 2, 0, 3, 0, 0),
      Array(0, 6, 0, 0, 9, 0, 0, 0, 0),
      Array(8, 0, 0, 3, 0, 2, 0, 0, 9),
      Array(0, 0, 0, 0, 4, 0, 0, 7, 0),
      Array(0, 0, 1, 0, 7, 0, 5, 0, 0),
      Array(4, 9, 5, 0, 0, 6, 1, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 9, 2)
    )
    val sudoku = new Sudoku()
    sudoku.resolve(grid)
  }

  it should "print grid" in {
    val grid = Array(
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0),
      Array(0, 0, 0, 0, 0, 0, 0, 0, 0)
    )

    val sudoku = new Sudoku()
    sudoku.printGrid(grid)
  }

}
