#!/usr/bin/python
# -*- coding: UTF-8 -*-

import math


class QueueNode:
    def __init__(self, priority, data=None):
        assert type(priority) is int and priority >= 0
        self.priority = priority
        self.data = data

    def __repr__(self):
        return str((self.priority, self.data))


class PriorityQueue:
    def __init__(self, capacity=100):
        self._capacity = capacity
        self._q = []
        self._length = 0

    def enqueue(self, priority, data=None):
        if self._length >= self._capacity:
            return False

        new_node = QueueNode(priority, data)
        self._q.append(new_node)
        self._length += 1

        # update queue
        nn = self._length - 1
        while nn > 0:
            p = (nn - 1) // 2
            if self._q[nn].priority < self._q[p].priority:
                self._q[nn], self._q[p] = self._q[p], self._q[nn]
                nn = p
            else:
                break

        return True

    def dequeue(self):
        if self._length <= 0:
            raise Exception('the queue is empty....')

        self._q[0], self._q[-1] = self._q[-1], self._q[0]
        ret = self._q.pop()
        self._length -= 1

        if self._length > 1:
            # update queue
            lp = (self._length - 2) // 2
            idx = 0

            while idx <= lp:
                lc = 2 * idx + 1
                rc = lc + 1

                if rc <= self._length - 1:
                    tmp = lc if self._q[lc].priority < self._q[rc].priority else rc
                else:
                    tmp = lc

                if self._q[tmp].priority < self._q[idx].priority:
                    self._q[tmp], self._q[idx] = self._q[idx], self._q[tmp]
                    idx = tmp
                else:
                    break
        return ret

    def get_length(self):
        return self._length

    @staticmethod
    def _draw_heap(data):
        """
        格式化打印
        :param data:
        :return:
        """
        length = len(data)

        if length == 0:
            return 'empty'

        ret = ''
        for i, n in enumerate(data):
            ret += str(n)
            # 每行最后一个换行
            if i == 2 ** int(math.log(i + 1, 2) + 1) - 2 or i == len(data) - 1:
                ret += '\n'
            else:
                ret += ', '

        return ret

    def __repr__(self):
        def formater(node):
            assert type(node) is QueueNode
            return node.priority, node.data

        data = list(map(formater, self._q))
        return self._draw_heap(data)


if __name__ == '__main__':
    pq = PriorityQueue()
    pq.enqueue(5, 'Watch TV')
    pq.enqueue(2, 'Learning')
    pq.enqueue(10, 'Go Sleep')
    pq.enqueue(0, 'Go Home')
    pq.enqueue(7, 'Mobile Games')
    print(pq)

    while pq.get_length() > 0:
        print(pq.dequeue())
