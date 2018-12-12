"""
    Boyer-Moore string-search algorithm.

    Author: Wenru Dong
"""

from typing import List, Tuple

SIZE = 256

def _generate_bad_character_table(pattern: str) -> List[int]:
    bc = [-1] * SIZE
    for i, char in enumerate(pattern):
        bc[ord(char)] = i
    return bc


def _generate_good_suffix_table(pattern: str) -> Tuple[List[bool], List[int]]:
    m = len(pattern)
    # prefix[k] records whether the last k-character suffix of pattern
    # can match with the first k-character prefix of pattern.
    # suffix[k] records the starting index of the last substring of
    # pattern that can match with the last k-character suffix of pattern.
    prefix, suffix = [False] * m, [-1] * m
    # For each substring patter[:i+1], we find the common suffix with
    # pattern, and the starting index of this common suffix.
    # This way we can re-write previous suffix[k] to record the index
    # as large as possible, hence the last substring.
    for i in range(m - 1):
        j = i  # starting index of the common suffix
        k = 0  # length of the common suffix
        while j >= 0 and pattern[j] == pattern[~k]:
            j -= 1
            k += 1
            suffix[k] = j + 1
        if j == -1: prefix[k] = True
    return (prefix, suffix)


def _move_by_good_suffix(bad_character_index: int, suffix: List[int], prefix: List[bool]) -> int:
    k = len(suffix) - 1 - bad_character_index
    if suffix[k] != -1: return bad_character_index - suffix[k] + 1
    # Test from k - 1
    for r, can_match_prefix in enumerate(reversed(prefix[:k]), bad_character_index + 2): 
        if can_match_prefix: return r
    return len(suffix)


def bm(s: str, pattern: str) -> int:
    bc = _generate_bad_character_table(pattern)
    prefix, suffix = _generate_good_suffix_table(pattern)
    n, m = len(s), len(pattern)
    i = 0
    while i <= n - m:
        j = m - 1  # bad character index in pattern
        while j >= 0: 
            if s[i + j] != pattern[j]: break
            j -= 1
        if j < 0: return i
        
        x = j - bc[ord(s[i + j])]
        y = 0
        if j < m - 1:
            y = _move_by_good_suffix(j, suffix, prefix)
        i += max(x, y)
    return -1


if __name__ == "__main__":

    s = "Here is a simple example"
    pattern = "example"
    print(bm(s, pattern))

    s = "abcdcccdc"
    pattern = "cccd"
    print(s.find(pattern) == bm(s, pattern))