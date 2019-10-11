import java.util.HashMap;

/**
 * @Description:基于散列表的LRU算法
 * @Author: Hoda
 * @Date: Create in 2019-08-09
 * @Modified By:
 * @Modified Date:
 */
public class LRUBaseHashTable<K, V> {

    /**
     * 默认链表容量
     */
    private final static Integer DEFAULT_CAPACITY = 10;

    /**
     * 头结点
     */
    private DNode<K, V> headNode;

    /**
     * 尾节点
     */
    private DNode<K, V> tailNode;

    /**
     * 链表长度
     */
    private Integer length;

    /**
     * 链表容量
     */
    private Integer capacity;

    /**
     * 散列表存储key
     */
    private HashMap<K, DNode<K, V>> table;

    /**
     * 双向链表
     */
    static class DNode<K, V> {

        private K key;

        /**
         * 数据
         */
        private V value;

        /**
         * 前驱指针
         */
        private DNode<K, V> prev;

        /**
         * 后继指针
         */
        private DNode<K, V> next;

        DNode() {
        }

        DNode(K key, V value) {
            this.key = key;
            this.value = value;
        }

    }

    public LRUBaseHashTable(int capacity) {
        this.length = 0;
        this.capacity = capacity;

        headNode = new DNode<>();

        tailNode = new DNode<>();

        headNode.next = tailNode;
        tailNode.prev = headNode;

        table = new HashMap<>();
    }

    public LRUBaseHashTable() {
        this(DEFAULT_CAPACITY);
    }

    /**
     * 新增
     *
     * @param key
     * @param value
     */
    public void add(K key, V value) {
        DNode<K, V> node = table.get(key);
        if (node == null) {
            DNode<K, V> newNode = new DNode<>(key, value);
            table.put(key, newNode);
            addNode(newNode);

            if (++length > capacity) {
                DNode<K, V> tail = popTail();
                table.remove(tail.key);
                length--;
            }
        } else {
            node.value = value;
            moveToHead(node);
        }
    }

    /**
     * 将新节点加到头部
     *
     * @param newNode
     */
    private void addNode(DNode<K, V> newNode) {
        newNode.next = headNode.next;
        newNode.prev = headNode;

        headNode.next.prev = newNode;
        headNode.next = newNode;
    }

    /**
     * 弹出尾部数据节点
     */
    private DNode<K, V> popTail() {
        DNode<K, V> node = tailNode.prev;
        removeNode(node);
        return node;
    }

    /**
     * 移除节点
     *
     * @param node
     */
    private void removeNode(DNode<K, V> node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    /**
     * 将节点移动到头部
     *
     * @param node
     */
    private void moveToHead(DNode<K, V> node) {
        removeNode(node);
        addNode(node);
    }

    /**
     * 获取节点数据
     *
     * @param key
     * @return
     */
    public V get(K key) {
        DNode<K, V> node = table.get(key);
        if (node == null) {
            return null;
        }
        moveToHead(node);
        return node.value;
    }

    /**
     * 移除节点数据
     *
     * @param key
     */
    public void remove(K key) {
        DNode<K, V> node = table.get(key);
        if (node == null) {
            return;
        }
        removeNode(node);
        length--;
        table.remove(node.key);
    }

    private void printAll() {
        DNode<K, V> node = headNode.next;
        while (node.next != null) {
            System.out.print(node.value + ",");
            node = node.next;
        }
        System.out.println();
    }
}
