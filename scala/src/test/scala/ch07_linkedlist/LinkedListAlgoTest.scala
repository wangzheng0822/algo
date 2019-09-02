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

    assert(LinkedListAlgo.checkCircle(node1).isDefined)
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

    assert(LinkedListAlgo.checkCircle(node1).isEmpty)
  }

  it should "calculate circle length" in {
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

    val node = LinkedListAlgo.checkCircle(node1).get

    val length = LinkedListAlgo.calculateCircleLength(node)

    length should equal(4)
  }

  it should "find entrance of the  circle" in {
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

    val node = LinkedListAlgo.findCircleEntrance(node1)

    node.get.data should equal(3)
  }

  it should "merge 2 sorted list into 1" in {
    val node1 = new Node(1, None)
    val node2 = new Node(2, None)
    val node3 = new Node(3, None)
    val node4 = new Node(4, None)
    val node5 = new Node(5, None)
    val node6 = new Node(6, None)
    //1->2->3->4->5->6->null
    //node1 is the head
    node1.next = Some(node2)
    node2.next = Some(node3)
    node3.next = Some(node4)
    node4.next = Some(node5)
    node5.next = Some(node6)

    val nodeA = new Node(2, None)
    val nodeB = new Node(4, None)
    val nodeC = new Node(6, None)
    val nodeD = new Node(8, None)
    val nodeE = new Node(10, None)
    //2->4->6->8->10->null
    //nodeA is the head
    nodeA.next = Some(nodeB)
    nodeB.next = Some(nodeC)
    nodeC.next = Some(nodeD)
    nodeD.next = Some(nodeE)

    val node = LinkedListAlgo.mergeSortedList(Some(node1), Some(nodeA))

    assert(node.isDefined)

    LinkedListAlgo.mkStringForChain(node.get) should equal("122344566810")
  }

  it should "merge empty list into exist list " in {
    val node1 = new Node(1, None)
    val node2 = new Node(2, None)
    val node3 = new Node(3, None)
    val node4 = new Node(4, None)
    val node5 = new Node(5, None)
    val node6 = new Node(6, None)
    //1->2->3->4->5->6->null
    //node1 is the head
    node1.next = Some(node2)
    node2.next = Some(node3)
    node3.next = Some(node4)
    node4.next = Some(node5)
    node5.next = Some(node6)

    val nodeA = LinkedListAlgo.mergeSortedList(Some(node1), None)
    assert(nodeA.isDefined)
    LinkedListAlgo.mkStringForChain(nodeA.get) should equal("123456")

    val nodeB = LinkedListAlgo.mergeSortedList(None, Some(node1))
    assert(nodeB.isDefined)
    LinkedListAlgo.mkStringForChain(nodeB.get) should equal("123456")
  }

  it should "merge 2 empty lists " in {
    val node = LinkedListAlgo.mergeSortedList(None, None)
    assert(node.isEmpty)
  }

  it should "delete last 2nd element " in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    LinkedListAlgo.mkStringForChain(list.headOpt.get) should equal((0 to 9).toArray.mkString(""))

    val node = LinkedListAlgo.deleteLastKthNode(list.headOpt, 2)
    assert(node.isDefined)
    LinkedListAlgo.mkStringForChain(node.get) should equal("012345679")
  }

  it should "delete last element " in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    LinkedListAlgo.mkStringForChain(list.headOpt.get) should equal((0 to 9).toArray.mkString(""))

    val node = LinkedListAlgo.deleteLastKthNode(list.headOpt, 1)
    assert(node.isDefined)
    LinkedListAlgo.mkStringForChain(node.get) should equal("012345678")
  }

  it should "delete first element " in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    LinkedListAlgo.mkStringForChain(list.headOpt.get) should equal((0 to 9).toArray.mkString(""))

    val node = LinkedListAlgo.deleteLastKthNode(list.headOpt, 10)
    assert(node.isDefined)
    LinkedListAlgo.mkStringForChain(node.get) should equal("123456789")
  }

  it should "delete firs only element " in {
    val list = new SinglyLinkedList()
    list.insertTail(0)

    val node = LinkedListAlgo.deleteLastKthNode(list.headOpt, 1)
    assert(node.isEmpty)
  }

  it should "throw exception if k < 0 " in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    assertThrows[IllegalArgumentException] {
      LinkedListAlgo.deleteLastKthNode(list.headOpt, -1)
    }
  }

  it should "throw exception if k greater than list length " in {
    val list = new SinglyLinkedList()

    for (i <- 0 to 9) {
      list.insertTail(i)
    }
    assertThrows[IllegalArgumentException] {
      LinkedListAlgo.deleteLastKthNode(list.headOpt, 15)
    }
  }

}
