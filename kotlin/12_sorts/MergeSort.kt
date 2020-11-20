package com.will.myapplication

/**
 * 归并排序
 * @author will
 */
object MergeSort {
    fun mergeSort(a: IntArray, n: Int) {
        mergeSortInternally(a, 0, n - 1)
    }

    // 递归调用函数
    private fun mergeSortInternally(a: IntArray, p: Int, r: Int) { // 递归终止条件
        if (p >= r) return
        // 取p到r之间的中间位置q,防止（p+r）的和超过int类型最大值
        val q = p + (r - p) / 2
        // 分治递归
        mergeSortInternally(a, p, q)
        mergeSortInternally(a, q + 1, r)
        // 将A[p...q]和A[q+1...r]合并为A[p...r]
        merge(a, p, q, r)
    }

    private fun merge(a: IntArray, p: Int, q: Int, r: Int) {
        var i = p
        var j = q + 1
        var k = 0 // 初始化变量i, j, k
        val tmp = IntArray(r - p + 1) // 申请一个大小跟a[p...r]一样的临时数组
        while (i <= q && j <= r) {
            if (a[i] <= a[j]) {
                tmp[k++] = a[i++] // i++等于i:=i+1
            } else {
                tmp[k++] = a[j++]
            }
        }
        // 判断哪个子数组中有剩余的数据
        var start = i
        var end = q
        if (j <= r) {
            start = j
            end = r
        }
        // 将剩余的数据拷贝到临时数组tmp
        while (start <= end) {
            tmp[k++] = a[start++]
        }
        // 将tmp中的数组拷贝回a[p...r]
        i = 0
        while (i <= r - p) {
            a[p + i] = tmp[i]
            ++i
        }
    }

    /**
     * 合并(哨兵)
     *
     */
    private fun mergeBySentry(arr: IntArray, p: Int, q: Int, r: Int) {
        val leftArr = IntArray(q - p + 2)
        val rightArr = IntArray(r - q + 1)
        for (i in 0..q - p) {
            leftArr[i] = arr[p + i]
        }
        // 第一个数组添加哨兵（最大值）
        leftArr[q - p + 1] = Int.MAX_VALUE
        for (i in 0 until r - q) {
            rightArr[i] = arr[q + 1 + i]
        }
        // 第二个数组添加哨兵（最大值）
        rightArr[r - q] = Int.MAX_VALUE
        var i = 0
        var j = 0
        var k = p
        while (k <= r) { // 当左边数组到达哨兵值时，i不再增加，直到右边数组读取完剩余值，同理右边数组也一样
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++]
            } else {
                arr[k++] = rightArr[j++]
            }
        }
    }
}