package ch20_linked_hash_map

import org.scalatest.{FlatSpec, Matchers}

class LRUCacheTest extends FlatSpec with Matchers {

  behavior of "LRUCacheTest"

  it should "put data and get back" in {
    val cache = new LRUCache[Int, Int](2)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.get(1) should equal(Some(1)) // returns 1
    cache.put(3, 3) // evicts key 2
    cache.get(2) should equal(None) //should not find
    cache.put(4, 4) // evicts key 1
    cache.get(1) should equal(None) //should not find
    cache.get(3) should equal(Some(3)) // returns 3
    cache.get(4) should equal(Some(4)) // returns 4
  }

}
