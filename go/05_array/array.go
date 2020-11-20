package _5_array

import (
    "errors"
    "fmt"
)

/**
 * 1) 数组的插入、删除、按照下标随机访问操作；
 * 2）数组中的数据是int类型的；
 *
 */


type Array struct {
    data []int
}

func NewArray(capacity uint) *Array{
    if capacity == 0 {
        return nil
    }
    return &Array{
        data:make([]int, 0, capacity),
    }
}

// 判断下标是否越界
func (a *Array)IsIndexOutOfRange(index uint) bool {
    return index >= uint(cap(a.data))
}

// 通过下标查找值，索引范围[0, n-1]
func (a *Array)Find(index uint)(int, error) {
    if a.IsIndexOutOfRange(index) {
        return 0, errors.New("out of index range")
    }
    return a.data[index], nil
}

// 插入数据到索引index上
func (a *Array)Insert(index uint, val int) error {
    if len(a.data) == cap(a.data) {
        return errors.New("array is full")
    }

    if a.IsIndexOutOfRange(index) {
        return errors.New("out of index range")
    }

    if index == uint(len(a.data)) {
        a.data = append(a.data, val)
        return nil
    }

    copy(a.data[index+1:], a.data[index:])
    a.data[index] = val
    return nil
}

// 插入数据到数组尾部
func (a *Array)InsertToTail(val int) error {
    return a.Insert(uint(len(a.data)), val)
}

func (a *Array)Delete(index uint)(int, error)  {
    if a.IsIndexOutOfRange(index) {
        return 0, errors.New("out of index range")
    }
    val := a.data[index]
    a.data = append(a.data[:index], a.data[index+1:]...)
    return val, nil
}

func (a *Array)Print()  {
    var format string
    for _, num := range a.data {
        format += fmt.Sprintf("|%+v", num)
    }
    fmt.Println(format)
}