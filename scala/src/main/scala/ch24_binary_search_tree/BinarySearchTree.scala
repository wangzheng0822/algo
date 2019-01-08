package ch24_binary_search_tree

import ch23_binary_tree.{BinaryTree, Node}

import scala.util.control.Breaks._

class BinarySearchTree(var root: Option[Node[Int]]) extends BinaryTree[Int] {

  def insert(data: Int): Node[Int] = {
    val dataNode = new Node(data, None, None)
    root match {
      case None => root = Some(dataNode)
      case Some(_) => {
        var p = root
        breakable {
          while (p.isDefined) {
            if (data > p.get.data) {
              p.get.right match {
                case None => {
                  p.get.right = Some(dataNode)
                  break
                }
                case Some(_) => p = p.get.right
              }
            }
            if (data < p.get.data) {
              p.get.left match {
                case None => {
                  p.get.left = Some(dataNode)
                  break
                }
                case Some(_) => p = p.get.left
              }
            }
          }
        }
      }
    }

    dataNode
  }

  def find(data: Int): Option[Node[Int]] = {
    var p = root
    breakable {
      while (p.isDefined) {
        if (data > p.get.data) {
          p = p.get.right
        } else if (data < p.get.data) {
          p = p.get.left
        } else {
          //find the value
          break
        }
      }
    }
    p
  }

  def delete(data: Int): Unit = {
    //there are 3 scenarios
    //1: data is leaf node
    //2: data has one child node
    //3: data has two child nodes, we need to find out the smallest node from right branch
    var p = root
    var pp: Option[Node[Int]] = None //parent node of deleted node

    //find matching node to delete
    breakable {
      while (p.isDefined) {
        if (data > p.get.data) {
          pp = p
          p = p.get.right
        } else if (data < p.get.data) {
          pp = p
          p = p.get.left
        } else {
          //find the value
          break
        }
      }
    }

    if (p.isEmpty) {
      //find nothing
      return
    }

    //now we find the node to delete
    //scenario 3
    if (p.get.left.isDefined && p.get.right.isDefined) {
      //need to find out the smallest node in right branch
      var minPP = p
      var minP = p.get.right
      while (minP.get.left.isDefined) {
        minPP = minP
        minP = minP.get.left
      }

      //assign the smallest value in the right branch to the node to be deleted
      p.get.data = minP.get.data
      //now problems becomes delete the minP in the tree
      //minP must not have any left child node
      //minP may or may not have right child node
      //it will fall back to scenario 1 or 2
      p = minP
      pp = minPP
    }

    //child is the child of p
    var child: Option[Node[Int]] = None
    if (p.get.left.isDefined) {
      child = p.get.left
    } else if (p.get.right.isDefined) {
      child = p.get.right
    }

    //starting the node deletion
    pp match {
      case None => root = child
      case Some(parentNode) => {
        if (parentNode.left == p) {
          parentNode.left = child
        } else if (parentNode.right == p) {
          parentNode.right = child
        }
      }
    }

  }

  def height(): Int = {
    _height(root)
  }

  private[this] def _height(nodeOpt: Option[Node[Int]]): Int = {
    nodeOpt match {
      case None => 0
      case Some(node) => {
        if (node.left.isEmpty && node.right.isEmpty) {
          1
        } else {
          scala.math.max(_height(node.left), _height(node.right)) + 1
        }
      }
    }
  }
}
