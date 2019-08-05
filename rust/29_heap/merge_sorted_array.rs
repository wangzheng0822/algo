use std::collections::BinaryHeap;

fn merge_sorted_array(nums1: &mut Vec<i32>, nums2: &mut Vec<i32>, nums3: &mut Vec<i32>) -> Vec<i32> {
    let mut new_nums = vec![];
    let mut heap = BinaryHeap::new();

    // Rust heap 是大顶堆，将待入堆的数值取反后再入堆，堆顶即为最小值，即达到小顶堆效果
    heap.push(-nums1[0]);
    heap.push(-nums2[0]);
    heap.push(-nums3[0]);

    while !nums1.is_empty() || !nums2.is_empty() || !nums3.is_empty() {
        if heap.is_empty() { break; }
        let num = -heap.pop().unwrap();
        new_nums.push(num);

        if !nums1.is_empty() && num == nums1[0] {
            nums1.remove(0);
            if !nums1.is_empty() { heap.push(-nums1[0]); }
        } else if !nums2.is_empty() && num == nums2[0] {
            nums2.remove(0);
            if !nums2.is_empty() { heap.push(-nums2[0]); }
        } else if !nums3.is_empty() && num == nums2[0] {
            nums3.remove(0);
            if !nums3.is_empty() { heap.push(-nums3[0]); }
        }
    }
    new_nums
}

fn main() {
    let mut nums1 = vec![4, 5, 20, 90, 95, 100];
    let mut nums2 = vec![1, 6, 7, 8, 11, 23, 67, 89];
    let mut nums3 = vec![2, 5, 9, 30, 45];
    let new_nums = merge_sorted_array(&mut nums1, &mut nums2, &mut nums3);

    println!("{:?}", new_nums);
}
