package sorts;

/**
 * 冒泡排序、插入排序、选择排序
 *
 * Author: Zheng
 */
public class Sorts {

  // 冒泡排序，a是数组，n表示数组大小
  public static void bubbleSort(int[] a, int n) {
    if (n <= 1) return;

    for (int i = 0; i < n; ++i) {
      // 提前退出标志位
      boolean flag = false;
      for (int j = 0; j < n - i - 1; ++j) {
        if (a[j] > a[j+1]) { // 交换
          int tmp = a[j];
          a[j] = a[j+1];
          a[j+1] = tmp;
          // 此次冒泡有数据交换
          flag = true;
        }
      }
      if (!flag) break;  // 没有数据交换，提前退出
    }
  }

  // 插入排序，a表示数组，n表示数组大小
  public static void insertionSort(int[] a, int n) {
    if (n <= 1) return;

    for (int i = 1; i < n; ++i) {
      int value = a[i];
      int j = i - 1;
      // 查找要插入的位置并移动数据
      for (; j >= 0; --j) {
        if (a[j] > value) {
          a[j+1] = a[j];
        } else {
          break;
        }
      }
      a[j+1] = value;
    }
  }

  // 选择排序，a表示数组，n表示数组大小
  public static void selectionSort(int[] a, int n) {
    if (n <= 1) return;

    for (int i = 0; i < n - 1; ++i) {
      // 查找最小值
      int minIndex = i;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] < a[minIndex]) {
          minIndex = j;
        }
      }
      
      // 交换
      int tmp = a[i];
      a[i] = a[minIndex];
      a[minIndex] = tmp;
    }
  }

}
