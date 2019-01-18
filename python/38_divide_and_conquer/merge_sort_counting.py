#!/usr/bin/python
# -*- coding: UTF-8 -*-

inversion_num = 0


def merge_sort_counting(nums, start, end):
    if start >= end:
        return

    mid = (start + end)//2
    merge_sort_counting(nums, start, mid)
    merge_sort_counting(nums, mid+1, end)
    merge(nums, start, mid, end)


def merge(nums, start, mid, end):
    global inversion_num
    i = start
    j = mid+1
    tmp = []
    while i <= mid and j <= end:
        if nums[i] <= nums[j]:
            inversion_num += j - mid - 1
            tmp.append(nums[i])
            i += 1
        else:
            tmp.append(nums[j])
            j += 1

    while i <= mid:
        # 这时nums[i]的逆序数是整个nums[mid+1: end+1]的长度
        inversion_num += end - mid
        tmp.append(nums[i])
        i += 1

    while j <= end:
        tmp.append(nums[j])
        j += 1

    nums[start: end+1] = tmp


if __name__ == '__main__':
    print('--- count inversion number using merge sort ---')
    # nums = [5, 0, 4, 2, 3, 1, 6, 8, 7]
    nums = [5, 0, 4, 2, 3, 1, 3, 3, 3, 6, 8, 7]
    print('nums  : {}'.format(nums))
    merge_sort_counting(nums, 0, len(nums)-1)
    print('sorted: {}'.format(nums))
    print('inversion number: {}'.format(inversion_num))
