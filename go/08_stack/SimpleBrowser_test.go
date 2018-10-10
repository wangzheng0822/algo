package _8_stack

import "testing"

func TestBrowser(t *testing.T) {
	b := NewBrowser()
	b.PushBack("www.qq.com")
	b.PushBack("www.baidu.com")
	b.PushBack("www.sina.com")
	if b.CanBack() {
		b.Back()
	}
	if b.CanForward() {
		b.Forward()
	}
	if b.CanBack() {
		b.Back()
	}
	if b.CanBack() {
		b.Back()
	}
	if b.CanBack() {
		b.Back()
	}
	b.Open("www.taobao.com")
	if b.CanForward() {
		b.Forward()
	}
}
