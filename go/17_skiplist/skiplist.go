package _17_skiplist

import (
	"fmt"
	"math/rand"
)

// 参考跳表Java版本的Go语言实现, based on go1.9.5

const maxLevel = 16

type skipList struct {
	levelCount int
	head       *Node
}

func NewSkipList() *skipList {
	return &skipList{levelCount: 1, head: &Node{data: -1, forwards: make([]*Node, maxLevel), maxLevel: 0}}
}

func (list *skipList) Find(value int) *Node {
	p := list.head
	for i := list.levelCount - 1; i >= 0; i-- {
		for p.forwards[i] != nil && p.forwards[i].data < value {
			p = p.forwards[i]
		}
	}
	if p.forwards[0] != nil && p.forwards[0].data == value {
		return p.forwards[0]
	}
	return nil
}

func (list *skipList) Insert(value int) {
	level := list.randomLevel()
	newNode := &Node{data: value, forwards: make([]*Node, maxLevel), maxLevel: level}
	update := make([]*Node, level)
	for i := 0; i < level; i++ {
		update[i] = list.head
	}

	p := list.head
	for i := level - 1; i >= 0; i-- {
		for p.forwards[i] != nil && p.forwards[i].data < value {
			p = p.forwards[i]
		}
		update[i] = p
	}

	for i := 0; i < level; i++ {
		newNode.forwards[i] = update[i].forwards[i]
		update[i].forwards[i] = newNode
	}
	if list.levelCount < level {
		list.levelCount = level
	}
}

func (list *skipList) Delete(value int) {
	update := make([]*Node, list.levelCount)
	p := list.head
	for i := list.levelCount - 1; i >= 0; i-- {
		for p.forwards[i] != nil && p.forwards[i].data < value {
			p = p.forwards[i]
		}
		update[i] = p
	}

	if p.forwards[0] != nil && p.forwards[0].data == value {
		for i := list.levelCount - 1; i >= 0; i-- {
			if update[i].forwards[i] != nil && update[i].forwards[i].data == value {
				update[i].forwards[i] = update[i].forwards[i].forwards[i]
			}
		}
	}
}

func (list *skipList) PrintAll(value int) {
	p := list.head
	for p.forwards != nil {
		fmt.Print(p.forwards[0].String() + " ")
		p = p.forwards[0]
	}
	fmt.Println()
}

func (list *skipList) randomLevel() int {
	level := 1
	for i := 1; i < maxLevel; i++ {
		if rand.Int()&1 == 1 {
			level++
		}
	}
	return level
}

type Node struct {
	data     int
	maxLevel int
	forwards []*Node
}

func (node *Node) String() string {
	return fmt.Sprintf("{ data: %d; levels: %d }", node.data, node.maxLevel)
}
