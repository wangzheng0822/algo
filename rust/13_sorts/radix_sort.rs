/// 基数排序
/// 时间复杂度：O(n), 稳定排序
// 基数排序
pub fn radix_sort(mut nums: Vec<i64>) -> Vec<i64> {
    let max_bit = max_bit(&nums);
    // 申请一个长度为 10 的桶
    let mut bucket = vec![0; 10];
    let mut tmp = vec![0; nums.len()];
    let mut radix = 1;
    let nums_len = nums.len();

    // 迭代 max_bit 次
    for _i in 0..max_bit {
        // 每次比较前先将桶清空
        for j in 0..bucket.len() { bucket[j] = 0; }

        for j in 0..nums_len {
            let index = ((nums[j] / radix) % 10) as usize;
            bucket[index] += 1;
        }

        for j in 1..bucket.len() { bucket[j] += bucket[j-1]; }

        // 对 nums 进行排序
        for j in (0..nums_len).rev() {
            let index = ((nums[j] / radix) % 10) as usize;
            tmp[(bucket[index]-1) as usize] = nums[j];
            bucket[index] -= 1;
        }

        for j in 0..nums_len {
            nums[j] = tmp[j];
        }

        radix *= 10;
    }
    nums
}

fn max_bit(nums: &Vec<i64>) -> i32 {
    let mut max = nums[0];
    let mut bit = 1; // 预防数据库中元素全部是 0 的情况
    for &num in nums.iter() {
        if num > max { max = num; }
    }

    while max >= 10 {
        max = max / 10;
        bit += 1;
    }
    bit
}

fn main() {
    // let nums = vec![1, 10, 100, 1000, 98, 67, 3, 28, 67, 888, 777];
    let nums = vec![13111111111, 13299999999, 13311111111, 13133333333, 13922222222, 13722222222];
    println!("{:?}", radix_sort(nums));
}
