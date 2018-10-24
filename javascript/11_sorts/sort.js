/**
 * 冒泡，插入，选择排序
 *
 * Author: nameczz
 */

// 冒泡排序
const bubbleSort = (arr) => {
    if (arr.length <= 1) return
    for (let i = 0; i < arr.length; i++) {
        let hasChange = false
        for (let j = 0; j < arr.length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                hasChange = true
            }
        }
        // 如果false 说明所有元素已经到位
        if (!hasChange) break
    }
    console.log(arr)
}

// 插入排序
const insertionSort = (arr) => {
    if (arr.length <= 1) return
    for (let i = 1; i < arr.length; i++) {
        const temp = arr[i]
        let j = i - 1
        // 若arr[i]前有大于arr[i]的值的化，向后移位，腾出空间，直到一个<=arr[i]的值
        for (j; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j]
            } else {
                break
            }
        }
        arr[j + 1] = temp
    }
    console.log(arr)
}

// 选择排序
const selectionSort = (arr) => {
    if (arr.length <= 1) return
    // 需要注意这里的边界, 因为需要在内层进行 i+1后的循环，所以外层需要 数组长度-1
    for (let i = 0; i < arr.length - 1; i++) {
        let minIndex = i
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j // 找到整个数组的最小值
            }
        }
        const temp = arr[i]
        arr[i] = arr[minIndex]
        arr[minIndex] = temp
    }
    console.log(arr)
}

const test = [4, 5, 6, 3, 2, 1]
bubbleSort(test)
const testSort = [4, 1, 6, 3, 2, 1]
insertionSort(testSort)
const testSelect = [4, 8, 6, 3, 2, 1, 0, 12]
selectionSort(testSelect)