package tree24;

import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * Created by dell on 2019/1/27.
 */
public class HeapSot {

    public static void main(String[] args) {
//        PriorityQueue
        int[] data = new int[]{4, 6, 5, 3, 7, 1, 2};
        sort(data, 7);

        System.out.println(data);
    }

    // n 表示数据的个数，数组 a 中的数据从下标 1 到 n 的位置。
    public static void sort(int[] a, int n) {
        buildHeap(a, n);
        int k = n;
        while (k > 1) {
            swap(a, 1, k);
            --k;
            heapify(a, k, 1);
        }
    }

    private static void buildHeap(int[] a, int n) {
        for (int i = n/2; i >= 1; --i) {
            heapify(a, n, i);
        }
    }

    private static void heapify(int[] a, int n, int i) {
        while (true) {
            int maxPos = i;
            if (i*2+1 <= n && a[i] < a[i*2+1]) maxPos = i*2+1;
            if (i*2+2 <= n && a[maxPos] < a[i*2+2]) maxPos = i*2+2;
            if (maxPos == i) break;
            swap(a, i, maxPos);
            i = maxPos;
        }
    }


    /* 堆排序
     * 1. 先将初始序列K[1..n]建成一个大顶堆, 那么此时第一个元素K1最大, 此堆为初始的无序区.
     * 2. 再将关键字最大的记录K1 (即堆顶, 第一个元素)和无序区的最后一个记录 Kn 交换, 由此得到新的无序区K[1..n−1]和有序区K[n], 且满足K[1..n−1].keys⩽K[n].key
     * 3. 交换K1 和 Kn 后, 堆顶可能违反堆性质, 因此需将K[1..n−1]调整为堆. 然后重复步骤②, 直到无序区只有一个元素时停止.
     */
    public static void heapSort(int[] arr){
        for(int i = arr.length; i > 0; i--){
            // 把数组中(0,i)之间的索引的数据送入到最大堆函数中实现最大堆
            max_heapify(arr, i);  //由于i在减小，所以输入的可以操作的数组也在变小，实现了后面排序好的数据的不可操作性
            swap(arr, i-1, 0);  //堆顶元素(第一个元素)与Kn交换
        }
    }

    private static void max_heapify(int[] arr, int limit){
        if(arr.length <= 0 || arr.length < limit) return;
        int parentIdx = limit / 2;
        //横向层序遍历，从右向左，从下往上，实现把最大的数值往上走，从而实现最大堆
        for(; parentIdx >= 0; parentIdx--){
            if(parentIdx * 2 >= limit){
                continue;
            }
            int left = parentIdx * 2;       //左子节点位置
            int right = (left + 1) >= limit ? left : (left + 1);    //右子节点位置，如果没有右节点，默认为左节点位置

            int maxChildId = arr[left] >= arr[right] ? left : right;
            if(arr[maxChildId] > arr[parentIdx]){   //交换父节点与左右子节点中的最大值
                swap(arr, maxChildId, parentIdx);
            }
        }
        System.out.println("Max_Heapify: " + Arrays.toString(arr));
    }
    public static void swap(int[] arr,int a,int b){
        int tmp=arr[a];
        arr[a]=arr[b];
        arr[b]=tmp;
    }
}
