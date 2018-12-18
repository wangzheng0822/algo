#!/usr/bin/python
# -*- coding: UTF-8 -*-

from time import time


def bf(main, pattern):
    """
    字符串匹配，bf暴搜
    :param main: 主串
    :param pattern: 模式串
    :return:
    """
    n = len(main)
    m = len(pattern)

    if n <= m:
        return 0 if pattern == main else -1

    for i in range(n-m+1):
        for j in range(m):
            if main[i+j] == pattern[j]:
                if j == m-1:
                    return i
                else:
                    continue
            else:
                break
    return -1


def simple_hash(s, start, end):
    """
    计算子串的哈希值
    每个字符取acs-ii码后求和
    :param s:
    :param start:
    :param end:
    :return:
    """
    assert start <= end

    ret = 0
    for c in s[start: end+1]:
        ret += ord(c)
    return ret


def rk(main, pattern):
    n = len(main)
    m = len(pattern)

    if n <= m:
        return 0 if pattern == main else -1

    # 子串哈希值表
    hash_memo = [None] * (n-m+1)
    hash_memo[0] = simple_hash(main, 0, m-1)
    for i in range(1, n-m+1):
        hash_memo[i] = hash_memo[i-1] - simple_hash(main, i-1, i-1) + simple_hash(main, i+m-1, i+m-1)

    # 模式串哈希值
    hash_p = simple_hash(pattern, 0, m-1)

    for i, h in enumerate(hash_memo):
        # 可能存在哈希冲突
        if h == hash_p:
            if pattern == main[i:i+m]:
                return i
            else:
                continue
    return -1


if __name__ == '__main__':
    m_str = 'a'*10000
    p_str = 'a'*200+'b'

    print('--- time consume ---')
    t = time()
    print('[bf] result:', bf(m_str, p_str))
    print('[bf] time cost: {0:.5}s'.format(time()-t))

    t = time()
    print('[rk] result:', rk(m_str, p_str))
    print('[rk] time cost: {0:.5}s'.format(time()-t))

    print('')
    print('--- search ---')
    m_str = 'thequickbrownfoxjumpsoverthelazydog'
    p_str = 'jump'
    print('[bf] result:', bf(m_str, p_str))
    print('[rk] result:', rk(m_str, p_str))
