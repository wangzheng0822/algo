package ch23_binary_tree

import scala.collection.mutable

class Node[T](var data: T, var left: Option[Node[T]], var right: Option[Node[T]])

class BinaryTree[T] {

  def preOrder(root: Option[Node[T]]): String = {
    val result = new StringBuilder

    if (root.isDefined) {
      result.append(root.map(_.data.toString).get)
      result.append(preOrder(root.get.left))
      result.append(preOrder(root.get.right))
    }
    result.mkString
  }

  def inOrder(root: Option[Node[T]]): String = {
    val result = new StringBuilder

    if (root.isDefined) {
      result.append(inOrder(root.get.left))
      result.append(root.map(_.data.toString).get)
      result.append(inOrder(root.get.right))
    }
    result.mkString
  }

  def postOrder(root: Option[Node[T]]): String = {
    val result = new StringBuilder

    if (root.isDefined) {
      result.append(postOrder(root.get.left))
      result.append(postOrder(root.get.right))
      result.append(root.map(_.data.toString).get)
    }
    result.mkString
  }

  def levelOrder(root: Option[Node[T]]): String = {
    val result = new StringBuilder
    val queue = new mutable.Queue[Node[T]]()
    if (root.isDefined) {
      queue += root.get
      while (!queue.isEmpty) {
        val node = queue.dequeue()
        result.append(node.data.toString)
        if (node.left.isDefined) {
          queue += node.left.get
        }
        if (node.right.isDefined) {
          queue += node.right.get
        }
      }
    }

    result.mkString
  }
}
