package lru;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dell on 2019/3/19.
 */
public class LRUCache<K, V> {

    private int capacity;
    private Node head;
    private Node tail;
    private Map<K, Node> nodeMap;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.nodeMap = new HashMap<>(capacity);
    }

    /**
     * Get Key
     *
     * @param key
     * @return
     */
    public V get(K key) {
        Node existNode = nodeMap.get(key);
        if (existNode == null) {
            return null;
        }
        remove(existNode);
        addFirst(existNode);
        return existNode.value;
    }

    /**
     * Add Key-Value
     *
     * @param key
     * @param value
     */
    public void put(K key, V value) {
        Node existNode = nodeMap.get(key);
        if (existNode == null) {
            Node newNode = new Node(key, value);
            if (nodeMap.size() >= capacity) {
                removeLast();
            }
            addFirst(newNode);
        }
        else {
            // update the value
            existNode.value = value;
            remove(existNode);
            addFirst(existNode);
        }
    }

    /**
     * remove node
     *
     * @param node
     */
    private void remove(Node node) {
        Node prev = node.prev;
        Node next = node.next;

        if (prev == null) {
            head = next;
        } else {
            prev.next = next;
        }
        if (next == null) {
            tail = prev;
        } else {
            next.prev = prev;
        }
        nodeMap.remove(node.key);
    }

    /**
     * add first node
     *
     * @param node
     */
    private void addFirst(Node node) {
        // don't forget set node prev pointer to null !
        node.prev = null;
        if (head == null) {
            head = tail = node;
        } else {
            node.next = head;
            head.prev = node;
            head = node;
        }
        nodeMap.put(node.key, node);
    }

    /**
     * remove last
     */
    private void removeLast() {
        if (tail == null) {
            return;
        }
        // remove key from map
        nodeMap.remove(tail.key);
        // remove node from linked list
        Node prev = tail.prev;
        if (prev != null) {
            prev.next = null;
            tail = prev;
        } else {
            head = tail = null;
        }
    }

    private class Node {

        private K key;
        private V value;
        private Node prev;
        private Node next;

        private Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}