const countingSort = array => {
    if (array.length <= 1) return

    const max = findMaxValue(array)
    const counts = new Array(max + 1)

    // 计算每个元素的个数，放入到counts桶中
    // counts下标是元素，值是元素个数
    array.forEach(element => {
        if (!counts[element]) {
            counts[element] = 0
        }
        counts[element]++
    })

    // counts下标是元素，值是元素个数
    // 例如： array: [6, 4, 3, 1], counts: [empty, 1, empty, 1, 1, empty, 1]
    // i是元素, count是元素个数
    let sortedIndex = 0
    counts.forEach((count, i) => {
        while (count > 0) {
            array[sortedIndex] = i
            sortedIndex++
            count--
        }
    })
    // return array
}

function findMaxValue(array) {
    let max = array[0]
    for (let i = 1; i < array.length; i++) {
        if (array[i] > max) {
            max = array[i]
        }
    }
    return max
}
