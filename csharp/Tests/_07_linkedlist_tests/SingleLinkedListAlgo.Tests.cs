using System;
using Xunit;
using algo06_linkedlist_tests;
using algo06_linked_list;
using algo07_linkedlist;

namespace algo07_linkedlist_tests
{
    public class SingleLinkedListAlgoTests : BaseLinkedListTests
    {
        [Fact]
        public void Reverse_When_List_Is_Empty()
        {
            var list = new SingleLinkedListAlgo<string>();

            list.Reverse();

            PrintLinkedList(list);

            Assert.Null(list.First);
        }

        [Fact]
        public void Reverse_When_List_Has_Many_Elements()
        {
            var list = new SingleLinkedListAlgo<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            list.Reverse();

            PrintLinkedList(list);

            Assert.True(list.First.Value == "dog");
        }

        [Fact]
        public void HasCycle_List_Empty()
        {
            var list = new SingleLinkedListAlgo<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_False_When_List_Length_1()
        {
            var list = new SingleLinkedListAlgo<string>("The");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_False_When_List_Length_2()
        {
            var list = new SingleLinkedListAlgo<string>("The", "Quick");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_True_When_List_Length_2()
        {
            var list = new SingleLinkedListAlgo<string>();

            var firstNode = list.Insert(1, "The");
            var secondNode = list.Insert(2, "Quick");

            secondNode.Next = firstNode;

            bool hasCycle = list.HasCycle();

            Assert.True(hasCycle);
        }

        [Fact]
        public void HasCycle_False()
        {
            var linkList =
                new SingleLinkedListAlgo<string>("The", "Quick", "Brown", "fox", "jumps", "over", "the", "lazy", "dog");

            bool hasCycle = linkList.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_True()
        {
            var list = new SingleLinkedListAlgo<string>();

            // 初始化一个具有环的链表
            list.Insert(1, "The");
            list.Insert(2, "Quick");
            list.Insert(3, "Brown");
            var fourthNode = list.Insert(4, "fox");
            list.Insert(5, "jumps");
            list.Insert(6, "over");
            list.Insert(7, "the");
            list.Insert(8, "lazy");
            var last = list.Insert(9, "dog");

            last.Next = fourthNode;

            bool hasCycle = list.HasCycle();

            Assert.True(hasCycle);
        }

        [Fact]
        public void Merge()
        {
            var list1 = new SingleLinkedListAlgo<int>(1, 2, 4);
            var list2 = new SingleLinkedListAlgo<int>(1, 3, 4);

            var list3 = list1.Merge(list2);

            PrintLinkedList(list3);

            Assert.True(list1.First.Next.Next.Value == 2);
        }

        [Fact]
        public void Remove_2th_Node_From_End()
        {
            var list = new SingleLinkedListAlgo<int>(1, 2, 3, 4, 5);
            list.RemoveNthNodeFromEnd(2);

            PrintLinkedList(list);

            Assert.True(list.First.Next.Next.Next.Value == 5);
        }

        [Fact]
        public void FindMiddleNode()
        {
            var list = new SingleLinkedListAlgo<int>(1, 2, 3, 4, 5);

            ListNode<int> middleNode = list.FindMiddleNode();

            Assert.True(middleNode.Value == 3);
        }
    }
}