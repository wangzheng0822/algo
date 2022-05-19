"""
    Author: Wenru
    Fix: nzjia
"""

from typing import List


def bsearch_left(nums: List[int], target: int) -> int:
    """Binary search of the index of the first element
    equal to a given target in the ascending sorted array.
    If not found, return -1.
    """
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    if low < len(nums) and nums[low] == target:
        return low
    else:
        return -1


def bsearch_right(nums: List[int], target: int) -> int:
    """Binary search of the index of the last element
    equal to a given target in the ascending sorted array.
    If not found, return -1.
    """
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] <= target:
            low = mid + 1
        else:
            high = mid - 1
    if high >= 0 and nums[high] == target:
        return high
    else:
        return -1


def bsearch_left_not_less(nums: List[int], target: int) -> int:
    """Binary search of the index of the first element
    not less than a given target in the ascending sorted array.
    If not found, return -1.
    """
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    if low < len(nums) and nums[low] >= target:
        return low
    else:
        return -1


def bsearch_right_not_greater(nums: List[int], target: int) -> int:
    """Binary search of the index of the last element
    not greater than a given target in the ascending sorted array.
    If not found, return -1.
    """
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] <= target:
            low = mid + 1
        else:
            high = mid - 1
    if high >= 0 and nums[high] <= target:
        return high
    else:
        return -1


def test_bsearch_left_not_less():
    a = bsearch_left_not_less([1, 2, 5], 1)
    assert a == 0
    a = bsearch_left_not_less([1, 2, 5], 5)
    assert a == 2
    a = bsearch_left_not_less([1, 2, 5], 2)
    assert a == 1
    a = bsearch_left_not_less([1, 2, 3, 3, 5], 2)
    assert a == 1
    a = bsearch_left_not_less([1, 2, 3, 3, 5], 6)
    assert a == -1
    a = bsearch_left_not_less([], 1)
    assert a == -1
    a = bsearch_left_not_less([1], 1)
    assert a == 0


if __name__ == "__main__":
    a = [1, 1, 2, 3, 4, 6, 7, 7, 7, 7, 10, 22]

    print(bsearch_left(a, 0) == -1)
    print(bsearch_left(a, 7) == 6)
    print(bsearch_left(a, 30) == -1)

    print(bsearch_right(a, 0) == -1)
    print(bsearch_right(a, 7) == 9)
    print(bsearch_right(a, 30) == -1)

    test_bsearch_left_not_less()

    print(bsearch_right_not_greater(a, 0) == -1)
    print(bsearch_right_not_greater(a, 6) == 5)
    print(bsearch_right_not_greater(a, 30) == 11)
