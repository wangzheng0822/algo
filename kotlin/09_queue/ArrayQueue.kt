package com.wil.leetcode.algo_09_queue

/**
 *
 * Desc:用数组实现的队列,申请容量大小的数组
 * <p>
 * Date: 2019-12-05
 * Updater:
 * Update Time:
 * Update Comments:
 *
 * Author: pengyushan
 */
class ArrayQueue(private val capacity: Int) {
    // 定义容量大小的数组
    private val items: Array<String?> = arrayOfNulls(capacity)
    // 队头下标
    private var head = 0
    //队尾下标
    private var tail = 0

    // 入队
    fun enqueue(item: String?): Boolean {
        // 如果队尾已经等于n了，表示队列已经满了
        if (tail == capacity) return false
        items[tail] = item
        ++tail
        return true
    }

    // 出队
    fun dequeue(): String? {
        // 如果head == tail 表示队列为空
        if (head == tail) return null
        val ret = items[head]
        ++head
        return ret
    }
}