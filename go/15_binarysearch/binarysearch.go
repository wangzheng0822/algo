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
