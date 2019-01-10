package bsearch16;

/**
 * Created by dell on 2019/1/11.
 */
public class BSearch {

    public static void main(String[] args) {
        int[] a = new int[]{1,2,6,9,12,12,12,12,67,91,321};

        int value = 12;

//        int index = bsearchSimple(a, 11, value);
//        int index = bsearchFistEqual(a, 11, value);
        int index = bsearchLastEqual(a, 11, value);
//        int index = bsearchFistBigger(a, 11, value);
//        int index = bsearchLastSmaller(a, 11, value);
        System.out.println("index:" + index + "," +(value == a[index]));

    }

    //简单二分查找
    public static int bsearchSimple(int[] a, int n, int value){
        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if(a[mid] == value){
                return mid;
            } else if(a[mid] < value) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return -1;
    }

    //查找第一个值等于给定值的数字
    public static int bsearchFistEqual(int[] a, int n , int value){
        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = low + ((high - low) >> 1);

            if(a[mid] < value){
                low = mid +1;
            } else if (a[mid] > value){
                high = mid -1;
            } else {
                if(mid == 0 || a[mid -1] != value){
                    return mid;
                } else {
                    high = mid -1;
                }
            }
        }
        return -1;
    }

    //查找最后一个值等于给定值的数字
    public static int bsearchLastEqual(int[] a, int n , int value){
        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = low + ((high - low) >> 1);

            if(a[mid] < value){
                low = mid +1;
            } else if (a[mid] > value){
                high = mid -1;
            } else {
                if(mid == n-1 || a[mid + 1] != value){
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }

    //查找第一个大于等于给定值的数字
    public static int bsearchFistBigger(int[] a, int n , int value){
        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = low + ((high - low) >> 1);

            if(a[mid] < value){
                low = mid +1;
            } else if (a[mid] >= value){
                if(mid == 0 || a[mid - 1] < value){
                    return mid;
                }
                high = mid -1;
            }
        }
        return -1;
    }

    //查找最后一个小于等于给定值的数字
    public static int bsearchLastSmaller(int[] a, int n , int value){
        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = low + ((high - low) >> 1);

            if(a[mid] <= value){
                if(mid == n -1 || a[mid + 1] > value){
                    return mid;
                }
                low = mid +1;
            } else if (a[mid] > value){
                high = mid -1;
            }
        }
        return -1;
    }

}
