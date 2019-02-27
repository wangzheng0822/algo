namespace algo06_linked_list
{
    /// <summary>
    /// 使用单链表实现LRU缓存淘汰算法
    /// </summary>
    public class LRUWithLinkedList
    {
        private readonly int _capacity;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="capacity">缓存容量</param>
        public LRUWithLinkedList(int capacity = 10)
        {
            _capacity = capacity;
        }

        public SingleLinkedList<int> CachedList { get; } = new SingleLinkedList<int>();

        /// <summary>
        /// 存储缓存数据
        /// </summary>
        /// <param name="val"></param>
        public void Set(int val)
        {
            // 尝试删除匹配到和给定值相等的结点，并返回
            var deletedNode = CachedList.Delete(value: val);

            // 数据在缓存中存在，从原位置删除，然后插入到表头
            if (deletedNode != null)
            {
                CachedList.Insert(1, val);
                return;
            }

            // 数据不存在
            if (CachedList.Length == _capacity)
            {
                // 链表已满，删除尾结点，将新数据插入到头部
                CachedList.Delete(CachedList.Length);
            }

            // 将新缓存值插入到表头
            CachedList.Insert(1, val);
        }
    }
}