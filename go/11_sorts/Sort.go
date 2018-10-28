package _1_sorts

/*
冒泡排序、插入排序、选择排序
 */

//冒泡排序，a是数组，n表示数组大小
func BubbleSort(a []int, n int) {
	if n <= 1 {
		return
	}
	for i := 0; i < n; i++ {
		// 提前退出标志
		flag := false
		for j := 0; j < n-i-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				//此次冒泡有数据交换
				flag = true
			}
		}
		// 如果没有交换数据，提前退出
		if !flag {
			break
		}
	}
}

// 插入排序，a表示数组，n表示数组大小
func InsertionSort(a []int, n int) {
	if n <= 1 {
		return
	}
	for i := 1; i < n; i++ {
		value := a[i]
		j := i - 1
		//查找要插入的位置并移动数据
		for ; j >= 0; j-- {
			if a[j] > value {
				a[j+1] = a[j]
			} else {
				break
			}
		}
		a[j+1] = value
	}
}

// 选择排序，a表示数组，n表示数组大小
func SelectionSort(a []int, n int) {
	if n <= 1 {
		return
	}
	for i := 0; i < n; i++ {
		// 查找最小值
		minIndex := i
		for j := i + 1; j < n; j++ {
			if a[j] < a[minIndex] {
				minIndex = j
			}
		}
		// 交换
		a[i], a[minIndex] = a[minIndex],a[i]

	}
}
