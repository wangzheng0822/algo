package pqueue

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_AdjustHeap(t *testing.T) {
	list := []Node{Node{0, 0}, Node{1, 1}, Node{2, 2}, Node{3, 3}, Node{4, 1}, Node{6, 6}}

	adjustHeap(list, 1, len(list)-1)
	assert.Equal(t, 6, list[1].value)
}
