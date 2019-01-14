package ch35_tire_tree

import org.scalatest.{FlatSpec, Matchers}

class TrieTreeTest extends FlatSpec with Matchers {

  behavior of "TrieTreeTest"

  it should "insert data into the tree and find it back" in {
    val texts = Array("how", "hi", "her", "hello", "so", "see")
    val tree = new TrieTree()
    for (i <- texts.indices) {
      tree.insert(texts(i).toCharArray)
    }

    for (i <- texts.indices) {
      assert(tree.find(texts(i).toCharArray))
    }
  }

  it should "find prefix" in {
    val texts = Array("how", "hi", "her", "hello", "so", "see")
    val tree = new TrieTree()
    for (i <- texts.indices) {
      tree.insert(texts(i).toCharArray)
    }

    for (i <- texts.indices) {
      assert(tree.prefix(texts(i).toCharArray.slice(0, 1)))
    }

    assert(!tree.prefix("howlo".toCharArray))
    assert(!tree.prefix("aaa".toCharArray))
  }

  it should "give suggestion" in {
    val texts = Array("how", "hi", "her", "hello", "so", "see")
    val tree = new TrieTree()
    for (i <- texts.indices) {
      tree.insert(texts(i).toCharArray)
    }

    tree.suggestion("he".toCharArray).get should contain("her")
    tree.suggestion("he".toCharArray).get should contain("hello")
    tree.suggestion("he".toCharArray).get.size should equal(2)
  }

}
