// leetcode 33 Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/)
pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    if nums.is_empty() { return -1; }

    let mut low = 0;
    let mut high = nums.len() - 1;

    while low <= high {
        let mid = low + ((high - low) >> 1);
        if nums[mid] == target { return mid as i32; }

        // left is order
        if nums[low] <= nums[mid] {
            // target is in left array
            if nums[low] <= target && target <= nums[mid] {
                high = mid - 1;
            }  else {
                low = mid + 1;
            }
        } else {
            if nums[mid] <= target && target <= nums[high] {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    -1
}

fn main() {
    let nums = vec![4,5,6,7,0,1,2];
    let n = search(nums, 0);
    println!("{:?}", n);
}
