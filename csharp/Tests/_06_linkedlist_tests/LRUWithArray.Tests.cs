using algo05_array;
using algo06_linked_list;
using Xunit;
using Xunit.Abstractions;

namespace algo06_linkedlist_tests
{
    public class LRUWithArrayTests
    {
        private ITestOutputHelper _output;

        public LRUWithArrayTests(ITestOutputHelper output)
        {
            _output = output;
        }

        private void PrintList(Array<int> list)
        {
            if (list == null) return;
            for (int idx = 0; idx < list.Length; idx++)
            {
                _output.WriteLine(list.Find(idx).ToString());
            }
        }

        [Fact]
        public void LRU_Set_Value_When_Not_Existed()
        {
            var lru = new LRUWithArray(5);

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);

            var list = lru.CachedList;

            PrintList(list);

            Assert.Equal(9, list.Find(0));
        }


        [Fact]
        public void LRU_Set_Value_When_Existed()
        {
            var lru = new LRUWithArray(5);

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(3);

            var list = lru.CachedList;

            PrintList(list);

            Assert.Equal(3, list.Find(0));
        }

        [Fact]
        public void LRU_Set_Value_When_Full()
        {
            var lru = new LRUWithArray(5);

            lru.Set(1);
            lru.Set(3);
            lru.Set(5);
            lru.Set(7);
            lru.Set(9);
            lru.Set(8);

            var list = lru.CachedList;

            PrintList(list);

            Assert.Equal(8, list.Find(0));
        }
    }
}