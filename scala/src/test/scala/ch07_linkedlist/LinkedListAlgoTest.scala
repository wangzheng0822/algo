package ch07_linkedlist

import ch06_linkedlist.{Node, SinglyLinkedList}
import org.scalatest.{FlatSpec, Matchers}

class LinkedListAlgoTest extends FlatSpec with Matchers {

  behavior of "LinkedListAlgoTest"

  it should "reverse a node for long linked list" in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    LinkedListAlgo.mkStringForChain(list.headOpt.get) should equal((0 to 9).toArray.mkString(""))

    val reverseNode = LinkedListAlgo.reverse(list.headOpt.get)

    LinkedListAlgo.mkStringForChain(reverseNode) should equal((9 to 0 by -1).toArray.mkString(""))
  }

  it should "reverse a node for linked list with 1 node" in {
    val list = new SinglyLinkedList()

    list.insertTail(100)

    LinkedListAlgo.mkStringForChain(list.headOpt.get) should equal("100")

    val reverseNode = LinkedListAlgo.reverse(list.headOpt.get)

    LinkedListAlgo.mkStringForChain(reverseNode) should equal("100")
  }

  it should "check circle for circled linked list" in {

    val node1 = new Node(1, None)
    val node2 = new Node(2, None)
    val node3 = new Node(3, None)
    val node4 = new Node(4, None)
    val node5 = new Node(5, None)
    val node6 = new Node(6, None)

    //1->2->3->4->5->6->3 it's a circle
    //node1 is the head
    node1.next = Some(node2)
    node2.next = Some(node3)
    node3.next = Some(node4)
    node4.next = Some(node5)
    node5.next = Some(node6)
    node6.next = Some(node3)

    assert(LinkedListAlgo.checkCircle(node1))
  }

  it should "check circle for none circled linked list" in {

    val node1 = new Node(1, None)
    val node2 = new Node(2, None)
    val node3 = new Node(3, None)
    val node4 = new Node(4, None)
    val node5 = new Node(5, None)
    val node6 = new Node(6, None)

    //1->2->3->4->5->6->null it's not a circle
    //node1 is the head
    node1.next = Some(node2)
    node2.next = Some(node3)
    node3.next = Some(node4)
    node4.next = Some(node5)
    node5.next = Some(node6)

    assert(!LinkedListAlgo.checkCircle(node1))
  }

}
