package ch08_stack

import org.scalatest.{FlatSpec, Matchers}

class StackDemoTest extends FlatSpec with Matchers {

  behavior of "StackDemoTest"

  it should "push/pop should be FILO" in {
    val stack = new StackDemo[String]
    val num = 100
    for (i <- 1 to num) {
      stack.push(i.toString)
    }

    for (i <- num to 1 by -1) {
      stack.pop().get.data should equal(i.toString)
    }
  }

  it should "pop should also work for empty stack" in {
    val stack = new StackDemo[Int]
    val num = 100
    for (i <- num to 1 by -1) {
      assert(stack.pop().isEmpty)
    }
  }

}
