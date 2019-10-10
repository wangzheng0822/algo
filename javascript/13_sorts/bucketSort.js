// 思路：
// 将数组中的数据，按桶进行划分，将相邻的数据划分在同一个桶中
// 每个桶用插入排序算法（或者快速排序）进行排序
// 最后整合每个桶中的数据

function bucketSort(array, bucketSize = 5) {
    if (array.length < 2) {
        return array
    }
    const buckets = createBuckets(array, bucketSize)
    return sortBuckets(buckets)
}

function createBuckets(array, bucketSize) {
    let minValue = array[0]
    let maxValue = array[0]
    // 遍历数组，找到数组最小值与数组最大值
    for (let i = 1; i < array.length; i++) {
        if (array[i] < minValue) {
            minValue = array[i]
        } else if (array[i] > maxValue) {
            maxValue = array[i]
        }
    }
    // 根据最小值、最大值、桶的大小，计算得到桶的个数
    const bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1
    // 建立一个二维数组，将桶放入buckets中
    const buckets = []
    for (let i = 0; i < bucketCount; i++) {
        buckets[i] = []
    }
    // 计算每一个值应该放在哪一个桶中
    for (let i = 0; i < array.length; i++) {
        const bucketIndex = Math.floor((array[i] - minValue) / bucketSize)
        buckets[bucketIndex].push(array[i])
    }
    return buckets
}

function sortBuckets(buckets) {
    const sortedArray = []
    for (let i = 0; i < buckets.length; i++) {
        if (buckets[i] != null) {
            insertionSort(buckets[i])
            sortedArray.push(...buckets[i])
        }
    }
    return sortedArray
}

// 插入排序
function insertionSort(array) {
    const { length } = array
    if (length <= 1) return

    for (let i = 1; i < length; i++) {
        let value = array[i]
        let j = i - 1

        while (j >= 0) {
            if (array[j] > value) {
                array[j + 1] = array[j] // 移动
                j--
            } else {
                break
            }
        }
        array[j + 1] = value // 插入数据
    }
}
