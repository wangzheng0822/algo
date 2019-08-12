pub fn sort(nums: &mut Vec<i32>) {
    build_heap(nums);
    for i in (0..nums.len()).rev() {
        swap(nums, 0, i);
        heapify(nums, 0, i);
    }
}

fn build_heap(nums: &mut Vec<i32>) {
    let nums_len = nums.len();
    for i in (0..nums_len).rev() {
        heapify(nums, i, nums_len);
    }
}

fn heapify(nums: &mut Vec<i32>, idx: usize, nums_len: usize) {
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
    let mut nums = vec![9, 6, 3, 1, 5];
    sort(&mut nums);
    println!("{:?}", nums);
}
