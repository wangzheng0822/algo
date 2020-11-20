/**
 * @Description:基数排序
 * @Author: Hoda
 * @Date: Create in 2019-07-25
 * @Modified By:
 * @Modified Date:
 */
object RadixSort {
    /**
     * 基数排序
     *
     * @param arr
     */
    fun radixSort(arr: IntArray) {
        var max = arr[0]
        for (i in arr.indices) {
            if (arr[i] > max) {
                max = arr[i]
            }
        }
        // 从个位开始，对数组arr按"指数"进行排序
        var exp = 1
        while (max / exp > 0) {
            countingSort(arr, exp)
            exp *= 10
        }
    }

    /**
     * 计数排序-对数组按照"某个位数"进行排序
     *
     * @param arr
     * @param exp 指数
     */
    fun countingSort(arr: IntArray, exp: Int) {
        if (arr.size <= 1) {
            return
        }
        // 计算每个元素的个数
        val c = IntArray(10)
        for (i in arr.indices) {
            c[arr[i] / exp % 10]++
        }
        // 计算排序后的位置
        for (i in 1 until c.size) {
            c[i] += c[i - 1]
        }
        // 临时数组r，存储排序之后的结果
        val r = IntArray(arr.size)
        for (i in arr.indices.reversed()) {
            r[c[arr[i] / exp % 10] - 1] = arr[i]
            c[arr[i] / exp % 10]--
        }
        for (i in arr.indices) {
            arr[i] = r[i]
        }
    }
}