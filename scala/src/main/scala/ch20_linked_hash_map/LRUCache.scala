package ch20_linked_hash_map

class Node[K, V](var key: Option[K], var data: Option[V], var prev: Option[Node[K, V]], var next: Option[Node[K, V]],
                 var hNext: Option[Node[K, V]]) {

  def this(key: Option[K], data: Option[V]) = this(key, data, None, None, None)
}

/**
  * LRU cache - https://leetcode.com/problems/lru-cache/ see unit test from LRUCacheTest
  *
  * @author email2liyang@gmail.com
  */
class LRUCache[K, V](var head: Node[K, V], var tail: Node[K, V], var table: Array[Node[K, V]],
                     capacity: Int = 1000, var elementCount: Int = 0) {

  head.next = Some(tail)
  tail.prev = Some(head)

  def this(capacity: Int) = this(new Node(None, None), new Node(None, None), new Array[Node[K, V]](capacity), capacity)

  def get(key: K): Option[V] = {
    val index = indexFor(key.hashCode())
    var hNode = table(index)
    if (hNode == null) {
      None
    } else {
      while (!hNode.key.get.equals(key) && hNode.hNext.isDefined) {
        hNode = hNode.hNext.get
      }
      if (hNode.key.get.equals(key)) {
        //move this to the end of the linked list
        moveHNodeToTail(hNode)
        hNode.data
      } else {
        None
      }
    }
  }


  //put data into the linked hash map
  //1: check if the data exist in the linked list
  //2: if it's not exist , append it in the linked list
  //3: if it's exist in the list, move it to the tail of the linked list
  //4: return old value if it's exist
  def put(key: K, value: V): Option[V] = {

    if (elementCount == capacity) {
      deleteLRUElement()
    }

    val node = new Node(Some(key), Some(value))
    val index = indexFor(key.hashCode())
    var hNode = table(index)
    var result: Option[V] = None
    if (hNode == null) {
      //if it's not exist , append it in the linked list
      node.prev = tail.prev
      node.next = Some(tail)
      tail.prev.get.next = Some(node)
      tail.prev = Some(node)
      table(index) = node
      elementCount += 1
    } else {
      //we find a key conflict in the hash table
      //start to loop the hNode to match the key
      while (!hNode.key.get.equals(key) && hNode.hNext.isDefined) {
        hNode = hNode.hNext.get
      }

      if (hNode.key.get.equals(key)) {
        //find the old data from the hash table
        result = hNode.data
        hNode.data = Some(value)
        //move the node to the tail of the linked list
        moveHNodeToTail(hNode)
        //hNext pointer stay untouched
      } else {
        //could not find the old data
        //put the new node into the tail of the linked list
        node.prev = tail.prev
        node.next = Some(tail)
        tail.prev.get.next = Some(node)
        tail.prev = Some(node)

        //put it the tail of the hash table's list
        //iterator to the end of hNode
        while (hNode.hNext.isDefined) {
          hNode = hNode.hNext.get
        }
        hNode.hNext = Some(node)
        elementCount += 1
      }
    }
    result
  }

  private[this] def moveHNodeToTail(hNode: Node[K, V]) = {
    hNode.prev.get.next = hNode.next
    hNode.next.get.prev = hNode.prev
    hNode.prev = tail.prev
    hNode.next = Some(tail)
    tail.prev.get.next = Some(hNode)
    tail.prev = Some(hNode)
  }

  private[this] def deleteLRUElement(): Unit = {
    //cache is full, start to delete element from the head
    val node = head.next.get

    //delete it from head
    node.next.get.prev = Some(head)
    head.next = node.next

    //deal with hNext in the table
    val index = indexFor(node.key.get.hashCode())
    var hNode = table(index)
    //deal with first element in the hash table
    if (hNode.key.get.equals(node.key.get)) {
      hNode.hNext match {
        case Some(n) => table(index) = n
        case None => table(index) = null
      }
    } else {
      //deal with not first element in the hash table
      var hNodePrev = hNode
      hNode = hNode.next.get
      while (!hNode.key.get.equals(node.key.get)) {
        hNode = hNode.next.get
        hNodePrev = hNodePrev.next.get
      }
      //now hNodePrev is the previous hNode in the hashtable
      //remove the hNode
      hNodePrev.next = hNode.next

      hNode.next match {
        case Some(n) => n.prev = Some(hNodePrev)
        case None =>
      }
    }

    elementCount -= 1
  }

  private[this] def indexFor(hash: Int): Int = {
    hash % table.length
  }
}
