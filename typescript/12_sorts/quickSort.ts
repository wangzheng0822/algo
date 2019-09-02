/**
 * 快速排序是不稳定的排序
 * 原地排序，空间复杂度O（1），比归并排序使用更广泛
 * 平均复杂度基本接近O(nlg(n))
 */

export class QuickSort {
  static sort(array: number[]): void {
    this.sortInternally(array, 0, array.length - 1)
  }
  private static sortInternally(array: number[], p: number, r: number) {
    if (p >= r) return
    // 获取分界点
    const q: number = this.partition(array, p, r)
    this.sortInternally(array, p, q - 1)
    this.sortInternally(array, q + 1, r)
  }
  private static partition(array: number[], p: number, r: number): number {
    /**
     * 参考值pivot，小于pivot的放在左边，大于pivot的在右边，最后再把分界点的值和它做交换
     * 这样返回的index一定是值在中间的下标
     */
    const pivot = array[p]
    // 分界点
    let index = p + 1
    for (let i = index; i <= r; i++) {
      if (array[i] < pivot) {
        this.swap(array, index, i)
        // 找到了比标记值小的元素就移动分界点
        index++
      }
    }
    this.swap(array, p, index - 1)
    return index - 1
  }

  private static swap(array: number[], p: number, q: number) {
    const temp = array[p]
    array[p] = array[q]
    array[q] = temp
  }
}

const testSort = [1, 3, 2, 3, 10, 9, 7, 6, 0, -12]
QuickSort.sort(testSort)
console.log(testSort)
