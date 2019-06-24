package backtracking

import (
	"fmt"
)

const intMax = int(^uint(0) >> 1)

var Cnt int

// LeastCoins find least number of coins of which the total values are equals a given one
func LeastCoins(targetTotal int, coinOptions []int) int {
	minNum := intMax

	memo := make([][]int, targetTotal+1)
	for i := range memo {
		memo[i] = make([]int, len(coinOptions))
	}
	fmt.Println("start")
	leastCoins(&minNum, 0, targetTotal, len(coinOptions)-1, coinOptions, memo)
	fmt.Println("end")

	return minNum

}

func leastCoins(minNum *int, cNum, totalValue, opIndex int, coinOptions []int, memo [][]int) {
	Cnt++
	if 0 == totalValue {
		if cNum < *minNum {
			*minNum = cNum
		}

		return
	}

	if opIndex < 0 {
		return
	}

	num4Option := 0
	remaining := totalValue - coinOptions[opIndex]*num4Option
	for remaining >= 0 {

		if opIndex != 0 {
			if shouldSkip(memo, remaining, opIndex-1, cNum+num4Option) {
				goto Next
			}
		}
		leastCoins(minNum, cNum+num4Option, remaining, opIndex-1, coinOptions, memo)

	Next:
		num4Option++
		remaining = totalValue - coinOptions[opIndex]*num4Option

	}

}

func shouldSkip(memo [][]int, totalValue, nextOpIdex, cNum int) bool {
	if memo[totalValue][nextOpIdex] > 0 && memo[totalValue][nextOpIdex] <= cNum {
		fmt.Printf("skip，%d, %d  as %d <= %d \n", totalValue, nextOpIdex, memo[totalValue][nextOpIdex], cNum)
		return true
	}
	if memo[totalValue][nextOpIdex] == 0 || memo[totalValue][nextOpIdex] > cNum {
		memo[totalValue][nextOpIdex] = cNum
	}
	return false
}

func LeastCoins2(targetTotal int, coinOptions []int) int {

	minNum := intMax
	memo := make([][]bool, targetTotal)
	for i := range memo {
		memo[i] = make([]bool, targetTotal/coinOptions[0])
	}

	fmt.Println("start")
	leastCoins2(&minNum, targetTotal, coinOptions, 0, 0, memo)
	fmt.Println("end")

	return minNum

}

func leastCoins2(minNum *int, targetTotal int, coinOptions []int, cNum, cValue int, memo [][]bool) {
	Cnt++
	if cValue == targetTotal {
		if *minNum > cNum {
			*minNum = cNum
		}
		return
	}

	for _, coin := range coinOptions {
		if coin+cValue <= targetTotal && !memo[cValue+coin-1][cNum] {
			memo[cValue+coin-1][cNum] = true
			leastCoins2(minNum, targetTotal, coinOptions, cNum+1, cValue+coin, memo)
		}
	}
}
