package Recursion

import "testing"

func TestFac_Factorial(t *testing.T) {
	fac := NewFactorial(10)
	for i:=1; i<15; i++{
		fac.Factorial(i)
		fac.Print(i)
	}
}
