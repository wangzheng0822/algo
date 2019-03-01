using Xunit;
using Xunit.Abstractions;
using algo06_linked_list;

namespace algo06_linkedlist_tests
{
    public class LRUWithLinkedListTests : BaseLinkedListTests
    {
        [Fact]
        public void LRU_Set_Value_When_Not_Existed()
        {
            var lru = new LRUWithLinkedList();

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);

            var list = lru.CachedList;

            PrintLinkedList(list);

            Assert.Equal(9, list.First.Value);
        }

        [Fact]
        public void LRU_Set_Value_When_Existed()
        {
            var lru = new LRUWithLinkedList();

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(3);

            var list = lru.CachedList;

            PrintLinkedList(list);

            Assert.Equal(3, list.First.Value);
        }

        [Fact]
        public void LRU_Set_Value_When_Full()
        {
            var lru = new LRUWithLinkedList(5);

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);
            lru.Set(8);

            var list = lru.CachedList;

            PrintLinkedList(list);

            Assert.Equal(8, list.First.Value);
        }
    }
}