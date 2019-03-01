using System;
using algo06_linked_list;

namespace algo06_linkedlist_tests
{
    public class BaseLinkedListTests
    {
        protected void PrintLinkedList<T> (SingleLinkedList<T> list) where T : IComparable<T>
        {
            if (list == null) return;

            var p = list.First;
            while (p != null)
            {
                System.Console.WriteLine (p.Value);
                p = p.Next;
            }
        }
    }
}