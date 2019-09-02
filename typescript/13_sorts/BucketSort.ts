/**
 * 桶排序对数据的要求比较高
 * 首先要知道数据的范围
 * 然后根据范围将数据分到小范围的桶中
 * 每个桶采用快速排序
 * 当桶的数量接近数据量大小的时候，时间复杂度为O(n)
 */
import { QuickSort } from '../12_sorts/quickSort'

class BucketSort {
  static sort(array: number[], bucketSize: number = 5) {
    const length = array.length
    if (length === 0) return array
    // 首先要确定数据的范围
    let min = array[0]
    let max = array[0]
    for (let i = 0; i < length; i++) {
      if (array[i] < min) {
        min = array[i]
      } else if (array[i] > max) {
        max = array[i]
      }
    }

    // 初始化桶,确定桶的数量
    // 因为不能保证正好被整除，需要+1 存放剩余的元素
    const bucketCount = Math.floor((max - min) / bucketSize) + 1
    // 桶是个二维数组
    const buckets = new Array(bucketCount)
    for (let i = 0; i < bucketCount; i++) {
      buckets[i] = []
    }

    // 利用映射函数将数据分配到各个桶中
    // 这个时间复杂度为O(n)
    for (let i = 0; i < length; i++) {
      buckets[Math.floor((array[i]-min) / bucketSize)].push(array[i])
    }
    array.length = 0 // 返回数组
    for (let i = 0; i < bucketCount; i++) {
      // 每个桶里根据具体情况排序，使用插入排序或者快速排序等等
      QuickSort.sort(buckets[i])
      for (let j = 0; j < buckets[i].length; j++) {
        array.push(buckets[i][j]);
      }
    }
  }
}

const bucketTest = [1, 3, 2, 3, 10, 9, 7, 6, 0, -12]
BucketSort.sort(bucketTest)
console.log(bucketTest)
