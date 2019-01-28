using System;

namespace algo05_array
{
    public sealed class Array<T> where T : IComparable<T>
    {
        private T[] _data;
        private readonly int _capacity;
        private int _length;

        public Array(int capacity)
        {
            _data = new T[capacity];
            _capacity = capacity;
            _length = 0;
        }

        // length of list
        public int Length => _length;

        // insert a new element at specified index (index start from 0)
        public void Insert(int index, T newElem)
        {
            if (_length == _capacity)
            {
                throw new OutOfMemoryException("List has no more space");
            }

            if (index < 0 || index > _length)
            {
                throw new IndexOutOfRangeException("Index was outside the bounds of the list");
            }

            // to loop array from end until finding the target index
            for (int k = _length; k > index; k--)
            {
                _data[k] = _data[k - 1];
            }

            _data[index] = newElem;

            _length++;
        }

        // get an element base on index
        public T Find(int index)
        {
            if (index < 0 || index > _length - 1)
            {
                throw new IndexOutOfRangeException("Index was outside the bounds of the list");
            }

            return _data[index];
        }

        // search the node which matches specified value and return its index (index start from 0)
        public int IndexOf(T val)
        {
            if (_length == 0) return -1;
            if (_data[0].Equals(val)) return 0;
            if (_data[_length - 1].CompareTo(val) == 0) return _length - 1;

            int start = 1;
            while (start < _length - 1)
            {
                if (_data[start].CompareTo(val) == 0) return start;
                start++;
            }

            return -1;
        }

        // delete an node which is on the specified index
        public bool Delete(int index)
        {
            if (index < 0 || index > _length - 1)
            {
                throw new IndexOutOfRangeException("Index must be in the bound of list");
            }

            T deletedElem = _data[index];
            if (index < _length - 1)
            {
                for (int k = index; k < _length; k++)
                {
                    _data[k] = _data[k + 1];
                }
            }

            _length--;

            return true;
        }

        // delete an node 
        public bool Delete(T val)
        {
            int index;
            for (index = 0; index < Length; index++)
            {
                if (_data[index].CompareTo(val) == 0) break;
            }

            if (index >= Length) return false;

            return Delete(index);
        }

        // clear list
        public void Clear()
        {
            _data = new T[_capacity];
            _length = 0;
        }
    }
}