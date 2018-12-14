package ch06_linkedlist

import org.scalatest.{FlatSpec, Matchers}

class SinglyLinkedListTest extends FlatSpec with Matchers {

  behavior of "SinglyLinkedListTest"

  it should "insertToHead for new values" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertToHead(0)
    list.insertToHead(1)
    list.insertToHead(2)
    list.insertToHead(3)

    list.mkString() should equal("3210")

  }

  it should "insertTail for new values" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(2)
    list.insertTail(3)

    list.mkString() should equal("0123")

  }

  it should "find by value" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(2)
    list.insertTail(3)

    list.mkString() should equal("0123")
    val node1 = list.findByValue(1).get
    node1.next.get.data should equal(2)
  }

  it should "insert after node and can find it back" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(3)
    list.insertTail(4)

    val node1 = list.findByValue(1).get
    list.insertAfter(node1,2)

    list.mkString() should equal("01234")
  }

  it should "insert before node and can find it back" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(3)
    list.insertTail(4)

    val node3 = list.findByValue(3).get
    list.insertBefore(node3,2)

    list.mkString() should equal("01234")
  }

  it should "delete desired node" in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(2)
    list.insertTail(3)

    val node1 = list.findByValue(1).get
    list.deleteByNode(node1)

    list.mkString() should equal("023")
  }

  it should "delete head node " in {
    val list: SinglyLinkedList = new SinglyLinkedList()

    list.insertTail(0)
    list.insertTail(1)
    list.insertTail(2)
    list.insertTail(3)

    val node0 = list.findByValue(0).get
    list.deleteByNode(node0)

    list.mkString() should equal("123")
  }

}
