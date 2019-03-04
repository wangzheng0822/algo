using System;
using Xunit;
using Xunit.Abstractions;
using algo06_linked_list;

namespace algo06_linkedlist_tests
{
    public class SingleLinkedListTests : BaseLinkedListTests
    {
        [Fact]
        public void Insert_3_Elements_Return_Length_3()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            PrintLinkedList(list);

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
        public void Find_Return_Null_When_Position_LessThan_1()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(0);
            Assert.Null(node);
        }

        [Fact]
        public void Find_Return_Null_When_Position_GreaterThan_Length()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(4);
            Assert.Null(node);
        }

        [Fact]
        public void Find_Return_Correct_When_Position_Valid()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Find(2);
            Assert.Equal("Quick", node.Value);
        }

        [Fact]
        public void Delete_Return_Null_When_Position_LessThan_1()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown");

            var node = list.Delete(0);
            Assert.Null(node);
        }

        [Fact]
        public void Delete_Return_Null_When_Position_GreaterThan_Length()
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

            PrintLinkedList(list);

            Assert.Equal("over", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Element_Not_Exist()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("hello");

            PrintLinkedList(list);

            Assert.Null(deletedNode);
            Assert.Equal(9, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Delete_First()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("The");

            PrintLinkedList(list);

            Assert.Equal("The", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_By_Value_Success_When_Delete_Last()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var deletedNode = list.Delete("dog");

            PrintLinkedList(list);

            Assert.Equal("dog", deletedNode.Value);
            Assert.Equal(8, list.Length);
        }

        [Fact]
        public void Delete_Success_When_Position_Valid()
        {
            var list = new SingleLinkedList<string>("The", "Quick", "Brown", "Fox", "jumps", "over", "the", "lazy",
                "dog");

            var node = list.Delete(3);

            PrintLinkedList(list);

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

    }
}