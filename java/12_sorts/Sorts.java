package com.study.sort;

import java.util.Arrays;

/**
 * 冒泡，选择，插入，快速，归并
 *
 * @author ldb
 * @date 2019-10-08 16:09
 */
public class Sorts {

    /**
     * 冒泡排序
     *
     * @param arr
     */
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    /**
     * 优化冒泡排序
     *
     * @param arr
     */
    public static void bubbleSort2(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            boolean flag = true;
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
    }

    /**
     * 插入排序
     *
     * @param arr
     */
    public static void insertSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int val = arr[i];
            int index = i - 1;
            while (index >= 0 && arr[index] > val) {
                arr[index + 1] = arr[index];
                index--;
            }
            arr[index + 1] = val;
        }
    }

    /**
     * 插入排序
     *
     * @param arr
     * @param n   表示数组有用大小
     */
    public static void insertSort(int[] arr, int n) {
        for (int i = 1; i < n; i++) {
            int val = arr[i];
            int index = i - 1;
            while (index >= 0 && arr[index] > val) {
                arr[index + 1] = arr[index];
                index--;
            }
            arr[index + 1] = val;
        }
    }

    /**
     * 选择排序
     *
     * @param arr
     */
    public static void selectSort(int[] arr) {

        for (int i = 0; i < arr.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[minIndex] > arr[j]) {
                    minIndex = j;
                }
            }
            // 交换
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    /**
     * 归并排序
     *
     * @param arr
     */
    public static void mergeSort(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int q = (left + right) / 2;
        mergeSort(arr, left, q);
        mergeSort(arr, q + 1, right);
        merge2(arr, left, q, right);

    }

    private static void merge2(int[] arr, int left, int q, int right) {
        int[] leftArr = new int[q - left + 2];
        int[] rightArr = new int[right - q + 1];

        for (int i = 0; i <= q - left; i++) {
            leftArr[i] = arr[left + i];
        }
        // 第一个数组添加哨兵（最大值）
        leftArr[q - left + 1] = Integer.MAX_VALUE;

        for (int i = 0; i < right - q; i++) {
            rightArr[i] = arr[q + 1 + i];
        }
        // 第二个数组添加哨兵（最大值）
        rightArr[right - q] = Integer.MAX_VALUE;

        int i = 0;
        int j = 0;
        int k = left;
        while (k <= right) {
            // 当左边数组到达哨兵值时，i不再增加，直到右边数组读取完剩余值，同理右边数组也一样
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
    }

    private static void merge(int[] arr, int left, int q, int right) {
        int i = left;
        int j = q + 1;
        int k = 0;
        int[] tmp = new int[right - left + 1];
        while (i <= q && j <= right) {
            if (arr[i] <= arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
            }
        }
        int start = i;
        int end = q;
        if (j <= right) {
            start = j;
            end = right;
        }
        while (start <= end) {
            tmp[k++] = arr[start++];
        }
        for (int l = 0; l <= right - left; l++) {
            arr[l + left] = tmp[l];
        }

    }

    /**
     * 快速排序
     *
     * @param arr
     */
    public static void quickSort(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int q = partition2(arr, left, right);
        quickSort(arr, left, q - 1);
        quickSort(arr, q + 1, right);
    }

    private static int partition(int[] arr, int left, int right) {
        int pivot = arr[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                if (i == j) {
                    ++i;
                } else {
                    int tmp = arr[i];
                    arr[i++] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        int tmp = arr[i];
        arr[i] = arr[right];
        arr[right] = tmp;
        return i;
    }

    private static int partition2(int[] arr, int left, int right) {
        // 三数取中法 , 随机数在这里写
        int middle = (left + right) / 2;
        int pivot = arr[middle];
        // 交换到最右边
        int val = arr[right];
        arr[right] = pivot;
        arr[middle] = val;
        int i = left;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                if (i == j) {
                    ++i;
                } else {
                    int tmp = arr[i];
                    arr[i++] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        int tmp = arr[i];
        arr[i] = arr[right];
        arr[right] = tmp;
        return i;
    }

    /**
     * 三向切分快速排序
     *
     * @param arr
     * @param left
     * @param right
     * @return
     */
    private static void quickSort3(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int k = left + 1;
        int r = right;
        int pivot = arr[l];

        while (k <= r) {
            if (arr[k] < pivot) {
                int tmp = arr[l];
                arr[l] = arr[k];
                arr[k] = tmp;
                l++;
                k++;
            } else if (arr[k] == pivot) {
                k++;
            } else {
                if (arr[r] > pivot) {
                    r--;
                } else if (arr[r] == pivot) {
                    int tmp = arr[k];
                    arr[k] = arr[r];
                    arr[r] = tmp;
                    k++;
                    r--;
                } else {
                    int tmp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = arr[k];
                    arr[k] = tmp;
                    l++;
                    k++;
                    r--;
                }
            }
        }

        quickSort(arr, left, l - 1);
        quickSort(arr, r + 1, right);
    }

    /**
     * 双轴快速排序
     *
     * @param arr
     * @param left
     * @param right
     */
    private static void quickSort4(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int k = left + 1;
        int r = right;
        // 判断pivot1 与 pivot2 大小
        if (arr[l] > arr[r]) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
        }
        int pivot1 = arr[l];
        int pivot2 = arr[r];

        while (k < r) {
            if (arr[k] < pivot1) {
                l++;
                if (l != k) {
                    int tmp = arr[l];
                    arr[l] = arr[k];
                    arr[k] = tmp;
                }
                k++;
            } else if (arr[k] >= pivot1 && arr[k] <= pivot2) {
                k++;
            } else {
                --r;
                if (arr[r] > pivot2) {
                } else if (arr[r] >= pivot1 && arr[r] <= pivot2) {
                    int tmp = arr[k];
                    arr[k] = arr[r];
                    arr[r] = tmp;
                    k++;
                } else {
                    l++;
                    int tmp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = arr[k];
                    arr[k] = tmp;
                    k++;
                }
            }
        }

        // 交换pivot1 和 pivot2
        arr[left] = arr[l];
        arr[l] = pivot1;
        arr[right] = arr[r];
        arr[r] = pivot2;

        quickSort(arr, left, l - 1);
        quickSort(arr, l + 1, r - 1);
        quickSort(arr, r + 1, right);
    }

    /**
     * O(n)  时间复杂度内求无序数组中的第 K  大元素。比如， 4 ， 2 ， 5 ， 12 ， 3  这样一组数据，第 3  大元素就是 4 。
     *
     * @param arr
     */
    public static int sort(int[] arr, int l, int r, int k) {
        if (l >= r) {
            return 0;
        }
        int p = partition(arr, l, r);
        if ((p + 1) == k) {
            return arr[p];
        } else if ((p + 1) < k) {
            return sort(arr, p + 1, r, k);
        } else {
            return sort(arr, l, p - 1, k);
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 1, 5, 6, 8, 4, 12, 11, 13, 15, 7, 9, 0, -1};
//        bubbleSort(arr);
//        bubbleSort2(arr);
//        selectSort(arr);
//        mergeSort(arr, 0, arr.length - 1);
//        quickSort4(arr, 0, arr.length - 1);

        Arrays.sort(arr);
        print(arr);

    }

    public static void print(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }


}
