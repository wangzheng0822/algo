"""
    KMP algorithm

    Author: Wenru Dong
"""

from typing import List

def kmp(s: int, pattern: int) -> int:
    m = len(pattern)
    partial_match_table = _get_partial_match_table(pattern)
    j = 0
    for i in range(len(s)):
        while j and s[i] != pattern[j]:
            j = partial_match_table[j - 1] + 1
        j += 1
        if j == m:
            return i - m + 1
    return -1


def _get_partial_match_table(pattern: int) -> List[int]:
    # Denote pi^k(i) as pi applied to i for k times,
    # i.e., pi^2(i) = pi(pi(i)).
    # Then we have the result:
    #    pi(i) = pi^k(i-1) + 1,
    # where k is the smallest integer such that
    # pattern[pi^k(i-1)+1] == pattern[i].
    
    m = len(pattern)
    pi = [0] * m
    pi[0] = k = -1  # We use k here to represent pi^k(i)
    for i in range(1, m):
        while k >= 0 and pattern[k + 1] != pattern[i]:
            k = pi[k]
        k += 1
        pi[i] = k
    return pi


if __name__ == "__main__":

    s = "abc abcdab abcdabcdabde"
    pattern = "bcdabd"
    print(kmp(s, pattern), s.find(pattern))