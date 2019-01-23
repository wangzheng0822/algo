package ch17_skip_list

import org.scalatest.{FlatSpec, Matchers}

import scala.util.Random

class SkipListTest extends FlatSpec with Matchers {

  behavior of "SkipListTest"

  it should "insert skip list" in {
    val list = new SkipList()
    for (i <- Range(0, 10)) {
      list.insert(i)
    }

    list.mkString() should equal("0123456789")
  }

  it should "delete skip list" in {
    val list = new SkipList()
    for (i <- Range(0, 10)) {
      list.insert(i)
    }

    list.delete(5)
    list.mkString() should equal("012346789")
  }

  it should "find value in skip list" in {
    val list = new SkipList()
    val length = 5000
    val array = new Array[Int](length)
    val rnd = new Random()
    for (i <- Range(0, length)) {
      array(i) = rnd.nextInt(length)
      list.insert(array(i))
    }

    assert(list.find(array(rnd.nextInt(length - 1))).isDefined)
    assert(list.find(array(rnd.nextInt(length - 1)) + length + 1).isEmpty)

  }
}
