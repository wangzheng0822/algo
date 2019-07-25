/// 计数排序
/// 时间复杂度：O(n), 稳定排序
// 计数排序
pub fn counting_sort(mut nums: Vec<i32>) -> Vec<i32> {
    if nums.len() <= 1 { return nums; }

    let nums_len = nums.len();
    // 获取最大数
    let mut max = nums[0];
    // 申请一个长度为 max + 1 的新数组
    let mut bucket = vec![0; (max+1) as usize];
    let mut tmp = vec![0; nums_len];

    for i in 1..nums_len {
        if max < nums[i] { max = nums[i]; }
    }

    for i in 0..nums_len {
        bucket[nums[i] as usize] += 1;
    }

    // 对 bucket 中元素进行累加，针对 nums 数组中每个元素，小于等于这个元素的个数
    // 如，nums 数组中元素 3，小于等于 3 的个数为 7 个
    for i in 1..bucket.len() {
        bucket[i] += bucket[i-1];
    }

    // 排序
    // 1. 申请一个与 nums 等长的数组，用于存储排序后的内容；
    // 2. 对数组 nums 从后向前迭代
    // 1). 从 bucket 数组中取出下标为 nums 数组中当前元素的值，如 nums 中当前元素为3，则从 bucket
    //   中取出下标为 3 的元素（即：在 nums 数组中元素 3 的位置应该为 7，index 为 6）
    // 2). 将元素 3 存入临时数组，此时元素 3 的个数变为 6 个
    // 3). 依次类推，直到将所有元素存入临时数组 tmp 中，完成排序
    for i in (0..nums_len).rev() {
        let index = bucket[nums[i] as usize] - 1;
        tmp[index] = nums[i];
        bucket[nums[i] as usize] -= 1;
    }

    for i in 0..tmp.len() {
        nums[i] = tmp[i];
    }
    nums
}

fn main() {
    let nums = vec![2, 5, 3, 0, 2, 3, 0, 3];
    let m = counting_sort(nums);
    println!("{:?}", m);
}
