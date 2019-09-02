package _5_binarysearch

func BinarySearch(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	low := 0
	high := n - 1
	for low <= high {
		mid := (low + high) / 2
		if a[mid] == v {
			return mid
		} else if a[mid] > v {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return -1
}

func BinarySearchRecursive(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	return bs(a, v, 0, n-1)
}

func bs(a []int, v int, low, high int) int {
	if low > high {
		return -1
	}

	mid := (low + high) / 2
	if a[mid] == v {
		return mid
	} else if a[mid] > v {
		return bs(a, v, low, mid-1)
	} else {
		return bs(a, v, mid+1, high)
	}
}

//查找第一个等于给定值的元素
func BinarySearchFirst(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	low := 0
	high := n - 1
	for low <= high {
		mid := (low + high) >> 1
		if a[mid] > v {
			high = mid - 1
		} else if a[mid] < v {
			low = mid + 1
		} else {
			if mid == 0 || a[mid-1] != v {
				return mid
			} else {
				high = mid - 1
			}
		}
	}

	return -1
}

//查找最后一个值等于给定值的元素
func BinarySearchLast(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	low := 0
	high := n - 1
	for low <= high {
		mid := (low + high) >> 1
		if a[mid] > v {
			high = mid - 1
		} else if a[mid] < v {
			low = mid + 1
		} else {
			if mid == n-1 || a[mid+1] != v {
				return mid
			} else {
				low = mid + 1
			}
		}
	}

	return -1
}

//查找第一个大于等于给定值的元素
func BinarySearchFirstGT(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	low := 0
	high := n - 1
	for low <= high {
		mid := (high + low) >> 1
		if a[mid] > v {
			high = mid - 1
		} else if a[mid] < v {
			low = mid + 1
		} else {
			if mid != n-1 && a[mid+1] > v {
				return mid + 1
			} else {
				low = mid + 1
			}
		}
	}

	return -1
}

//查找最后一个小于等于给定值的元素
func BinarySearchLastLT(a []int, v int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	low := 0
	high := n - 1
	for low <= high {
		mid := (low + high) >> 1
		if a[mid] > v {
			high = mid - 1
		} else if a[mid] < v {
			low = mid + 1
		} else {
			if mid == 0 || a[mid-1] < v {
				return mid - 1
			} else {
				high = mid - 1
			}
		}
	}

	return -1
}
