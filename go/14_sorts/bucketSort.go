package _14_sorts

import "math"

func bucketSort(arr []int)  {
	minNum,maxNum,n:=math.MaxInt32,math.MinInt32,len(arr)
	for i := 0; i <n ; i++ {
		maxNum=max(maxNum,arr[i])
		minNum=min(minNum,arr[i])
	}

	//桶数
	bucketNum:=(maxNum-minNum)/n+1
	bucketArr:=make([][]int,bucketNum)
	for i := 0; i <bucketNum ; i++ {
		bucketArr[i]=[]int{}
	}

	//将每个元素放入桶
	for i := 0; i < n; i++ {
		num := (arr[i] - minNum) / n
		bucketArr[num] = append(bucketArr[num], arr[i])
	}

	k:=0
	//对每个桶进行排序
	for i := 0; i <bucketNum ; i++ {
		//归并
		mergeSort(bucketArr[i],0,len(bucketArr[i])-1)
		for j := 0; j <len(bucketArr[i]) ; j++ {
			arr[k]=bucketArr[i][j]
			k++
		}
	}
}
func max (x,y int)int{
	if x>y {
		return x
	}
	return y
}
func min (x,y int)int{
	if x>y {
		return y
	}
	return x
}