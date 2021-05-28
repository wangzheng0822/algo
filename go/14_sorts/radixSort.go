package _14_sorts

import "math"

func radixSort(arr []int) {
	n := len(arr)
	if n <= 1 {
		return
	}
	d := maxbit(arr)
	radix := 1
	var k int
	count, newArr := make([]int, 10), make([]int, n)
	for d >= 1 {
		for i := 0; i < 10; i++ {
			count[i] = 0
		}
		for i := 0; i < n; i++ {
			k = (arr[i] / radix) % 10
			count[k]++
		}
		for i := 1; i < 10; i++ {
			count[i] += count[i-1]
		}
		for i := n - 1; i >= 0; i-- {
			k = (arr[i] / radix) % 10
			newArr[count[k]-1] = arr[i]
			count[k]--
		}
		d--
		radix *= 10
		copy(arr, newArr)
	}

}
func maxbit(arr []int) int {
	maxNum := math.MinInt32
	for _, val := range arr {
		if val > maxNum {
			maxNum = val
		}
	}
	d := 1
	for maxNum >= 10 {
		d++
		maxNum /= 10
	}
	return d
}
