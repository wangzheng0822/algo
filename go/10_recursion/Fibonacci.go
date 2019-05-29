package Recursion

import "fmt"

// 递归实现斐波那契数列
type Fibs struct {
	val map[int]int  // 使用字典存储结果
}

func NewFibs(n int) *Fibs  {
	return &Fibs{
		make(map[int]int, n),
	}
}

func (fib *Fibs)Fibonacci(n int) int {
	if fib.val[n] != 0{
		return fib.val[n]
	}
	if n <= 1 {
		fib.val[1] = 1
		return 1
	}else if n ==2{
		fib.val[2] = 1
		return 1
	} else {
		res := fib.Fibonacci(n-1) + fib.Fibonacci(n-2)
		fib.val[n] = res
		return res
	}
}

func (fib *Fibs)Print(n int) {
	fmt.Println(fib.val[n])
}
