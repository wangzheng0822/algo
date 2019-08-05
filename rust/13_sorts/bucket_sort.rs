/// 桶排序
/// 时间复杂度：O(n), 稳定排序
// 桶排序
pub fn bucket_sort(mut nums: Vec<i32>, step: i32) -> Vec<i32> {
    let (mut min, mut max) = (nums[0], nums[0]);
    for i in 0..nums.len() {
        if min > nums[i] { min = nums[i]; }
        if max < nums[i] { max = nums[i]; }
    }

    // 设置需要的桶的数量
    let bucket_num = (max - min) / step + 1;
    let mut bucket_list: Vec<Vec<i32>> = vec![vec![]; bucket_num as usize];
    // 将 nums 数组中元素分别装入桶中
    for i in 0..nums.len() {
        // 计算桶 index
        let index = (nums[i] - min) / step;
        bucket_list[index as usize].push(nums[i]);
    }

    let mut index = 0;
    for i in 0..bucket_num {
        let bucket = &bucket_list[i as usize];
        // 对每个桶中元素使用快排进行排序
        let new_bucket = quick_sort(bucket.to_vec());
        // 将已经排序好的桶中元素拷贝到 nums 数组中
        for num in new_bucket.into_iter() {
            nums[index as usize] = num;
            index += 1;
        }
    }
    nums
}

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
    let nums = vec![2, 5, 3, 0, 2, 3, 0, 3];
    let m = bucket_sort(nums, 3);
    println!("{:?}", m);
}
