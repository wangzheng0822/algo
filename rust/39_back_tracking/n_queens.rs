# leetcode 51 [N-queens])https://leetcode.com/problems/n-queens/)

pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
    let mut board = vec![vec!['.'; n as usize]; n as usize];
    let mut solution = vec![];
    schedule_queens(&mut board, &mut solution, n as usize, 0);
    solution
}

fn schedule_queens(board: &mut Vec<Vec<char>>, solution: &mut Vec<Vec<String>>, len: usize, row: usize) {
    for col in 0..len {
        if !collision(&board, len, row, col) {
            board[row][col] = 'Q';
            if row == len - 1 {
                solution.push(board.iter().map(|vec| vec.iter().collect()).collect());
            } else {
                schedule_queens(board, solution, len, row+1);
            }
            board[row][col] = '.';
        }
    }
}

#[inline(always)]
fn collision(board: &Vec<Vec<char>>, len: usize, row: usize, col: usize) -> bool {
    for i in 0..row {
        if board[i][col] == 'Q' { return true }
    }
    let (mut i, mut j) = (row as i32 - 1, col as i32 - 1);
    while i >= 0 && j >= 0 {
        if board[i as usize][j as usize] == 'Q' { return true }
        i -= 1; j -= 1;
    }
    let (mut i, mut j) = (row as i32 - 1, col as i32 + 1);
    while i >= 0 && j < len as i32 {
        if board[i as usize][j as usize] == 'Q' { return true}
        i -= 1; j += 1;
    }
    false
}

fn main() {
    let m = solve_n_queens(8);
    println!("{:?}", m);
}
