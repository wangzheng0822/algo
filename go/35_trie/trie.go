package _2_trie

// 若是将trieNode指针换成数组，则可能会耗费更多的内存，
// 因为在某个子节点不存在时，要存储的是空结构体，而不仅仅是一个空指针。
// data在本例中没啥用，仅仅表示当前节点存储的字符，
// 而这一点已经通过该节点在父节点的children数组中的位置表明；
type trieNode struct {
	data         byte
	isEndingChar bool
	children     []*trieNode
}

type Trie struct {
	root *trieNode
}

func Constructor() Trie {
	return Trie{
		root: &trieNode{
			children: make([]*trieNode, 26),
		},
	}
}

func (t *Trie) Insert(word string) {
	p := t.root
	for i := 0; i < len(word); i++ {
		pos := word[i] - 'a'
		if p.children[pos] == nil {
			p.children[pos] = &trieNode{
				data:     word[i],
				children: make([]*trieNode, 26),
			}
		}
		p = p.children[pos]
	}

	p.isEndingChar = true
}

func (t *Trie) Search(word string) bool {
	p := t.root
	for i := 0; i < len(word); i++ {
		pos := word[i] - 'a'
		if p.children[pos] == nil {
			return false
		}
		p = p.children[pos]
	}
	if p.isEndingChar == true {
		return true
	}

	return false
}

func (t *Trie) StartsWith(prefix string) bool {
	p := t.root
	for i := 0; i < len(prefix); i++ {
		pos := prefix[i] - 'a'
		if p.children[pos] == nil {
			return false
		}
		p = p.children[pos]
	}
	// StartsWith包含完全匹配的情况
	return true
}
