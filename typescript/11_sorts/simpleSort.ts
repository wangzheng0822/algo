/**
 * 简单的排序，分为冒泡和插入排序
 * 注意他们都是稳定的排序,并且是原地排序
 * 一般情况下更推荐使用插入排序，因为它所需要的操作更少
 * 这里使用简单工厂创建我们的排序算法
 */

/**
 * 排序的枚举类型
 */
enum SortType {
  BubbleSort,
  InsertSort
}

interface SortAlgo {
  sort(array: number[]): void
}

class BubbleSort implements SortAlgo {
  sort(array: number[]) {
    for (let i = 0; i < array.length; i++) {
      let flag = false
      for (let j = 0; j < array.length; j++) {
        if (array[j] > array[j + 1]) {
          const temp = array[j]
          array[j] = array[j + 1]
          array[j + 1] = temp
          flag = true
        }
      }
      if (!flag) {
        break
      }
    }
  }
}

class InsertSort implements SortAlgo {
  sort(array: number[]) {
    for (let i = 1; i < array.length; i++) {
      let j = i - 1
      const temp = array[i]
      for (; j >= 0; j--) {
        if (array[j] > array[j + 1]) {
          array[j + 1] = array[j]
        } else {
          // 这个说明之前的已经排好了，没必要继续比较
          break
        }
      }
      array[j + 1] = temp
    }
  }
}

class SortFactory {
  static getSortAlgo(type: SortType): SortAlgo {
    switch (type) {
      case SortType.BubbleSort:
        return new BubbleSort()
      case SortType.InsertSort:
        return new InsertSort()
      default:
        throw new Error('unknown sort algorithm type')
    }
  }
}

const insertSort = SortFactory.getSortAlgo(SortType.InsertSort)
const test1 = [1, 0, 2, 4, 8, 5, 10]
insertSort.sort(test1)
console.log(test1)


