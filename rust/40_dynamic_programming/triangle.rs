# leetcode [minimum_total](https://leetcode.com/problems/triangle/)

pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
    if triangle.len() == 0 { return 0; }

    for i in (0..triangle.len() - 1).rev() {
        for j in 0..triangle[i].len() {
            triangle[i][j] = triangle[i+1][j].min(triangle[i+1][j+1]) + triangle[i][j];
        }
    }
    triangle[0][0]
}

fn main() {
    let triangle = vec![
        vec![2],
        vec![3, 4],
        vec![6, 5, 7],
        vec![4, 1, 8, 3],
    ];

    println!("{:?}", minimum_total(triangle));
}
