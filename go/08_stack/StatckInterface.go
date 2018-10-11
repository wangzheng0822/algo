package _8_stack

type Stack interface {
	Push(v interface{})
	Pop() interface{}
	IsEmpty() bool
	Top() interface{}
	Flush()
}
