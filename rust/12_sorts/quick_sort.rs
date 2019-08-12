/// 快排
/// 时间复杂度：O(nlogn), 空间复杂度： O(1), 不稳定排序
// 快排
pub fn quick_sort(mut nums: Vec<i32>) -> Vec<i32> {
    if nums.is_empty() { return nums; }

    let n = nums.len() - 1;
    quick_sort_internally(&mut nums, 0, n);
    nums
}

fn quick_sort_internally(nums: &mut Vec<i32>, start: usize, end: usize) {
    if start >= end { return; }

    // 分区点
    let pivot = partition(nums, start, end);
    if pivot != 0 {
        quick_sort_internally(nums, start, pivot-1);
    }
    quick_sort_internally(nums, pivot+1, end);
}

fn partition(nums: &mut Vec<i32>, start: usize, end: usize) -> usize {
    let pivot = nums[end];
    let mut i = start;
    for j in start..end {
        if nums[j] < pivot {
            swap(nums, i, j);
            i += 1;
        }
    }

    swap(nums, i, end);
    i
}

fn swap(nums: &mut Vec<i32>, i: usize, j: usize) {
    if i == j { return; }

    let tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

fn main() {
    let nums = vec![8, 10, 2, 3, 6,1, 5];
    println!("{:?}", quick_sort(nums));
}
