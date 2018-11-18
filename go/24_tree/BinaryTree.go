package _4_tree

import "fmt"

type BinaryTree struct {
	root *Node
}

func NewBinaryTree(rootV interface{}) *BinaryTree {
	return &BinaryTree{NewNode(rootV)}
}

func (this *BinaryTree) InOrderTraverse() {
	p := this.root
	s := NewArrayStack()

	for !s.IsEmpty() || nil != p {
		if nil != p {
			s.Push(p)
			p = p.left
		} else {
			tmp := s.Pop().(*Node)
			fmt.Printf("%+v ", tmp.data)
			p = tmp.right
		}
	}
	fmt.Println()
}

func (this *BinaryTree) PreOrderTraverse() {
	p := this.root
	s := NewArrayStack()

	for !s.IsEmpty() || nil != p {
		if nil != p {
			fmt.Printf("%+v ", p.data)
			s.Push(p)
			p = p.left
		} else {
			p = s.Pop().(*Node).right
		}
	}

	fmt.Println()
}

func (this *BinaryTree) PostOrderTraverse() {
	s1 := NewArrayStack()
	s2 := NewArrayStack()
	s1.Push(this.root)
	for !s1.IsEmpty() {
		p := s1.Pop().(*Node)
		s2.Push(p)
		if nil != p.left {
			s1.Push(p.left)
		}
		if nil != p.right {
			s1.Push(p.right)
		}
	}

	for !s2.IsEmpty() {
		fmt.Printf("%+v ", s2.Pop().(*Node).data)
	}
}
