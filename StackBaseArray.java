package Stack;

/**
 * 顺序栈(基于数组实现)
 * Author: PeiJiaNi
 */
public class StackBaseArray {
    private int[] items;    // 数组
    private int count;      // 栈中元素个数
    private int length;   // 栈空间大小

    public StackBaseArray(int capactiy) {
        this.items = new int[capactiy];
        this.count = 0;
        this.length = capactiy;
    }

    /**
     * 入栈操作 时间复杂度O(1)
     * @param item 要入栈的元素
     * @return     入栈成功则返回true,否则返回false
     */
    public boolean  push(int item) {
        if(count == length) {
            System.out.println("当前栈已满，无法进行入栈操作");
            return false;
        }
        items[count] = item;
        ++count;
        return true;
    }

    /**
     * 出栈操作 时间复杂度O(1)
     * @return 如果栈内不为空，则返回栈顶元素，否则返回-1
     */
    public int  pop(){
        if(count == 0) {
            System.out.println("当前栈已空，无法进行出栈操作");
            return -1;
        }

        // 返回下标为 count-1 的数组元素，并且栈中元素个数count-1
        return items[--count];
    }

    public static void main(String[] args){
        StackBaseArray stack = new StackBaseArray(6);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());

    }


}

