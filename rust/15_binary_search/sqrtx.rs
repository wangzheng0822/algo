// leetcode: https://leetcode.com/problems/sqrtx/

pub fn my_sqrt(x: i32, precision: f32) -> f32 {
    if x == 0 || x == 1 { return x as f32; }

    let mut left = 0f32;
    let mut right = x as f32;
    let mut res = 0f32;

    while left <= right {
        let mid: f32 = (right - left) / 2.0 + left;

        if (right - left).abs() < precision { return mid; }

        if mid > x as f32 / mid {
            right = mid;
        } else {
            left = mid;
        }
        res = mid
    }

    res
}

fn main() {
    println!("{:?}", my_sqrt(8, 0.000001));
}
