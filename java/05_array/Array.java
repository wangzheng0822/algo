package array;

/**
 * 1) 数组的插入、删除、按照下标随机访问操作；
 * 2）数组中的数据是int类型的；
 *
 * Author: Zheng
 */
public class Array {
    //定义整型数据data保存数据
    public int data[];
    //定义数组长度
    private int n;
    //定义中实际个数
    private int count;

    //构造方法，定义数组大小
    public Array(int capacity){
        this.data = new int[capacity];
        this.n = capacity;
        this.count=0;//一开始一个数都没有存所以为0
    }

    //根据索引，找到数据中的元素并返回
    public int find(int index){
        if (index<0 || index>=count) return -1;
        return data[index];
    }

    //根据索引，删除数组中元素
    public boolean delete(int index){
        if (index<0 || index >=count) return false;
        //从删除位置开始，将后面的元素向前移动一位
        for (int i=index+1; i<count; ++i){
            data[i-1] = data[i];
        }
        //删除数组末尾元素  这段代码不需要也可以
        /*int[] arr = new int[count-1];
        for (int i=0; i<count-1;i++){
            arr[i] = data[i];
        }
        this.data = arr;*/


        --count;
        return true;
    }

    //向数组中插入一个元素
    public boolean insert(int index, int value){
        if (index<0 || index>=count) return false;
        //当实际存储的个数等于数组的最大长度就不让新增
        if (count == n) return false;
        //数组长度增加1。不需要初始化
        /*int[] arr = new int[count+1];
        for (int i = 0; i < data.length; i++) {
            arr[i] = data[i];
        }
        data=arr;*/

        for (int i = count-1; i>=index; --i){
            data[i+1] = data[i];
        }
        data[index] = value;
        ++count;
        return true;
    }

    public boolean insertToTail(int value) {
        
        //当实际存储的个数等于数组的最大长度就不让新增
        if (count == n) return false;
        //数组长度增加1
        /*int[] arr = new int[count+1];
        for (int i = 0; i < data.length; i++) {
            arr[i] = data[i];
        }
        data=arr;*/
        data[count++] = value;
        return true;
    }

    public void printAll() {
        for (int i = 0; i < count; ++i) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }



}
