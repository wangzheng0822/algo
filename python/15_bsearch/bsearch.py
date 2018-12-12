"""
    Author: Wenru
"""

from typing import List

def bsearch(nums: List[int], target: int) -> int:
    """Binary search of a target in a sorted array
    without duplicates. If such a target does not exist,
    return -1, othewise, return its index.
    """
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1
