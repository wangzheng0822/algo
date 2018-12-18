package graph

import (
	"container/list"
	"fmt"
)

//adjacency table, 无向图
type Graph struct {
	adj []*list.List
	v   int
}

//init graphh according to capacity
func newGraph(v int) *Graph {
	graphh := &Graph{}
	graphh.v = v
	graphh.adj = make([]*list.List, v)
	for i := range graphh.adj {
		graphh.adj[i] = list.New()
	}
	return graphh
}

//insert as add edge，一条边存2次
func (self *Graph) addEdge(s int, t int) {
	self.adj[s].PushBack(t)
	self.adj[t].PushBack(s)
}

//search path by BFS
func (self *Graph) BFS(s int, t int) {

	//todo
	if s == t {
		return
	}

	//init prev
	prev := make([]int, self.v)
	for index := range prev {
		prev[index] = -1
	}

	//search by queue
	var queue []int
	visited := make([]bool, self.v)
	queue = append(queue, s)
	visited[s] = true
	isFound := false
	for len(queue) > 0 && !isFound {
		top := queue[0]
		queue = queue[1:]
		linkedlist := self.adj[top]
		for e := linkedlist.Front(); e != nil; e = e.Next() {
			k := e.Value.(int)
			if !visited[k] {
				prev[k] = top
				if k == t {
					isFound = true
					break
				}
				queue = append(queue, k)
				visited[k] = true
			}
		}
	}

	if isFound {
		printPrev(prev, s, t)
	} else {
		fmt.Printf("no path found from %d to %d\n", s, t)
	}

}

//search by DFS
func (self *Graph) DFS(s int, t int) {

	prev := make([]int, self.v)
	for i := range prev {
		prev[i] = -1
	}

	visited := make([]bool, self.v)
	visited[s] = true

	isFound := false
	self.recurse(s, t, prev, visited, isFound)

	printPrev(prev, s, t)
}

//recursivly find path
func (self *Graph) recurse(s int, t int, prev []int, visited []bool, isFound bool) {

	if isFound {
		return
	}

	visited[s] = true

	if s == t {
		isFound = true
		return
	}

	linkedlist := self.adj[s]
	for e := linkedlist.Front(); e != nil; e = e.Next() {
		k := e.Value.(int)
		if !visited[k] {
			prev[k] = s
			self.recurse(k, t, prev, visited, false)
		}
	}

}

//print path recursively
func printPrev(prev []int, s int, t int) {

	if t == s || prev[t] == -1 {
		fmt.Printf("%d ", t)
	} else {
		printPrev(prev, s, prev[t])
		fmt.Printf("%d ", t)
	}

}

//func main() {
//	graph := newGraph(8)
//	graph.addEdge(0, 1)
//	graph.addEdge(0, 3)
//	graph.addEdge(1, 2)
//	graph.addEdge(1, 4)
//	graph.addEdge(2, 5)
//	graph.addEdge(3, 4)
//	graph.addEdge(4, 5)
//	graph.addEdge(4, 6)
//	graph.addEdge(5, 7)
//	graph.addEdge(6, 7)
//
//	graph.BFS(0, 7)
//	fmt.Println()
//	graph.BFS(1, 3)
//	fmt.Println()
//	graph.DFS(0, 7)
//	fmt.Println()
//	graph.DFS(1, 3)
//	fmt.Println()
//}
