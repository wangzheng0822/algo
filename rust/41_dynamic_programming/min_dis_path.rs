fn min_dis_path(matrix: Vec<Vec<i32>>) -> i32 {
    let m_len = matrix.len();
    if m_len == 0 { return 0; }

    let mut states = vec![vec![0; m_len]; m_len];
    let mut sum = 0;
    // 初始化第一行数据
    for j in 0..m_len {
        sum += matrix[0][j];
        states[0][j] = sum;
    }

    sum = 0;
    // 初始化第一列数据
    for i in 0..m_len {
        sum += matrix[i][0];
        states[i][0] = sum;
    }

    for i in 1..m_len {
        for j in 1..m_len {
            states[i][j] = matrix[i][j] + states[i-1][j].min(states[i][j-1])
        }
    }

    states[m_len-1][m_len-1]
}
fn main() {
    let matrix = vec![
        vec![1, 3, 5, 9],
        vec![2, 1, 3, 4],
        vec![5, 2, 6, 7],
        vec![6, 8, 4, 3],
    ];

   let m = min_dis_path(matrix);
   println!("{}", m);
}
