package com.will.myapplication

/**
 * @author will
 */
object KthSmallest {
    fun kthSmallest(arr: IntArray?, k: Int): Int {
        if (arr == null || arr.size < k) {
            return -1
        }
        var partition = partition(arr, 0, arr.size - 1)
        while (partition + 1 != k) {
            partition = if (partition + 1 < k) {
                partition(arr, partition + 1, arr.size - 1)
            } else {
                partition(arr, 0, partition - 1)
            }
        }
        return arr[partition]
    }

    private fun partition(arr: IntArray, p: Int, r: Int): Int {
        val pivot = arr[r]
        var i = p
        for (j in p until r) {
            if (arr[j] <= pivot) {
                swap(arr, i, j)
                i++
            }
        }
        swap(arr, i, r)
        return i
    }

    private fun swap(arr: IntArray, i: Int, j: Int) {
        if (i == j) {
            return
        }
        val tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
    }
}