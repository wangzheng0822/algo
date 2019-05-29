using algo05_array;

namespace algo06_linked_list
{
    /// <summary>
    /// 使用数组实现LRU缓存淘汰算法
    /// </summary>
    public class LRUWithArray
    {
        private readonly int _capacity;

        public LRUWithArray(int capacity)
        {
            _capacity = capacity;
            CachedList = new Array<int>(capacity);
        }

        public Array<int> CachedList { get; }

        public void Set(int val)
        {
            // 找出该值在缓存中的索引位置
            int idx = CachedList.IndexOf(val);

            // 存在该缓存值
            if (idx != -1)
            {
                CachedList.Delete(idx);
                CachedList.Insert(0, val);
                return;
            }

            // 不存在该缓存值
            if (CachedList.Length == _capacity)
            {
                // 缓存已满，删除最后一个元素
                CachedList.Delete(CachedList.Length - 1);
            }

            // 将新缓存插入到表头
            CachedList.Insert(0, val);
        }
    }
}