// leetcode 72 [edit_distance](https://leetcode.com/problems/edit-distance/)
fn edit_distance(word1: &str, word2: &str) -> i32 {
    let word1_chars: Vec<char> = word1.chars().collect();
    let word2_chars: Vec<char> = word2.chars().collect();
    let m = word1.len();
    let n = word2.len();
    let mut dp = vec![vec![0; m+1]; n+1];

    // 初始化第一行
    for i in 0..=m { dp[i][0] = i; }
    // 初始化第一列
    for j in 0..=n { dp[0][j] = j; }

    for i in 1..=m {
        for j in 1..=n {
            let mut step = 0;
            if word1_chars[i-1] != word2_chars[j-1] { step = 1; }
            dp[i][j] = (dp[i][j-1] + 1).min(dp[i-1][j] + 1).min(dp[i-1][j-1] + step);
        }
    }

    dp[m][n] as i32
}
fn main() {
    let word1 = "mitcmu";
    let word2 = "mtacnu";
    let m = edit_distance(word1, word2);
    println!("{:?}", m);
}
