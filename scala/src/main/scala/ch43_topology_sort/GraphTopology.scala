package ch43_topology_sort

import scala.collection.mutable

class GraphTopology(vertex: Int) {

  //define the graph
  val adjacency = new Array[mutable.MutableList[Int]](vertex)
  for (i <- Range(0, vertex)) {
    adjacency(i) = new mutable.MutableList[Int]()
  }

  def addEdge(startIndex: Int, targetIndex: Int) = {
    adjacency(startIndex) += targetIndex
  }

  def topologySortByKahn(): Array[Int] = {
    val seq = new mutable.ArrayBuffer[Int]()
    //inDgrees contains all the inDegree for a given node
    val inDegrees = new Array[Int](vertex)
    for (i <- Range(0, vertex)) {
      for (j <- adjacency(i).indices) {
        val index = adjacency(i).get(j).get
        inDegrees(index) += 1
      }
    }

    val queue = new mutable.Queue[Int]()
    for (i <- inDegrees.indices) {
      if (inDegrees(i) == 0) {
        // means there is no inDegree for this node,
        // this could be the starting point of the dependency graph
        queue += i
      }
    }

    //start to navigating the graph from the starting point
    while (queue.nonEmpty) {
      val index = queue.dequeue()

      //push to the result
      seq += index

      for (i <- adjacency(index).indices) {
        val inDegreeIndex = adjacency(index).get(i).get
        inDegrees(inDegreeIndex) -= 1

        if (inDegrees(inDegreeIndex) == 0) {
          queue += inDegreeIndex
        }
      }
    }

    seq.toArray
  }
}


