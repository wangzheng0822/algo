/**
 * 归并排序
 * 稳定排序，稳定的O(nlgn)时间复杂度
 * O(n)的空间复杂度
 * 在小规模数据排序中很常用
 */
class MergeSort {
  public static mergeSort(array: number[]) {
    if (!array || !array.length) return
    const length = array.length
    this.mergeSortInternally(array, 0, length - 1)
  }

  static mergeSortInternally(array: number[], p: number, r: number) {
    if (p >= r) return
    // 严格按照中间值作切分点
    // js中除法需要做取整操作，不然结果有可能是小数
    const q = Math.floor(p + (r - p) / 2)
    this.mergeSortInternally(array, p, q)
    this.mergeSortInternally(array, q + 1, r)
    this.mergeArray(array, p, q, r)
  }

  private static mergeArray(a: number[], p: number, q: number, r: number) {
    let i = p
    let j = q + 1
    let k = 0
    // 定义一个临时数组来存放排序的值
    const tmp: number[] = []
    while (i <= q && j <= r) {
      if (a[i] <= a[j]) {
        tmp[k++] = a[i++]
      } else {
        tmp[k++] = a[j++]
      }
    }
    // 判断哪个子数组中有剩余的数据
    let start = i
    let end = q
    if (j <= r) {
      start = j
      end = r
    }
    // 将剩余的数据拷贝到临时数组tmp
    while (start <= end) {
      tmp[k++] = a[start++]
    }

    // 将tmp中的数组拷贝回a[p...r]
    for (i = 0; i <= r - p; i++) {
      a[p + i] = tmp[i]
    }
  }
}

const test4 = [1, 3, 2, 3, 10, 9, 7, 6, 0, 12]
MergeSort.mergeSort(test4)
console.log(test4)
