using System;

namespace _06_linked_list
{
    public class BaseLinkedListTests
    {
        protected void PrintList<T> (SingleLinkedList<T> list) where T : IComparable<T>
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