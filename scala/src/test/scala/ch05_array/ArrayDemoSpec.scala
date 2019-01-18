package ch05_array

import org.scalatest.{FlatSpec, Matchers}

class ArrayDemoSpec extends FlatSpec with Matchers {

  behavior of "ArrayDemoTest"

  it should "find value after insert" in {
    val demo = new ArrayDemo(10)
    assert(demo.insert(0, 'a'))
    assert(demo.insert(1, 'b'))
    assert(demo.insert(2, 'c'))
    assert(demo.insert(3, 'd'))
    assert(demo.insert(4, 'e'))
    demo.print should equal("abcde")

    assert(demo.insert(2, 'x'))
    demo.print should equal("abxcde")
  }

  it should "not insert value if capacity is full " in {
    val demo = new ArrayDemo(10)
    for (i <- Range(0, 10)) {
      demo.insert(i, (i + 97).toChar)
    }

    assert(!demo.insert(1, 'a'))
  }

  it should "not insert if index is negative" in {
    val demo = new ArrayDemo(10)
    assert(!demo.insert(-1, 'a'))
  }

  it should "not insert if index is exceed capacity" in {
    val demo = new ArrayDemo(10)
    assert(!demo.insert(10, 'a'))
    assert(!demo.insert(11, 'a'))
  }

  it should "not find after delete" in {
    val demo = new ArrayDemo(10)
    assert(demo.insert(0, 'a'))
    assert(demo.insert(1, 'b'))
    assert(demo.insert(2, 'c'))
    assert(demo.insert(3, 'd'))
    assert(demo.insert(4, 'e'))
    demo.print should equal("abcde")


    assert(demo.insert(2, 'x'))
    demo.print should equal("abxcde")

    demo.delete(2) should equal('x')
    demo.find(2) should not equal ('x')
    demo.print should equal("abcde")
  }

  it should "not delete for empty array" in {
    val demo = new ArrayDemo(10)
    assertThrows[IllegalStateException] {
      demo.delete(2) should equal('x')
    }
  }

}
