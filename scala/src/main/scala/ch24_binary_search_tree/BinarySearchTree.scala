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
}
