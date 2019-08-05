use std::collections::BinaryHeap;

// 动态数组取位数
// 对数组进行从小到大排序，数组下标为 n/2 的数据即为中位数
fn get_median(nums: &mut Vec<i32>, x: i32) -> i32 {
    let nums_len = nums.len();
    let mid = nums_len >> 1;
    let mut max_heap = BinaryHeap::new();
    let mut min_heap = BinaryHeap::new();
    nums.sort();

    // 将数组前半部分数据放入大顶堆
    // 数组后半部分数据入入小顶堆
    for i in 0..nums_len {
        if i < mid {
            max_heap.push(nums[i]);
        } else {
            min_heap.push(-nums[i]);
        }
    }

    nums.push(x);

    // 校验待插入数据
    // 若此数据小于大顶堆中顶数据，则将此数据插入大顶堆
    // 若此数据大于大顶堆中顶数据，将此数据插入小顶堆
    if x <= *max_heap.peek().unwrap() {
        max_heap.push(x);
    } else {
        min_heap.push(-x);
    }

    // 平衡两个堆
    // 大顶堆的数据个数一定小于等于小顶堆数据个数
    // 小顶堆数据个数一定是等于或者比大顶堆数据个数多1个
    // 不满足上述两个条件，即进行堆平衡
    if max_heap.len() > min_heap.len() {
        min_heap.push(-max_heap.pop().unwrap());
    } else if min_heap.len() - max_heap.len() >= 2 {
        max_heap.push(-min_heap.pop().unwrap());
    }

    -*min_heap.peek().unwrap()
}

fn main() {
    let mut nums = vec![12, 45, 30, 77, 5, 6, 7, 8];
    let m = get_median(&mut nums, 9);
    println!("{:?}", m); // 9
    let n = get_median(&mut nums, 20);
    println!("{:?}", n); // 12
    let h = get_median(&mut nums, 11);
    println!("{:?}", h); // 11
    let i = get_median(&mut nums, 10);
    println!("{:?}", i); // 11
}
