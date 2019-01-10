using System;
using Xunit;
using Xunit.Abstractions;

namespace _06_linked_list
{
    public class SingleLinkedListTests : BaseLinkedListTests
    {
        [Fact]
        public void Insert_3_Elements_Return_Length_3()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            PrintList(list);

            Assert.Equal(3, list.Length);
        }

        [Fact]
        public void Insert_Some_Elements_Then_Verify_First()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            Assert.Equal("The", list.First.Value);
        }

        [Fact]
        public void Insert_Some_Elements_Then_Verify_Last()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            Assert.Equal("Brown", list.First.Next.Next.Value);
        }

        [Fact]
        public void Find_Return_Null_When_Postion_LessThan_1()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(0);
            Assert.Null(node);
        }

        [Fact]
        public void Find_Return_Null_When_Postion_GreaterThan_Length()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(4);
            Assert.Null(node);
        }

        [Fact]
        public void Find_Return_Correct_When_Postion_Valid()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(2);
            Assert.Equal("Quick", node.Value);
        }

        [Fact]
        public void Delete_Return_Null_When_Postion_LessThan_1()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Delete(0);
            Assert.Null(node);
        }

        [Fact]
        public void Delete_Return_Null_When_Postion_GreaterThan_Length()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Delete(4);
            Assert.Null(node);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Element_Exist()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("over");

            PrintList(list);

            Assert.Equal("over", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Element_Not_Exist()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("hello");

            PrintList(list);

            Assert.Null(deletedNode);
            Assert.Equal(9, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Delete_First()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("The");

            PrintList(list);

            Assert.Equal("The", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Delete_Last()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("dog");

            PrintList(list);

            Assert.Equal("dog", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_Success_When_Position_Valid()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var node = list.Delete(3);

            PrintList(list);

            Assert.Equal("Brown", node.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Clear_Length_Equal_0()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            list.Clear();

            Assert.Equal(0, list.Length);
        }

        [Fact]
        public void Clear_First_Is_Null()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            list.Clear();

            Assert.Null(list.First);
        }

        [Fact]
        public void Reverse_When_List_Is_Empty()
        {
            var list = new SingleLinkedList<string>();

            list.Reverse();

            PrintList(list);

            Assert.Null(list.First);
        }

        [Fact]
        public void Reverse_When_List_Has_Many_Elements()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            list.Reverse();

            PrintList(list);

            Assert.True(list.First.Value == "dog");
        }

        [Fact]
        public void HasCycle_List_Empty()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_False_When_List_Length_1()
        {
            var list = new SingleLinkedList<string>("The");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_False_When_List_Length_2()
        {
            var list = new SingleLinkedList<string>("The", "Quick");

            bool hasCycle = list.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_True_When_List_Length_2()
        {
            var list = new SingleLinkedList<string>();

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
                new SingleLinkedList<string>("The", "Quick", "Brown", "fox", "jumps", "over", "the", "lazy", "dog");

            bool hasCycle = linkList.HasCycle();

            Assert.False(hasCycle);
        }

        [Fact]
        public void HasCycle_True()
        {
            var list = new SingleLinkedList<string>();

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
            var list1 = new SingleLinkedList<int>(1, 2, 4);
            var list2 = new SingleLinkedList<int>(1, 3, 4);

            var list3 = list1.Merge(list2);

            PrintList(list3);

            Assert.True(list1.First.Next.Next.Value == 2);
        }

        [Fact]
        public void Remove_2th_Node_From_End()
        {
            var list = new SingleLinkedList<int>(1, 2, 3, 4, 5);
            list.RemoveNthNodeFromEnd(2);

            PrintList(list);

            Assert.True(list.First.Next.Next.Next.Value == 5);
        }

        [Fact]
        public void FindMiddleNode()
        {
            var list = new SingleLinkedList<int>(1, 2, 3, 4, 5);

            LinkedListNode<int> middleNode = list.FindMiddleNode();

            Assert.True(middleNode.Value == 3);
        }
    }
}