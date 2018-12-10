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
        while j >= 0 and s[i] != pattern[j]:
            j = partial_match_table[j]
        j += 1
        if j == m:
            return i - m + 1
    return -1


def _get_partial_match_table(pattern: int) -> List[int]:
    # Denote πᵏ(i) as π applied to i for k times,
    # i.e., π²(i) = π(π(i)).
    # Then we have the result:
    #    π(i) = πᵏ(i-1) + 1,
    # where k is the smallest integer such that
    # pattern[πᵏ(i-1)+1] == pattern[i].

    # The value of π means the maximum length
    # of proper prefix/suffix.
    # The index of π means the length of the prefix
    # considered for pattern.
    # For example, π[2] means we are considering the first 2 characters
    # of the pattern.
    # If π[2] == 1, it means for the prefix of the pattern, P[0]P[1],
    # it has a maximum length proper prefix of 1, which is also the
    # suffix of P[0]P[1].
    # We also add a π[0] == -1 for easier handling of boundary
    # condition.
    
    m = len(pattern)
    π = [0] * (m + 1)
    π[0] = k = -1  # We use k here to represent πᵏ(i)
    for i in range(1, m + 1):
        while k >= 0 and pattern[k] != pattern[i - 1]:
            k = π[k]
        k += 1
        π[i] = k
    return π


if __name__ == "__main__":

    s = "abc abcdab abcdabcdabde"
    pattern = "bcdabd"
    print(kmp(s, pattern), s.find(pattern))

    s = "hello"
    pattern = "ll"
    print(kmp(s, pattern), s.find(pattern))