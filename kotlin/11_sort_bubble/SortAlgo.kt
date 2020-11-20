
/**
 * 冒泡排序
 */
fun bubbleSort(array: IntArray?) {
    array ?: return
    if (array.size == 1)
        return
    for (i in 0 until array.size - 1) {
        var flag = false
        for (j in 0 until array.size - i - 1) {
            if (array[j] > array[j + 1]) {
                val tmp = array[j + 1]
                array[j + 1] = array[j]
                array[j] = tmp
                flag = true
            }
        }
        if (!flag) break
    }
}

/**
 * 选择排序
 */
fun selectionSort(array: IntArray?) {
    array ?: return
    if (array.size == 1)
        return
    for (i in 0 until array.size - 1) {
        for (j in i + 1 until array.size) {
            if (array[i] > array[j]) {
                val tmp = array[j]
                array[j] = array[i]
                array[i] = tmp
            }
        }
    }
}

/**
 * 插入排序
 */
fun insertionSort(array: IntArray?) {
    array ?: return
    if (array.size == 1)
        return
    for (i in 1 until array.size) {
        var value = array[i]
        for (j in i - 1 downTo 0) {
            if (value < array[j]) {
                array[j + 1] = array[j]
                array[j] = value
            } else {
                break
            }
        }
    }
}
