package com.will.myapplication

import java.util.*

/**
 * 冒泡，选择，插入，快速，归并
 *
 * @author will
 */
object Sorts {
    /**
     * 冒泡排序
     *
     * @param arr
     */
    fun bubbleSort(arr: IntArray) {
        for (i in arr.indices) {
            for (j in 0 until arr.size - 1 - i) {
                if (arr[j] > arr[j + 1]) {
                    val temp = arr[j]
                    arr[j] = arr[j + 1]
                    arr[j + 1] = temp
                }
            }
        }
    }

    /**
     * 优化冒泡排序
     *
     * @param arr
     */
    fun bubbleSort2(arr: IntArray) {
        for (i in 0 until arr.size - 1) {
            var flag = true
            for (j in 0 until arr.size - 1 - i) {
                if (arr[j] > arr[j + 1]) {
                    val temp = arr[j]
                    arr[j] = arr[j + 1]
                    arr[j + 1] = temp
                    flag = false
                }
            }
            if (flag) {
                break
            }
        }
    }

    /**
     * 插入排序
     *
     * @param arr
     */
    fun insertSort(arr: IntArray) {
        for (i in 1 until arr.size) {
            val `val` = arr[i]
            var index = i - 1
            while (index >= 0 && arr[index] > `val`) {
                arr[index + 1] = arr[index]
                index--
            }
            arr[index + 1] = `val`
        }
    }

    /**
     * 插入排序
     *
     * @param arr
     * @param n   表示数组有用大小
     */
    fun insertSort(arr: IntArray, n: Int) {
        for (i in 1 until n) {
            val `val` = arr[i]
            var index = i - 1
            while (index >= 0 && arr[index] > `val`) {
                arr[index + 1] = arr[index]
                index--
            }
            arr[index + 1] = `val`
        }
    }

    /**
     * 选择排序
     *
     * @param arr
     */
    fun selectSort(arr: IntArray) {
        for (i in 0 until arr.size - 1) {
            var minIndex = i
            for (j in i + 1 until arr.size) {
                if (arr[minIndex] > arr[j]) {
                    minIndex = j
                }
            }
            // 交换
            val temp = arr[i]
            arr[i] = arr[minIndex]
            arr[minIndex] = temp
        }
    }

    /**
     * 归并排序
     *
     * @param arr
     */
    fun mergeSort(arr: IntArray, left: Int, right: Int) {
        if (left >= right) {
            return
        }
        val q = (left + right) / 2
        mergeSort(arr, left, q)
        mergeSort(arr, q + 1, right)
        merge2(arr, left, q, right)
    }

    private fun merge2(arr: IntArray, left: Int, q: Int, right: Int) {
        val leftArr = IntArray(q - left + 2)
        val rightArr = IntArray(right - q + 1)
        for (i in 0..q - left) {
            leftArr[i] = arr[left + i]
        }
        // 第一个数组添加哨兵（最大值）
        leftArr[q - left + 1] = Int.MAX_VALUE
        for (i in 0 until right - q) {
            rightArr[i] = arr[q + 1 + i]
        }
        // 第二个数组添加哨兵（最大值）
        rightArr[right - q] = Int.MAX_VALUE
        var i = 0
        var j = 0
        var k = left
        while (k <= right) { // 当左边数组到达哨兵值时，i不再增加，直到右边数组读取完剩余值，同理右边数组也一样
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++]
            } else {
                arr[k++] = rightArr[j++]
            }
        }
    }

    private fun merge(arr: IntArray, left: Int, q: Int, right: Int) {
        var i = left
        var j = q + 1
        var k = 0
        val tmp = IntArray(right - left + 1)
        while (i <= q && j <= right) {
            if (arr[i] <= arr[j]) {
                tmp[k++] = arr[i++]
            } else {
                tmp[k++] = arr[j++]
            }
        }
        var start = i
        var end = q
        if (j <= right) {
            start = j
            end = right
        }
        while (start <= end) {
            tmp[k++] = arr[start++]
        }
        for (l in 0..right - left) {
            arr[l + left] = tmp[l]
        }
    }

    /**
     * 快速排序
     *
     * @param arr
     */
    private fun quickSort(arr: IntArray, left: Int, right: Int) {
        if (left >= right) {
            return
        }
        val q = partition2(arr, left, right)
        quickSort(arr, left, q - 1)
        quickSort(arr, q + 1, right)
    }

    private fun partition(arr: IntArray, left: Int, right: Int): Int {
        val pivot = arr[right]
        var i = left
        for (j in left until right) {
            if (arr[j] < pivot) {
                if (i == j) {
                    ++i
                } else {
                    val tmp = arr[i]
                    arr[i++] = arr[j]
                    arr[j] = tmp
                }
            }
        }
        val tmp = arr[i]
        arr[i] = arr[right]
        arr[right] = tmp
        return i
    }

    private fun partition2(arr: IntArray, left: Int, right: Int): Int { // 三数取中法 , 随机数在这里写
        val middle = (left + right) / 2
        val pivot = arr[middle]
        // 交换到最右边
        val `val` = arr[right]
        arr[right] = pivot
        arr[middle] = `val`
        var i = left
        for (j in left until right) {
            if (arr[j] < pivot) {
                if (i == j) {
                    ++i
                } else {
                    val tmp = arr[i]
                    arr[i++] = arr[j]
                    arr[j] = tmp
                }
            }
        }
        val tmp = arr[i]
        arr[i] = arr[right]
        arr[right] = tmp
        return i
    }

    /**
     * 三向切分快速排序
     *
     * @param arr
     * @param left
     * @param right
     * @return
     */
    private fun quickSort3(arr: IntArray, left: Int, right: Int) {
        if (left >= right) {
            return
        }
        var l = left
        var k = left + 1
        var r = right
        val pivot = arr[l]
        while (k <= r) {
            if (arr[k] < pivot) {
                val tmp = arr[l]
                arr[l] = arr[k]
                arr[k] = tmp
                l++
                k++
            } else if (arr[k] == pivot) {
                k++
            } else {
                if (arr[r] > pivot) {
                    r--
                } else if (arr[r] == pivot) {
                    val tmp = arr[k]
                    arr[k] = arr[r]
                    arr[r] = tmp
                    k++
                    r--
                } else {
                    val tmp = arr[l]
                    arr[l] = arr[r]
                    arr[r] = arr[k]
                    arr[k] = tmp
                    l++
                    k++
                    r--
                }
            }
        }
        quickSort(arr, left, l - 1)
        quickSort(arr, r + 1, right)
    }

    /**
     * 双轴快速排序
     *
     * @param arr
     * @param left
     * @param right
     */
    private fun quickSort4(arr: IntArray, left: Int, right: Int) {
        if (left >= right) {
            return
        }
        var l = left
        var k = left + 1
        var r = right
        // 判断pivot1 与 pivot2 大小
        if (arr[l] > arr[r]) {
            val tmp = arr[l]
            arr[l] = arr[r]
            arr[r] = tmp
        }
        val pivot1 = arr[l]
        val pivot2 = arr[r]
        while (k < r) {
            if (arr[k] < pivot1) {
                l++
                if (l != k) {
                    val tmp = arr[l]
                    arr[l] = arr[k]
                    arr[k] = tmp
                }
                k++
            } else if (arr[k] in pivot1..pivot2) {
                k++
            } else {
                --r
                if (arr[r] > pivot2) {
                } else if (arr[r] in pivot1..pivot2) {
                    val tmp = arr[k]
                    arr[k] = arr[r]
                    arr[r] = tmp
                    k++
                } else {
                    l++
                    val tmp = arr[l]
                    arr[l] = arr[r]
                    arr[r] = arr[k]
                    arr[k] = tmp
                    k++
                }
            }
        }
        // 交换pivot1 和 pivot2
        arr[left] = arr[l]
        arr[l] = pivot1
        arr[right] = arr[r]
        arr[r] = pivot2
        quickSort(arr, left, l - 1)
        quickSort(arr, l + 1, r - 1)
        quickSort(arr, r + 1, right)
    }

    /**
     * O(n)  时间复杂度内求无序数组中的第 K  大元素。比如， 4 ， 2 ， 5 ， 12 ， 3  这样一组数据，第 3  大元素就是 4 。
     *
     * @param arr
     */
    fun sort(arr: IntArray, l: Int, r: Int, k: Int): Int {
        if (l >= r) {
            return 0
        }
        val p = partition(arr, l, r)
        return if (p + 1 == k) {
            arr[p]
        } else if (p + 1 < k) {
            sort(arr, p + 1, r, k)
        } else {
            sort(arr, l, p - 1, k)
        }
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val arr = intArrayOf(2, 1, 5, 6, 8, 4, 12, 11, 13, 15, 7, 9, 0, -1)
        Arrays.sort(arr)
        print(arr)
    }

    private fun print(arr: IntArray) {
        for (i in arr) {
            print("$i ")
        }
        println()
    }
}