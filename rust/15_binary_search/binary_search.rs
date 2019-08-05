// 二分查找
pub fn binary_search(nums: Vec<i32>, value: i32) -> i32 {
    if nums.is_empty() { return -1; }

    let mut low = 0;
    let mut high = nums.len() - 1;

    while low <= high {
        let mid = low + ((high - low) >> 1);
        if nums[mid] == value { return mid as i32; }

        if nums[mid] < value {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    -1
}

// 二分查找递归
pub fn binary_search_recursion(nums: Vec<i32>, value: i32) -> i32 {
    if nums.is_empty() { return -1; }

    _recursion(&nums, 0, nums.len()-1, value)
}

fn _recursion(nums: &Vec<i32>, low: usize, high: usize, value: i32) -> i32 {
    if low > high { return -1; }

    let mid = low + ((high - low) >> 1);
    if nums[mid] == value { return mid as i32; }

    if nums[mid] < value {
        return _recursion(nums, mid+1, high, value);
    } else {
        return _recursion(nums, low, mid-1, value);
    }
}

fn main() {
    let nums1 = vec![8,11,19,23,27,33,45,55,67,98];
    let nums2 = vec![8,11,19,23,27,33,45,55,67,98];
    println!("{:?}", binary_search(nums1, 23));
    println!("{:?}", binary_search_recursion(nums2, 23));
}
