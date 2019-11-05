/// 归并排序
/// 时间复杂度 O(nlogn), 空间复杂度：O(n), 稳定排序
// 归并排序
pub fn merge_sort(mut nums: Vec<i32>) -> Vec<i32> {
    if nums.is_empty() { return nums; }

    let n = nums.len() - 1;
    merge_sort_internally(&mut nums, 0, n);
    nums
}

fn merge_sort_internally(nums: &mut Vec<i32>, start: usize, end: usize) {
    if start >= end { return; }

    let middle = start + (end - start) / 2;
    merge_sort_internally(nums, start, middle);
    merge_sort_internally(nums, middle+1, end);

    // merge two array
    merge(nums, start, middle, end);
}

fn merge(nums: &mut Vec<i32>, start: usize, middle: usize, end: usize) {
    let mut i = start;
    let mut j = middle + 1;
    let mut tmp = vec![];
    while i <= middle && j <= end {
        if nums[i] <= nums[j] {
            tmp.push(nums[i]);
            i += 1;
        } else {
            tmp.push(nums[j]);
            j += 1;
        }
    }

    let mut s = i;
    let mut r = middle;
    if j <= end {
        s = j;
        r = end;
    }

    while s <= r {
        tmp.push(nums[s]);
        s += 1;
    }

    for i in 0..=(end-start) {
        nums[start+i] = tmp[i];
    }
}

fn main() {
    let nums = vec![8, 10, 2, 3, 6,1, 5];
    println!("{:?}", merge_sort(nums));
}
