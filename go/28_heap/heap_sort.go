package heap

//build a heap
func buidHeap(a []int, n int) {

	//heapify from the last parent node
	for i := n / 2; i >= 1; i-- {
		heapifyUpToDown(a, i, n)
	}

}

//sort by ascend, a index begin from 1, has n elements
func sort(a []int, n int) {
	buidHeap(a, n)

	k := n
	for k >= 1 {
		swap(a, 1, k)
		heapifyUpToDown(a, 1, k-1)
		k--
	}
}

//heapify from up to down , node index = top
func heapifyUpToDown(a []int, top int, count int) {

	for i := top; i <= count/2; {

		maxIndex := i
		if a[i] < a[i*2] {
			maxIndex = i * 2
		}

		if i*2+1 <= count && a[maxIndex] < a[i*2+1] {
			maxIndex = i*2 + 1
		}

		if maxIndex == i {
			break
		}

		swap(a, i, maxIndex)
		i = maxIndex
	}

}

//swap two elements
func swap(a []int, i int, j int) {
	tmp := a[i]
	a[i] = a[j]
	a[j] = tmp
}
