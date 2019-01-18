#!/usr/bin/python
# -*- coding: UTF-8 -*-

from typing import List


def longest_increasing_subsequence(nums: List[int]) -> int:
    """
    最长子上升序列的一种DP解法，从回溯解法转化，思路类似于有限物品的背包问题
    每一次决策都算出当前可能的lis的长度，重复子问题合并，合并策略是lis的末尾元素最小
    时间复杂度：O(n^2)
    空间复杂度：O(n^2)，可优化至O(n)

    没leetcode上的参考答案高效，提供另一种思路作为参考
    https://leetcode.com/problems/longest-increasing-subsequence/solution/
    :param nums:
    :return:
    """
    if not nums:
        return 0

    n = len(nums)
    # memo[i][j] 表示第i次决策，长度为j的lis的 最小的 末尾元素数值
    # 每次决策都根据上次决策的所有可能转化，空间上可以类似背包优化为O(n)
    memo = [[-1] * (n+1) for _ in range(n)]

    # 第一列全赋值为0，表示每次决策都不选任何数
    for i in range(n):
        memo[i][0] = 0
    # 第一次决策选数组中的第一个数
    memo[0][1] = nums[0]

    for i in range(1, n):
        for j in range(1, n+1):
            # case 1: 长度为j的lis在上次决策后存在，nums[i]比长度为j-1的lis末尾元素大
            if memo[i-1][j] != -1 and nums[i] > memo[i-1][j-1]:
                memo[i][j] = min(nums[i], memo[i-1][j])

            # case 2: 长度为j的lis在上次决策后存在，nums[i]比长度为j-1的lis末尾元素小/等
            if memo[i-1][j] != -1 and nums[i] <= memo[i-1][j-1]:
                memo[i][j] = memo[i-1][j]

            if memo[i-1][j] == -1:
                # case 3: 长度为j的lis不存在，nums[i]比长度为j-1的lis末尾元素大
                if nums[i] > memo[i-1][j-1]:
                    memo[i][j] = nums[i]
                # case 4: 长度为j的lis不存在，nums[i]比长度为j-1的lis末尾元素小/等
                break

    for i in range(n, -1, -1):
        if memo[-1][i] != -1:
            return i


if __name__ == '__main__':
    # 要求输入的都是大于0的正整数(可优化至支持任意整数)
    nums = [2, 9, 3, 6, 5, 1, 7]
    print(longest_increasing_subsequence(nums))
