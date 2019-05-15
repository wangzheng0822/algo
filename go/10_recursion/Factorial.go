package Recursion

// 迭代实现阶乘
type Fac struct {
	val map[int]int
}

func  NewFactorial(n int) *Fac {
	return &Fac{
		make(map[int]int, n),
	}
}

func (fac *Fac) Factorial(n int) int {
	if fac.val[n] != 0{
		return fac.val[n]
	}

	if n <= 1{
		fac.val[n] = 1
		return 1
	}else {
		res := n * fac.Factorial(n-1)
		fac.val[n] =res
		return res
	}
}

func (fac *Fac) Print(n int )  {
	println(fac.val[n])
}
