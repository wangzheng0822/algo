"""
    Author: Wenru Dong
"""

from typing import List

def knapsack01(weights: List[int], values: List[int], capacity: int) -> int:
    # Denote the state as (i, c), where i is the stage number,
    # and c is the capacity available. Denote f(i, c) to be the
    # maximum value when the capacity available is c, and Item 0
    # to Item i-1 are to be packed.
    # The goal is to find f(n-1, W), where W is the total capacity.
    # Then the DP functional equation is:
    #   f(i, c) = max(xᵢvᵢ + f(i-1, c-xᵢwᵢ)), xᵢ ∈ D, i ≥ 0,
    #   f(-1, c) = 0, 0 ≤ c ≤ W,
    # where
    #                  /  {0},    if wᵢ > c
    #   D = D(i, c) = 
    #                  \  {0, 1}, if wᵢ ≤ c

    prev = [0] * (capacity + 1)
    for w, v in zip(weights, values):
        prev = [c >= w and max(prev[c], prev[c-w] + v) for c in range(capacity + 1)]
    return prev[-1]


if __name__ == "__main__":
    # To find the maximum weight that can be packed,
    # set values equal to the weights
    print(knapsack01([2, 2, 4, 6, 3], [2, 2, 4, 6, 3], 9))
