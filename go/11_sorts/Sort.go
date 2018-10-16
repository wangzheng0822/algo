package _1_sorts

func BubbleSort(a []int) {
	arrLen := len(a)
	if arrLen <= 1 {
		return
	}
	for i := arrLen - 1; i > 0; i-- {
		for j := 0; j < i; j++ {
			if a[j] > a[j+1] {
				tmp := a[j+1]
				a[j+1] = a[j]
				a[j] = tmp
			}
		}
	}
}

func InsertSort(a []int) {
	arrLen := len(a)
	if arrLen <= 1 {
		return
	}
	for i := 1; i < arrLen; i++ {
		v := a[i]
		j := i - 1
		for ; j >= 0; j-- {
			if a[j] > v {
				a[j+1] = a[j]
			} else {
				break
			}
		}
		a[j+1] = v
	}
}

func SelectionSort(a []int) {
	arrLen := len(a)
	if arrLen <= 1 {
		return
	}
	for i := 0; i < arrLen; i++ {
		minIndex := i
		for j := i + 1; j < arrLen; j++ {
			if a[j] < a[minIndex] {
				minIndex = j
			}
		}
		if minIndex != i {
			tmp := a[minIndex]
			a[minIndex] = a[i]
			a[i] = tmp
		}
	}
}
