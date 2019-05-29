package ch17_skip_list

import scala.util.Random

class Node(var data: Int, var forwards: Array[Node], var maxLevel: Int)

class SkipList(var head: Node, var skipListLevel: Int) {

  def this() = this(new Node(-1, new Array[Node](16), 0), 1)

  val MAX_LEVEL = 16
  val random = new Random()

  def find(value: Int): Option[Node] = {
    var p = head
    for (i <- skipListLevel - 1 to 0 by -1) {
      while (p.forwards(i) != null && p.forwards(i).data < value) {
        p = p.forwards(i)
      }
    }
    if (p.forwards(0) != null && p.forwards(0).data == value) {
      Some(p.forwards(0))
    } else {
      None
    }
  }

  def insert(value: Int): Unit = {
    //init the new node
    val level = randomLevel()
    val newNode = new Node(value, new Array[Node](level), level)

    //use updtes array to record all nodes in all level before the inserted node
    val updates: Array[Node] = new Array[Node](level)
    var p = head
    for (i <- level - 1 to 0 by -1) {
      while (p.forwards(i) != null && p.forwards(i).data < value) {
        p = p.forwards(i)
      }
      updates(i) = p
    }

    for (i <- Range(0, level)) {
      newNode.forwards(i) = updates(i).forwards(i)
      updates(i).forwards(i) = newNode
    }

    if (level > skipListLevel) {
      skipListLevel = level
    }
  }

  def delete(value: Int): Unit = {
    var p = head
    val updates: Array[Node] = new Array[Node](skipListLevel)

    //try to locate the given node with the value
    for (i <- skipListLevel - 1 to 0 by -1) {
      while (p.forwards(i) != null && p.forwards(i).data < value) {
        p = p.forwards(i)
      }
      updates(i) = p
    }

    if (p.forwards(0) != null && p.forwards(0).data == value) {
      //find the value node, start to delete the node from the skip list
      for (i <- skipListLevel - 1 to 0 by -1) {
        if (updates(i).forwards(i) != null && updates(i).forwards(i).data == value) {
          updates(i).forwards(i) = updates(i).forwards(i).forwards(i)
        }
      }
    }

  }

  def randomLevel(): Int = {
    var level = 1
    for (i <- Range(1, MAX_LEVEL)) {
      if (random.nextInt() % 2 == 1) {
        level += 1
      }
    }

    level
  }

  def mkString(): String = {
    val builder = new StringBuilder
    var p = head
    while (p.forwards(0) != null) {
      p = p.forwards(0)
      builder.append(p.data)
    }

    builder.mkString
  }
}


