package ch23_binary_tree

import org.scalatest.{BeforeAndAfterEach, FlatSpec, Matchers}

class BinaryTreeTest extends FlatSpec with BeforeAndAfterEach with Matchers {

  /*
   *         A
   *        / \
   *       B   C
   *      / \ / \
   *     D  E F  G
   *
   */
  var root: Option[Node[String]] = None
  val tree = new BinaryTree[String]

  override def beforeEach() {
    val D = new Node[String]("D", None, None)
    val E = new Node[String]("E", None, None)
    val B = new Node[String]("B", Some(D), Some(E))
    val F = new Node[String]("F", None, None)
    val G = new Node[String]("G", None, None)
    val C = new Node[String]("C", Some(F), Some(G))
    val A = new Node[String]("A", Some(B), Some(C))
    root = Some(A)
  }

  override protected def afterEach(): Unit = {
    root = None
  }

  behavior of "BinaryTreeTest"

  it should "postOrder" in {
    tree.postOrder(root) should equal("DEBFGCA")
  }

  it should "inOrder" in {
    tree.inOrder(root) should equal("DBEAFCG")
  }

  it should "preOrder" in {
    tree.preOrder(root) should equal("ABDECFG")
  }

  it should "levelOrder" in {
    tree.levelOrder(root) should equal("ABCDEFG")
  }
}
