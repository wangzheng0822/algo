#!/usr/bin/python
# -*- coding: UTF-8 -*-

SIZE = 256


def bm(main, pattern):
    """
    BM算法
    匹配规则：
    1. 坏字符规则
    2. 好字符规则
    :param main:
    :param pattern:
    :return:
    """
    assert type(main) is str and type(pattern) is str
    n, m = len(main), len(pattern)

    if n <= m:
        return 0 if main == pattern else -1

    # bc
    bc = [-1] * SIZE
    generate_bc(pattern, m, bc)

    # gs
    suffix = [-1] * m
    prefix = [False] * m
    generate_gs(pattern, m, suffix, prefix)

    i = 0
    while i < n-m+1:
        j = m - 1
        while j >= 0:
            if main[i+j] != pattern[j]:
                break
            else:
                j -= 1

        # pattern整个已被匹配，返回
        if j == -1:
            return i

        # 1. bc规则计算后移位数
        x = j - bc[ord(main[i+j])]

        # 2. gs规则计算后移位数
        y = 0
        if j != m - 1:    # 存在gs
            y = move_by_gs(j, m, suffix, prefix)

        i += max(x, y)

    return -1


def generate_bc(pattern, m, bc):
    """
    生成坏字符哈希表
    :param pattern:
    :param m:
    :param bc:
    :return:
    """
    for i in range(m):
        bc[ord(pattern[i])] = i


def generate_gs(pattern, m, suffix, prefix):
    """
    好后缀预处理
    :param pattern:
    :param m:
    :param suffix:
    :param prefix:
    :return:
    """
    for i in range(m-1):
        k = 0   # pattern[:i+1]和pattern的公共后缀长度
        for j in range(i, -1, -1):
            if pattern[j] == pattern[m-1-k]:
                k += 1
                suffix[k] = j
                if j == 0:
                    prefix[k] = True
            else:
                break


def move_by_gs(j, m, suffix, prefix):
    """
    通过好后缀计算移动值
    需要处理三种情况：
    1. 整个好后缀在pattern仍能找到
    2. 好后缀里存在 *后缀子串* 能和pattern的 *前缀* 匹配
    3. 其他
    :param j:
    :param m:
    :param suffix:
    :param prefix:
    :return:
    """
    k = m - 1 - j           # j指向从后往前的第一个坏字符，k是此次匹配的好后缀的长度

    if suffix[k] != -1:             # 1. 整个好后缀在pattern剩余字符中仍有出现
        return j - suffix[k] + 1
    else:
        for r in range(j+2, m):     # 2. 后缀子串从长到短搜索
            if prefix[m-r]:
                return r
        return m                    # 3. 其他情况


if __name__ == '__main__':
    print('--- search ---')
    m_str = 'dfasdeeeetewtweyyyhtruuueyytewtweyyhtrhrth'
    p_str = 'eyytewtweyy'
    print('[Built-in Functions] result:', m_str.find(p_str))
    print('[bm] result:', bm(m_str, p_str))
