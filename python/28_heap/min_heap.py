class Heap(object):
    '''
    索引从0开始的小顶堆
    参考: https://github.com/python/cpython/blob/master/Lib/heapq.py

    author: Ben
    '''

    def __init__(self, nums):
        self._heap = nums

    def _siftup(self, pos):
        '''
        从上向下的堆化
        将pos节点的子节点中的最值提升到pos位置
        '''
        start = pos
        startval = self._heap[pos]
        n = len(self._heap)
        # 完全二叉树特性
        child = pos * 2 + 1
        # 比较叶子节点
        while child < n:
            right = child + 1
            # 平衡二叉树的特性, 大的都在右边
            if right < n and not self._heap[right] > self._heap[child]:
                child = right
            self._heap[pos] = self._heap[child]
            pos = child
            child = pos * 2 + 1
        self._heap[pos] = startval

        # 此时只有pos是不确定的
        self._siftdown(start, pos)

    def _siftdown(self, start, pos):
        '''
        最小堆: 大于start的节点, 除pos外已经是最小堆
        以pos为叶子节点, start为根节点之间的元素进行排序. 将pos叶子节点交换到正确的排序位置
        操作: 从叶子节点开始, 当父节点的值大于子节点时, 父节点的值降低到子节点
        '''
        startval = self._heap[pos]
        while pos > start:
            parent = (pos - 1) >> 1
            parentval = self._heap[parent]
            if parentval > startval:
                self._heap[pos] = parentval
                pos = parent
                continue
            break
        self._heap[pos] = startval

    def heapify(self):
        '''
        堆化: 从后向前(从下向上)的方式堆化, _siftup中pos节点的子树已经是有序的,
        这样要排序的节点在慢慢减少
        1. 因为n/2+1到n的节点是叶子节点(完全二叉树的特性), 它们没有子节点,
        所以, 只需要堆化n/2到0的节点, 以对应的父节点为根节点, 将最值向上筛选,
        然后交换对应的根节点和查找到的最值
        2. 因为开始时待排序树的根节点还没有排序, 为了保证根节点的有序,
        需要将子树中根节点交换到正确顺序
        '''
        n = len(self._heap)
        for i in reversed(range(n // 2)):
            self._siftup(i)

    def heappop(self):
        '''
        弹出堆首的最值 O(logn)
        '''
        tail = self._heap.pop()
        # 为避免破环完全二叉树特性, 将堆尾元素填充到堆首
        # 此时, 只有堆首是未排序的, 只需要一次从上向下的堆化
        if self._heap:
            peak = self._heap[0]
            self._heap[0] = tail
            self._siftup(0)
            return peak
        return tail

    def heappush(self, val):
        '''
        添加元素到堆尾 O(logn)
        '''
        n = len(self._heap)
        self._heap.append(val)
        # 此时只有堆尾的节点是未排序的, 将添加的节点迭代到正确的位置
        self._siftdown(0, n)

    def __repr__(self):
        vals = [str(i) for i in self._heap]
        return '>'.join(vals)


if __name__ == '__main__':
    h = Heap([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11])
    h.heapify()
    print(h)
    print(h.heappop())
    print(h)
    h.heappush(3.5)
    print(h)
    h.heappush(0.1)
    print(h)
    h.heappush(0.5)
    print(h)
    print(h.heappop())
    print(h)
