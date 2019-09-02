package backtracking

import "testing"

func TestFindLeastCoins(t *testing.T) {

	coinOptions := []int{1, 3, 5, 10, 50}

	Cnt = 0
	result := LeastCoins(9, coinOptions)

	t.Log("test 1 =====================")
	if result != 3 {
		t.Logf("least coins %d", result)
		t.Error("failed")
	}
	t.Logf("cnt===%d", Cnt)

	Cnt = 0
	t.Log("test 2 =====================")
	result = LeastCoins(36, coinOptions)

	if result != 5 {
		t.Logf("least coins %d", result)
		t.Error("failed")
	}
	t.Logf("cnt===%d", Cnt)

}

func TestFindLeastCoins2(t *testing.T) {

	coinOptions := []int{1, 3, 5, 10, 50}

	Cnt = 0
	result := LeastCoins2(9, coinOptions)

	t.Log("test 1 =====================")
	if result != 3 {
		t.Logf("least coins %d", result)
		t.Error("failed")
	}

	t.Logf("cnt===%d", Cnt)

	Cnt = 0
	t.Log("test 2 =====================")
	result = LeastCoins2(36, coinOptions)

	if result != 5 {
		t.Logf("least coins %d", result)
		t.Error("failed")
	}
	t.Logf("cnt===%d", Cnt)

}
