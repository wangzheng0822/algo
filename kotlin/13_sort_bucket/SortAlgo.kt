
/**
 * 桶排序
 *
 * @param array 待排序数组
 * @param bucketSize 每个桶可以装多少个不同的数字，注意相同的数字可以装 n 个
 */
fun bucketSort(array: IntArray?, bucketSize: Int) {
    array ?: return
    if (array.size <= 1)
        return
    if (bucketSize < 1)
        return
    //先找到最小值、最大值
    var max = array[0]
    var min = array[0]
    for (item in array) {
        if (item > max) {
            max = item
        } else if (item < min) {
            min = item
        }
    }

    //总共需要的桶的个数
    var bucketCount = (max - min) / bucketSize + 1
    //创建桶
    val bucketList = ArrayList<ArrayList<Int>>(bucketCount)
    for (i in 0 until bucketCount) {
        bucketList.add(ArrayList())
    }

    //遍历数组，将数据放在各自的桶内部，一轮下来第1个桶内的数据肯定比第2个桶小，第2个桶比第3个桶小
    for (i in array.indices) {
        val j = (array[i] - min) / bucketSize
        bucketList[j].add(array[i])
    }

    //每个桶自己本身进行排序，可以选择快排，也可以选择递归桶排序
    for (i in bucketList.indices) {
        val itemList = bucketList[i]
        if (itemList.isEmpty())
            continue
        val arr: IntArray = itemList.toIntArray()
        //这里并不一定需要转换成数组，只是为了方便引用之前的测试算法
        //对桶内数据排序，可以选择快排，也可以选择其他排序方式
        quickSort(arr)
        itemList.clear()
        for (item in arr)
            itemList.add(item)
    }

    var i = 0
    for (itemList in bucketList) {
        for (item in itemList) {
            array[i++] = item
        }
    }
}

/**
 * 计数排序，待排序不能有非负整数，如果有则需要将数据处理成非负整数
 */
fun countingSort(array: IntArray?) {
    array ?: return
    if (array.size <= 1)
        return
    //查找最大值
    var max = array[0]
    for (item in array) {
        if (max < item) max = item
    }

    //定义计数数组 [0, max]，大小为 max + 1，
    var countingArr = Array(max + 1) { 0 }
    //遍历数组，统计每个数字的个数，例如数字 1 的个数存储在 countingArr[1] 中
    for (item in array) {
        countingArr[item]++
    }

    //计数数组依次累加，累加后对计数数组来说， c[k] 存储的是 <= k 的数据的个数
    for (i in 0 until countingArr.size - 1) {
        countingArr[i + 1] = countingArr[i + 1] + countingArr[i]
    }

    //申请一个临时数组，大小与待排序数组一样大
    var tmp = Array(array.size) { 0 }
    //从原数组的逆序开始遍历，将数据填充到 tmp 数组里
    for (i in array.size - 1 downTo 0) {
        val item = array[i]
        tmp[countingArr[item] - 1] = item
        countingArr[item]--
    }

    //从排好序的数组拷贝数据到原数组里
    for (i in tmp.indices) {
        array[i] = tmp[i]
    }
}

/**
 * 基数排序
 */
fun radixSort(array: IntArray?) {
    array ?: return
    if (array.size <= 1)
        return
    //查找最大值
    var max = array[0]
    for (item in array) {
        if (max < item) max = item
    }
    //计算最大值的位数，例如 max = 148，则位数为 3
    var maxDigit = 0
    while (max != 0) {
        maxDigit++
        max /= 10
    }

    //每位的数字范围是[0-9]，所以桶的大小设置成 10
    val bucketList = ArrayList<ArrayList<Int>>(10)
    for (i in 0 until 10) {
        bucketList.add(ArrayList())
    }

    //从低位到高位开始排序，这里采用桶排序
    var mod = 10
    var divide = 1
    for (i in 0 until maxDigit) {
        //遍历数据，根据"位"来判断数据放在哪个桶中
        for (j in array.indices) {
            val item = array[j]
            //取出数字的"位"，例如 158 的个位为：(158 % 10) / 1 = 8
            //158 的十位为：(158 % 100) / 10 = 5
            //158 的百位为：(158 % 1000) / 100 = 1
            val num = (item % mod) / divide
            bucketList[num].add(item)
        }

        //从桶中取出数据放在原数组中
        var index = 0
        for (list in bucketList) {
            for (item in list) {
                array[index++] = item
            }
            list.clear()
        }

        mod *= 10
        divide *= 10
    }
}
