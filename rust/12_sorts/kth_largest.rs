pub fn kth_largest(mut nums: Vec<i32>, k: i32) -> Option<i32> {
    if nums.is_empty() || k >= nums.len() as i32 { return None; }

    let end = nums.len() - 1;
    let k = k as usize;
    // 分区点
    let mut pivot = partition(&mut nums, 0, end);
    while pivot + 1 != k {
        if k > pivot + 1 {
            pivot = partition(&mut nums, pivot + 1, end);
        } else {
            pivot = partition(&mut nums, 0, pivot - 1);
        }
    }

    Some(nums[pivot])
}

fn partition(nums: &mut Vec<i32>, start: usize, end: usize) -> usize {
    let pivot = nums[end];
    let mut i = start;
    for j in start..end {
        if nums[j] >= pivot { // if nums[j] <= pivot then swap, search kth smallest
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
    println!("{:?}", kth_largest(nums, 3));
}
