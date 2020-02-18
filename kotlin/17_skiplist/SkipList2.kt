package com.study.skiplist

import java.util.*

/**
 * 1，跳表的一种实现方法，用于练习。跳表中存储的是正整数，并且存储的是不重复的。
 * 2，本类是参考作者zheng ，自己学习，优化了添加方法
 * 3，看完这个，我觉得再看ConcurrentSkipListMap 源码，会有很大收获
 * Author：ldb
 */
class SkipList2 {
    private var levelCount = 1
    /**
     * 带头链表
     */
    private val head =
        Node(MAX_LEVEL)
    private val r = Random()
    fun find(value: Int): Node? {
        var p: Node? = head
        // 从最大层开始查找，找到前一节点，通过--i，移动到下层再开始查找
        for (i in levelCount - 1 downTo 0) {
            while (p!!.forwards[i] != null && p.forwards[i]!!.data < value) { // 找到前一节点
                p = p.forwards[i]
            }
        }
        return if (p!!.forwards[0] != null && p.forwards[0]!!.data == value) {
            p.forwards[0]
        } else {
            null
        }
    }

    /**
     * 优化了作者zheng的插入方法
     *
     * @param value 值
     */
    fun insert(value: Int) {
        var level = if (head.forwards[0] == null) 1 else randomLevel()
        // 每次只增加一层，如果条件满足
        if (level > levelCount) {
            level = ++levelCount
        }
        val newNode = Node(level)
        newNode.data = value
        val update =
            arrayOfNulls<Node>(level)
        for (i in 0 until level) {
            update[i] = head
        }
        var p: Node? = head
        // 从最大层开始查找，找到前一节点，通过--i，移动到下层再开始查找
        for (i in levelCount - 1 downTo 0) {
            while (p!!.forwards[i] != null && p.forwards[i]!!.data < value) { // 找到前一节点
                p = p.forwards[i]
            }
            // levelCount 会 > level，所以加上判断
            if (level > i) {
                update[i] = p
            }
        }
        for (i in 0 until level) {
            newNode.forwards[i] = update[i]!!.forwards[i]
            update[i]!!.forwards[i] = newNode
        }
    }

    /**
     * 优化了作者zheng的插入方法2
     *
     * @param value 值
     */
    fun insert2(value: Int) {
        var level = if (head.forwards[0] == null) 1 else randomLevel()
        // 每次只增加一层，如果条件满足
        if (level > levelCount) {
            level = ++levelCount
        }
        val newNode = Node(level)
        newNode.data = value
        var p: Node? = head
        // 从最大层开始查找，找到前一节点，通过--i，移动到下层再开始查找
        for (i in levelCount - 1 downTo 0) {
            while (p!!.forwards[i] != null && p.forwards[i]!!.data < value) { // 找到前一节点
                p = p.forwards[i]
            }
            // levelCount 会 > level，所以加上判断
            if (level > i) {
                if (p.forwards[i] == null) {
                    p.forwards[i] = newNode
                } else {
                    val next = p.forwards[i]
                    p.forwards[i] = newNode
                    newNode.forwards[i] = next
                }
            }
        }
    }

    /**
     * 作者zheng的插入方法，未优化前，优化后参见上面insert()
     *
     * @param value
     * @param level 0 表示随机层数，不为0，表示指定层数，指定层数
     * 可以让每次打印结果不变动，这里是为了便于学习理解
     */
    fun insert(value: Int, level: Int) { // 随机一个层数
        var level = level
        if (level == 0) {
            level = randomLevel()
        }
        // 创建新节点
        val newNode = Node(level)
        newNode.data = value
        // 表示从最大层到低层，都要有节点数据
        newNode.maxLevel = level
        // 记录要更新的层数，表示新节点要更新到哪几层
        val update =
            arrayOfNulls<Node>(level)
        for (i in 0 until level) {
            update[i] = head
        }
        /**
         *
         * 1，说明：层是从下到上的，这里最下层编号是0，最上层编号是15
         * 2，这里没有从已有数据最大层（编号最大）开始找，（而是随机层的最大层）导致有些问题。
         * 如果数据量为1亿，随机level=1 ，那么插入时间复杂度为O（n）
         */
        var p: Node? = head
        for (i in level - 1 downTo 0) {
            while (p!!.forwards[i] != null && p.forwards[i]!!.data < value) {
                p = p.forwards[i]
            }
            // 这里update[i]表示当前层节点的前一节点，因为要找到前一节点，才好插入数据
            update[i] = p
        }
        // 将每一层节点和后面节点关联
        for (i in 0 until level) { // 记录当前层节点后面节点指针
            newNode.forwards[i] = update[i]!!.forwards[i]
            // 前一个节点的指针，指向当前节点
            update[i]!!.forwards[i] = newNode
        }
        // 更新层高
        if (levelCount < level) levelCount = level
    }

    fun delete(value: Int) {
        val update =
            arrayOfNulls<Node>(levelCount)
        var p: Node? = head
        for (i in levelCount - 1 downTo 0) {
            while (p!!.forwards[i] != null && p.forwards[i]!!.data < value) {
                p = p.forwards[i]
            }
            update[i] = p
        }
        if (p!!.forwards[0] != null && p.forwards[0]!!.data == value) {
            for (i in levelCount - 1 downTo 0) {
                if (update[i]!!.forwards[i] != null && update[i]!!.forwards[i]!!.data == value) {
                    update[i]!!.forwards[i] = update[i]!!.forwards[i]!!.forwards[i]
                }
            }
        }
    }

    /**
     * 随机 level 次，如果是奇数层数 +1，防止伪随机
     *
     * @return
     */
    private fun randomLevel(): Int {
        var level = 1
        for (i in 1 until MAX_LEVEL) {
            if (r.nextInt() % 2 == 1) {
                level++
            }
        }
        return level
    }

    /**
     * 打印每个节点数据和最大层数
     */
    fun printAll() {
        var p: Node? = head
        while (p!!.forwards[0] != null) {
            print(p.forwards[0].toString() + " ")
            p = p.forwards[0]
        }
        println()
    }

    /**
     * 打印所有数据
     */
    fun printAll_beautiful() {
        val p = head
        val c = p.forwards
        var d = c
        val maxLevel = c.size
        for (i in maxLevel - 1 downTo 0) {
            do {
                print((if (d[i] != null) d[i]!!.data else null).toString() + ":" + i + "-------")
            } while (d[i] != null && d[i]!!.forwards.also { d = it }[i] != null)
            println()
            d = c
        }
    }

    /**
     * 跳表的节点，每个节点记录了当前节点数据和所在层数数据
     */
    inner class Node(level: Int) {
        val data = -1
        /**
         * 表示当前节点位置的下一个节点所有层的数据，从上层切换到下层，就是数组下标-1，
         * forwards[3]表示当前节点在第三层的下一个节点。
         */
        val forwards: Array<Node?>
        /**
         * 这个值其实可以不用，看优化insert()
         */
        val maxLevel = 0

        override fun toString(): String {
            val builder = StringBuilder()
            builder.append("{ data: ")
            builder.append(data)
            builder.append("; levels: ")
            builder.append(maxLevel)
            builder.append(" }")
            return builder.toString()
        }

        init {
            forwards = arrayOfNulls(level)
        }
    }

    companion object {
        private const val MAX_LEVEL = 16
        @JvmStatic
        fun main(args: Array<String>) {
            val list = SkipList2()
            list.insert(1, 3)
            list.insert(2, 3)
            list.insert(3, 2)
            list.insert(4, 4)
            list.insert(5, 10)
            list.insert(6, 4)
            list.insert(8, 5)
            list.insert(7, 4)
            list.printAll_beautiful()
            list.printAll()
            /**
             * 结果如下：
             * null:15-------
             * null:14-------
             * null:13-------
             * null:12-------
             * null:11-------
             * null:10-------
             * 5:9-------
             * 5:8-------
             * 5:7-------
             * 5:6-------
             * 5:5-------
             * 5:4-------					 8:4-------
             * 4:3-------5:3-------6:3-------7:3-------8:3-------
             * 1:2-------2:2-------		     4:2-------5:2-------6:2-------7:2-------8:2-------
             * 1:1-------2:1-------3:1-------4:1-------5:1-------6:1-------7:1-------8:1-------
             * 1:0-------2:0-------3:0-------4:0-------5:0-------6:0-------7:0-------8:0-------
             * { data: 1; levels: 3 } { data: 2; levels: 3 } { data: 3; levels: 2 } { data: 4; levels: 4 }
             * { data: 5; levels: 10 } { data: 6; levels: 4 } { data: 7; levels: 4 } { data: 8; levels: 5 }
             */
// 优化后insert()
            val list2 = SkipList2()
            list2.insert2(1)
            list2.insert2(2)
            list2.insert2(6)
            list2.insert2(7)
            list2.insert2(8)
            list2.insert2(3)
            list2.insert2(4)
            list2.insert2(5)
            println()
            list2.printAll_beautiful()
        }
    }
}