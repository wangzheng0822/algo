using System;

namespace _06_linked_list
{
    /// <summary>
    /// 单链表的插入、删除、清空、查找
    /// 1. 链表反转
    /// 2. 环的检测
    /// 3. 两个有序链表的合并
    /// 4. 删除链表倒数第n个结点
    /// 5. 求链表的中间结点
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class SingleLinkedList<T> where T : IComparable<T>
    {
        public SingleLinkedList ()
        {
            Head = new LinkedListNode<T> (default (T));
        }

        public SingleLinkedList (params T[] list)
        {
            Head = new LinkedListNode<T> (default (T));
            if (list == null) return;

            var p = Head;
            foreach (var item in list)
            {
                var q = new LinkedListNode<T> (item);
                p.Next = q;
                p = q;
            }

            Length = list.Length;
        }

        // Head node
        public LinkedListNode<T> First => Head.Next;
        public LinkedListNode<T> Head { get; }

        public int Length { get; private set; }

        public LinkedListNode<T> Insert (int position, T newElem)
        {
            if (position < 1 || position > Length + 1)
            {
                throw new IndexOutOfRangeException ("Position must be in bound of list");
            }

            var p = Head;

            int j = 1;
            while (p != null && j < position)
            {
                p = p.Next;
                ++j;
            }

            var newNode = new LinkedListNode<T> (newElem);
            newNode.Next = p.Next;
            p.Next = newNode;

            Length++;

            return newNode;
        }

        public LinkedListNode<T> Find (int position)
        {
            LinkedListNode<T> p = First;
            int j = 1;

            while (p != null && j < position)
            {
                p = p.Next;
                j++;
            }

            if (p == null || j > position)
            {
                return null;
            }

            return p;
        }

        public LinkedListNode<T> Find (T elem)
        {
            LinkedListNode<T> p = Head.Next;

            while (p != null)
            {
                if (p.Value.CompareTo (elem) == 0) return p;

                p = p.Next;
            }

            return null;
        }

        public LinkedListNode<T> Delete (T value)
        {
            LinkedListNode<T> cur = Head;
            while (cur.Next != null && cur.Next.Value.CompareTo (value) != 0)
            {
                cur = cur.Next;
            }

            if (cur.Next == null) return null;

            var q = cur.Next;
            cur.Next = q.Next;

            Length--;

            return q;
        }

        public LinkedListNode<T> Delete (int position)
        {
            if (position < 1 || position > Length)
            {
                return null;
            }

            var p = First;
            int j = 1;
            while (p != null && j < position - 1)
            {
                p = p.Next;
                ++j;
            }

            var q = p.Next;
            p.Next = q.Next;

            Length--;

            return q;
        }

        public void Clear ()
        {
            var cur = Head;
            while (cur.Next != null)
            {
                var q = cur.Next;
                cur.Next = null;

                cur = q;
            }

            Length = 0;
        }

        /// <summary>
        /// reverse current list
        /// </summary>
        public void Reverse ()
        {
            if (Length <= 1) return;

            LinkedListNode<T> p = First;
            LinkedListNode<T> q = First.Next;

            LinkedListNode<T> r = null;

            p.Next = null;
            while (q != null)
            {
                r = q.Next;

                q.Next = p;
                p = q;
                q = r;
            }

            Head.Next = p;
        }

        /// <summary>
        /// 环的检测
        /// </summary>
        /// <remarks>
        /// 用快慢两个指针，快指针每次移动2个结点，慢指针每次移动1个结点，当两个指针相遇时，说明存在环。
        /// LeetCode 编号： 141
        /// </remarks>
        public bool HasCycle ()
        {
            if (Length == 0) return false;

            var slow = Head.Next;
            var fast = Head.Next.Next;

            while (fast != null && slow != null && fast != slow)
            {
                fast = fast.Next?.Next;
                slow = slow.Next;
            }

            bool ret = fast == slow;
            return ret;
        }

        /// <summary>
        /// 合并两个有序链表(从小到大)
        /// </summary>
        /// <remarks>LeetCode 编号： 21</remarks>
        /// <param name="list"></param>
        /// <returns></returns>
        public SingleLinkedList<T> Merge (SingleLinkedList<T> list)
        {
            if (list == null) return null;

            var root = new SingleLinkedList<T> ();

            LinkedListNode<T> pointer = root.Head; // 总是向新链表的尾结点

            var head1 = list.First;
            var head2 = this.First;

            while (head1 != null && head2 != null)
            {
                if (head1.Value.CompareTo (head2.Value) < 0)
                {
                    pointer.Next = head1;
                    head1 = head1.Next;
                }
                else
                {
                    pointer.Next = head2;
                    head2 = head2.Next;
                }

                pointer = pointer.Next; // 指向尾结点
            }

            if (head1 != null)
            {
                pointer.Next = head1;
            }

            if (head2 != null)
            {
                pointer.Next = head2;
            }

            return root;
        }

        /// <summary>
        /// 删除倒数第n个结点
        /// </summary>
        /// <remarks>
        /// 用快慢两个指针，快指针比慢指针早n个结点，然后再同步移动两个指针，当快指针指向尾结点时，慢指针就是将要删除的结点
        /// LeetCode 编号： 19
        /// </remarks>
        /// <param name="n"></param>
        public void RemoveNthNodeFromEnd (int n)
        {
            if (n < 1 || n > Length) return;

            LinkedListNode<T> preNode = Head;
            LinkedListNode<T> curNode = Head;

            for (int i = 0; i < n; i++)
            {
                curNode = curNode.Next;
            }

            if (curNode == null) return;

            while (curNode.Next != null)
            {
                preNode = preNode.Next;
                curNode = curNode.Next;
            }

            preNode.Next = preNode.Next.Next;
        }

        /// <summary>
        /// 链表的中间结点
        /// </summary>
        /// <remarks>
        /// 思路： 利用快慢指针，快指针步长2，慢指针步长1，当快指针到达尾结点时，慢指针正好到达中间结点
        /// LeetCode 编号： 876
        /// </remarks>
        /// <returns></returns>
        public LinkedListNode<T> FindMiddleNode ()
        {
            if (First?.Next == null) return null;

            LinkedListNode<T> slowPointer = First;
            LinkedListNode<T> fastPointer = First.Next;

            while (fastPointer.Next?.Next != null)
            {
                fastPointer = fastPointer.Next.Next;
                slowPointer = slowPointer.Next;
            }

            slowPointer = slowPointer.Next;
            return slowPointer;
        }
    }

    public class LinkedListNode<T>
    {
        private T _value;

        public LinkedListNode (T value)
        {
            _value = value;
        }

        public T Value => _value;
        public LinkedListNode<T> Next { get; set; }
    }
}