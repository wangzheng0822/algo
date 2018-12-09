package main

import (
	"fmt"
	"math"
)

//bc: pattern char index hash mapping
func generateBC(pattern string) []int {

	bc := make([]int, 256)

	for index := range bc {
		bc[index] = -1
	}

	for index, char := range pattern {
		bc[int(char)] = index
	}

	return bc
}

//generate suffix and prefix array for pattern
func generateGS(pattern string) ([]int, []bool) {
	m := len(pattern)
	suffix := make([]int, m)
	prefix := make([]bool, m)

	//init
	for i := 0; i < m; i++ {
		suffix[i] = -1
		prefix[i] = false
	}

	for i := 0; i < m-1; i++ {
		j := i
		k := 0
		for j >= 0 && pattern[j] == pattern[m-1-k] {
			j--
			k++
			suffix[k] = j + 1
		}

		if j == -1 {
			prefix[k] = true
		}
	}

	return suffix, prefix
}

//todo
func moveByGS(patternLength int, badCharStartIndex int, suffix []int, prefix []bool) int {

	//length of good suffix
	k := patternLength - badCharStartIndex - 1

	//complete match
	if suffix[k] != -1 {
		return badCharStartIndex + 1 - suffix[k]
	}

	//partial match
	for t := patternLength - 1; t > badCharStartIndex+1; t-- {
		if prefix[t] {
			return t
		}
	}

	//no match
	return patternLength

}

func bmSearch(main string, pattern string) int {
	//defensive
	if len(main) == 0 || len(pattern) == 0 || len(pattern) > len(main) {
		return -1
	}

	bc := generateBC(pattern)
	suffix, prefix := generateGS(pattern)

	n := len(main)
	m := len(pattern)

	// i : start index of main string
	step := 1
	for i := 0; i <= n-m; i = i + step {
		subStr := main[i : i+m]
		k, j := findBadChar(subStr, pattern, bc)

		stepForBC := j - k
		//j is bad char occur index
		if j == -1 {
			return i
		}

		stepForGS := -1
		if j < m-1 {
			stepForGS = moveByGS(m, j, suffix, prefix)
		}

		//k is bad char index in pattern
		step = int(math.Max(float64(stepForBC), float64(stepForGS)))
	}

	return -1
}

func findBadChar(subStr string, pattern string, bc []int) (int, int) {

	j := -1
	k := -1
	badChar := rune(0)

	for index := len(subStr) - 1; index >= 0; index-- {
		if subStr[index] != pattern[index] {
			j = index
			badChar = rune(subStr[index])
			break
		}
	}

	//if bad character exist, then find it's index at pattern
	if j > 0 {
		k = bc[int(badChar)]
	}

	return k, j
}

func main() {

	main := "abcacabcbcabcabc"
	pattern := "cabcab"

	fmt.Println(bmSearch(main, pattern))
}
