fn merge_sort_count(mut nums: Vec<i32>) -> i32 {
    let mut count = 0;
    let n = nums.len() - 1;
    merge_sort(&mut nums, 0, n, &mut count);
    count
}

fn merge_sort(nums: &mut Vec<i32>, low: usize, high: usize, count: &mut i32) {
    if low >= high { return; }

    let middle = low + ((high - low) >> 1);
    merge_sort(nums, low, middle, count);
    merge_sort(nums, middle+1, high, count);

    merge(nums, low, middle, high, count);
}

fn merge(nums:   &mut Vec<i32>,
         low:    usize,
         middle: usize,
         high:   usize,
         count:  &mut i32) {
    let mut i = low;
    let mut j = middle + 1;
    let mut tmp = vec![];

    while i <= middle && j <= high {
        if nums[i] <= nums[j] {
            tmp.push(nums[i]);
            i += 1;
        } else {
            // count += &(middle - i + 1);
            *count += (middle - i + 1) as i32;
            tmp.push(nums[j]);
            j += 1;
        }
    }

    while i <= middle {
        tmp.push(nums[i]);
        i += 1;
    }

    while j <= high {
        tmp.push(nums[j]);
        j += 1;
    }

   for i in 0..=(high-low) {
       nums[low+1] = tmp[i];
   }
}
fn main() {
    let nums = vec![1, 5, 6, 2, 3, 4];
    let m = merge_sort_count(nums);
    println!("{:?}", m);
}
