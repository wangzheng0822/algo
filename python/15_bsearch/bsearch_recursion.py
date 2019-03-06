"""
    Author: dreamkong
"""

from typing import List


def bsearch(nums: List[int], target: int) -> int:
    return bsearch_internally(nums, 0, len(nums)-1, target)


def bsearch_internally(nums: List[int], low: int, high: int, target: int) -> int:
    if low > high:
        return -1

    mid = low+int((high-low) >> 2)
    if nums[mid] == target:
        return mid
    elif nums[mid] < target:
        return bsearch_internally(nums, mid+1, high, target)
    else:
        return bsearch_internally(nums, low, mid-1, target)
