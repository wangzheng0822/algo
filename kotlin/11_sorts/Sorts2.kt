package sorts

import java.util.*

/**
 * 冒泡排序、插入排序、选择排序
 *
 * Author: will
 */
object Sorts2 {
    // 冒泡排序，a是数组，n表示数组大小
    fun bubbleSort(a: IntArray, n: Int) {
        if (n <= 1) return
        for (i in 0 until n) { // 提前退出标志位
            var flag = false
            for (j in 0 until n - i - 1) {
                if (a[j] > a[j + 1]) { // 交换
                    val tmp = a[j]
                    a[j] = a[j + 1]
                    a[j + 1] = tmp
                    // 此次冒泡有数据交换
                    flag = true
                }
            }
            if (!flag) break // 没有数据交换，提前退出
        }
    }

    /**
     * 冒泡排序改进:在每一轮排序后记录最后一次元素交换的位置,作为下次比较的边界,
     * 对于边界外的元素在下次循环中无需比较.
     */
    fun bubbleSort2(a: IntArray, n: Int) {
        if (n <= 1) return
        // 最后一次交换的位置
        var lastExchange = 0
        // 无序数据的边界,每次只需要比较到这里即可退出
        var sortBorder = n - 1
        for (i in 0 until n) { // 提前退出标志位
            var flag = false
            for (j in 0 until sortBorder) {
                if (a[j] > a[j + 1]) {
                    val tmp = a[j]
                    a[j] = a[j + 1]
                    a[j + 1] = tmp
                    // 此次冒泡有数据交换
                    flag = true
                    // 更新最后一次交换的位置
                    lastExchange = j
                }
            }
            sortBorder = lastExchange
            if (!flag) break // 没有数据交换，提前退出
        }
    }

    // 插入排序，a表示数组，n表示数组大小
    fun insertionSort(a: IntArray, n: Int) {
        if (n <= 1) return
        for (i in 1 until n) {
            val value = a[i]
            var j = i - 1
            // 查找要插入的位置并移动数据
            while (j >= 0) {
                if (a[j] > value) {
                    a[j + 1] = a[j]
                } else {
                    break
                }
                --j
            }
            a[j + 1] = value
        }
    }

    // 选择排序，a表示数组，n表示数组大小
    fun selectionSort(a: IntArray, n: Int) {
        if (n <= 1) return
        for (i in 0 until n - 1) { // 查找最小值
            var minIndex = i
            for (j in i + 1 until n) {
                if (a[j] < a[minIndex]) {
                    minIndex = j
                }
            }
            // 交换
            val tmp = a[i]
            a[i] = a[minIndex]
            a[minIndex] = tmp
        }
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val array = intArrayOf(3, 4, 2, 1, 5, 6, 7, 8)
        bubbleSort2(array, array.size)
        println(Arrays.toString(array))
    }
}