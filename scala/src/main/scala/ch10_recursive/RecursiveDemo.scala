package ch10_recursive

import scala.collection.mutable

object RecursiveDemo {

  def calculateStepWays(steps: Int): Int = {
    //use knownResults to avoid duplicated computing
    val knownResults = mutable.HashMap.empty[Int, Int]
    steps match {
      case 1 => 1
      case 2 => 2
      case _ => knownResults.get(steps) match {
        case Some(result) => result
        case None => {
          val result = calculateStepWays(steps - 1) + calculateStepWays(steps - 2)
          knownResults.put(steps, result)
          result
        }
      }
    }
  }
}
