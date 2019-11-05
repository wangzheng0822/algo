import kotlin.Array

/**
 * 1) 数组的插入、删除、按照下标随机访问操作；
 * 2）数组中的数据是int类型的；
 *
 * Author: Zackratos
 */

class ArrayKt constructor(private val capacity: Int) {
    // 定义整型数据data保存数据
    private val data: IntArray = IntArray(capacity)
    // 定义数组中实际个数
    private var count: Int = 0

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val array = ArrayKt(5)
            array.printAll()
            array.insert(0, 3)
            array.insert(0, 4)
            array.insert(1, 5)
            array.insert(3, 9)
            array.insert(3, 10)
            array.printAll()
        }
    }

    // 根据索引，找到数据中的元素并返回
    fun find(index: Int): Int {
        if (index !in 0..(count - 1)) return -1
        return data[index]
    }

    // 插入元素：头部插入，尾部插入
    fun insert(index: Int, value: Int): Boolean {
        // 数组空间已满
        if (count == capacity) {
            System.out.println("没有可插入的位置")
            return false
        }
        // 如果count还没满，那么就可以插入数据到数组中
        // 位置不合法
        if (index !in 0..count) {
            System.out.println("位置不合法")
            return false
        }
        // 位置合法
        (count downTo index + 1).forEach {
            data[it] = data[it - 1]
        }
        data[index] = value
        ++count
        return true
    }

    // 根据索引，删除数组中元素
    fun delete(index: Int): Boolean {
        if (index !in 0..(count - 1)) return false
        (index + 1 until count).forEach {
            data[it - 1] = data[it]
        }
        --count
        return true
    }

    fun printAll() {
        (0 until count).forEach {
            System.out.println("${data[it]} ")
        }
    }

}