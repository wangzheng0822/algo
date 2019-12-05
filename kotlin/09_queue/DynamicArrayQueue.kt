
/**
 *
 * Desc:动态队列
 * <p>
 * Date: 2019-12-05
 * Updater:
 * Update Time:
 * Update Comments:
 *
 * Author: pengyushan
 */
class DynamicArrayQueue(private val capacity: Int) {
    // 数组：items，数组大小：n
    private val items: Array<String?> = arrayOfNulls(capacity)
    // 队头下标
    private var head = 0
    //队尾下标
    private var tail = 0

    // 入队操作，将item放入队尾
    fun enqueue(item: String?): Boolean {
        // tail == n表示队列末尾没有空间了
        if (tail == capacity) {
            // tail ==n && head==0，表示整个队列都占满了
            if (head == 0) return false
            // 数据搬移
            for (i in head until tail) {
                items[i - head] = items[i]
            }
            // 搬移完之后重新更新head和tail
            tail -= head
            head = 0
        }
        items[tail] = item
        tail++
        return true
    }

    // 出队
    fun dequeue(): String? { // 如果head == tail 表示队列为空
        if (head == tail) return null
        val ret = items[head]
        ++head
        return ret
    }

}