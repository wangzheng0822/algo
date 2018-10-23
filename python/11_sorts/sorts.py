"""
    Bubble sort, insertion sort and selection sort
    冒泡排序、插入排序、选择排序

    Author: Wenru
"""

from typing import List

# 冒泡排序
def bubble_sort(a: List[int]):
    if len(a) <= 1: return
    
<<<<<<< HEAD
    made_swap = False
    for i in range(len(a)):
=======
    for i in range(len(a)):
        made_swap = False
>>>>>>> upstream/master
        for j in range(len(a) - i - 1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
                made_swap = True
        if not made_swap: break

# 插入排序
def insertion_sort(a: List[int]):
    if len(a) <= 1: return
    
    for i in range(1, len(a)):
        value = a[i]
        j = i - 1
        while j >= 0 and a[j] > value:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = value

# 选择排序
def selection_sort(a: List[int]):
    if len(a) <= 1: return
    
    for i in range(len(a)):
        min_index = i
        min_val = a[i]
        for j in range(i, len(a)):
            if a[j] < min_val:
                min_val = a[j]
                min_index = j
        a[i], a[min_index] = a[min_index], a[i]


if __name__ == "__main__":
    array = [1, 1, 1, 1]
    bubble_sort(array)
    print(array)

    array = [1, 2, 3, 4]
    bubble_sort(array)
    print(array)

    array = [4, 3, 2, 1]
    bubble_sort(array)
    print(array)

    array = [5, 6, -1, 4, 2, 8, 10, 7, 6]
    bubble_sort(array)
    print(array)

    array = [1, 1, 1, 1]
    insertion_sort(array)
    print(array)

    array = [1, 2, 3, 4]
    insertion_sort(array)
    print(array)

    array = [4, 3, 2, 1]
    insertion_sort(array)
    print(array)

    array = [5, 6, -1, 4, 2, 8, 10, 7, 6]
    insertion_sort(array)
    print(array)

    array = [1, 1, 1, 1]
    selection_sort(array)
    print(array)

    array = [1, 2, 3, 4]
    selection_sort(array)
    print(array)

    array = [4, 3, 2, 1]
    selection_sort(array)
    print(array)

    array = [5, 6, -1, 4, 2, 8, 10, 7, 6]
    selection_sort(array)
    print(array)