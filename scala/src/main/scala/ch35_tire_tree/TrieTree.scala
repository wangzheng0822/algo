package ch35_tire_tree

import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._

class TrieNode(var data: Char, var children: Array[TrieNode], var isEndNode: Boolean = false) {

  def this(data: Char) = this(data, new Array[TrieNode](26))

}

class TrieTree {

  val root = new TrieNode('/') //root node without any data

  def insert(text: Array[Char]): Unit = {
    var p = root
    for (i <- text.indices) {
      val index = text(i) - 'a'
      if (p.children(index) == null) {
        val node = new TrieNode(text(i))
        p.children(index) = node
      }
      p = p.children(index)
    }
    //now p is pointing the leaf node
    p.isEndNode = true
  }

  def find(text: Array[Char]): Boolean = {
    var p = root

    breakable {
      for (i <- text.indices) {
        val index = text(i) - 'a'
        if (p.children(index) == null) {
          break
        }
        p = p.children(index)
      }
    }

    p.isEndNode
  }

  def prefix(prefix: Array[Char]): Boolean = {
    var p = root
    var level = -1
    breakable {
      for (i <- prefix.indices) {
        val index = prefix(i) - 'a'
        if (p.children(index) == null) {
          break
        }
        p = p.children(index)
        level = i
      }
    }

    //should not reach leaf node and should have at least 1 matching level
    !p.isEndNode && level > -1
  }

  def suggestion(text: Array[Char]): Option[Array[String]] = {
    var p = root
    var level = -1
    breakable {
      for (i <- text.indices) {
        val index = text(i) - 'a'
        if (p.children(index) == null) {
          break
        }
        p = p.children(index)
        level = i
      }
    }
    //have prefix matching
    if (!p.isEndNode && level > -1) {
      //now the problem becomes print all the children from p
      Some(_children(p).map(str => "%s%s".format(text.slice(0, text.length - 1).mkString(""), str)).toArray)
    } else {
      None
    }

  }

  def _children(p: TrieNode): ArrayBuffer[String] = {
    if (p.isEndNode) {
      return ArrayBuffer(p.data.toString)
    }

    //p is not leaf node
    val arrayBuffer = new ArrayBuffer[String]()
    for (i <- p.children.indices) {
      if (p.children(i) != null) {
        _children(p.children(i)).foreach(subStr =>
          arrayBuffer.append("%s%s".format(p.data.toString, subStr))
        )
      }
    }

    arrayBuffer
  }


}
