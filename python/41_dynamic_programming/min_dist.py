"""
    Author: Wenru Dong
"""

from typing import List
from itertools import accumulate

def min_dist(weights: List[List[int]]) -> int:
    """Find the minimum weight path from the weights matrix."""
    m, n = len(weights), len(weights[0])
    table = [[0] * n for _ in range(m)]
    # table[i][j] is the minimum distance (weight) when
    # there are i vertical moves and j horizontal moves
    # left.
    table[0] = list(accumulate(reversed(weights[-1])))
    for i, v in enumerate(accumulate(row[-1] for row in reversed(weights))):
        table[i][0] = v
    for i in range(1, m):
        for j in range(1, n):
            table[i][j] = weights[~i][~j] + min(table[i - 1][j], table[i][j - 1])
    return table[-1][-1]


def min_dist_recur(weights: List[List[int]]) -> int:
    m, n = len(weights), len(weights[0])
    table = [[0] * n for _ in range(m)]
    def min_dist_to(i: int, j: int) -> int:
        if i == j == 0: return weights[0][0]
        if table[i][j]: return table[i][j]
        min_left = float("inf") if j - 1 < 0 else min_dist_to(i, j - 1)
        min_up = float("inf") if i - 1 < 0 else min_dist_to(i - 1, j)
        return weights[i][j] + min(min_left, min_up)
    return min_dist_to(m - 1, n - 1)


if __name__ == "__main__":
    weights = [[1, 3, 5, 9], [2, 1, 3, 4], [5, 2, 6, 7], [6, 8, 4, 3]]
    print(min_dist(weights))
    print(min_dist_recur(weights))
