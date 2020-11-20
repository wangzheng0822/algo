
/**
 * 归并排序
 */
fun mergeSort(array: IntArray?) {
    //如果数组为空，或者数组元素个数 <= 1 则直接返回
    array ?: return
    if (array.size <= 1)
        return
    mergeSort(array, 0, array.size - 1)
}

fun mergeSort(array: IntArray, p: Int, r: Int) {
    //递归终止条件
    if (p >= r)
        return

    //将数组分隔成 2 半，对每半分别进行排序
    val q = (p + r) / 2
    mergeSort(array, p, q)
    mergeSort(array, q + 1, r)

    //将排好序的两半数组合并到一个里面
    //申请一个临时数组，存放已排好序的数据
    val tmpArr = IntArray(r - p + 1)
    var i = p
    var j = q + 1
    var k = 0
    while (i <= q && j <= r) {
        if (array[i] <= array[j]) {
            tmpArr[k++] = array[i++]
        } else {
            tmpArr[k++] = array[j++]
        }
    }

    //判断哪半边还有数据
    var start: Int
    var end: Int
    if (i <= q) {  //左半边有
        start = i
        end = q
    } else {       //右半边有
        start = j
        end = r
    }
    for (pos in start..end) {
        tmpArr[k++] = array[pos]
    }

    //将临时数组里的数据再复制到原来数组里
    start = p
    for (pos in tmpArr.indices) {
        array[start++] = tmpArr[pos]
    }
}

/**
 * 快排
 */
fun quickSort(array: IntArray?) {
    //如果数组为空，或者数组元素个数 <= 1 则直接返回
    array ?: return
    if (array.size <= 1)
        return
    quickSort(array, 0, array.size - 1)
}

fun quickSort(array: IntArray, p: Int, r: Int) {
    if (p >= r)
        return
    val q = partition(array, p, r)
    quickSort(array, p, q - 1)
    quickSort(array, q + 1, r)
}


/**
 * 分区函数，最后返回分区数据在数组的索引位置
 */
fun partition(array: IntArray, p: Int, r: Int): Int {
    var i = p
    //通常选取最后一个元素作为参照
    var pivot = array[r]
    //从头开始遍历数据
    for (j in p until r) {
        if (array[j] < pivot) {
            var tmp = array[i]
            array[i] = array[j]
            array[j] = tmp
            i++
        }
    }
    array[r] = array[i]
    array[i] = pivot
    return i
}


/**
 * 找出一个数组中第 k 大的数据
 */
fun findKElement(array: IntArray?, k: Int): Int? {
    array ?: return null
    if (k <= 0 || k > array.size)
        return null

    //找第 k 大的元素，就是找升序排列数组中的第 [size - k + 1] 个元素
    return findK(array, 0, array.size - 1, array.size - k + 1)
}

fun findK(array: IntArray, p: Int, r: Int, k: Int): Int {
    if (p >= r) {
        return array[p]
    }
    //分区，找到一个基准位置，该位置元素在当前数组段 [p...r] 中排第 [q - p + 1] 个
    var q = partition(array, p, r)
    var i = q - p + 1
    if (k == i) {   //刚好命中
        return array[q]
    } else if (k < i) { //在左边找
        return findK(array, p, q - 1, k)
    } else {    //在右边找
        return findK(array, q + 1, r, k - i)
    }
}

