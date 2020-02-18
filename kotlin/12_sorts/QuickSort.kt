package com.will.myapplication

/**
 * 快速排序
 * @author will
 */
object QuickSort {
    // 快速排序，a是数组，n表示数组的大小
    fun quickSort(a: IntArray, n: Int) {
        quickSortInternally(a, 0, n - 1)
    }

    // 快速排序递归函数，p,r为下标
    private fun quickSortInternally(a: IntArray, p: Int, r: Int) {
        if (p >= r) return
        val q = partition(a, p, r) // 获取分区点
        quickSortInternally(a, p, q - 1)
        quickSortInternally(a, q + 1, r)
    }

    private fun partition(a: IntArray, p: Int, r: Int): Int {
        val pivot = a[r]
        var i = p
        for (j in p until r) {
            if (a[j] < pivot) {
                if (i == j) {
                    ++i
                } else {
                    val tmp = a[i]
                    a[i++] = a[j]
                    a[j] = tmp
                }
            }
        }
        val tmp = a[i]
        a[i] = a[r]
        a[r] = tmp
        println("i=$i")
        return i
    }
}