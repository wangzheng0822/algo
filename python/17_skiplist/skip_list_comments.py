import random


class SkipListNode(object):
    def __init__(self, val, high=1):
        # 节点存储的值
        self.data = val
        # 节点对应索引层的深度
        self.deeps = [None] * high


class SkipList(object):
    """
        An implementation of skip list.
        The list stores positive integers without duplicates.
        跳表的一种实现方法。
        跳表中储存的是正整数，并且储存的是不重复的。
        Author: Ben
    """

    def __init__(self):
        # 索引层的最大深度
        self.__MAX_LEVEL = 16
        # 跳表的高度
        self._high = 1
        # 每一索引层的首节点, 默认值为None
        self._head = SkipListNode(None, self.__MAX_LEVEL)

    def find(self, val):
        cur = self._head
        # 从索引的顶层, 逐层定位要查找的值
        # 索引层上下是对应的, 下层的起点是上一个索引层中小于插入值的最大值对应的节点
        for i in range(self._high - 1, -1, -1):
            # 同一索引层内, 查找小于插入值的最大值对应的节点
            while cur.deeps[i] and cur.deeps[i].data < val:
                cur = cur.deeps[i]

        if cur.deeps[0] and cur.deeps[0].data == val:
            return cur.deeps[0]
        return None

    def insert(self, val):
        '''
        新增时, 通过随机函数获取要更新的索引层数,
        要对低于给定高度的索引层添加新结点的指针
        '''
        high = self.randomLevel()
        if self._high < high:
            self._high = high
        # 申请新结点
        newNode = SkipListNode(val, high)
        # cache用来缓存对应索引层中小于插入值的最大节点
        cache = [self._head] * high
        cur = self._head

        # 在低于随机高度的每一个索引层寻找小于插入值的节点
        for i in range(high - 1, -1, -1):
            # 每个索引层内寻找小于带插入值的节点
            # ! 索引层上下是对应的, 下层的起点是上一个索引层中小于插入值的最大值对应的节点
            while cur.deeps[i] and cur.deeps[i].data < val:
                cur = cur.deeps[i]
            cache[i] = cur

        # 在小于高度的每个索引层中插入新结点
        for i in range(high):
            # new.next = prev.next \ prev.next = new.next
            newNode.deeps[i] = cache[i].deeps[i]
            cache[i].deeps[i] = newNode

    def delete(self, val):
        '''
        删除时, 要将每个索引层中对应的节点都删掉
        '''
        # cache用来缓存对应索引层中小于插入值的最大节点
        cache = [None] * self._high
        cur = self._head
        # 缓存每一个索引层定位小于插入值的节点
        for i in range(self._high - 1, -1, -1):
            while cur.deeps[i] and cur.deeps[i].data < val:
                cur = cur.deeps[i]
            cache[i] = cur
        # 如果给定的值存在, 更新索引层中对应的节点
        if cur.deeps[0] and cur.deeps[0].data == val:
            for i in range(self._high):
                if cache[i].deeps[i] and cache[i].deeps[i].data == val:
                    cache[i].deeps[i] = cache[i].deeps[i].deeps[i]

    def randomLevel(self, p=0.25):
        '''
        #define ZSKIPLIST_P 0.25      /* Skiplist P = 1/4 */
        https://github.com/antirez/redis/blob/unstable/src/t_zset.c
        '''
        high = 1
        for _ in range(self.__MAX_LEVEL - 1):
            if random.random() < p:
                high += 1
        return high

    def __repr__(self):
        vals = []
        p = self._head
        while p.deeps[0]:
            vals.append(str(p.deeps[0].data))
            p = p.deeps[0]
        return '->'.join(vals)


if __name__ == '__main__':
    sl = SkipList()
    for i in range(100):
        sl.insert(i)
    print(sl)
    p = sl.find(7)
    print(p.data)
    sl.delete(37)
    print(sl)
    sl.delete(37.5)
    print(sl)
