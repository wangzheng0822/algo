/**
 * 散列表
 * @Author: will
 */
class HashTable<K, V> {
    /**
     * 初始化散列表数组
     */
    private var table: Array<Entry<K?, V?>?>
    /**
     * 实际元素数量
     */
    private var size = 0
    /**
     * 散列表索引数量
     */
    private var use = 0

    internal class Entry<K, V>(var key: K, var value: V, var next: Entry<K, V>?)

    /**
     * 新增
     *
     * @param key     键
     * @param value   值
     */
    fun put(key: K, value: V) {
        val index = hash(key)
        // 位置未被引用，创建哨兵节点
        if (table[index] == null) {
            table[index] = Entry(null, null, null)
        }
        var tmp = table[index]
        // 新增节点
        if (tmp!!.next == null) {
            tmp.next = Entry(key, value, null)
            size++
            use++
            // 动态扩容
            if (use >= table.size * LOAD_FACTOR) {
                resize()
            }
        } else {
            do {
                tmp = tmp!!.next
                // key相同，覆盖旧的数据
                if (tmp!!.key === key) {
                    tmp!!.value = value
                    return
                }
            } while (tmp!!.next != null)
            val temp = table[index]?.next
            table[index]?.next = Entry(key, value, temp)
            size++
        }
    }

    /**
     * 散列函数
     *
     *
     * 参考hashmap散列函数
     *
     * @param key
     * @return
     */
    private fun hash(key: Any?): Int {
        var h: Int
        return if (key == null) 0 else (key.hashCode().also {
            h = it
        } xor (h ushr 16)) % table.size
    }

    /**
     * 扩容
     */
    private fun resize() {
        val oldTable = table
        table =
            arrayOfNulls<Entry<*, *>?>(table.size * 2) as Array<Entry<K?, V?>?>
        use = 0
        for (i in oldTable.indices) {
            if (oldTable[i] == null || oldTable[i]?.next == null) {
                continue
            }
            var e = oldTable[i]
            while (e!!.next != null) {
                e = e.next
                val index = hash(e!!.key)
                if (table[index] == null) {
                    use++
                    // 创建哨兵节点
                    table[index] = Entry(null, null, null)
                }
                table[index]?.next =
                    Entry(e.key, e.value, table[index]?.next)
            }
        }
    }

    /**
     * 删除
     *
     * @param key   值
     */
    fun remove(key: K) {
        val index = hash(key)
        var e: Entry<*, *>? = table[index]
        if (e?.next == null) {
            return
        }
        var pre: Entry<*, *>?
        val headNode = table[index]
        do {
            pre = e
            e = e!!.next
            if (key === e!!.key) {
                pre!!.next = e!!.next
                size--
                if (headNode!!.next == null) use--
                return
            }
        } while (e!!.next != null)
    }

    /**
     * 获取
     *
     * @param key
     * @return
     */
    operator fun get(key: K): V? {
        val index = hash(key)
        var e = table[index]
        if (e?.next == null) {
            return null
        }
        while (e!!.next != null) {
            e = e.next
            if (key === e!!.key) {
                return e!!.value
            }
        }
        return null
    }

    companion object {
        /**
         * 散列表默认长度
         */
        private const val DEFAULT_INITAL_CAPACITY = 8
        /**
         * 装载因子
         */
        private const val LOAD_FACTOR = 0.75f
    }

    init {
        table =
            arrayOfNulls<Entry<*, *>?>(DEFAULT_INITAL_CAPACITY) as Array<Entry<K?, V?>?>
    }
}