package _4_tree

type BST struct {
	*BinaryTree
	//比对函数，0:v==nodeV,正数:v>nodeV,负数:v<nodeV
	compareFunc func(v, nodeV interface{}) int
}

func NewBST(rootV interface{}, compareFunc func(v, nodeV interface{}) int) *BST {
	if nil == compareFunc {
		return nil
	}
	return &BST{BinaryTree: NewBinaryTree(rootV), compareFunc: compareFunc}
}

func (this *BST) Find(v interface{}) *Node {
	p := this.root
	for nil != p {
		compareResult := this.compareFunc(v, p.data)
		if compareResult == 0 {
			return p
		} else if compareResult > 0 { //v > nodeV
			p = p.right
		} else { //v < nodeV
			p = p.left
		}
	}
	return nil
}

func (this *BST) Insert(v interface{}) bool {
	p := this.root
	for nil != p {
		compareResult := this.compareFunc(v, p.data)
		if compareResult == 0 {
			return false
		} else if compareResult > 0 {
			if nil == p.right {
				p.right = NewNode(v)
				break
			}
			p = p.right
		} else {
			if nil == p.left {
				p.left = NewNode(v)
				break
			}
			p = p.left
		}
	}
	return true
}

func (this *BST) Delete(v interface{}) bool {
	var pp *Node = nil
	p := this.root
	deleteLeft := false
	for nil != p {
		compareResult := this.compareFunc(v, p.data)
		if compareResult > 0 {
			pp = p
			p = p.right
			deleteLeft = false
		} else if compareResult < 0 {
			pp = p
			p = p.left
			deleteLeft = true
		} else {
			break
		}
	}

	if nil == p { //需要删除的节点不存在
		return false
	} else if nil == p.left && nil == p.right { //删除的是一个叶子节点
		if nil != pp {
			if deleteLeft {
				pp.left = nil
			} else {
				pp.right = nil
			}
		} else { //根节点
			this.root = nil
		}
	} else if nil != p.right { //删除的是一个有右孩子，不一定有左孩子的节点
		//找到p节点右孩子的最小节点
		pq := p
		q := p.right //向右走一步
		fromRight := true
		for nil != q.left { //向左走到底
			pq = q
			q = q.left
			fromRight = false
		}
		if fromRight {
			pq.right = nil
		} else {
			pq.left = nil
		}
		q.left = p.left
		q.right = p.right
		if nil == pp { //根节点被删除
			this.root = q
		} else {
			if deleteLeft {
				pq.left = q
			} else {
				pq.right = q
			}
		}
	} else { //删除的是一个只有左孩子的节点
		if nil != pp {
			if deleteLeft {
				pp.left = p.left
			} else {
				pp.right = p.left
			}
		} else {
			if deleteLeft {
				this.root = p.left
			} else {
				this.root = p.left
			}
		}
	}

	return true

}

func (this *BST) Min() *Node {
	p := this.root
	for nil != p.left {
		p = p.left
	}
	return p
}

func (this *BST) Max() *Node {
	p := this.root
	for nil != p.right {
		p = p.right
	}
	return p
}
