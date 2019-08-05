// 建堆，自底向上堆化
pub fn build_heap_down_up(nums: &mut Vec<i32>) {
    for i in 1..nums.len() {
        heapify_down_up(nums, i);
    }
}

fn heapify_down_up(nums: &mut Vec<i32>, idx: usize) {
    let mut idx = idx;
    let mut parent_idx = idx - 1 >> 1;
    while nums[idx] > nums[parent_idx] {
        swap(nums, idx, parent_idx);
        idx = parent_idx;
        if idx == 0 { break; }
        parent_idx = idx - 1 >> 1;
    }
}

// 建堆，自上向下堆化
pub fn build_heap_up_down(nums: &mut Vec<i32>) {
    let nums_len = nums.len();
    for i in (0..nums_len).rev() {
        heapify_up_down(nums, i, nums_len);
    }
}

fn heapify_up_down(nums: &mut Vec<i32>, idx: usize, nums_len: usize) {
    let mut idx = idx;
    loop {
        let mut max_pos = idx;
        if 2 * idx + 1 < nums_len && nums[idx] < nums[2 * idx + 1] { max_pos = 2 * idx + 1; }
        if 2 * idx + 2 < nums_len && nums[max_pos] < nums[2 * idx + 2] { max_pos = 2 * idx + 2; }

        if max_pos == idx { break; }
        swap(nums, idx, max_pos);
        idx = max_pos;
    }
}

fn swap(nums: &mut Vec<i32>, idx: usize, parent_idx: usize) {
    let tmp = nums[parent_idx];
    nums[parent_idx] = nums[idx];
    nums[idx] = tmp;
}

fn main() {
    let mut nums = vec![1, 4, 5, 7, 8, 13, 16, 19, 20];
    build_heap_down_up(&mut nums);
    println!("{:?}", nums);
    let mut nums1 = vec![1, 4, 5, 7, 8, 13, 16, 19, 20];
    build_heap_up_down(&mut nums1);
    println!("{:?}", nums1);
}
