using System;
using algo06_linked_list;

namespace algo07_linkedlist
{
    /// <summary>
    /// 单链表常用算法操作
    /// 1. 链表反转
    /// 2. 环的检测
    /// 3. 两个有序链表的合并
    /// 4. 删除链表倒数第n个结点
    /// 5. 求链表的中间结点
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class SingleLinkedListAlgo<T> : SingleLinkedList<T> where T : IComparable<T>
    {
        public SingleLinkedListAlgo(params T[] list) : base(list)
        {
        }

        /// <summary>
        /// 链表反转
        /// </summary>
        public void Reverse()
        {
            if (Length <= 1) return;

            ListNode<T> p = First;
            ListNode<T> q = First.Next;

            ListNode<T> r = null;

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
        public bool HasCycle()
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
        /// <param name="listAlgo"></param>
        /// <returns></returns>
        public SingleLinkedListAlgo<T> Merge(SingleLinkedListAlgo<T> listAlgo)
        {
            if (listAlgo == null) return null;

            var root = new SingleLinkedListAlgo<T>();

            ListNode<T> pointer = root.Head; // 总是向新链表的尾结点

            var head1 = listAlgo.First;
            var head2 = this.First;

            while (head1 != null && head2 != null)
            {
                if (head1.Value.CompareTo(head2.Value) < 0)
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
        public void RemoveNthNodeFromEnd(int n)
        {
            if (n < 1 || n > Length) return;

            ListNode<T> preNode = Head;
            ListNode<T> curNode = Head;

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
        public ListNode<T> FindMiddleNode()
        {
            if (First?.Next == null) return null;

            ListNode<T> slowPointer = First;
            ListNode<T> fastPointer = First.Next;

            while (fastPointer.Next?.Next != null)
            {
                fastPointer = fastPointer.Next.Next;
                slowPointer = slowPointer.Next;
            }

            slowPointer = slowPointer.Next;
            return slowPointer;
        }
    }
}