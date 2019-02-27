package bitmap

import (
	"testing"
)

func TestBitMap(t *testing.T) {
	bitMap := New(80)
	for i := 0; i <= 100; i += 10 {
		bitMap.Set(uint(i))
	}
	for i := 0; i <= 100; i += 10 {
		t.Log(bitMap.Get(uint(i)))
	}
}
