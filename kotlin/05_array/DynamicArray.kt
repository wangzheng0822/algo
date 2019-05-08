/**
 * 动态扩容的数组
 */
class DynamicArray {
    companion object {
        // 默认容量
        const val DEFAULT_CAPACITY = 10

        // 最大容量
        const val MAX_CAPACITY = Int.MAX_VALUE
    }

    // 当前已使用大小
    private var usedSize = 0

    // 当前容量大小
    private var capacity = 0

    // 数组容器
    private var data: Array<Int>

    init {
        this.capacity = DEFAULT_CAPACITY
        this.data = Array(this.capacity) { 0 }
    }

    /**
     * 增加元素
     */
    fun add(value: Int) {
        if (this.usedSize == this.capacity - 1) {
            this.doubleCapacity()
        }
        this.data[this.usedSize] = value
        ++this.usedSize
    }

    /**
     * 移除元素
     */
    fun remove(value: Int) {
        if (this.usedSize >= 0) {
            var target = -1

            // 查找目标所在位置
            for (i in 0 until this.usedSize) {
                if (this.data[i] == value) {
                    target = i
                    break
                }
            }

            // 找到了
            if (target >= 0) {
                val size = this.usedSize - 1

                // 把后续元素往前搬
                for (i in target until size) {
                    this.data[i] = this.data[i + 1]
                }

                // 最后一个元素位置置为空
                this.data[size] = 0

                // 更新已使用大小
                this.usedSize = size
            }
        }
    }

    /**
     * 通过索引设置元素的值
     */
    fun set(index: Int, value: Int) {
        if (this.checkIndex(index)) {
            this.data[index] = value
            return
        }

        throw IllegalArgumentException("index must be in rang of 0..${this.usedSize}")
    }

    /**
     * 获取元素
     */
    fun get(index: Int): Int? {
        if (this.checkIndex(index)) {
            return this.data[index]
        }

        throw IllegalArgumentException("index must be in rang of 0..${this.usedSize}")
    }

    /**
     * 获取当前数组的大小
     */
    fun getSize(): Int = this.usedSize

    private fun checkIndex(index: Int): Boolean {
        return index >= 0 && index < this.usedSize
    }

    /**
     * 按原容量的两倍进行扩容
     */
    private fun doubleCapacity() {
        if (this.capacity < MAX_CAPACITY) {
            this.capacity = Math.min(this.capacity * 2, MAX_CAPACITY)
            val newArray = Array(this.capacity) { 0 }

            for (i in 0 until this.usedSize) {
                newArray[i] = this.data[i]
            }

            this.data = newArray
        }
    }
}