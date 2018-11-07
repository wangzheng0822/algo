package sorts;

/**
 * 向下冒泡算法 （或许比冒泡更易懂的排序算法？）
 * 希尔排序
 *
 * Author: wliu
 */
public class SortsAddOn {

  public static void main(String[] args) {
    int[] arr = {3, 2, 6, 4, 5, 1, 9, 20, 13, 16};
    // bubbleDownSort(arr);
    shellSort(arr);
    print(arr);
  }

  /**
   * 向下冒泡。可能比冒泡更易懂？
   * 
   * 算法概要：
   * 从0开始，用这个元素去跟后面的所有元素比较，如果发现这个元素大于后面的某个元素，则交换。
   * 3 2 6 4 5 1
   * 第一趟是从 index=0 也就是 3， 开始跟index=1及其后面的数字比较
   *  3 大于 2，交换，变为 2 3 6 4 5 1，此时index=0的位置变为了2
   *    接下来将用2跟index=2比较
   *  2 不大于 6 不交换
   *  2 不大于 4 不交换
   *  2 不大于 5 不交换
   *  2 大于 1，交换，变为 1 3 6 4 5 2，第一趟排序完成。
   * 
   * 第二趟是从 index=1 也就是 3，开始跟index=2及其后面的数字比较
   *  3 不大于 6 不交换
   *  3 不大于 4 不交换
   *  3 不大于 5 不交换
   *  3 大于 2，交换，变为 1 2 6 4 5 3，第二趟排序完成。
   * 
   * 第三趟是从 index=2 也就是 6，开始跟index=3及其后面的数字比较
   *  6 大于 4，交换，变为 1 2 4 6 5 3, 此时 index = 2 的位置变为了4
   *     接下来将用4跟index=4比较
   *  4 不大于 5 不交换
   *  4 大于 3，交换，变为 1 2 3 6 5 4，第三趟排序完成。
   * 
   * 第四趟是从 index=3 也就是 6，开始跟index=4及其后面的数字比较
   *  6 大于 5，交换，变为 1 2 3 5 6 4, 此时 index = 3 的位置变为了5
   *     接下来将用5跟index=5比较
   *  5 大于 4，交换，变为 1 2 3 4 6 5, 第四趟排序完成。
   *
   * 第五趟是从 index=4 也就是 6，开始跟index=5及其后面的数字比较
   *  6 大于 5，交换，变为 1 2 3 4 5 6, 此时 index = 4 的位置变为了5
   *     接下来将用5跟index=6比较
   *  index = 6 已经不满足 index < length 的条件，整个排序完成。
   */
  private static void bubbleDownSort(int[] arr) {
    int len = arr.length;
    if (len == 1) return;

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] > arr[j]) {
          int tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
  }


  private static void shellSort(int[] arr) {
    int len = arr.length;
    if (len == 1) return;

    int step = len / 2;
    while (step >= 1) {
      for (int i = step; i < len; i++) {
        int value = arr[i];
        int j = i - step;
        for (; j >= 0; j -= step) {
          if (value < arr[j]) {
            arr[j+step] = arr[j];
          } else {
            break;
          }
        }
        arr[j+step] = value;
      }

      step = step / 2;
    }
  }

  private static void print(int[] arr) {
    System.out.println("Print array:");
    for (int x : arr) {
      System.out.print(x + "\t");
    }
    System.out.println("");
  }
}
