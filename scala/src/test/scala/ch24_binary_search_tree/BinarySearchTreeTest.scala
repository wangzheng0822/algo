package ch24_binary_search_tree

import org.scalatest.{FlatSpec, Matchers}

class BinarySearchTreeTest extends FlatSpec with Matchers {

  /*
   *                 33
   *              /      \
   *             17       50
   *           /    \   /   \
   *          13    18 34   58
   *           \     \      / \
   *            16   25    51  66
   *                /  \    \
   *               19  27    55
   *
   */
  behavior of "BinarySearchTreeTest"

  it should "insert" in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33, 17, 50, 13, 18, 34, 58, 16, 25, 51, 66, 19, 27, 55)
    nums.foreach(tree.insert)
    tree.inOrder(tree.root) should equal(nums.sorted.mkString(""))
    tree.preOrder(tree.root) should equal("3317131618251927503458515566")
    tree.postOrder(tree.root) should equal("1613192725181734555166585033")
    tree.levelOrder(tree.root) should equal("3317501318345816255166192755")
  }

  it should "find " in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33, 17, 50, 13, 18, 34, 58, 16, 25, 51, 66, 19, 27, 55)
    nums.foreach(tree.insert)

    nums.foreach(num => {
      assert(tree.find(num).isDefined)
      tree.find(num).get.data should equal(num)
    })
    assert(tree.find(100).isEmpty)
  }

  it should "delete" in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33, 17, 50, 13, 18, 34, 58, 16, 25, 51, 66, 19, 27, 55)
    nums.foreach(tree.insert)
    tree.delete(13)
    tree.inOrder(tree.root) should equal(nums.sorted.tail.mkString(""))
    tree.delete(18)
    tree.inOrder(tree.root) should equal("1617" + nums.sorted.slice(4, nums.size).mkString(""))
    tree.delete(66)
    tree.inOrder(tree.root) should equal("1617" + nums.sorted.slice(4, nums.size - 1).mkString(""))
  }

  it should "calc height of a tree -1" in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33, 17, 50, 13, 18, 34, 58, 16, 25, 51, 66, 19, 27, 55)
    nums.foreach(tree.insert)
    tree.height() should equal(5)
  }

  it should "calc height of a tree -2" in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33, 17, 50, 13, 18, 34, 88).sorted
    nums.foreach(tree.insert)
    tree.height() should equal(7)
  }

  it should "calc height of a tree -3" in {
    val tree = new BinarySearchTree(None)
    val nums = Array(33).sorted
    nums.foreach(tree.insert)
    tree.height() should equal(1)
  }

}
