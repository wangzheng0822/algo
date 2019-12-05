
/**
 *
 * Desc:循环队列
 * <p>
 * Date: 2019-12-05
 * Updater:
 * Update Time:
 * Update Comments:
 *
 * Author: pengyushan
 */
class CircularQueue(private val capacity: Int) {
    // 数组：items，数组大小：n
    private val items: Array<String?> = arrayOfNulls(capacity)
    // 队头下标
    private var head = 0
    //队尾下标
    private var tail = 0

    // 入队
    fun enqueue(item: String?): Boolean {
        // 队列满了
        if ((tail + 1) % capacity == head) return false
        items[tail] = item
        tail = (tail + 1) % capacity
        return true
    }

    // 出队
    fun dequeue(): String? {
        // 判断队列是否是空的
        if (items.isEmpty()) return null
        val ret = items[head]
        head = (head + 1) % capacity
        return ret
    }

}