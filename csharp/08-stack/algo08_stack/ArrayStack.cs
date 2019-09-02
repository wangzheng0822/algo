using System;

namespace algo08_stack
{
    public class ArrayStack<T>
    {
        private readonly int _capacity;

        private readonly T[] _data;

        private int _top = -1; // 指向栈顶元素，当为-1时表示栈为空

        public ArrayStack(int capacity)
        {
            _capacity = capacity;

            _data = new T[capacity];
        }

        public int Count => _top + 1;

        public void Push(T val)
        {
            if (Count == _capacity) throw new InvalidOperationException("Stack full.");

            _top++;

            _data[_top] = val;
        }

        public T Pop()
        {
            if (_top == -1) throw new InvalidOperationException("Stack empty.");

            T val = _data[_top];
            _top--;

            return val;
        }
    }
}