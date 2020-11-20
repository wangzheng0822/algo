/**
 * @Description:桶排序算法
 * @Author: Hoda
 * @Date: Create in 2019-06-01
 * @Modified By:
 * @Modified Date:
 */
object BucketSort {
    /**
     * 桶排序
     *
     * @param arr 数组
     * @param bucketSize 桶容量
     */
    fun bucketSort(arr: IntArray, bucketSize: Int) {
        if (arr.size < 2) {
            return
        }
        // 数组最小值
        var minValue = arr[0]
        // 数组最大值
        var maxValue = arr[1]
        for (i in arr.indices) {
            if (arr[i] < minValue) {
                minValue = arr[i]
            } else if (arr[i] > maxValue) {
                maxValue = arr[i]
            }
        }
        // 桶数量
        val bucketCount = (maxValue - minValue) / bucketSize + 1
        val buckets =
            Array(bucketCount) { IntArray(bucketSize) }
        val indexArr = IntArray(bucketCount)
        // 将数组中值分配到各个桶里
        for (i in arr.indices) {
            val bucketIndex = (arr[i] - minValue) / bucketSize
            if (indexArr[bucketIndex] == buckets[bucketIndex].length) {
                ensureCapacity(buckets, bucketIndex)
            }
            buckets[bucketIndex][indexArr[bucketIndex]++] = arr[i]
        }
        // 对每个桶进行排序，这里使用了快速排序
        var k = 0
        for (i in buckets.indices) {
            if (indexArr[i] == 0) {
                continue
            }
            quickSortC(buckets[i], 0, indexArr[i] - 1)
            for (j in 0 until indexArr[i]) {
                arr[k++] = buckets[i][j]
            }
        }
    }

    /**
     * 数组扩容
     *
     * @param buckets
     * @param bucketIndex
     */
    private fun ensureCapacity(
        buckets: Array<IntArray>,
        bucketIndex: Int
    ) {
        val tempArr = buckets[bucketIndex]
        val newArr = IntArray(tempArr.size * 2)
        for (j in tempArr.indices) {
            newArr[j] = tempArr[j]
        }
        buckets[bucketIndex] = newArr
    }

    /**
     * 快速排序递归函数
     *
     * @param arr
     * @param p
     * @param r
     */
    private fun quickSortC(arr: IntArray, p: Int, r: Int) {
        if (p >= r) {
            return
        }
        val q = partition(arr, p, r)
        quickSortC(arr, p, q - 1)
        quickSortC(arr, q + 1, r)
    }

    /**
     * 分区函数
     *
     * @param arr
     * @param p
     * @param r
     * @return 分区点位置
     */
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

    /**
     * 交换
     *
     * @param arr
     * @param i
     * @param j
     */
    private fun swap(arr: IntArray, i: Int, j: Int) {
        if (i == j) {
            return
        }
        val tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
    }
}