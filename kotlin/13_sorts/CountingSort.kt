package sorts

/**
 * 计数排序
 *
 * Author: will
 */
object CountingSort {
    // 计数排序，a是数组，n是数组大小。假设数组中存储的都是非负整数。
    fun countingSort(a: IntArray, n: Int) {
        if (n <= 1) return
        // 查找数组中数据的范围
        var max = a[0]
        for (i in 1 until n) {
            if (max < a[i]) {
                max = a[i]
            }
        }
        // 申请一个计数数组c，下标大小[0,max]
        val c = IntArray(max + 1)
        // 计算每个元素的个数，放入c中
        for (i in 0 until n) {
            c[a[i]]++
        }
        // 依次累加
        for (i in 1 until max + 1) {
            c[i] = c[i - 1] + c[i]
        }
        // 临时数组r，存储排序之后的结果
        val r = IntArray(n)
        // 计算排序的关键步骤了，有点难理解
        for (i in n - 1 downTo 0) {
            val index = c[a[i]] - 1
            r[index] = a[i]
            c[a[i]]--
        }
        // 将结果拷贝会a数组
        for (i in 0 until n) {
            a[i] = r[i]
        }
    }
}