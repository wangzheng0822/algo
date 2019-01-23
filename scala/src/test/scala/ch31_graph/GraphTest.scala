package ch31_graph

import org.scalatest.{FlatSpec, Matchers}

class GraphTest extends FlatSpec with Matchers {

  /*
        0 - 1 - 2
        |   |   |
        3 - 4 - 5
            |   |
            6 - 7
   */

  behavior of "GraphTest"

  def initGraph: Graph = {
    val num = 8
    val vertex = new Array[String](num)
    for (i <- Range(0, num)) {
      vertex(i) = i.toString
    }
    val graph = new Graph(vertex)

    graph.addEdge("0", "1")
    graph.addEdge("1", "2")
    graph.addEdge("0", "3")
    graph.addEdge("1", "4")
    graph.addEdge("2", "5")
    graph.addEdge("3", "4")
    graph.addEdge("4", "5")
    graph.addEdge("4", "6")
    graph.addEdge("5", "7")
    graph.addEdge("6", "7")
    graph
  }

  it should "construct the graph" in {
    val graph: Graph = initGraph

    graph.getEdges("0").sorted should equal(Array("1", "3"))
    graph.getEdges("1").sorted should equal(Array("0", "2", "4"))
    graph.getEdges("2").sorted should equal(Array("1", "5"))
    graph.getEdges("3").sorted should equal(Array("0", "4"))
    graph.getEdges("4").sorted should equal(Array("1", "3", "5", "6"))
    graph.getEdges("5").sorted should equal(Array("2", "4", "7"))
    graph.getEdges("6").sorted should equal(Array("4", "7"))
    graph.getEdges("7").sorted should equal(Array("5", "6"))
  }

  it should "do breath first search in graph" in {
    val graph: Graph = initGraph
    graph.breathFirstSearch("0", "4").get should equal(Array("0", "1", "3", "2", "4"))
    graph.breathFirstSearch("1", "5").get should equal(Array("1", "0", "2", "4", "3", "5"))
    assert(graph.breathFirstSearch("1", "8").isEmpty)
  }

  it should "do depth first search in graph" in {
    val graph: Graph = initGraph
    graph.depthFirstSearch("0", "4").get should equal(Array("0", "1", "2", "5", "4"))
    graph.depthFirstSearch("1", "5").get should equal(Array("1", "0", "3", "4", "5"))
    assert(graph.depthFirstSearch("1", "8").isEmpty)
  }
}
