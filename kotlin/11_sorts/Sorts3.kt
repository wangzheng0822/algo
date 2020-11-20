package sorts

/**
 * 向下冒泡算法
 * Author: will
 */
object Sorts3 {
    @JvmStatic
    fun main(args: Array<String>) {
        val arr = intArrayOf(3, 2, 6, 4, 5, 1, 9, 20, 13, 16)
        shellSort(arr)
    }

    private fun shellSort(arr: IntArray) {
        val len = arr.size
        if (len == 1) return
        var step = len / 2
        while (step >= 1) {
            for (i in step until len) {
                val value = arr[i]
                var j = i - step
                while (j >= 0) {
                    if (value < arr[j]) {
                        arr[j + step] = arr[j]
                    } else {
                        break
                    }
                    j -= step
                }
                arr[j + step] = value
            }
            step /= 2
        }
    }
}