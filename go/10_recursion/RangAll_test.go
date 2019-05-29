package Recursion

import "testing"

func TestRangeALL(t *testing.T) {
	slice1 := NewRangeArray(4)
	for i:=0; i<4; i++{
		slice1.value[i] = i+1
	}
	slice1.RangeALL(0)

	slice2 := NewRangeArray(3)
	slice2.value[0] = "a"
	slice2.value[1] = "b"
	slice2.value[2] = "c"
	slice2.RangeALL(0)

}
