#!/usr/bin/python
# -*- coding: UTF-8 -*-

from binary_heap import BinaryHeap


class BinaryHeapSort(BinaryHeap):
    def __init__(self):
        super(BinaryHeapSort, self).__init__()

    def sort(self, nums):
        """
        排序
        1. 堆化，大顶堆
        2. 排序，从后往前遍历，首尾元素互换，子数组堆化
        :param nums:
        :return:
        """
        assert type(nums) is list
        length = len(nums)

        if length <= 1:
            return

        self._type_assert(nums)

        # heapify
        self._heapify(nums, length-1)

        # sort
        for i in range(length-1, 0, -1):
            nums[0], nums[i] = nums[i], nums[0]
            self._heap_down(nums, 0, i-1)

        return


if __name__ == '__main__':
    bhs = BinaryHeapSort()
    nums = [3, 5, 2, 6, 1, 7, 6]

    print('--- before sort ---')
    print(nums)

    bhs.sort(nums)
    print('--- after sort ---')
    print(nums)
