/**
 * 堆排序
 *
 * Author: nameczz
 */

// 忽视数组的第一位
class HeapSort {
    constructor(originArray) {
        this.originArray = originArray
        console.log(this.originArray)
    }
    buildHeap() {
        const arr = this.originArray
        const startIndex = Math.floor(arr.length)
        for (let i = startIndex; i >= 1; i--) {
            this.heapify(arr, arr.length, i)
        }
        return arr
    }

    heapify(arr, len, i) {
        while (true) {
            let maxPos = i
            // 如果index i拥有叶左节点 并且左节点较大
            if (i * 2 <= len && arr[i] < arr[i * 2]) {
                maxPos = i * 2
            }
            // 如果index i拥有叶右节点 与Max节点比较大小，选出父/左/右中最大的一个
            if (i * 2 + 1 <= len && arr[maxPos] < arr[i * 2 + 1]) {
                maxPos = i * 2 + 1
            }
            if (maxPos === i) break // 循环直到i节点为最大值
            this.swap(arr, i, maxPos) // 交换位置, 父节点为父/左/右中最大的一个
            i = maxPos // i为左/右节点，并尝试向下查找更大的值
        }
    }

    sort() {
        const arr = this.buildHeap() // 先建堆
        let len = arr.length - 1
        while (len > 1) {
            this.swap(arr, 1, len) // 交换顶元素和最后一位。顶元素永远是最大的。
            len--
            this.heapify(arr, len, 1) //剩下的元素重新建堆 直到len === 1 停止
        }
        console.log(arr)
    }

    swap(arr, i, max) {
        let temp = arr[i]
        arr[i] = arr[max]
        arr[max] = temp
    }
}

const arr = [null]
let i = 0
while (i <= 10) {
    const num = Math.floor(Math.random() * 100)
    arr.push(num)
    i++
}
const testHeap = new HeapSort(arr)
testHeap.sort()