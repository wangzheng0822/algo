use std::collections::BinaryHeap;

// 动态数组取 top k 元素
fn get_top_k(nums: &mut Vec<i32>, k: i32, x: i32) -> Vec<i32> {
    let nums_len = nums.len() as i32;
    if nums_len <= k { return nums.clone(); }

    let mut heap = BinaryHeap::new();

    // 先将数组的前k个数据放入堆中
    for _i in 0..k {
        heap.push(-nums[k as usize]);
    }

    // 对数组中其它数据进行迭代，若数据大于堆顶元素，将堆顶元素移除，将此数据放入堆中
    for i in k + 1..nums_len {
        if -nums[i as usize] < *heap.peek().unwrap() {
            heap.pop();
            heap.push(-nums[i as usize]);
        }
    }

    // 向数组中插入新数据
    nums.push(x);

    // 新插入的数据若大于堆顶元素，将堆顶元素移除，将此数据放入堆中
    if -x < *heap.peek().unwrap() {
        heap.pop();
        heap.push(-x);
    }

    // let m: Vec<i32> = heap.iter().map(|h| h * -1).collect();
    // m

    heap.iter().map(|h| h * -1).collect::<Vec<i32>>()
}

fn main() {
    let mut nums = vec![4, 5, 7, 9, 10, 6, 11];
    let m = get_top_k(&mut nums, 3, 23);
    println!("{:?}", m);
}
