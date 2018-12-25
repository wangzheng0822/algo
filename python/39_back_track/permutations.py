#!/usr/bin/python
# -*- coding: UTF-8 -*-

from typing import List

permutations_list = []  # 全局变量，用于记录每个输出


def permutations(nums: List, n: int, pick_count: int):
    """
    从nums选取n个数的全排列

    回溯法，用一个栈记录当前路径信息
    当满足n==0时，说明栈中的数已足够，输出并终止遍历
    :param nums:
    :param n:
    :param pick_count:
    :return:
    """
    if n == 0:
        print(permutations_list)
    else:
        for i in range(len(nums) - pick_count):
            permutations_list[pick_count] = nums[i]
            nums[i], nums[len(nums) - pick_count - 1] = nums[len(nums) - pick_count - 1], nums[i]
            permutations(nums, n-1, pick_count+1)
            nums[i], nums[len(nums) - pick_count - 1] = nums[len(nums) - pick_count - 1], nums[i]


if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    n = 3
    print('--- list ---')
    print(nums)

    print('\n--- pick num ---')
    print(n)

    print('\n--- permutation list ---')
    permutations_list = [0] * n
    permutations(nums, n, 0)

