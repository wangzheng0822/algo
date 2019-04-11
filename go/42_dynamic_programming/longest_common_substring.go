package main

import "fmt"

func lsc(s1 string, s2 string) int {
	m := len(s1)
	n := len(s2)

	memo := make([][]int, m + 1)
	for i := 0; i < m + 1; i++ {
		memo[i] = make([]int, n + 1)
	}


	for i := 1; i < m + 1; i++ {
		for j := 1; j < n + 1; j++ {
			if s1[i - 1] == s2[j - 1] {
				memo[i][j] = memo[i - 1][j - 1] + 1
			}
		}
	}

	fmt.Println(memo)
	longest := 0
	for i, _ := range memo {
		for j, e2 := range memo[i] {
			if longest < memo[i][j] {
				longest = e2
			}
		}
	}

	return longest
}

func main() {
	fmt.Println(lsc("blue", "clues"))	//3
	fmt.Println(lsc("fosh", "fish"))	//2
	fmt.Println(lsc("fosh", "fort"))	//2
	fmt.Println(lsc("hish", "fish"))	//3
	fmt.Println(lsc("hish", "vista"))	//2
}