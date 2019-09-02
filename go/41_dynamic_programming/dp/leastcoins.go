package dp

var Cnt int

// minNum(v) = 1 + min(minNum(v-i))
func LeastCoins(targetTotal int, coinOptions []int) int {
	memo := make([]int, targetTotal)

	cMinNum := leastCoins(targetTotal, coinOptions, memo)

	return cMinNum

}

// State Transition Table
func LeastCoins2(targetTotal int, coinOptions []int) int {
	memo := make([]int, targetTotal)

	for i := 1; i <= targetTotal; i++ {

		minNum := -1
		for _, coin := range coinOptions {
			Cnt++
			if i < coin {
				break
			}
			if i == coin {
				minNum = 1
				break
			}
			if minNum == -1 || minNum > memo[i-coin-1]+1 {
				minNum = memo[i-coin-1] + 1
			}
		}
		memo[i-1] = minNum
	}

	return memo[targetTotal-1]

}

func leastCoins(targetTotal int, coinOptions, memo []int) int {
	Cnt++
	if targetTotal == 0 {
		return 0
	}
	if memo[targetTotal-1] != 0 {
		return memo[targetTotal-1]
	}
	cMinNum := -1
	for _, coin := range coinOptions {
		if targetTotal-coin < 0 {
			continue
		}
		cNum := 1 + leastCoins(targetTotal-coin, coinOptions, memo)
		if cMinNum == -1 || cNum < cMinNum {
			cMinNum = cNum
		}

	}
	memo[targetTotal-1] = cMinNum
	return cMinNum
}
