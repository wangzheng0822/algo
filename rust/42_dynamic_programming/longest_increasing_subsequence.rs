// leetcode 300 [longest_increasing_subsequence](https://leetcode.com/problems/longest-increasing-subsequence)
fn longest_increasing_subsequence(nums: Vec<i32>) -> i32 {
    if nums.len() <= 1 { return nums.len() as i32; }

    let mut dp = vec![1; nums.len()];
    let mut max_list = 1;

    for i in 0..nums.len() {
        for j in 0..i {
            if nums[i] > nums[j] {
                dp[i] = dp[i].max(dp[j]+1);
            }
        }
        max_list = max_list.max(dp[i]);
    }
    max_list
}
fn main() {
    let nums = vec![2, 9, 3, 6, 5, 1, 7];
    let m = longest_increasing_subsequence(nums);
    println!("{:?}", m);
}
