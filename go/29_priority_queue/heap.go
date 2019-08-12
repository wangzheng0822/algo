package pqueue

func adjustHeap(src []Node, start, end int) {
	if start >= end {
		return
	}

	// 只需要保证优先级最高的节点在 src[1] 的位置即可
	for i := end / 2; i >= start; i-- {
		high := i
		if src[high].priority < src[2*i].priority {
			high = 2 * i
		}
		if 2*i+1 <= end && src[high].priority < src[2*i+1].priority {
			high = 2*i + 1
		}
		if high == i {
			continue
		}
		src[high], src[i] = src[i], src[high]
	}
}
