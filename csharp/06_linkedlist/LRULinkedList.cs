namespace _06_linked_list
{
    /// <summary>
    /// 使用单链表实现LRU缓存淘汰算法
    /// </summary>
    /// <remarks>
    /// 思路：
    /// 维护一个有序单链表，越是靠近链尾的数据是最早访问的。当有一个新的数据被访问时，
    /// 1. 如果数据在缓存中，则将其从原位置删除，然后插入到表头；
    /// 2. 如果数据不在缓存中，有两种情况：
    ///     1) 链表未满，则将数据插入到表头；
    ///     2) 链表已满，则删除尾结点，将新数据插入到表头。
    /// </remarks>
    public class LRULinkedList
    {
        private readonly SingleLinkedList<int> _cachedList = new SingleLinkedList<int>();
        private readonly int _capacity;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="capacity">缓存容量</param>
        public LRULinkedList(int capacity = 10)
        {
            _capacity = capacity;
        }

        /// <summary>
        /// 存储缓存数据
        /// </summary>
        /// <param name="val"></param>
        public void Set(int val)
        {
            var deletedNode = _cachedList.Delete(value: val);

            // 数据在缓存中存在，从原位置删除，然后插入到表头
            if (deletedNode != null)
            {
                _cachedList.Insert(1, val);
                return;
            }

            // 数据不存在
            if (_cachedList.Length != _capacity)
            {
                // 链表未满
                _cachedList.Insert(1, val);
            }
            else
            {
                // 链表已满，删除尾结点，将新数据插入到头部
                _cachedList.Delete(_cachedList.Length);
                _cachedList.Insert(1, val);
            }
        }

        public SingleLinkedList<int> GetCachedList()
        {
            return _cachedList;
        }
    }

}