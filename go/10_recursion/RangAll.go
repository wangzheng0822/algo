package Recursion

import (
	"fmt"
)
// 实现一组数据集合的全排列
type RangeType struct {
	value []interface{}
}

func NewRangeArray(n int) *RangeType  {
	return &RangeType{
		make([]interface{},n),
	}
}

func (slice *RangeType)RangeALL( start int)  {
	len := len(slice.value)
	if start == len-1{
		// 如果已经是最后位置，直接将数组数据合并输出
		fmt.Println(slice.value)
	}

	for i:=start; i<len; i++{
		// i = start 时输出自己
		// 如果i和start的值相同就没有必要交换
		if i==start || slice.value[i] != slice.value[start]{
			//交换当前这个与后面的位置
			slice.value[i], slice.value[start] = slice.value[start], slice.value[i]
			//递归处理索引+1
			slice.RangeALL(start+1)
			//换回来，因为是递归，如果不换回来会影响后面的操作，并且出现重复
			slice.value[i], slice.value[start] = slice.value[start], slice.value[i]
		}
	}
}




