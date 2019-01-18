package main

import (
	"fmt"
)

//BF search pattern index, return the first match subs start index
func bfSearch(main string, pattern string) int {

	//defensive
	if len(main) == 0 || len(pattern) == 0 || len(main) < len(pattern) {
		return -1
	}

	for i := 0; i <= len(main)-len(pattern); i++ {
		subStr := main[i : i+len(pattern)]
		if subStr == pattern {
			return i
		}
	}

	return -1
}

func main() {

	main := "abcd227fac"
	pattern := "ac"
	fmt.Println(bfSearch(main, pattern))
}
