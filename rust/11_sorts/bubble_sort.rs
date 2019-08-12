/// 冒泡排序
/// 时间复杂度:O(n2)，原地排序算法, 稳定排序算法
// 冒泡排序
fn bubble_sort(mut nums: Vec<i32>) -> Vec<i32> {
    if nums.is_empty() { return vec![]; }

    let n = nums.len();
    for i in 0..n {
        // 提前退出标志
        let mut swap = false;
        for j in 0..n-i-1 {
            if nums[j] > nums[j+1] {
                // 此次冒泡有数据交换
                swap = true;
                let tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
        // 若没有数据交换，提前退出
        if !swap { break; }
    }
    nums
}

fn main() {
    let nums = vec![4, 5, 6, 1, 2, 3];
    println!("{:?}", bubble_sort(nums));
}
