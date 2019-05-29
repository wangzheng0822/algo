using System;

namespace algo08_stack
{
    public class LinkedStack<T>
    {
        private StackListNode<T> _top;

        public int Count { get; private set; }

        public void Push(T val)
        {
            var newNode = new StackListNode<T>(val);
            newNode.Next = _top;
            _top = newNode;

            Count++;
        }

        public T Pop()
        {
            if (_top == null) throw new InvalidOperationException("Stack empty");

            T val = _top.Value;
            _top = _top.Next;

            Count--;

            return val;
        }

        public void Clear()
        {
            while (Count > 0)
            {
                Pop();
            }
        }
    }

    public class StackListNode<T>
    {
        public StackListNode(T nodeValue)
        {
            Value = nodeValue;
        }

        public T Value { get; set; }
        public StackListNode<T> Next { get; set; }
    }
}