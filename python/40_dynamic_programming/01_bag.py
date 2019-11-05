#!/usr/bin/python
# -*- coding: UTF-8 -*-

from typing import List, Tuple


def bag(items_info: List[int], capacity: int) -> int:
    """
    固定容量的背包，计算能装进背包的物品组合的最大重量

    :param items_info: 每个物品的重量
    :param capacity: 背包容量
    :return: 最大装载重量
    """
    n = len(items_info)
    memo = [[-1]*(capacity+1) for i in range(n)]
    memo[0][0] = 1
    if items_info[0] <= capacity:
        memo[0][items_info[0]] = 1

    for i in range(1, n):
        for cur_weight in range(capacity+1):
            if memo[i-1][cur_weight] != -1:
                memo[i][cur_weight] = memo[i-1][cur_weight]   # 不选
                if cur_weight + items_info[i] <= capacity:    # 选
                    memo[i][cur_weight + items_info[i]] = 1

    for w in range(capacity, -1, -1):
        if memo[-1][w] != -1:
            return w


def bag_with_max_value(items_info: List[Tuple[int, int]], capacity: int) -> int:
    """
    固定容量的背包，计算能装进背包的物品组合的最大价值

    :param items_info: 物品的重量和价值
    :param capacity: 背包容量
    :return: 最大装载价值
    """
    n = len(items_info)
    memo = [[-1]*(capacity+1) for i in range(n)]
    memo[0][0] = 0
    if items_info[0][0] <= capacity:
        memo[0][items_info[0][0]] = items_info[0][1]

    for i in range(1, n):
        for cur_weight in range(capacity+1):
            if memo[i-1][cur_weight] != -1:
                memo[i][cur_weight] = memo[i-1][cur_weight]
                if cur_weight + items_info[i][0] <= capacity:
                    memo[i][cur_weight + items_info[i][0]] = max(memo[i][cur_weight + items_info[i][0]],
                                                                 memo[i-1][cur_weight] + items_info[i][1])
    return max(memo[-1])


if __name__ == '__main__':
    # [weight, ...]
    items_info = [2, 2, 4, 6, 3]
    capacity = 9
    print(bag(items_info, capacity))

    # [(weight, value), ...]
    items_info = [(3, 5), (2, 2), (1, 4), (1, 2), (4, 10)]
    capacity = 8
    print(bag_with_max_value(items_info, capacity))
