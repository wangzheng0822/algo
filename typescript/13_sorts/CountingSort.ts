/**
 * 计数排序
 * 也是线性时间复杂度，和桶排序非常类似
 * 适用于值范围较小的大数据排序
 * 注意值范围需要不小于0，不然需要将数据预处理
 * 并非原地排序
 */
class CountingSort {
  static sort(array: number[]) {
    const length = array.length

    // 找到这个数组的最大值
    let max = array[0]
    array.forEach((item) => {
      if (item > max) {
        max = item
      }
    })

    // 初始化值范围数组
    const countArray = new Array(max + 1).fill(0, 0, max + 1)
    // 先计算每个元素的出现个数
    for (let i = 0; i < length; i++) {
      countArray[array[i]] = countArray[array[i]] + 1
    }
    // 计算元素的累计出现个数
    for (let i = 1; i <= max; i++) {
      countArray[i] = countArray[i - 1] + countArray[i]
    }

    // 接下来开始计数排序了
    // 空间还是要申请
    const sortedArray = []
    // 倒序遍历能够达到稳定排序的作用
    for (let i = length - 1; i >= 0; i--) {
      // -1是为了填补sortedArray在0的位置,因为countArray在0的位置中一定么有值
      const index = countArray[array[i]] - 1
      sortedArray[index] = array[i]
      countArray[array[i]]--
    }
    for (let i = 0; i < length; i++) {
      array[i] = sortedArray[i]
    }
  }
}


const testSort2 = [1, 3, 2, 3, 10, 9, 7, 6, 0]
CountingSort.sort(testSort2)
console.log(testSort2)

