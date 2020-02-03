""" 查找数组中第k大的数 快速排序算法实现 """


def findKth(s, k):
    return findKth_c(s, 0, len(s) - 1, k)


def findKth_c(s, low, high, k):
    m = partition(s, low, high)
    if m == len(s) - k:
        return s[m]
    elif m < len(s) - k:
        return findKth_c(s, m+1, high, k)
    else:
        return findKth_c(s, low, m-1, k)


def partition(s, low, high):
    pivot, j = s[low], low
    for i in range(low + 1, high + 1):
        if s[i] <= pivot:
            j += 1
            s[i], s[j] = s[j], s[i]
    s[j], s[low] = s[low], s[j]
    return j


for _ in range(int(input())):
    s = list(map(int, input().split()))
    k = int(input())
    print(findKth(s, k))
