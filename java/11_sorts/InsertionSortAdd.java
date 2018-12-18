package sorts;

import java.util.Arrays;

/**
 * 插入排序（插入位置，从头至尾搜索）
 * @Author： ooooor
 */
public class InsertionSortAdd {

    public static void main(String[] args) {
        int[] data = new int[]{4, 6, 5, 3, 7, 1, 2};
        fromStartToEnd(Arrays.copyOf(data, data.length));
        System.out.println(Arrays.toString(data));
    }

    /**
     * 查询插入位置时， 从头至尾搜索
     * @param data
     */
    private static void fromStartToEnd(int[] data) {
        for (int i=1; i < data.length; i++) {
            int value = data[i];

            int[] tmp = new int[2];
            int change = i;
            for (int j=0; j < i; j++) {
                if(value >= data[j]) {
                    continue;
                }

                int index = j%2;
                if (change == i) {
                    tmp[Math.abs(index-1)] = data[j];
                    change = j;
                }
                tmp[index] = data[j+1];
                if (0 == index) {
                    data[j+1] = tmp[index+1];
                } else {
                    data[j+1] = tmp[index-1];
                }
            }
            data[change] = value;
        }
    }

}
