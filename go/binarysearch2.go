package binarySearch

//查找第一个值等于给定值得元素
func BinarySearch2(nums []int, value int) int {
	length := len(nums)
	start := 0
	end := length - 1
	for start <= end {
		mid := start + ((end - start) >> 1)
		if nums[mid] > value {
			end = mid - 1
		} else if nums[mid] < value {
			start = mid + 1
		} else {
			for mid >= 0 {
				if nums[mid-1] == value {
					mid--
				} else {
					return mid
				}
			}
		}
	}
	return -1
}

// 查找最后一个值等于给定值的元素
func BinarySearch3(nums []int, value int) int {
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := start + ((end - start) >> 1)
		if nums[mid] > value {
			end = mid - 1
		} else if nums[mid] < value {
			start = mid + 1
		} else {
			for mid < len(nums) {
				if nums[mid+1] == value {
					mid++
				} else {
					return mid
				}
			}
		}
	}
	return -1
}

// 查找第一个大于等于给定值的元素
func BinarySearch4(nums []int, value int) int {
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := (start + end) >> 1
		if nums[mid] < value {
			start = mid + 1
		} else {
			for mid >= 0 {
				if nums[mid-1] >= value {
					mid--
				} else {
					return mid
				}
			}
		}
	}
	return -1
}

// 查找最后一个小于等于给定值的元素
func BinarySearch5(nums []int, value int) int {
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := (start + end) >> 1
		if nums[mid] > value {
			end = mid - 1
		} else {
			for mid < len(nums) {
				if nums[mid+1] <= value {
					mid++
				} else {
					return mid
				}
			}
		}
	}
	return -1
}
