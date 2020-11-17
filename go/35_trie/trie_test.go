package _2_trie

import "testing"

func TestTrie(t *testing.T) {
	trie := Constructor()
	trie.Insert("straiway")
	trie.Insert("lena")
	t.Log(trie.Search("straiway"))
	t.Log(trie.Search("lena"))
	t.Log(trie.Search("lenasdf"))
}
