package ch06_linkedlist

import org.scalatest.{FlatSpec, Matchers}

class NodeTest extends FlatSpec with Matchers {

  behavior of "NodeTest"
  it should "create node with constructor" in {
    val node1 = new Node(1, None)
    val node2 = new Node(2, Some(node1))
    val node3 = new Node(2, Some(node2))

    node1.next should be(None)
    node1.next = Some(node3)
    node1.next should equal(Some(node3))
  }

}
