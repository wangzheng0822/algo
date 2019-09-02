/// 选择排序
/// 时间复杂度:O(n2)，原地排序算法, 不稳定排序算法
// 选择排序
fn selection_sort(mut nums: Vec<i32>) -> Vec<i32> {
    if nums.is_empty() { return vec![]; }

    for i in 0..nums.len() {
        let mut mini_index = i;
        // 查找最小 index
        for j in i+1..nums.len() {
            if nums[j] < nums[mini_index] {
                mini_index = j;
            }
        }
        // 交换数据
        let tmp = nums[i];
        nums[i] = nums[mini_index];
        nums[mini_index] = tmp;
    }
    nums
}

fn main() {
    let nums = vec![4, 5, 6, 1, 2, 3];
    println!("{:?}", selection_sort(nums));
}
