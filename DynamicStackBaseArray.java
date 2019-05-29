package Stack;

import java.util.Iterator;

/**
 * 顺序栈的动态扩容
 * Author: PeiJiaNi
 * @param <T>  顺序栈元素类型
 */

public class DynamicStackBaseArray<T> implements Iterable<T> {
    private T[] items;   // 数组
    private int count;   // 栈中的元素个数
    private int length;  // 栈空间大小

    /**
     * 初始化栈
     *
     * @param length 栈空间大小
     */
    public DynamicStackBaseArray(int length) {
        this.items = (T[]) new Object[length];
        this.count = 0;
        this.length = length;
    }

    /**
     * 入栈操作 平均时间复杂度O(1)
     *
     * @param item 入栈元素
     */
    public void push(T item) {
        // 栈空间已满，则扩容
        if (count == length) {
            resize(2 * items.length);
        }

        items[count++] = item;
    }

    /**
     * 出栈操作 平均时间复杂度O(1)
     *
     * @return 如果栈内不为空，则返回栈顶元素，否则返回-1
     */
    public T pop() {
        if (count == 0) {
            System.out.println("当前栈已空，无法进行出栈操作");
            return null;
        }

        T item = items[--count];
        items[count] = null;

        if (count > 0 && (count == items.length / 4)) {
            resize(items.length / 2);
        }

        // 返回下标为 count-1 的数组元素，并且栈中元素个数count-1
        return item;
    }

    /**
     * 栈空间动态增加或减小
     *
     * @param size
     */
    private void resize(int size) {
        T[] newItems = (T[]) new Object[size];
        for (int i = 0; i < count; i++) {
            newItems[i] = this.items[i];
        }
        this.items = newItems;
    }

    //返回栈中最近添加的元素而不删除它
    public T peek() {
        return items[count - 1];
    }

    /**
     * 判断当前栈是否为空
     *
     * @return 栈为空，则返回true,否则返回-1
     */
    public boolean isEmpty() {
        return count == 0;
    }

    /**
     * 返回栈中元素个数
     *
     * @return
     */
    public int size() {
        return count;
    }

    @Override
    public Iterator<T> iterator() {
        return new ArrayIterator();
    }

    // 内部类
    class ArrayIterator implements Iterator {
        int numOfItems = count;

        @Override
        public boolean hasNext() {
            return numOfItems > 0;
        }

        @Override
        public T next() {
            return items[--numOfItems];
        }
    }

    public static void main(String[] args) {
        DynamicStackBaseArray<Integer> stack = new DynamicStackBaseArray<Integer>(6);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        // System.out.println(stack.peek());
        Iterator iterator = stack.iterator();
        // System.out.println(iterator.hasNext());
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

    }

}

