/**
 * 二分查找适合于连续内存的数组查找
 * 并且是已经排好序的数组
 * 时间复杂度只有log(n)
 */
class BinarySearch {
  static bSearch(array: number[], target: number) {
    if (!array || array.length === 0) return -1
    const length = array.length
    let low = 0
    let high = length - 1
    while (low <= high) {
      // 一定是整数,这边的移位运算优先级低于+，-运算符，需要加括号
      const mid = low + ((high - low) >> 1)
      if (array[mid] === target) {
        return mid
      } else if (array[mid] > target) {
        high = mid - 1
      } else {
        low = mid + 1
      }
    }
    return -1
  }
}

const testBinarySearch = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
console.log(BinarySearch.bSearch(testBinarySearch, 10))
