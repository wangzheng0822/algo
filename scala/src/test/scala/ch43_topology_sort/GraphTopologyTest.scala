package ch43_topology_sort

import org.scalatest.{FlatSpec, Matchers}

class GraphTopologyTest extends FlatSpec with Matchers {

  behavior of "GraphTopologyTest"

  /*
     a -> b
     |    |
    \|/  \|/
     c -> d -> e
   */
  it should "topologySortByKahn - 1" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 1)
    graphTopology.addEdge(0, 2)
    graphTopology.addEdge(1, 3)
    graphTopology.addEdge(2, 3)
    graphTopology.addEdge(3, 4)

    val seq = graphTopology.topologySortByKahn()
    seq.map(nodes(_)).mkString(",") should equal("a,b,c,d,e")
  }

  /*
     a -> d ---
          |    |
         \|/  \|/
          e -> c
   */
  it should "topologySortByKahn - 2" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 3)
    graphTopology.addEdge(3, 4)
    graphTopology.addEdge(3, 2)
    graphTopology.addEdge(4, 2)

    val seq = graphTopology.topologySortByKahn()
    seq.map(nodes(_)).mkString(",") should equal("a,b,d,e,c")
  }

  /*
     a -> d <- b
          |   /|\
         \|/   |
          e -> c
   */
  it should "topologySortByKahn - 3" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 3)
    graphTopology.addEdge(3, 4)
    graphTopology.addEdge(4, 2)
    graphTopology.addEdge(2, 1)
    graphTopology.addEdge(1, 3)

    val seq = graphTopology.topologySortByKahn()
    seq.map(nodes(_)).mkString(",") should equal("a")
  }

  /*
     a -> b
     |    |
    \|/  \|/
     c -> d -> e
   */
  it should "topologySortByDFS - 1" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 1)
    graphTopology.addEdge(0, 2)
    graphTopology.addEdge(1, 3)
    graphTopology.addEdge(2, 3)
    graphTopology.addEdge(3, 4)

    val seq = graphTopology.topologySortByDFS()
    seq.map(nodes(_)).mkString(",") should equal("a,b,c,d,e")
  }

  /*
     a -> d ---
          |    |
         \|/  \|/
          e -> c
   */
  it should "topologySortByDFS - 2" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 3)
    graphTopology.addEdge(3, 4)
    graphTopology.addEdge(3, 2)
    graphTopology.addEdge(4, 2)

    val seq = graphTopology.topologySortByDFS()
    seq.map(nodes(_)).mkString(",") should equal("a,b,d,e,c")
  }

  /*
     a -> d <- b
          |   /|\
         \|/   |
          e -> c
   */
  it should "topologySortByDFS - 3" in {
    val nodes = Array("a", "b", "c", "d", "e")
    val graphTopology = new GraphTopology(nodes.length)
    graphTopology.addEdge(0, 3)
    graphTopology.addEdge(3, 4)
    graphTopology.addEdge(4, 2)
    graphTopology.addEdge(2, 1)
    graphTopology.addEdge(1, 3)

    val seq = graphTopology.topologySortByKahn()
    seq.map(nodes(_)).mkString(",") should equal("a")
  }
}
