package ch31_graph

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._

class Graph(vertex: Array[String]) {

  require(vertex.nonEmpty, "nonEmpty vertex required")
  val adjacency = new Array[mutable.MutableList[String]](vertex.length)
  for (i <- Range(0, vertex.length)) {
    adjacency(i) = new mutable.MutableList[String]()
  }

  def addEdge(startNode: String, endNode: String): Unit = {
    adjacency(vertex.indexOf(startNode)) += endNode
    adjacency(vertex.indexOf(endNode)) += startNode
  }

  def getEdges(node: String): Array[String] = {
    adjacency(vertex.indexOf(node)).toArray
  }

  def breathFirstSearch(startNode: String, destNode: String): Option[Array[String]] = {
    var result: Option[Array[String]] = None
    val queue = new mutable.Queue[String]()
    val visited = new mutable.HashSet[String]()
    val explored = new ArrayBuffer[String]()

    //put starting node into the queue
    queue += startNode
    breakable {
      while (queue.nonEmpty) {
        val node = queue.dequeue()
        if (!visited.contains(node)) {
          explored += node
          visited += node

          if (node.equals(destNode)) {
            result = Some(explored.toArray)
            break
          }
          queue ++= adjacency(vertex.indexOf(node))
        }

      }
    }

    result
  }

  def depthFirstSearch(startNode: String, destNode: String): Option[Array[String]] = {
    var found = false
    val visited = new mutable.HashSet[String]()
    val explored = new ArrayBuffer[String]()

    def _dfs(start: String): Unit = {
      if (found) {
        return
      }
      if (!visited.contains(start)) {
        visited += start
        explored += start
        val destsForStart: mutable.MutableList[String] = adjacency(vertex.indexOf(start))

        breakable {
          for (i <- destsForStart.indices) {
            val node = destsForStart(i)
            if (node.equals(destNode)) {
              found = true
              if (!explored.contains(node)) {
                explored += node
              }
              break()
            }
            _dfs(node)
          }
        }
      }
    }

    _dfs(startNode)
    if (found) {
      Some(explored.toArray)
    } else {
      None
    }
  }
}
