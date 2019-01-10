using Xunit;
using Xunit.Abstractions;

namespace _06_linked_list
{
    public class LRULinkedListTests : BaseLinkedListTests
    {
        [Fact]
        public void LRU_Set_Value_When_Not_Existed()
        {
            var lru = new LRULinkedList();

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);

            var list = lru.GetCachedList();

            PrintList(list);

            Assert.Equal(9, list.First.Value);
        }

        [Fact]
        public void LRU_Set_Value_When_Existed()
        {
            var lru = new LRULinkedList();

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(3);

            var list = lru.GetCachedList();

            PrintList(list);

            Assert.Equal(3, list.First.Value);
        }

        [Fact]
        public void LRU_Set_Value_When_Full()
        {
            var lru = new LRULinkedList(5);

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);
            lru.Set(8);

            var list = lru.GetCachedList();

            PrintList(list);

            Assert.Equal(8, list.First.Value);
        }
    }
}