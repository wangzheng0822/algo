fn knapsack(items: Vec<i32>, capacity: i32) -> i32 {
    let mut states = vec![vec![false; (capacity + 1) as usize]; items.len()];
    let mut result = vec![];
    states[0][0] = true;
    if items[0] <= capacity { states[0][items[0] as usize] = true; }
    for i in 1..items.len() {
        for j in 0..=capacity as usize {
            if states[i-1][j] { states[i][j] = true; }
        }

        for j in 0..=(capacity - items[i]) as usize {
            if states[i-1][j] { states[i][j + items[i] as usize] = true; }
        }
    }

    let mut idx = capacity;
    while idx <= capacity {
       if states[items.len()-1][idx as usize] { break; }
       idx += 1;
    }
    for i in (1..items.len()).rev() {
        if idx - items[i] >= 0 && states[i-1][(idx-items[i]) as usize] {
            idx -= items[i];
            result.push(items[i]);
        }
    }

    if idx != 0 { result.push(items[0]); }
    println!("{:?}", result);

    for i in (0..=capacity as usize).rev() {
        if states[items.len()-1][i] { return i as i32; }
    }
    0
}

fn main() {
    let items = vec![2, 2, 4, 6, 3];
    let capacity = 9;
    let m = knapsack(items, capacity);
    println!("{}", m);
}
